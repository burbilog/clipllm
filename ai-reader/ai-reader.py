#!/usr/bin/env python3

import sys
import os
import json
import subprocess
import requests
import pyperclip
import threading
import argparse
import tkinter as tk
import datetime  # Добавлено для работы с датой/временем
import base64
from tkinter import scrolledtext, font, ttk

# GTK clipboard (для изображений)
try:
    import gi
    gi.require_version("Gtk", "3.0")
    from gi.repository import Gtk, Gdk
except Exception:
    Gtk = None
    Gdk = None


# --- КОНФИГУРАЦИЯ ---
MODEL = "moonshotai/kimi-k2-thinking"
MODEL = "x-ai/grok-4.1-fast"
MODEL = "openai/gpt-5.1-codex"
API_URL = "https://openrouter.ai/api/v1/chat/completions"
KEY_FILE = os.path.expanduser("~/.openrouter-api-key")
CONFIG_DIR = os.path.expanduser("~/.ai-reader")
LOG_FILE = os.path.join(CONFIG_DIR, "history.txt")
CONFIG_FILE = os.path.join(CONFIG_DIR, "config.json")
PROXY_URL = "http://127.0.0.1:8085"  # HTTP прокси для всех запросов

# Создаём каталог если не существует
os.makedirs(CONFIG_DIR, exist_ok=True)

# Миграция старого лог-файла
old_log_file = os.path.expanduser("~/.ai-reader-transcriptions.txt")
if os.path.exists(old_log_file) and not os.path.exists(LOG_FILE):
    try:
        import shutil
        shutil.move(old_log_file, LOG_FILE)
    except Exception:
        pass


# --- ФУНКЦИИ КОНФИГУРАЦИИ ОКОН ---

def load_window_config(window_id):
    """Загружает конфигурацию окна из файла"""
    try:
        if os.path.exists(CONFIG_FILE):
            with open(CONFIG_FILE, 'r', encoding='utf-8') as f:
                config = json.load(f)
                return config.get("windows", {}).get(window_id, {})
    except Exception:
        pass
    return {}


def save_window_config(window_id, x=None, y=None, width=None,
                       height=None, font_size=None):
    """Сохраняет конфигурацию окна в файл"""
    try:
        config = {}
        if os.path.exists(CONFIG_FILE):
            with open(CONFIG_FILE, 'r', encoding='utf-8') as f:
                config = json.load(f)

        if "windows" not in config:
            config["windows"] = {}

        if window_id not in config["windows"]:
            config["windows"][window_id] = {}

        if x is not None:
            config["windows"][window_id]['x'] = x
        if y is not None:
            config["windows"][window_id]['y'] = y
        if width is not None:
            config["windows"][window_id]['width'] = width
        if height is not None:
            config["windows"][window_id]['height'] = height
        if font_size is not None:
            config["windows"][window_id]['font_size'] = font_size

        with open(CONFIG_FILE, 'w', encoding='utf-8') as f:
            json.dump(config, f, indent=2, ensure_ascii=False)
    except Exception:
        pass


# --- ПРОМПТЫ ---
PROMPT_SUMMARY = (
    "Ты — профессиональный аналитик. "
    "Твоя задача — прочитать текст и написать его "
    "структурированное краткое содержание (summary) на русском языке. "
    "Выдели ключевые идеи маркированным списком. "
    "Игнорируй веб-мусор (меню, рекламу, футеры). "
    "Пиши емко и по сути."
)

PROMPT_FULL_RU = (
    "Ты — профессиональный редактор и переводчик. "
    "Твоя задача — подготовить текст для чтения. "
    "1. Сохрани полный объем информации, не сокращай. "
    "2. Переведи текст на русский язык (если он не на русском). "
    "3. Разбей текст на удобные логические абзацы. "
    "4. Убери веб-мусор и исправь опечатки. "
    "Верни только готовый текст."
)

PROMPT_FULL_EN = (
    "You are a professional editor. "
    "Your task is to format the text for better readability. "
    "1. Keep the full content, do not summarize. "
    "2. Keep the text in its original language (mostly English). "
    "   Do NOT translate. "
    "3. Split into logical paragraphs. "
    "4. Remove web garbage (ads, menus) and fix typos. "
    "Return only the clean text."
)

PROMPT_FIX = (
    "You are a professional English editor. "
    "Your task is to fix English grammar, spelling, "
    "and punctuation errors. "
    "1. Correct all grammatical mistakes "
    "2. Fix spelling errors and typos "
    "3. Improve punctuation and sentence structure "
    "4. Keep the original meaning and vocabulary "
    "5. Do not use long dash, use -- (two regular dashes) "
    "   instead with spaces around it. "
    "6. Do not use strange quote characters, "
    "   use regular \" and ' ones. "
    "Output only the fixed text without any explanation "
    "or additional comments."
)

