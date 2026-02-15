# ClipLLM TODO

## Фичи

- [x] Хоткеи на каждый промпт с моментальным открытием результата
- [x] Вкладка в настройках "Отладка" с уровнями логирования
- [x] Поддержка DeepSeek
- [x] Группа Languages с промптами перевода
- [x] Prompt chaining (nextPromptId, autoContinue)
- [x] Флаг `--popup` для открытия меню
- [x] Флаг `--run <prompt>` для запуска конкретного промпта
- [ ] Поддержка японского языка в UI
- [x] "Save as..." в окне результата с запоминанием директории

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

