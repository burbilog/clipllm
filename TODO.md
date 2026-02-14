# ClipLLM TODO

## Фичи

- [x] Хоткеи на каждый промпт с моментальным открытием результата
- [x] Вкладка в настройках "Отладка" с уровнями логирования
- [x] Поддержка DeepSeek
- [x] Группа Languages с промптами перевода
- [x] Prompt chaining (nextPromptId, autoContinue)
- [ ] Флаг `--popup` для открытия меню
- [ ] Флаг `--run <prompt>` для запуска конкретного промпта
- [ ] Поддержка японского языка в UI
- [ ] "Save as..." в окне результата с запоминанием директории

---

## Рефакторинг (из code review)

### Высокий приоритет

- [ ] **N3: Поддержка Wayland**
  - CMakeLists.txt требует X11 unconditionally
  - Сделать X11 опциональным или добавить Wayland backend

### Средний приоритет

- [ ] **N9: Дублирование кода (частично исправлено)**
  - [x] Геометрия окон — унифицировано через UiUtils
  - [ ] Fetch models from API — дублирование в settingsdialog/prompteditordialog
  - [ ] Hotkey conflict checking — 3 похожие функции

- [x] **N12: Проблема cleanupByCount**
  - Заменён removeFirst() в цикле (O(n²)) на erase() (O(n))

- [~] **N11: Версионирование моделей** (отложено)
  - Добавить поле version в Prompt, HistoryEntry, LLMConfig
  - Реализовать миграцию в fromJson()

### Низкий приоритет (код-стайл)

- [x] **N13: Magic numbers**
  - Вынесены в именованные константы: CONNECTION_TEST_MAX_TOKENS, DEFAULT_MAX_HISTORY_ENTRIES, MIN_SELECTION_SIZE, CHARS_PER_TOKEN_ESTIMATE

- [ ] **N14: Несогласованное именование**
  - promptId vs prompt_id
  - Унифицировать naming convention

- [ ] **N15: HistoryEntry — struct vs class**
  - Рассмотреть рефакторинг

- [ ] **N16: Длинные функции**
  - app.cpp:onPromptSelected() — 230 строк
  - Рассмотреть декомпозицию

- [ ] **N17: Мёртвый код**
  - app.cpp:onTrayIconActivated() с Q_UNUSED(reason)