PROMPT_GRAMMAR = (
    "Ты — профессиональный лингвист и эксперт по грамматике. "
    "Проанализируй грамматику данного текста. "
    "Для каждого предложения укажи: "
    "1. Исходное предложение "
    "2. Полный грамматический разбор "
    "   (части речи, время, структура предложения и т.д.) "
    "3. Объясняй сложную грамматику подробно "
    "Будь кратким и структурированным. "
    "Используй маркированные списки для ясности. "
    "Отвечай на русском языке."
)

PROMPT_IMAGE_RU = (
    "Ты -- переводчик и редактор. "
    "Твоя задача -- извлечь текст с изображения (OCR) "
    "и перевести на русский. "
    "1) Сохрани смысл максимально точно. "
    "2) Сохрани структуру (заголовки/списки), если она читается. "
    "3) Если на изображении несколько блоков текста, раздели их абзацами. "
    "Верни только изначальный текст (с фонетикой хираганой через пробелы, "
    "если это японский) и перевод (без пояснений), для каждого предложения. "
    "Например: "
    "私はとあるアイテムで\n"
    "わたし は とある アイテム で\n"
    "Я пользуюсь одним предметом."
)

PROMPT_IMAGE_GRAMMAR = (
    "Ты — профессиональный лингвист и эксперт по грамматике. "
    "Твоя задача — распознать текст с изображения (OCR) "
    "и проанализировать его грамматику. "
    "1. Распознай весь текст с изображения "
    "   (включая японский, английский, русский и другие языки). "
    "2. Для каждого предложения укажи: "
    "   — Исходное предложение (с фонетикой хираганой через пробелы, "
    "     если это японский) "
    "   — Полный грамматический разбор "
    "     (части речи, время, структура предложения) "
    "   — Объяснение сложной грамматики "
    "Будь кратким и структурированным. "
    "Используй маркированные списки для ясности. "
    "Отвечай на русском языке."
)


def get_api_key():
    try:
        with open(KEY_FILE, 'r') as f:
            return f.read().strip()
    except FileNotFoundError:
        print(f"Ошибка: Файл с ключом не найден: {KEY_FILE}")
        sys.exit(1)


def format_size(size_bytes):
    if size_bytes == 0:
        return "0 B"
    size_name = ("B", "KB", "MB", "GB")
    i = 0
    p = size_bytes
    while p >= 1024 and i < len(size_name) - 1:
        p /= 1024.0
        i += 1
    return f"{p:.2f} {size_name[i]}"


def get_clipboard_image_png_bytes():
    """
    Возвращает PNG bytes из clipboard, если там есть изображение.
    Работает в KDE/LXQt через GTK clipboard.
    """
    if Gtk is None or Gdk is None:
        raise RuntimeError(
            "GTK (python3-gi) недоступен. "
            "Установите python3-gi и gir1.2-gtk-3.0"
        )

    cb = Gtk.Clipboard.get(Gdk.SELECTION_CLIPBOARD)
    pixbuf = cb.wait_for_image()
    if pixbuf is None:
        return None

    ok, buf = pixbuf.save_to_bufferv("png", [], [])
    if not ok:
        raise RuntimeError("Не удалось конвертировать clipboard image в PNG")
    return bytes(buf)


