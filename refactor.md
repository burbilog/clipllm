🔴 Критические проблемы (исправить немедленно)

 2. [x] Гонки данных (Race Conditions) — НЕВАЛИДНО

   Замечание ошибочно. Приложение является однопоточным Qt GUI-приложением
   (нет QThread, moveToThread, QtConcurrent во всём проекте).

   DebugLogger: конструктор/деструктор singleton защищены самой природой
   lifecycle — никто не может вызвать writeLog() во время выполнения
   конструктора, а деструктор выполняется после завершения всех потоков.

   HistoryManager и LLMClient: все операции происходят в GUI-потоке.
   Qt signal/slot механизм гарантирует доставку в правильный поток.

   Рекомендация отклонена: не требуется.

 3. [x] Отсутствие поддержки Wayland — ДОКУМЕНТИРОВАНО

 Файл: CMakeLists.txt:50-61

 find_package(X11 REQUIRED)
 list(APPEND QHOTKEY_SOURCES 3rdparty/qhotkey/qhotkey_x11.cpp)

 Проблема: X11 REQUIRED — на чистом Wayland без XWayland сборка невозможна.

 Решение:
 - Добавлены CLI опции --popup, --run, --list (commit 13cf9c0)
 - Документированы workarounds в README.md:
   * Требования для сборки (X11 libs)
   * Таблица совместимости функций
   * Примеры конфигурации для Sway/wlroots
   * Примеры конфигурации для GNOME/KDE
   * Скриншоты через grim/slurp

 Для полной нативной поддержки Wayland (низкий приоритет):
 - Сделать X11 опциональным (find_package(X11 QUIET))
 - Добавить проверку QHotkey::isPlatformSupported() при запуске

 ---
 🟠 Высокий приоритет

 4. [x] Проблемы с памятью в UI — НЕВАЛИДНО

   Замечание ошибочно. В конструкторе ScreenshotSelector (screenshotselector.cpp:41)
   УЖЕ установлен атрибут:

     setAttribute(Qt::WA_DeleteOnClose);

   Все пути закрытия обрабатываются корректно:
   - Escape/Enter: emit signal + close() → WA_DeleteOnClose
   - Right-click cancel: emit cancelled() + close() → WA_DeleteOnClose
   - Mouse release: emit areaSelected() + close() → WA_DeleteOnClose
   - Alt+F4/window manager: close() → WA_DeleteOnClose

   Дополнительно слоты App вызывают deleteLater() для гарантии.

   Рекомендация отклонена: уже реализовано.

 5. [x] Неверный диапазон top_p — ИСПРАВЛЕНО

   Поле m_topP существовало в LLMConfig, но:
   - НЕ отправлялось в API (LLMRequest::toJson() не включал top_p)
   - НЕ использовалось в UI (нет элементов для настройки)
   - Было мёртвым кодом

   Исправление: поле полностью удалено из llmconfig.h и llmconfig.cpp.

 6. [x] Отсутствие валидации JSON — НЕВАЛИДНО

   Утверждение "может привести к крашу" неверно. Код безопасен:

   Non-streaming (onFinished):
   - Проверяется QJsonParseError::NoError
   - Проверяется doc.isObject()
   - Проверяется наличие "error" поля
   - Проверяется !choices.isEmpty()

   Streaming (processOpenRouterChunk):
   - Проверяется parse error с LOG_WARNING и return
   - Проверяется doc.isObject()
   - Проверяется choices.isEmpty()

   Qt JSON API (toObject, toArray, toString, toInt) возвращает
   безопасные default значения, а не вызывает краш при обращении
   к несуществующим полям.

   Рекомендация отклонена: валидация достаточна.

 8. [x] Бог-объект App — НЕВАЛИДНО

   App выполняет валидную роль Composition Root + Application Controller:
   - Наследует QApplication — стандартный паттерн для Qt
   - Владеет уже выделенными компонентами (9 core, 4 UI)
   - 1095 строк — умеренно для главного класса приложения

   Выделение HotkeyManager/ChainExecutor/ScreenshotController:
   - Усложнит код (потребует expose приватных членов)
   - Не улучшит архитектуру
   - Риск регрессий

   Рекомендация отклонена: текущая архитектура валидна.

 ---
 🟡 Средний приоритет

 9. [x] Масштабное дублирование кода в UI — ЧАСТИЧНО ИСПРАВЛЕНО

   ✅ Геометрия окна — ИСПРАВЛЕНО
   Добавлены утилиты в uiutils.h:
   - saveWindowGeometry(QWidget*, const QString& key)
   - restoreWindowGeometry(QWidget*, const QString& key)
   - saveSplitterState(QSplitter*, const QString& key)
   - restoreSplitterState(QSplitter*, const QString& key)

   Обновлены диалоги: resultdialog, historydialog, prompteditordialog,
   settingsdialog, promptpreviewdialog, groupsdialog, imageviewdialog.

   ⏳ Fetch models from API — ОСТАВЛЕНО
   Дублирование в settingsdialog.cpp и prompteditordialog.cpp.
   Низкий приоритет — работает корректно.

   ⏳ Hotkey conflict checking — ОСТАВЛЕНО
   3 похожие функции в prompteditordialog.cpp и settingsdialog.cpp.
   Низкий приоритет — логика слегка отличается.

 10. [x] Несогласованность дефолтных значений — НЕВАЛИДНО

   Проверено сравнение prompt.cpp:85-96 vs prompt.h:123-135:

   | Поле | fromJson() | prompt.h |
   |------|------------|----------|
   | temperature | 0.7 | 0.7 |
   | maxTokens | 131072 | 131072 |
   | enabled | true | true |
   | priority | 0 | 0 |
   | overrideTemperature | false | false |
   | overrideProvider | false | false |
   | autoContinue | false | false |

   Все дефолты идентичны. Нарушения DRY нет.

 11. [~] Отсутствие версионирования моделей — ОТЛОЖЕНО

   Валидное замечание для долгосрочной поддержки. Текущая реализация:
   - fromJson() использует дефолты для отсутствующих полей
   - Это обеспечивает implicit backward compatibility

   Для реализации нужно:
   - Добавить поле version в Prompt, HistoryEntry, LLMConfig
   - Реализовать миграцию в fromJson() на основе version

   Отложено: не критично для v1.0.x, схема стабилизирована.

 12. [x] Проблема cleanupByCount — ИСПРАВЛЕНО

   Заменён цикл removeFirst() (O(n²)) на erase() (O(n)):

   Было:
   ```cpp
   for (int i = 0; i < toRemove; ++i) {
       m_entries.removeFirst();
   }
   ```

   Стало:
   ```cpp
   m_entries.erase(m_entries.begin(), m_entries.begin() + toRemove);
   ```

 ---
 🟢 Низкий приоритет (код-стайл, рефакторинг)

 13. [x] Magic numbers — ИСПРАВЛЕНО

   Вынесены в именованные константы:
   - llmclient.cpp: `CONNECTION_TEST_MAX_TOKENS = 10`
   - historymanager.h: `DEFAULT_MAX_HISTORY_ENTRIES = 1000`
   - screenshotselector.cpp: `MIN_SELECTION_SIZE = 5`
   - resultdialog.cpp: `CHARS_PER_TOKEN_ESTIMATE = 4`

 14. [x] Несогласованное именование — НЕВАЛИДНО

   Различия обоснованы:

   - promptId vs prompt_id: C++ использует camelCase, JSON — snake_case.
     Это стандартная практика для Qt/JSON проектов.

   - hotkey vs screenshotHotkey: Это разные поля с разным смыслом.
     hotkey — для промптов из буфера, screenshotHotkey — для скриншотов.

   - llmClient vs clipboardManager: Оба следуют lowerCamelCase.
     Это согласованное именование переменных-членов.

   Рекомендация отклонена: именование корректно.

 15. [x] HistoryEntry — struct, не class — НЕВАЛИДНО

   HistoryEntry — это data class без инвариантов:
   - Все поля публичные (id, timestamp, promptId, ...)
   - Методы toJson/fromJson/getPreview — helpers для сериализации
   - Нет private данных, нет validation, нет инвариантов

   Prompt/LLMConfig имеют:
   - Private поля с getters/setters
   - Validation (isValid())
   - Инварианты

   В Modern C++ struct для data classes — валидный паттерн.
   Разница оправдана разной природой типов.

 16. [x] Длинные функции — ЧАСТИЧНО ИСПРАВЛЕНО

   ✅ onPromptSelected() — сокращён с ~230 до ~190 строк
   Выделен метод resolveProviderProfile() для разрешения профиля провайдера.

   ⏳ onRenameIdClicked() — 81 строка
   Оставлено: умеренная длина, логическая целостность.

 17. [x] Мёртвый код — ИСПРАВЛЕНО

   Удалён пустой слот onTrayIconActivated():
   - TrayIcon уже обрабатывает activated() сигнал сам
   - TrayIcon обрабатывает Trigger (левый клик) для показа меню
   - Слот в App был ненужным дублированием

   Удалено: декларация в app.h, соединение в app.cpp, реализация в app.cpp.

