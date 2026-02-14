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

 8. [ ] Бог-объект App

 Файл: app.cpp — 1095 строк

 Класс App управляет: lifecycle, hotkeys, settings, dialogs, chains, screenshots, translations. 20+ приватных методов.

 Рекомендация: Выделить:
 - HotkeyManager
 - ChainExecutor
 - ScreenshotController

 ---
 🟡 Средний приоритет

 9. [ ] Масштабное дублирование кода в UI

 Паттерн сохранения геометрии окна — дублируется 8+ раз:
 - resultdialog.cpp:561-569
 - historydialog.cpp:646-659
 - prompteditordialog.cpp:961-967
 - и т.д.

 Рекомендация: Вынести в UiUtils::saveWindowGeometry() / restoreWindowGeometry().

 Fetch models from API — дублируется в:
 - settingsdialog.cpp:1493-1565
 - prompteditordialog.cpp:997-1048

 Hotkey conflict checking — 3 похожие функции:
 - prompteditordialog.cpp:1167-1216
 - prompteditordialog.cpp:1268-1317
 - settingsdialog.cpp:2157-2177

 10. [ ] Несогласованность дефолтных значений

 Файл: prompt.cpp:85-96 vs prompt.h:123-125

 Дефолты в fromJson() отличаются от дефолтов в объявлении класса. Нарушение DRY.

 11. [ ] Отсутствие версионирования моделей

 Нет поля version в сериализованных форматах. При изменении схемы невозможно мигрировать старые данные.

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