class AIReaderApp:
    def __init__(self, mode):
        self.api_key = get_api_key()
        self.mode = mode

        self.root = tk.Tk()
        self.root.title(f"AI Reader [{mode}]")

        # Загружаем конфигурацию окна
        config = load_window_config("main")
        if config:
            w = config.get('width', 1000)
            h = config.get('height', 900)
            if 'x' in config and 'y' in config:
                self.root.geometry(f'{w}x{h}+{config["x"]}+{config["y"]}')
            else:
                self.root.geometry(f'{w}x{h}')
        else:
            self.root.geometry("1000x900")

        self.current_font_size = 16
        self.text_font = font.Font(
            family="Helvetica",
            size=self.current_font_size
        )

        self.result_text = ""
        self.error_message = ""
        self.downloaded_bytes = 0
        self.is_thinking = False
        self.is_processing = False

        self.setup_ui()
        self.setup_bindings()
        self.start_processing()

    def setup_ui(self):
        self.loading_frame = tk.Frame(self.root)
        self.loading_frame.pack(expand=True, fill='both')

        self.status_label = tk.Label(
            self.loading_frame,
            text="Инициализация...",
            font=("Helvetica", 14)
        )
        self.status_label.pack(pady=(180, 20))

        self.progress = ttk.Progressbar(
            self.loading_frame,
            mode='indeterminate',
            length=300
        )
        self.progress.pack(pady=10)

        self.bytes_label = tk.Label(
            self.loading_frame,
            text="Ожидание...",
            font=("Consolas", 10),
            fg="#555"
        )
        self.bytes_label.pack(pady=5)

        self.result_frame = tk.Frame(self.root)
        self.text_area = scrolledtext.ScrolledText(
            self.result_frame,
            wrap=tk.WORD,
            font=self.text_font,
            spacing1=2,  # Отступ выше каждой строки
            spacing3=2,  # Отступ ниже каждой строки
            padx=8,      # Горизонтальный отступ внутри текста
            pady=8       # Вертикальный отступ внутри текста
        )
        self.text_area.pack(
            expand=True,
            fill='both',
            padx=10,
            pady=10
        )

        btn_frame = tk.Frame(self.result_frame)
        btn_frame.pack(fill='x', padx=10, pady=5)

        tk.Label(
            btn_frame,
            text="Ctrl +/-: Шрифт | Esc: Выход",
            fg="gray"
        ).pack(side='left')
        tk.Button(
            btn_frame,
            text="Скопировать",
            command=self.copy_to_clipboard
        ).pack(side='right', padx=(0, 5))
        tk.Button(
            btn_frame,
            text="Закрыть",
            command=self.close_without_copy
        ).pack(side='right')

    def setup_bindings(self):
        # Глобальные привязки
        self.root.bind('<Escape>', lambda e: self.root.destroy())
        # Note: WM_DELETE_WINDOW handler is set in run() method
        # to save window position

        # Привязки клавиатуры для зума
        self.root.bind('<Control-plus>', lambda e: self.change_font_size(2))
        self.root.bind('<Control-equal>', lambda e: self.change_font_size(2))
        self.root.bind('<Control-minus>', lambda e: self.change_font_size(-2))
        self.root.bind('<Control-0>', lambda e: self.reset_font_size())

        # Привязки мыши (важно привязать именно к text_area,
        # чтобы перехватить фокус)
        # Колёсико мыши с Ctrl - Windows/macOS
        self.text_area.bind('<Control-MouseWheel>', self.on_mousewheel)

        # Колёсико мыши с Ctrl - Linux (Button-4/5 вместо MouseWheel)
        self.text_area.bind(
            '<Control-Button-4>',
            lambda e: self.change_font_size(2)
        )
        self.text_area.bind(
            '<Control-Button-5>',
            lambda e: self.change_font_size(-2)
        )

        # Copy-on-select: копировать при отпускании кнопки мыши
        # после выделения
        self.text_area.bind('<ButtonRelease-1>', self.on_select_copy)

    def on_mousewheel(self, event):
        if event.delta > 0:
            self.change_font_size(2)
        else:
            self.change_font_size(-2)
        return "break"

    def on_select_copy(self, event):
        """Copy-on-select: копирует выделенный текст в PRIMARY
        selection (для KDE Connect)"""
        try:
            # Получаем границы выделения
            sel_start = self.text_area.index("sel.first")
            sel_end = self.text_area.index("sel.last")

            # Читаем текст напрямую из виджета по индексам
            selected = self.text_area.get(sel_start, sel_end)

            # Пытаемся использовать xsel или xclip для записи в PRIMARY
            try:
                subprocess.run(
                    ['xsel', '-i', '--primary'],
                    input=selected.encode(),
                    check=True,
                    timeout=1
                )
            except (FileNotFoundError, subprocess.TimeoutExpired):
                try:
                    subprocess.run(
                        ['xclip', '-selection', 'primary'],
                        input=selected.encode(),
                        check=True,
                        timeout=1
                    )
                except (FileNotFoundError, subprocess.TimeoutExpired):
                    pass  # xsel/xclip не найдены

            # Отложенное восстановление выделения —
            # после того как Tkinter завершит свою работу
            def restore_selection():
                try:
                    self.text_area.tag_add("sel", sel_start, sel_end)
                except Exception:
                    pass

            self.root.after(10, restore_selection)

        except Exception:
            pass  # Игнорируем, если нет выделения или другая ошибка

    def change_font_size(self, delta):
        new_size = max(8, min(self.current_font_size + delta, 72))
        self.current_font_size = new_size
        self.text_font.configure(size=self.current_font_size)

    def reset_font_size(self):
        self.current_font_size = 14
        self.text_font.configure(size=self.current_font_size)

    def copy_to_clipboard(self):
        """Copy text area content to clipboard"""
        try:
            # Copy from the stored result_text
            if self.result_text.strip():
                self.root.clipboard_clear()
                self.root.clipboard_append(self.result_text)
                self.root.update()
            else:
                # Fallback: try reading from text area
                current_state = self.text_area.cget('state')
                self.text_area.configure(state='normal')
                content = self.text_area.get("1.0", tk.END).strip()
                if content:
                    self.root.clipboard_clear()
                    self.root.clipboard_append(content)
                    self.root.update()
                self.text_area.configure(state=current_state)
        except Exception as e:
            print(f"Failed to copy to clipboard: {e}")

    def close_without_copy(self):
        """Close the application without copying to clipboard"""
        self._save_and_destroy()

    def _save_and_destroy(self):
        """Сохраняет позицию окна и уничтожает его"""
        geometry = self.root.geometry()
        import re
        match = re.match(r'(\d+)x(\d+)\+?(-?\d+)\+?(-?\d+)?', geometry)
        if match:
            w, h, x, y = match.groups()
            save_window_config(
                "main", int(x),
                int(y) if y else None,
                int(w), int(h)
            )
        self.root.destroy()

    def start_processing(self):
        # --- image mode ---
        if self.mode == "image":
            try:
                png_bytes = get_clipboard_image_png_bytes()
                if not png_bytes:
                    self.show_error("В буфере обмена нет изображения!")
                    return
            except Exception as e:
                self.show_error(
                    f"Ошибка чтения изображения из буфера: {e}"
                )
                return

            self.status_label.config(text=f"Запрос к {MODEL} (image)...")
            self.progress.start(10)
            self.is_processing = True

            thread = threading.Thread(
                target=self.run_llm_request_image,
                args=(png_bytes,)
            )
            thread.daemon = True
            thread.start()

            self.check_thread(thread)
            return

        # --- grammar mode: сначала проверка изображения, затем текст ---
        if self.mode == "grammar":
            try:
                png_bytes = get_clipboard_image_png_bytes()
                if png_bytes:
                    self.status_label.config(
                        text=f"Запрос к {MODEL} (grammar image)..."
                    )
                    self.progress.start(10)
                    self.is_processing = True

                    thread = threading.Thread(
                        target=self.run_llm_request_image,
                        args=(
                            png_bytes,
                            PROMPT_IMAGE_GRAMMAR,
                            "Распознай текст на изображении "
                            "и проанализируй его грамматику."
                        )
                    )
                    thread.daemon = True
                    thread.start()

                    self.check_thread(thread)
                    return
            except Exception:
                pass  # Нет изображения, продолжаем с текстом

        # --- text modes (старое поведение) ---
        try:
            clipboard_text = pyperclip.paste()
            if not clipboard_text.strip():
                self.show_error("Буфер обмена пуст!")
                return
        except Exception as e:
            self.show_error(f"Ошибка буфера: {e}")
            return

        self.status_label.config(text=f"Запрос к {MODEL}...")
        self.progress.start(10)
        self.is_processing = True

        thread = threading.Thread(
            target=self.run_llm_request,
            args=(clipboard_text,)
        )
        thread.daemon = True
        thread.start()

        self.check_thread(thread)

    def run_llm_request(self, text_input):
        prompts = {
            'summary': PROMPT_SUMMARY,
            'full-ru': PROMPT_FULL_RU,
            'full-en': PROMPT_FULL_EN,
            'fix': PROMPT_FIX,
            'grammar': PROMPT_GRAMMAR
        }
        system_prompt = prompts.get(self.mode, PROMPT_SUMMARY)

        headers = {
            "Authorization": f"Bearer {self.api_key}",
            "Content-Type": "application/json",
            "HTTP-Referer": "https://localhost",
            "X-Title": "KDE AI Reader"
        }

        payload = {
            "model": MODEL,
            "messages": [
                {"role": "system", "content": system_prompt},
                {"role": "user", "content": text_input}
            ],
            "stream": True,
            "include_reasoning": True
        }

        try:
            proxies = {
                'http': PROXY_URL,
                'https': PROXY_URL
            }
            response = requests.post(
                API_URL,
                headers=headers,
                data=json.dumps(payload),
                stream=True,
                timeout=120,
                proxies=proxies
            )
            response.raise_for_status()

            for line in response.iter_lines():
                if line:
                    self.downloaded_bytes += len(line)
                    decoded_line = line.decode('utf-8').strip()

                    if decoded_line.startswith("data: "):
                        json_str = decoded_line[6:]
                        if json_str == "[DONE]":
                            break

                        try:
                            chunk = json.loads(json_str)
                            if ("choices" in chunk and
                                    len(chunk["choices"]) > 0):
                                delta = chunk["choices"][0].get("delta", {})

                                reasoning = (delta.get("reasoning") or
                                             delta.get("reasoning_content"))
                                content = delta.get("content")

                                if reasoning:
                                    self.is_thinking = True

                                if content:
                                    self.is_thinking = False
                                    self.result_text += content

                        except json.JSONDecodeError:
                            continue

        except Exception as e:
            self.error_message = f"Ошибка: {e}"
        finally:
            self.is_processing = False

    def run_llm_request_image(
        self,
        png_bytes: bytes,
        system_prompt=PROMPT_IMAGE_RU,
        user_text="Переведи текст на этом изображении на русский."
    ):
        headers = {
            "Authorization": f"Bearer {self.api_key}",
            "Content-Type": "application/json",
            "HTTP-Referer": "https://localhost",
            "X-Title": "KDE AI Reader"
        }

        b64 = base64.b64encode(png_bytes).decode("ascii")
        data_url = f"data:image/png;base64,{b64}"

        payload = {
            "model": MODEL,
            "messages": [
                {"role": "system", "content": system_prompt},
                {
                    "role": "user",
                    "content": [
                        {"type": "text", "text": user_text},
                        {
                            "type": "image_url",
                            "image_url": {"url": data_url}
                        },
                    ],
                },
            ],
            "stream": True,
            "include_reasoning": True
        }

        try:
            proxies = {
                'http': PROXY_URL,
                'https': PROXY_URL
            }
            response = requests.post(
                API_URL,
                headers=headers,
                data=json.dumps(payload),
                stream=True,
                timeout=120,
                proxies=proxies
            )
            response.raise_for_status()

            for line in response.iter_lines():
                if line:
                    self.downloaded_bytes += len(line)
                    decoded_line = line.decode('utf-8').strip()

                    if decoded_line.startswith("data: "):
                        json_str = decoded_line[6:]
                        if json_str == "[DONE]":
                            break

                        try:
                            chunk = json.loads(json_str)
                            if ("choices" in chunk and
                                    len(chunk["choices"]) > 0):
                                delta = chunk["choices"][0].get("delta", {})

                                reasoning = (delta.get("reasoning") or
                                             delta.get("reasoning_content"))
                                content = delta.get("content")

                                if reasoning:
                                    self.is_thinking = True

                                if content:
                                    self.is_thinking = False
                                    self.result_text += content

                        except json.JSONDecodeError:
                            continue

        except Exception as e:
            self.error_message = f"Ошибка: {e}"
        finally:
            self.is_processing = False

    def check_thread(self, thread):
        size_str = format_size(self.downloaded_bytes)

        if self.is_thinking:
            status_text = "🤔 Модель размышляет..."
            color = "blue"
        elif self.downloaded_bytes > 0:
            status_text = "📝 Генерация ответа..."
            color = "black"
        else:
            status_text = "⏳ Подключение..."
            color = "gray"

        self.status_label.config(text=status_text, fg=color)
        self.bytes_label.config(text=f"Трафик: {size_str}")

        if thread.is_alive():
            self.root.after(
                100,
                lambda: self.check_thread(thread)
            )
        else:
            self.progress.stop()
            if self.error_message:
                self.show_error(self.error_message)
            else:
                self.show_result()

    def save_log(self):
        """Сохраняет результат в лог-файл"""
        try:
            now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            separator = "═" * 60  # Unicode box drawing character
            # реже встречается в тексте

            log_entry = (
                f"{separator}\n"
                f"DATE: {now}\n"
                f"MODEL: {MODEL}\n"
                f"MODE: {self.mode}\n"
                f"{separator}\n"
                f"{self.result_text}\n\n"
            )

            with open(LOG_FILE, "a", encoding="utf-8") as f:
                f.write(log_entry)

        except Exception as e:
            # Если не удалось записать лог, выводим в консоль,
            # но не прерываем работу UI
            print(f"Не удалось сохранить лог: {e}")

    def show_result(self):
        # Сохраняем лог перед показом
        self.save_log()

        self.loading_frame.pack_forget()
        self.result_frame.pack(expand=True, fill='both')
        self.text_area.insert(tk.INSERT, self.result_text)
        self.text_area.configure(state='disabled')
        self.root.focus_force()

    def show_error(self, message):
        self.loading_frame.pack_forget()
        self.result_frame.pack(expand=True, fill='both')
        self.text_area.insert(tk.INSERT, f"ОШИБКА:\n\n{message}")
        self.text_area.configure(state='disabled', fg='red')

    def run(self):
        self.root.protocol("WM_DELETE_WINDOW", self._save_and_destroy)
        self.root.mainloop()


