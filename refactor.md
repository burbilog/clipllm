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

 3. [ ] Отсутствие поддержки Wayland

 Файл: CMakeLists.txt:50-61

 find_package(X11 REQUIRED)
 list(APPEND QHOTKEY_SOURCES 3rdparty/qhotkey/qhotkey_x11.cpp)

 Сборка требует X11 unconditionally. На современных дистрибутивах с Wayland приложение не соберётся или не будет работать.

 Рекомендация: Добавить поддержку Wayland или сделать X11 опциональным.

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

 12. [ ] Проблема cleanupByCount

 Файл: historymanager.cpp:412-418

 Сортировка ascending + removeFirst() даёт O(n²). После сортировки порядок нарушается.

 ---
 🟢 Низкий приоритет (код-стайл, рефакторинг)

 13. [ ] Magic numbers

 - llmclient.cpp:299: maxTokens = 10
 - historymanager.cpp: m_maxEntries = 1000
 - screenshotselector.cpp:272: 5 pixels threshold
 - resultdialog.cpp:332: length() / 4 для оценки токенов

 Рекомендация: Определить как константы.

 14. [ ] Несогласованное именование

 - promptId vs prompt_id (JSON vs C++)
 - hotkey vs screenshotHotkey
 - llmClient vs clipboardManager

 15. [ ] HistoryEntry — struct, не class

 HistoryEntry — struct с методами, в то время как Prompt/LLMConfig — classes.

 16. [ ] Длинные функции

 - app.cpp:761-991 — onPromptSelected() — 230 строк
 - prompteditordialog.cpp:869-950 — onRenameIdClicked() — 81 строка

 17. [ ] Мёртвый код

 app.cpp:1036: onTrayIconActivated() с Q_UNUSED(reason)

