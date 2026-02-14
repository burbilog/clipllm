🔴 Критические проблемы (исправить немедленно)

 2. [ ] Гонки данных (Race Conditions)

 DebugLogger (debuglogger.cpp:44-55, 123-134):
 - m_logStream доступен без мьютекса в конструкторе/деструкторе

 HistoryManager (historymanager.cpp:133-139):
 - m_dirty и m_entries без синхронизации при вызове из разных потоков

 LLMClient (llmclient.cpp:539-545):
 - m_state изменяется из network callbacks без синхронизации

 Рекомендация: Добавить QMutex для защиты всех разделяемых данных.

 3. [ ] Отсутствие поддержки Wayland

 Файл: CMakeLists.txt:50-61

 find_package(X11 REQUIRED)
 list(APPEND QHOTKEY_SOURCES 3rdparty/qhotkey/qhotkey_x11.cpp)

 Сборка требует X11 unconditionally. На современных дистрибутивах с Wayland приложение не соберётся или не будет работать.

 Рекомендация: Добавить поддержку Wayland или сделать X11 опциональным.

 ---
 🟠 Высокий приоритет

 4. [ ] Проблемы с памятью в UI

 ScreenshotSelector (app.cpp:580-587):
 auto* selector = new UI::ScreenshotSelector(screenshot);
 selector->show();
 Raw new без явного пути удаления. Memory leak на error paths.

 Рекомендация: Использовать std::unique_ptr или setAttribute(Qt::WA_DeleteOnClose).

 5. [ ] Неверный диапазон top_p

 Файл: llmconfig.h:104

 int m_topP = 100; // Stored as 0-100

 OpenAI API ожидает top_p в диапазоне 0.0-1.0. Значение 100 — невалидное.

 Рекомендация: Изменить на double и диапазон 0.0-1.0.

 6. [ ] Отсутствие валидации JSON

 Файл: llmclient.cpp:407-438

 Нет проверки структуры JSON-ответа от API. Предполагается, что choices существует и не пуст. Может привести к крашу при malformed response.

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