def parse_log_file():
    """
    Парсит лог-файл и возвращает список записей.
    Каждая запись: {'date': str, 'model': str, 'mode': str,
                    'content': str, 'preview': str}
    """
    entries = []
    try:
        with open(LOG_FILE, "r", encoding="utf-8") as f:
            lines = f.readlines()

        # Пробуем новый разделитель (Unicode), если записей нет - старый
        separator_new = "═" * 60
        separator_old = "=" * 60

        # Определяем какой разделитель использовать
        has_new = any(
            line.strip() == separator_new for line in lines
        )
        separator = separator_new if has_new else separator_old

        # Находим индексы строк с разделителем
        separator_indices = [
            i for i, line in enumerate(lines)
            if line.strip() == separator
        ]

        # Каждая запись занимает 2 разделителя:
        # начало заголовка и конец заголовка
        # Формат: [разделитель] DATE:... MODEL:... MODE:...
        # [разделитель] контент
        for i in range(0, len(separator_indices) - 1, 2):
            if i + 1 >= len(separator_indices):
                break

            header_start = separator_indices[i] + 1
            header_end = separator_indices[i + 1]

            # Читаем заголовок
            header_lines = lines[header_start:header_end]
            header_text = ''.join(header_lines)

            # Проверяем наличие обязательных полей
            if not ("DATE:" in header_text or
                    "MODEL:" in header_text or
                    "MODE:" in header_text):
                continue

            # Парсим заголовок
            date = "Неизвестно"
            model = "Неизвестно"
            mode = "Неизвестно"

            for line in header_lines:
                line = line.strip()
                if line.startswith("DATE:"):
                    date = line[5:].strip()
                elif line.startswith("MODEL:"):
                    model = line[6:].strip()
                elif line.startswith("MODE:"):
                    mode = line[5:].strip()

            # Читаем контент до следующего разделителя или конца файла
            content_start = header_end + 1
            if i + 2 < len(separator_indices):
                content_end = separator_indices[i + 2]
            else:
                content_end = len(lines)

            content_lines = lines[content_start:content_end]
            content_text = ''.join(content_lines).strip()

            # Создаем превью (первые 100 символов)
            preview = content_text[:100].replace('\n', ' ')
            if len(content_text) > 100:
                preview += "..."

            entries.append({
                'date': date,
                'model': model,
                'mode': mode,
                'content': content_text,
                'preview': preview
            })

    except FileNotFoundError:
        pass  # Файл не существует — возвращаем пустой список
    except Exception as e:
        print(f"Ошибка чтения лог-файла: {e}")

    # Разворачиваем список, чтобы новые записи были сверху
    return entries[::-1]


class HistoryViewerApp:
    """Окно просмотра истории с возможностью выбора записи"""

    def __init__(self):
        self.root = tk.Tk()
        self.root.title("AI Reader - История")

        # Загружаем конфигурацию окна
        config = load_window_config("history")
        if config:
            w = config.get('width', 950)
            h = config.get('height', 750)
            if 'x' in config and 'y' in config:
                self.root.geometry(f'{w}x{h}+{config["x"]}+{config["y"]}')
            else:
                self.root.geometry(f'{w}x{h}')
        else:
            self.root.geometry("950x750")

        # Заголовок
        tk.Label(
            self.root,
            text="История обработок",
            font=("Helvetica", 14, "bold")
        ).pack(pady=10)

        # Список записей
        list_frame = tk.Frame(self.root)
        list_frame.pack(expand=True, fill='both', padx=20, pady=10)

        # Scrollbar
        scrollbar = tk.Scrollbar(list_frame)
        scrollbar.pack(side='right', fill='y')

        # Listbox с записями
        self.listbox = tk.Listbox(
            list_frame,
            font=("Helvetica", 10),
            yscrollcommand=scrollbar.set,
            selectmode='single'
        )
        self.listbox.pack(side='left', expand=True, fill='both')
        scrollbar.config(command=self.listbox.yview)

        # Заполняем список
        entries = parse_log_file()
        if not entries:
            self.listbox.insert(0, "История пуста")
            self.listbox.configure(state='disabled')
        else:
            for idx, entry in enumerate(entries):
                self.listbox.insert(
                    idx,
                    f"[{entry['date']}] {entry['mode'].upper()} — "
                    f"{entry['preview']}"
                )
            self.entries = entries

        # Привязка двойного клика
        self.listbox.bind('<Double-Button-1>', self.on_double_click)

        # Кнопки
        btn_frame = tk.Frame(self.root)
        btn_frame.pack(fill='x', padx=20, pady=10)

        tk.Button(
            btn_frame,
            text="Открыть",
            command=self.open_selected,
            font=("Helvetica", 10)
        ).pack(side='left', padx=5)
        tk.Button(
            btn_frame,
            text="Назад",
            command=self._back_to_selector,
            font=("Helvetica", 10)
        ).pack(side='right', padx=5)

        # Escape для закрытия
        self.root.bind('<Escape>', lambda e: self._back_to_selector())

        # Enter для открытия
        self.root.bind('<Return>', lambda e: self.open_selected())

    def _back_to_selector(self):
        """Сохраняет позицию окна и закрывает его"""
        geometry = self.root.geometry()
        import re
        match = re.match(
            r'(\d+)x(\d+)(?:\+(-?\d+)\+(-?\d+))?',
            geometry
        )
        if match:
            w, h, x, y = match.groups()
            save_window_config(
                "history",
                int(x) if x else None,
                int(y) if y else None,
                int(w), int(h)
            )
        self.root.destroy()

    def on_double_click(self, event):
        self.open_selected()

    def open_selected(self):
        selection = self.listbox.curselection()
        if not selection:
            return

        idx = selection[0]
        if hasattr(self, 'entries') and idx < len(self.entries):
            self.show_entry(self.entries[idx])

    def show_entry(self, entry):
        """Показывает отдельную запись в новом окне"""
        window = tk.Toplevel(self.root)
        window.title(f"AI Reader - {entry['mode'].upper()} [{entry['date']}]")

        # Загружаем конфигурацию окна
        config = load_window_config("history_entry")
        if config:
            w = config.get('width', 950)
            h = config.get('height', 750)
            saved_font_size = config.get('font_size', 14)
            if 'x' in config and 'y' in config:
                window.geometry(f'{w}x{h}+{config["x"]}+{config["y"]}')
            else:
                window.geometry(f'{w}x{h}')
        else:
            window.geometry("950x750")
            saved_font_size = 14

        # Заголовок с информацией
        header = tk.Frame(window)
        header.pack(fill='x', padx=10, pady=10)

        tk.Label(
            header,
            text=f"Режим: {entry['mode'].upper()}",
            font=("Helvetica", 11, "bold")
        ).pack(anchor='w')
        tk.Label(
            header,
            text=f"Дата: {entry['date']}",
            font=("Helvetica", 10),
            fg="gray"
        ).pack(anchor='w')
        tk.Label(
            header,
            text=f"Модель: {entry['model']}",
            font=("Helvetica", 10),
            fg="gray"
        ).pack(anchor='w')

        # Текстовый виджет
        text_font = font.Font(family="Helvetica", size=saved_font_size)
        text_area = scrolledtext.ScrolledText(
            window,
            wrap=tk.WORD,
            font=text_font,
            spacing1=2,
            spacing3=2,
            padx=8,
            pady=8
        )
        text_area.pack(expand=True, fill='both', padx=10, pady=(0, 10))
        text_area.insert(tk.INSERT, entry['content'])
        text_area.configure(state='disabled')

        # Кнопки
        btn_frame = tk.Frame(window)
        btn_frame.pack(fill='x', padx=10, pady=5)

        def copy_content():
            window.clipboard_clear()
            window.clipboard_append(entry['content'])
            window.update()

        tk.Label(
            btn_frame,
            text="Ctrl +/-: Шрифт",
            fg="gray"
        ).pack(side='left')

        current_font_size = [saved_font_size]

        def change_font_size(delta):
            new_size = max(8, min(current_font_size[0] + delta, 72))
            current_font_size[0] = new_size
            text_font.configure(size=new_size)

        window.bind('<Control-plus>', lambda e: change_font_size(2))
        window.bind('<Control-equal>', lambda e: change_font_size(2))
        window.bind('<Control-minus>', lambda e: change_font_size(-2))

        # Колёсико мыши с Ctrl - Windows/macOS
        text_area.bind(
            '<Control-MouseWheel>',
            lambda e: change_font_size(2)
            if e.delta > 0 else change_font_size(-2)
        )
        # Колёсико мыши с Ctrl - Linux (Button-4/5)
        text_area.bind('<Control-Button-4>', lambda e: change_font_size(2))
        text_area.bind('<Control-Button-5>', lambda e: change_font_size(-2))

        # Обработчик закрытия для сохранения размеров
        def on_entry_closing():
            geometry = window.geometry()
            import re
            # Toplevel может включать позицию,
            # парсим оба формата
            match = re.match(
                r'(\d+)x(\d+)(?:\+(-?\d+)\+(-?\d+))?',
                geometry
            )
            if match:
                groups = match.groups()
                w, h = int(groups[0]), int(groups[1])
                x = int(groups[2]) if groups[2] else None
                y = int(groups[3]) if groups[3] else None
                save_window_config(
                    "history_entry",
                    x=x, y=y,
                    width=w, height=h,
                    font_size=current_font_size[0]
                )
            window.destroy()

        tk.Button(
            btn_frame,
            text="Скопировать",
            command=copy_content
        ).pack(side='right', padx=(0, 5))

        def copy_and_exit():
            """Копирует содержимое и полностью закрывает приложение"""
            copy_content()
            # Даём время буферу обмена сохраниться
            window.update()
            window.after(100, do_exit)

        def do_exit():
            """Выполняет выход после задержки"""
            # Сохраняем конфигурацию перед выходом
            geometry = window.geometry()
            import re
            match = re.match(
                r'(\d+)x(\d+)(?:\+(-?\d+)\+(-?\d+))?',
                geometry
            )
            if match:
                groups = match.groups()
                w, h = int(groups[0]), int(groups[1])
                x = int(groups[2]) if groups[2] else None
                y = int(groups[3]) if groups[3] else None
                save_window_config(
                    "history_entry",
                    x=x, y=y,
                    width=w, height=h,
                    font_size=current_font_size[0]
                )
            window.destroy()
            self.root.destroy()
            sys.exit(0)

        tk.Button(
            btn_frame,
            text="Скопировать и выйти",
            command=copy_and_exit
        ).pack(side='right', padx=(0, 5))
        tk.Button(
            btn_frame,
            text="Назад",
            command=on_entry_closing
        ).pack(side='right')

        # Copy-on-select
        def on_select_copy(event):
            try:
                sel_start = text_area.index("sel.first")
                sel_end = text_area.index("sel.last")
                selected = text_area.get(sel_start, sel_end)

                try:
                    subprocess.run(
                        ['xsel', '-i', '--primary'],
                        input=selected.encode(),
                        check=True,
                        timeout=1
                    )
                except (FileNotFoundError, subprocess.TimeoutExpired):
                    try:
                        subprocess.run(
                            ['xclip', '-selection', 'primary'],
                            input=selected.encode(),
                            check=True,
                            timeout=1
                        )
                    except (FileNotFoundError, subprocess.TimeoutExpired):
                        pass

                def restore_selection():
                    try:
                        text_area.tag_add("sel", sel_start, sel_end)
                    except Exception:
                        pass

                window.after(10, restore_selection)
            except Exception:
                pass

        text_area.bind('<ButtonRelease-1>', on_select_copy)

        # Escape для закрытия — используем
        # тот же обработчик
        window.bind('<Escape>', lambda e: on_entry_closing())

        window.protocol("WM_DELETE_WINDOW", on_entry_closing)

        # Фокус на окно
        window.focus_force()

    def run(self):
        self.root.protocol("WM_DELETE_WINDOW", self._back_to_selector)
        self.root.mainloop()
        # После закрытия возвращаемся в меню
        show_mode_then_run()


def show_mode_then_run():
    """Показывает mode selector и запускает выбранное
    приложение"""
    mode = show_mode_selector()
    if mode and mode != "__history__":
        AIReaderApp(mode).run()


def show_mode_selector():
    """Показывает диалог выбора режима и возвращает
    выбранный режим или None"""
    root = tk.Tk()
    root.title("AI Reader - Выберите режим")

    # Загружаем конфигурацию окна
    config = load_window_config("selector")
    if config:
        w = config.get('width', 480)
        h = config.get('height', 500)
        if 'x' in config and 'y' in config:
            root.geometry(f'{w}x{h}+{config["x"]}+{config["y"]}')
        else:
            # Центрируем если нет
            # позиции
            root.geometry(f'{w}x{h}')
            root.update_idletasks()
            width = root.winfo_width()
            height = root.winfo_height()
            x = (root.winfo_screenwidth() // 2) - (
                width // 2
            )
            y = (root.winfo_screenheight() // 2) - (
                height // 2
            )
            root.geometry(f'{width}x{height}+{x}+{y}')
    else:
        root.geometry("480x500")
        # Центрируем окно на экране
        root.update_idletasks()
        width = root.winfo_width()
        height = root.winfo_height()
        x = (root.winfo_screenwidth() // 2) - (
            width // 2
        )
        y = (root.winfo_screenheight() // 2) - (
            height // 2
        )
        root.geometry(f'{width}x{height}+{x}+{y}')

    # Заголовок
    tk.Label(
        root,
        text="Выберите режим обработки:",
        font=("Helvetica", 14, "bold")
    ).pack(pady=20)

    # Описание режимов
    modes = [
        ("history", "📚 Просмотр истории обработок"),
        ("summary",
         "📝 Краткое содержание (структура текста на русском)"),
        ("full-ru", "🌐 Полный перевод на русский"),
        ("full-en", "📖 Форматирование английского текста"),
        ("fix", "✏️ Исправление английской грамматики"),
        ("grammar",
         "🔍 Грамматический разбор текста/изображения"),
        ("image",
         "🖼️ Распознавание и перевод текста с изображения"),
    ]

    selected_mode = [None]  # Используем список для изменения в замыкании

    def select_mode(mode):
        selected_mode[0] = mode
        root.destroy()

    def open_history():
        """Открывает окно истории"""
        root.destroy()
        HistoryViewerApp().run()
        selected_mode[0] = "__history__"  # Специальный
        # маркер

    def make_mode_command(key):
        """Создаёт команду для выбора режима"""
        def command():
            select_mode(key)
        return command

    # Кнопки выбора режима
    btn_frame = tk.Frame(root)
    btn_frame.pack(pady=10, padx=20, fill='x')

    for mode_key, mode_desc in modes:
        # Для истории используем отдельный
        # обработчик
        if mode_key == "history":
            cmd = open_history
        else:
            cmd = make_mode_command(mode_key)

        btn = tk.Button(
            btn_frame,
            text=mode_desc,
            font=("Helvetica", 11),
            anchor='w',
            command=cmd,
            relief='raised',
            bd=2,
            pady=8
        )
        btn.pack(fill='x', pady=5)

    # Обработчик закрытия для сохранения размеров
    def on_selector_closing():
        geometry = root.geometry()
        import re
        match = re.match(r'(\d+)x(\d+)\+?(-?\d+)\+?(-?\d+)?', geometry)
        if match:
            w, h, x, y = match.groups()
            save_window_config(
                "selector", int(x),
                int(y) if y else None,
                int(w), int(h)
            )
        root.destroy()

    # Кнопка выхода
    tk.Button(
        root,
        text="Выход",
        command=on_selector_closing,
        font=("Helvetica", 10)
    ).pack(pady=10)

    # Привязка Escape для выхода
    root.bind('<Escape>', on_selector_closing)

    root.protocol("WM_DELETE_WINDOW", on_selector_closing)

    root.mainloop()
    return selected_mode[0]


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "mode",
        nargs='?',
        choices=["summary", "full-ru", "full-en", "fix",
                 "grammar", "image", "select", "history"]
    )
    args = parser.parse_args()

    # Если режим не указан или указан "select" -
    # показываем диалог выбора
    if not args.mode or args.mode == "select":
        mode = show_mode_selector()
        if mode is None or mode == "__history__":
            sys.exit(0)  # Пользователь отменил выбор
            # или выбрал историю (уже открыта)
    elif args.mode == "history":
        HistoryViewerApp().run()
        sys.exit(0)
    else:
        mode = args.mode

    AIReaderApp(mode).run()
