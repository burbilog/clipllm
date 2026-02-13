<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="ru_RU">
<context>
    <name>ClipLLM</name>
    <message>
        <source>Clipboard Empty</source>
        <translation type="obsolete">Буфер обмена пуст</translation>
    </message>
    <message>
        <source>No content found in clipboard.</source>
        <translation type="obsolete">В буфере обмена нет содержимого.</translation>
    </message>
    <message>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation type="obsolete">Не удалось выполнить промпт: буфер обмена пуст.

Сначала скопируйте текст или изображение.</translation>
    </message>
    <message>
        <source>Error</source>
        <translation type="obsolete">Ошибка</translation>
    </message>
    <message>
        <source>Prompt not found: %1</source>
        <translation type="obsolete">Промпт не найден: %1</translation>
    </message>
    <message>
        <source>Provider Error</source>
        <translation type="obsolete">Ошибка провайдера</translation>
    </message>
    <message>
        <source>No valid LLM provider configured.</source>
        <translation type="obsolete">Не настроен ни один корректный провайдер LLM.</translation>
    </message>
    <message>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation type="obsolete">Провайдер LLM не настроен. Настройте его в настройках.</translation>
    </message>
    <message>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation type="obsolete">Провайдер LLM по умолчанию не найден. Настройте его в настройках.</translation>
    </message>
    <message>
        <source>Model Error</source>
        <translation type="obsolete">Ошибка модели</translation>
    </message>
    <message>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation type="obsolete">Модель не выбрана. Выберите модель в Настройки → LLM → Профили провайдеров.</translation>
    </message>
    <message>
        <source>Incompatible Content</source>
        <translation type="obsolete">Несовместимое содержимое</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="obsolete">Этот промпт требует содержимое типа %1.</translation>
    </message>
    <message>
        <source>[Image content]</source>
        <translation type="obsolete">[Изображение]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="268"/>
        <source>System Tray</source>
        <translation>Системный трей</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="269"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation>Не удалось обнаружить системный трей.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="279"/>
        <source>Welcome to ClipLLM</source>
        <translation>Добро пожаловать в ClipLLM</translation>
    </message>
    <message>
        <source>ClipLLM is running in the system tray. Press the global hotkey to start.</source>
        <translation type="vanished">ClipLLM запущен в системном трее. Нажмите глобальную горячую клавишу для начала работы.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="280"/>
        <source>ClipLLM is running in the system tray. Click the tray icon or configure a hotkey in settings.</source>
        <translation>ClipLLM работает в системном трее. Щёлкните по значку в трее или настройте горячую клавишу в настройках.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="372"/>
        <source>Hotkey Not Supported</source>
        <translation>Горячие клавиши не поддерживаются</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="373"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation>Глобальные горячие клавиши не поддерживаются на этой платформе (Wayland?).</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="398"/>
        <source>Hotkey Registration Failed</source>
        <translation>Не удалось зарегистрировать горячую клавишу</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="399"/>
        <source>Could not register global hotkey: %1</source>
        <translation>Не удалось зарегистрировать глобальную горячую клавишу: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="603"/>
        <location filename="../src/core/app.cpp" line="655"/>
        <source>Clipboard Empty</source>
        <translation>Буфер обмена пуст</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="604"/>
        <source>No content found in clipboard.</source>
        <translation>В буфере обмена нет содержимого.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="627"/>
        <source>Chain Cycle Detected</source>
        <translation>Обнаружен цикл в цепочке</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="628"/>
        <source>The prompt chain would create a cycle. Execution stopped.

Prompt &apos;%1&apos; was already executed in this chain.</source>
        <translation>Цепочка промптов создала бы цикл. Выполнение остановлено.

Промпт &apos;%1&apos; уже был выполнен в этой цепочке.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="636"/>
        <source>Chain Depth Limit</source>
        <translation>Лимит глубины цепочки</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="637"/>
        <source>Maximum chain depth (%1) reached. Execution stopped.

You can increase this limit in Settings → General → Prompt Chains.</source>
        <translation>Достигнута максимальная глубина цепочки (%1). Выполнение остановлено.

Вы можете увеличить этот лимит в Настройки → Общие → Цепочки промптов.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="656"/>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation>Не удалось выполнить промпт: буфер обмена пуст.

Сначала скопируйте текст или изображение.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="671"/>
        <source>Error</source>
        <translation>Ошибка</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="672"/>
        <source>Prompt not found: %1</source>
        <translation>Промпт не найден: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="694"/>
        <location filename="../src/core/app.cpp" line="699"/>
        <location filename="../src/core/app.cpp" line="710"/>
        <location filename="../src/core/app.cpp" line="715"/>
        <source>Provider Error</source>
        <translation>Ошибка провайдера</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="695"/>
        <source>No valid LLM provider configured.</source>
        <translation>Не настроен ни один корректный провайдер LLM.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="700"/>
        <location filename="../src/core/app.cpp" line="716"/>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation>Провайдер LLM не настроен. Настройте его в настройках.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="711"/>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation>Провайдер LLM по умолчанию не найден. Настройте его в настройках.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="753"/>
        <source>This prompt requires text content.</source>
        <translation>Этот промпт требует текстовое содержимое.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="207"/>
        <source>No LLM Provider Configured</source>
        <translation>Провайдер LLM не настроен</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="208"/>
        <source>No LLM provider profile has been configured.

Please add at least one provider profile in Settings to use ClipLLM.</source>
        <translation>Не настроен ни один профиль провайдера LLM.

Пожалуйста, добавьте хотя бы один профиль провайдера в Настройки для использования ClipLLM.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="733"/>
        <source>Model Error</source>
        <translation>Ошибка модели</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="734"/>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation>Модель не выбрана. Выберите модель в Настройки → LLM → Профили провайдеров.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="752"/>
        <source>Incompatible Content</source>
        <translation>Несовместимое содержимое</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="vanished">Этот промпт требует содержимое типа %1.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="778"/>
        <source>[Image content]</source>
        <translation>[Изображение]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::App</name>
    <message>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation type="vanished">ClipLLM — Кроссплатформенная утилита для работы с буфером обмена через LLM</translation>
    </message>
    <message>
        <source>Start minimized to system tray</source>
        <translation type="vanished">Запустить свернутым в системный трей</translation>
    </message>
    <message>
        <source>Another instance of ClipLLM is already running</source>
        <translation type="vanished">Уже запущен другой экземпляр ClipLLM</translation>
    </message>
    <message>
        <source>Failed to initialize application</source>
        <translation type="vanished">Не удалось инициализировать приложение</translation>
    </message>
    <message>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation type="vanished">Не удалось обнаружить системный трей.</translation>
    </message>
    <message>
        <source>Welcome to ClipLLM</source>
        <translation type="vanished">Добро пожаловать в ClipLLM</translation>
    </message>
    <message>
        <source>ClipLLM is running in the system tray. Press the global hotkey to start.</source>
        <translation type="vanished">ClipLLM запущен в системном трее. Нажмите глобальную горячую клавишу для начала работы.</translation>
    </message>
    <message>
        <source>Clipboard Empty</source>
        <translation type="vanished">Буфер обмена пуст</translation>
    </message>
    <message>
        <source>No content found in clipboard.</source>
        <translation type="vanished">В буфере обмена нет содержимого.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::LLMClient</name>
    <message>
        <location filename="../src/core/llmclient.cpp" line="280"/>
        <source>API key is not set</source>
        <translation>API ключ не установлен</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="352"/>
        <location filename="../src/core/llmclient.cpp" line="448"/>
        <source>Connection successful</source>
        <translation>Соединение успешно</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="385"/>
        <source>HTTP %1: Authentication required. Please check your API key.</source>
        <translation>HTTP %1: Требуется аутентификация. Проверьте ваш API ключ.</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="401"/>
        <location filename="../src/core/llmclient.cpp" line="451"/>
        <source>HTTP %1: %2</source>
        <translation>HTTP %1: %2</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="496"/>
        <source>HTTP %1: </source>
        <translation>HTTP %1: </translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="531"/>
        <source>SSL error: %1</source>
        <translation>Ошибка SSL: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::PromptManager</name>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="66"/>
        <source>Failed to load default prompts</source>
        <translation>Не удалось загрузить стандартные промпты</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="125"/>
        <source>Failed to open prompts file</source>
        <translation>Не удалось открыть файл промптов</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="135"/>
        <source>Failed to parse prompts file</source>
        <translation>Не удалось разобрать файл промптов</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="354"/>
        <source>ID is required</source>
        <translation>ID обязателен</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="358"/>
        <source>Name is required</source>
        <translation>Имя обязательно</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="373"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Неверный плейсхолдер в шаблоне пользователя: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="383"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Неверный плейсхолдер в системном промпте: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="451"/>
        <source>Summary</source>
        <translation>Резюме</translation>
    </message>
    <message>
        <source>Generate a structured summary of the text</source>
        <translation type="vanished">Создать структурированное резюме текста</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="453"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Вы профессиональный аналитик. Создайте четкое, структурированное резюме.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="454"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation>Пожалуйста, предоставьте полное резюме следующего текста:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="465"/>
        <source>Translate to Russian</source>
        <translation>Перевести на русский</translation>
    </message>
    <message>
        <source>Translate the text to Russian</source>
        <translation type="vanished">Перевести текст на русский язык</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="467"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="468"/>
        <location filename="../src/core/promptmanager.cpp" line="482"/>
        <source>{clipboard}</source>
        <translation>{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="479"/>
        <source>Translate to English</source>
        <translation>Перевести на английский</translation>
    </message>
    <message>
        <source>Translate the text to English</source>
        <translation type="vanished">Перевести текст на английский язык</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="481"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Вы профессиональный переводчик. Переведите текст на английский язык, сохраняя стиль и смысл.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="493"/>
        <source>Explain Code</source>
        <translation>Объяснить код</translation>
    </message>
    <message>
        <source>Explain what the code does</source>
        <translation type="vanished">Объяснить, что делает код</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="495"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Вы эксперт-программист. Четко и кратко объясните код.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="496"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation>Объясните следующий код:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="507"/>
        <source>Code Review</source>
        <translation>Ревизия кода</translation>
    </message>
    <message>
        <source>Review code and suggest improvements</source>
        <translation type="vanished">Проверить код и предложить улучшения</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="509"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Вы ревьюер кода. Проанализируйте код на наличие ошибок, проблем с безопасностью и предложите улучшения.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="510"/>
        <source>Review the following code:

{clipboard}</source>
        <translation>Проверьте следующий код:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="521"/>
        <source>Refactor Code</source>
        <translation>Рефакторинг кода</translation>
    </message>
    <message>
        <source>Suggest refactoring improvements</source>
        <translation type="vanished">Предложить улучшения рефакторинга</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="523"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Вы эксперт по оптимизации кода. Предложите рефакторинг для улучшения читаемости, поддерживаемости и производительности.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="524"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation>Выполните рефакторинг следующего кода:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="535"/>
        <source>Describe Image</source>
        <translation>Описать изображение</translation>
    </message>
    <message>
        <source>Generate a detailed description of the image</source>
        <translation type="vanished">Создать подробное описание изображения</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="537"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Вы визуальный аналитик. Предоставьте подробное описание изображения.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="538"/>
        <source>Describe this image in detail.</source>
        <translation>Опишите это изображение подробно.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="549"/>
        <source>Extract Text</source>
        <translation>Извлечь текст</translation>
    </message>
    <message>
        <source>Extract all text from the image</source>
        <translation type="vanished">Извлечь весь текст из изображения</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="551"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Извлеките весь текст из изображения, сохраняя форматирование, где это возможно.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="552"/>
        <source>Extract all text from this image.</source>
        <translation>Извлеките весь текст из этого изображения.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::GroupsDialog</name>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="53"/>
        <source>Manage Groups</source>
        <translation>Управление группами</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="59"/>
        <source>Right-click to add, rename, or delete groups. Drag and drop to move groups.</source>
        <translation>Щелкните правой кнопкой мыши для добавления, переименования или удаления групп. Перетаскивайте для перемещения групп.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="67"/>
        <source>Group Name</source>
        <translation>Имя группы</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="90"/>
        <source>Close</source>
        <translation>Закрыть</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="104"/>
        <source>Root</source>
        <translation>Корень</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="198"/>
        <source>New Group...</source>
        <translation>Новая группа...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="202"/>
        <source>New Subgroup...</source>
        <translation>Новая подгруппа...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="205"/>
        <source>Rename...</source>
        <translation>Переименовать...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="210"/>
        <source>Delete...</source>
        <translation>Удалить...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="221"/>
        <source>New Group</source>
        <translation>Новая группа</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="222"/>
        <source>Enter group name:</source>
        <translation>Введите имя группы:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="232"/>
        <location filename="../src/ui/groupsdialog.cpp" line="269"/>
        <source>Duplicate Group</source>
        <translation>Дубликат группы</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="233"/>
        <source>A group with this name already exists.</source>
        <translation>Группа с таким именем уже существует.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="258"/>
        <source>New Subgroup</source>
        <translation>Новая подгруппа</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="259"/>
        <source>Enter subgroup name:</source>
        <translation>Введите имя подгруппы:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="270"/>
        <source>A subgroup with this name already exists.</source>
        <translation>Подгруппа с таким именем уже существует.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="309"/>
        <source>(root)</source>
        <translation>(корень)</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="321"/>
        <source>Delete group &apos;%1&apos;?

%2 prompt(s) in this group will be moved to root.</source>
        <translation>Удалить группу &apos;%1&apos;?

%2 промпт(ов) из этой группы будет перемещено в корень.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="324"/>
        <source>Delete group &apos;%1&apos;?</source>
        <translation>Удалить группу &apos;%1&apos;?</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="328"/>
        <source>Delete Group</source>
        <translation>Удалить группу</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="372"/>
        <source>Invalid Name</source>
        <translation>Неверное имя</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="373"/>
        <source>Group name cannot be empty.</source>
        <translation>Имя группы не может быть пустым.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="393"/>
        <source>Duplicate Name</source>
        <translation>Дубликат имени</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="394"/>
        <source>A group with this name already exists in this location.</source>
        <translation>Группа с таким именем уже существует в этом месте.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="54"/>
        <source>ClipLLM - History</source>
        <translation>ClipLLM — История</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="63"/>
        <source>Search in history...</source>
        <translation>Поиск в истории...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="69"/>
        <source>Filters</source>
        <translation>Фильтры</translation>
    </message>
    <message>
        <source>Search...</source>
        <translation type="vanished">Поиск...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="73"/>
        <location filename="../src/ui/historydialog.cpp" line="294"/>
        <source>All Models</source>
        <translation>Все модели</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="78"/>
        <location filename="../src/ui/historydialog.cpp" line="301"/>
        <source>All Prompts</source>
        <translation>Все промпты</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="82"/>
        <source>Favorites only</source>
        <translation>Только избранные</translation>
    </message>
    <message>
        <source>Search:</source>
        <translation type="vanished">Поиск:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="100"/>
        <source>Model:</source>
        <translation>Модель:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="102"/>
        <source>Prompt:</source>
        <translation>Промпт:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="105"/>
        <source>From:</source>
        <translation>От:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="107"/>
        <source>To:</source>
        <translation>До:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="130"/>
        <source>Preview</source>
        <translation>Предпросмотр</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="133"/>
        <location filename="../src/ui/historydialog.cpp" line="137"/>
        <location filename="../src/ui/historydialog.cpp" line="600"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="137"/>
        <location filename="../src/ui/historydialog.cpp" line="600"/>
        <source>Raw</source>
        <translation>Исходный</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="158"/>
        <source>View Details</source>
        <translation>Просмотр деталей</translation>
    </message>
    <message>
        <source>Copy Output</source>
        <translation type="vanished">Копировать результат</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="163"/>
        <location filename="../src/ui/historydialog.cpp" line="427"/>
        <source>Favorite</source>
        <translation>В избранное</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="168"/>
        <source>Delete</source>
        <translation>Удалить</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="173"/>
        <source>Export</source>
        <translation>Экспорт</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="177"/>
        <source>Clear All</source>
        <translation>Очистить все</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="181"/>
        <source>Close</source>
        <translation>Закрыть</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="197"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="198"/>
        <source>Zoom out</source>
        <translation>Уменьшить</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="202"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="203"/>
        <source>Zoom in</source>
        <translation>Увеличить</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="228"/>
        <source>Date</source>
        <translation>Дата</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="229"/>
        <source>Prompt</source>
        <translation>Промпт</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="230"/>
        <source>Model</source>
        <translation>Модель</translation>
    </message>
    <message>
        <source>Input Preview</source>
        <translation type="vanished">Предпросмотр ввода</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="231"/>
        <source>Output Preview</source>
        <translation>Предпросмотр вывода</translation>
    </message>
    <message>
        <source>Duration</source>
        <translation type="vanished">Длительность</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="232"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="319"/>
        <source>Total entries: %1</source>
        <translation>Всего записей: %1</translation>
    </message>
    <message>
        <source>No history entries.\nEnable &apos;Automatically save to history&apos; in Settings\nor save prompts manually to populate this list.</source>
        <translation type="vanished">История пуста.\nВключите &apos;Автоматически сохранять в историю&apos; в Настройках\nили сохраняйте промпты вручную.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="551"/>
        <location filename="../src/ui/historydialog.cpp" line="560"/>
        <source>Unknown</source>
        <translation>Неизвестно</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="369"/>
        <source>Showing %1 entries</source>
        <translation>Показано записей: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="264"/>
        <source>No history entries.
Enable &apos;Automatically save to history&apos; in Settings
or save prompts manually to populate this list.</source>
        <translation>Нет записей истории.
Включите &apos;Автоматически сохранять в историю&apos; в Настройках
или сохраняйте промпты вручную, чтобы заполнить этот список.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="270"/>
        <source>Total entries: 0</source>
        <translation>Всего записей: 0</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="580"/>
        <source>Prompt: %1
</source>
        <translation>Промпт: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="581"/>
        <source>Model: %1
</source>
        <translation>Модель: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="582"/>
        <source>Date: %1
</source>
        <translation>Дата: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="583"/>
        <source>Duration: %1
</source>
        <translation>Длительность: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="584"/>
        <source>Tokens: %1 input / %2 output
</source>
        <translation>Токены: %1 на входе / %2 на выходе
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="588"/>
        <source>Input:
</source>
        <translation>Вход:
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="590"/>
        <source>Output:
</source>
        <translation>Результат:
</translation>
    </message>
    <message>
        <source>&lt;b&gt;Prompt:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Промпт:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Model:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Модель:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Date:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Дата:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Duration:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Длительность:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Tokens:&lt;/b&gt; %1 input / %2 output&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Токены:&lt;/b&gt; %1 на входе / %2 на выходе&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Input:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Ввод:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Output:&lt;/b&gt;&lt;br&gt;%1</source>
        <translation type="vanished">&lt;b&gt;Вывод:&lt;/b&gt;&lt;br&gt;%1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="427"/>
        <source>Unfavorite</source>
        <translation>Убрать из избранного</translation>
    </message>
    <message>
        <source>Copied to clipboard</source>
        <translation type="vanished">Скопировано в буфер обмена</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="443"/>
        <source>Delete Entry</source>
        <translation>Удалить запись</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="444"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>Вы уверены, что хотите удалить эту запись?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="472"/>
        <source>Export History</source>
        <translation>Экспорт истории</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="474"/>
        <source>JSON Files (*.json)</source>
        <translation>JSON файлы (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="495"/>
        <source>Exported to %1</source>
        <translation>Экспортировано в %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="497"/>
        <source>Export Failed</source>
        <translation>Экспорт не удался</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="498"/>
        <source>Failed to write to file: %1</source>
        <translation>Не удалось записать в файл: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="506"/>
        <source>Clear All History</source>
        <translation>Очистить всю историю</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="507"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Вы уверены, что хотите удалить все записи истории? Это действие нельзя отменить.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="538"/>
        <source>%1 ms</source>
        <translation>%1 мс</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="540"/>
        <source>%1 s</source>
        <translation>%1 с</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="544"/>
        <source>%1m %2s</source>
        <translation>%1м %2с</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HotkeyEdit</name>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="39"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="96"/>
        <source>Press hotkey...</source>
        <translation>Нажмите горячую клавишу...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="41"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="196"/>
        <source>Record</source>
        <translation>Запись</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="48"/>
        <source>Clear</source>
        <translation>Очистить</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="175"/>
        <source>Stop</source>
        <translation>Остановить</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="176"/>
        <source>Press key combination...</source>
        <translation>Нажмите сочетание клавиш...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="208"/>
        <source>None</source>
        <translation>Нет</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ImageViewDialog</name>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="45"/>
        <source>Clipboard Image</source>
        <translation>Изображение из буфера обмена</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="62"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Размер: %1 x %2 пикселей</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="72"/>
        <source>Close</source>
        <translation>Закрыть</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptConflictDialog</name>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="32"/>
        <source>Prompt Conflict</source>
        <translation>Конфликт промптов</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="39"/>
        <source>A prompt named &quot;%1&quot; already exists.</source>
        <translation>Промпт с именем &quot;%1&quot; уже существует.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="47"/>
        <source>&lt;b&gt;Existing:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Существующий:&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="53"/>
        <source>&lt;b&gt;New:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Новый:&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="60"/>
        <source>Do you want to replace it?</source>
        <translation>Хотите заменить его?</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="69"/>
        <source>Yes</source>
        <translation>Да</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="70"/>
        <source>Yes for all</source>
        <translation>Да для всех</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="71"/>
        <source>No</source>
        <translation>Нет</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="72"/>
        <source>No for all</source>
        <translation>Нет для всех</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="73"/>
        <source>Cancel</source>
        <translation>Отмена</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptEditorDialog</name>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="71"/>
        <source>Add Prompt</source>
        <translation>Добавить промпт</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="119"/>
        <source>Edit Prompt</source>
        <translation>Редактировать промпт</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="224"/>
        <source>Basic Information</source>
        <translation>Основная информация</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="228"/>
        <source>e.g., custom_prompt</source>
        <translation>например, custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="241"/>
        <source>ID:</source>
        <translation>ID:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="244"/>
        <source>e.g., My Custom Prompt</source>
        <translation>например, Мой промпт</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="246"/>
        <source>Name:</source>
        <translation>Имя:</translation>
    </message>
    <message>
        <source>e.g., Does something useful</source>
        <translation type="vanished">например, Делает что-то полезное</translation>
    </message>
    <message>
        <source>Description:</source>
        <translation type="vanished">Описание:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="250"/>
        <source>(root)</source>
        <translation>(корень)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="271"/>
        <source>Group:</source>
        <translation>Группа:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="215"/>
        <source>Prompts</source>
        <translation>Промпты</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="194"/>
        <source>System Prompt:</source>
        <translation>Системный промпт:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="197"/>
        <source>You are a helpful assistant...</source>
        <translation>Вы полезный помощник...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="201"/>
        <source>User Prompt Template:</source>
        <translation>Шаблон промпта пользователя:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="204"/>
        <source>Process the following text:

{clipboard}</source>
        <translation>Обработайте следующий текст:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="210"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation>Используйте {clipboard} для вставки содержимого буфера обмена, {clipboard:1000} для сокращенного содержимого, {language} для языка пользователя.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="392"/>
        <source>Settings</source>
        <translation>Настройки</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="274"/>
        <source>Text</source>
        <translation>Текст</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="275"/>
        <source>Image</source>
        <translation>Изображение</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="276"/>
        <source>Any</source>
        <translation>Любой</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="277"/>
        <source>Content Type:</source>
        <translation>Тип содержимого:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="313"/>
        <source>Override provider and model</source>
        <translation>Переопределить провайдера и модель</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="314"/>
        <source>When checked, use specific provider and model instead of defaults</source>
        <translation>Если отмечено, использовать указанного провайдера и модель вместо настроек по умолчанию</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="320"/>
        <source>Select provider for this prompt</source>
        <translation>Выберите провайдера для этого промпта</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="329"/>
        <source>Select or enter model name</source>
        <translation>Выберите или введите имя модели</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="332"/>
        <source>Refresh</source>
        <translation>Обновить</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="292"/>
        <source>Optional global hotkey to directly execute this prompt</source>
        <translation>Опциональный глобальный хоткей для прямого запуска этого промпта</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="304"/>
        <source>Hotkey:</source>
        <translation>Хоткей:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="368"/>
        <source>Select next prompt in the chain (only text prompts available)</source>
        <translation>Выберите следующий промпт в цепочке (доступны только текстовые промпты)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="371"/>
        <source>Next Prompt:</source>
        <translation>Следующий промпт:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="373"/>
        <source>Auto-continue to next prompt</source>
        <translation>Автопродолжение к следующему промпту</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="374"/>
        <source>Automatically run the next prompt after this one completes</source>
        <translation>Автоматически запустить следующий промпт после завершения текущего</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="169"/>
        <source>Export</source>
        <translation>Экспорт</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="232"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="876"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="884"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="926"/>
        <source>Rename ID</source>
        <translation>Переименовать ID</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="233"/>
        <source>Change the prompt ID</source>
        <translation>Изменить ID промпта</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="309"/>
        <source>LLM Settings</source>
        <translation>Настройки LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="364"/>
        <source>Chain Settings</source>
        <translation>Настройки цепочки</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="575"/>
        <source>(Select provider first)</source>
        <translation>(сначала выберите провайдера)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="582"/>
        <source>(Provider not found)</source>
        <translation>(провайдер не найден)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="600"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="611"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1077"/>
        <source>(Custom model...)</source>
        <translation>(Пользовательская модель...)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="768"/>
        <source>Chain Cycle Detected</source>
        <translation>Обнаружен цикл в цепочке</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="769"/>
        <source>This prompt would create a cycle in the chain.

Please select a different &apos;Next Prompt&apos; or set it to &apos;(None)&apos;.</source>
        <translation>Этот промпт создал бы цикл в цепочке.

Пожалуйста, выберите другой &apos;Следующий промпт&apos; или установите &apos;(Нет)&apos;.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="804"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="816"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="838"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="846"/>
        <source>Export Prompt</source>
        <translation>Экспорт промпта</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="805"/>
        <source>Cannot export: prompt is not valid.</source>
        <translation>Не удалось экспортировать: промпт некорректен.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="818"/>
        <source>JSON Files (*.json)</source>
        <translation>Файлы JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="839"/>
        <source>Failed to open file for writing: %1</source>
        <translation>Не удалось открыть файл для записи: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="847"/>
        <source>Prompt exported to %1</source>
        <translation>Промпт экспортирован в %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="861"/>
        <source>Rename Prompt ID</source>
        <translation>Переименовать ID промпта</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="862"/>
        <source>Enter new ID for this prompt:</source>
        <translation>Введите новый ID для этого промпта:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="877"/>
        <source>New ID is the same as the current ID.</source>
        <translation>Новый ID совпадает с текущим.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="892"/>
        <source>Rename ID - Historical Records</source>
        <translation>Переименование ID — Исторические записи</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="893"/>
        <source>Historical records of this prompt will remain with the old ID &quot;%1&quot;.

When re-running prompts from history, they will use the old ID.

Continue with renaming?</source>
        <translation>Исторические записи этого промпта останутся со старым ID &quot;%1&quot;.

При повторном запуске промптов из истории будет использоваться старый ID.

Продолжить переименование?</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="927"/>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.

Click OK to save the changes.</source>
        <translation>Нажмите OK, чтобы сохранить изменения.</translation>
    </message>
    <message>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.</source>
        <translation type="vanished">ID промпта был переименован с &quot;%1&quot; на &quot;%2&quot;.

Все ссылки в цепочках были обновлены.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="955"/>
        <source>No provider selected</source>
        <translation>Провайдер не выбран</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="962"/>
        <source>Provider not found</source>
        <translation>Провайдер не найден</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="970"/>
        <source>Model fetching not supported for this provider</source>
        <translation>Получение моделей не поддерживается для этого провайдера</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1025"/>
        <source>Fetching models...</source>
        <translation>Получение моделей...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1041"/>
        <source>Error: %1</source>
        <translation>Ошибка: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1054"/>
        <source>Error: Invalid response</source>
        <translation>Ошибка: неверный ответ</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1066"/>
        <source>No models found</source>
        <translation>Модели не найдены</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1103"/>
        <source>Loaded %1 models</source>
        <translation>Загружено моделей: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1141"/>
        <source>Hotkey Conflict</source>
        <translation>Конфликт хоткеев</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1142"/>
        <source>This hotkey is already in use by another prompt or the global hotkey.

Please choose a different hotkey.</source>
        <translation>Этот хоткей уже используется другим промптом или глобальным хоткеем.

Пожалуйста, выберите другой хоткей.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1186"/>
        <source>(None)</source>
        <translation>(Нет)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1216"/>
        <source> (disabled)</source>
        <translation> (отключено)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1289"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1307"/>
        <source>Warning: This would create a cycle in the chain!</source>
        <translation>Предупреждение: Это создало бы цикл в цепочке!</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1301"/>
        <source>Warning: Target prompt is part of an existing cycle!</source>
        <translation>Предупреждение: Целевой промпт является частью существующего цикла!</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="323"/>
        <source>Provider:</source>
        <translation>Провайдер:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="291"/>
        <source>None</source>
        <translation>Нет</translation>
    </message>
    <message>
        <source>Text Summary</source>
        <translation type="vanished">Текстовое резюме</translation>
    </message>
    <message>
        <source>Translate</source>
        <translation type="vanished">Перевод</translation>
    </message>
    <message>
        <source>Code Review</source>
        <translation type="vanished">Ревизия кода</translation>
    </message>
    <message>
        <source>Refactor</source>
        <translation type="vanished">Рефакторинг</translation>
    </message>
    <message>
        <source>Explain</source>
        <translation type="vanished">Объяснение</translation>
    </message>
    <message>
        <source>Custom</source>
        <translation type="vanished">Пользовательский</translation>
    </message>
    <message>
        <source>Icon:</source>
        <translation type="vanished">Иконка:</translation>
    </message>
    <message>
        <source>Use default model from settings</source>
        <translation type="vanished">Использовать модель по умолчанию из настроек</translation>
    </message>
    <message>
        <source>e.g., openai/gpt-4, anthropic/claude-3-opus</source>
        <translation type="vanished">например, openai/gpt-4, anthropic/claude-3-opus</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="343"/>
        <source>Model:</source>
        <translation>Модель:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="346"/>
        <source>Use default temperature from settings</source>
        <translation>Использовать температуру по умолчанию из настроек</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="354"/>
        <source>Temperature:</source>
        <translation>Температура:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="359"/>
        <source>Max Tokens:</source>
        <translation>Макс. токенов:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="279"/>
        <source>Enabled</source>
        <translation>Включено</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="287"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation>Промпты с более высоким приоритетом появляются первыми в меню</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="288"/>
        <source>Priority (higher = first):</source>
        <translation>Приоритет (выше = раньше):</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="173"/>
        <source>Prompt Preview</source>
        <translation>Предпросмотр промпта</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="177"/>
        <source>OK</source>
        <translation>ОК</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="182"/>
        <source>Cancel</source>
        <translation>Отмена</translation>
    </message>
    <message>
        <source>Uses global default model</source>
        <translation type="vanished">Использует глобальную модель по умолчанию</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="629"/>
        <source>(No providers available)</source>
        <translation>(нет доступных провайдеров)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="638"/>
        <source>(No providers configured)</source>
        <translation>(нет настроенных провайдеров)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="705"/>
        <source>Name is required</source>
        <translation>Имя обязательно</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="709"/>
        <source>ID is required</source>
        <translation>ID обязателен</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="724"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Неверный плейсхолдер в шаблоне пользователя: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="734"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Неверный плейсхолдер в системном промпте: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="744"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="885"/>
        <source>ID already exists: %1</source>
        <translation>ID уже существует: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="778"/>
        <source>Validation Error</source>
        <translation>Ошибка валидации</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="779"/>
        <source>The prompt has validation errors:

%1</source>
        <translation>Промпт имеет ошибки валидации:

%1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptMenu</name>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="59"/>
        <source>Search prompts...</source>
        <translation>Поиск промптов...</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="69"/>
        <source>History</source>
        <translation>История</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="77"/>
        <source>Settings</source>
        <translation>Настройки</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="143"/>
        <source>No prompts available</source>
        <translation>Нет доступных промптов</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="172"/>
        <source>No prompts available for this content type</source>
        <translation>Нет доступных промптов для этого типа содержимого</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="194"/>
        <source>No prompts found</source>
        <translation>Промпты не найдены</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="213"/>
        <source>Add priority to prompts to see them here</source>
        <translation>Добавьте приоритет промптам, чтобы увидеть их здесь</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptPreviewDialog</name>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="75"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation>⚠ Этот промпт настроен только для текстового содержимого, но в буфере обмена есть изображение. Изображение будет проигнорировано.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="84"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation>⚠ Этот промпт настроен только для изображений, но в буфере обмена есть текст. Только изображение будет отправлено модели.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="87"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation>⚠ Этот промпт настроен только для изображений, но буфер обмена пуст или не содержит изображение.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="181"/>
        <source>%1x%2</source>
        <translation>%1x%2</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="221"/>
        <source>Prompt Preview</source>
        <translation>Предпросмотр промпта</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="233"/>
        <source>Request that will be sent to the API</source>
        <translation>Запрос, который будет отправлен в API</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="246"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation>Это точный JSON, который будет отправлен в LLM API. Содержимое буфера обмена подставляется вместо плейсхолдера {clipboard}. Нажмите на ссылку изображения, чтобы просмотреть его полностью.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="258"/>
        <source>Refresh</source>
        <translation>Обновить</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="262"/>
        <source>Close</source>
        <translation>Закрыть</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="49"/>
        <source>ClipLLM - Result</source>
        <translation>ClipLLM — Результат</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="90"/>
        <location filename="../src/ui/resultdialog.cpp" line="274"/>
        <source>Model: -</source>
        <translation>Модель: -</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="92"/>
        <source>Tokens: 0 / 0</source>
        <translation>Токены: 0 / 0</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="93"/>
        <location filename="../src/ui/resultdialog.cpp" line="301"/>
        <source>Traffic: 0 B</source>
        <translation>Трафик: 0 Б</translation>
    </message>
    <message>
        <source>Settings</source>
        <translation type="obsolete">Настройки</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="110"/>
        <source>Ready</source>
        <translation>Готово</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="122"/>
        <location filename="../src/ui/resultdialog.cpp" line="126"/>
        <location filename="../src/ui/resultdialog.cpp" line="295"/>
        <location filename="../src/ui/resultdialog.cpp" line="669"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="126"/>
        <location filename="../src/ui/resultdialog.cpp" line="295"/>
        <location filename="../src/ui/resultdialog.cpp" line="669"/>
        <source>Raw</source>
        <translation>Исходный</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="129"/>
        <location filename="../src/ui/resultdialog.cpp" line="692"/>
        <source>Show Input</source>
        <translation>Показать ввод</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="144"/>
        <source>Input</source>
        <translation>Ввод</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="154"/>
        <source>Output</source>
        <translation>Вывод</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="171"/>
        <source>Copy &amp;&amp; close</source>
        <translation>Копировать и &amp;закрыть</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="176"/>
        <source>Save to History</source>
        <translation>Сохранить в историю</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="181"/>
        <source>Save as...</source>
        <translation>Сохранить как...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="184"/>
        <source>Save output to a file</source>
        <translation>Сохранить вывод в файл</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="187"/>
        <source>Retry</source>
        <translation>Повторить</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="192"/>
        <source>Continue</source>
        <translation>Продолжить</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="198"/>
        <source>Close</source>
        <translation>Закрыть</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="203"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="204"/>
        <source>Zoom out</source>
        <translation>Уменьшить</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="208"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="209"/>
        <source>Zoom in</source>
        <translation>Увеличить</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="237"/>
        <source>ClipLLM - %1</source>
        <translation>ClipLLM — %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="276"/>
        <location filename="../src/ui/resultdialog.cpp" line="278"/>
        <source>Model: %1</source>
        <translation>Модель: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="280"/>
        <source>Model: %1 / %2</source>
        <translation>Модель: %1 / %2</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="302"/>
        <source>Connecting...</source>
        <translation>Подключение...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="333"/>
        <source>Tokens: ~%1</source>
        <translation>Токены: ~%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="346"/>
        <source>Completed in %1 seconds</source>
        <translation>Выполнено за %1 секунд</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="351"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation>Токены: %1 на входе / %2 на выходе</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="389"/>
        <location filename="../src/ui/resultdialog.cpp" line="417"/>
        <source>API Error</source>
        <translation>Ошибка API</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="390"/>
        <location filename="../src/ui/resultdialog.cpp" line="418"/>
        <source>An error occurred while communicating with the API:

%1</source>
        <translation>Произошла ошибка при общении с API:

%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="393"/>
        <location filename="../src/ui/resultdialog.cpp" line="426"/>
        <source>Error: %1</source>
        <translation>Ошибка: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="459"/>
        <source>Saved</source>
        <translation>Сохранено</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="483"/>
        <source>Save Output As</source>
        <translation>Сохранить вывод как</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="485"/>
        <source>Text Files (*.txt);;All Files (*)</source>
        <translation>Текстовые файлы (*.txt);;Все файлы (*)</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="512"/>
        <source>Saved to %1</source>
        <translation>Сохранено в %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="518"/>
        <source>Save Failed</source>
        <translation>Ошибка сохранения</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="519"/>
        <source>Could not write to file:
%1</source>
        <translation>Не удалось записать в файл:
%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="582"/>
        <source>Close During Generation</source>
        <translation>Закрыть во время генерации</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="583"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation>Ответ все еще генерируется. Закрыть и отменить запрос?</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="591"/>
        <source>Cancelling...</source>
        <translation>Отмена...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="632"/>
        <source>Model is thinking...</source>
        <translation>Модель думает...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="635"/>
        <source>Generating response...</source>
        <translation>Генерация ответа...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="644"/>
        <source>Traffic: %1</source>
        <translation>Трафик: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="688"/>
        <source>Hide Input</source>
        <translation>Скрыть ввод</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="795"/>
        <source>Chain: %1</source>
        <translation>Цепочка: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="92"/>
        <source>ClipLLM - Settings</source>
        <translation>ClipLLM — Настройки</translation>
    </message>
    <message>
        <source>Miscellaneous</source>
        <translation type="vanished">Разное</translation>
    </message>
    <message>
        <source>Show prompt descriptions in menu</source>
        <translation type="vanished">Показывать описания промптов в меню</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the tray menu (disabled by default for cleaner menu)</source>
        <translation type="vanished">Показывать описания промптов в меню в трее (отключено по умолчанию для более чистого меню)</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup</source>
        <translation type="vanished">Показывать описания промптов во всплывающем меню</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Показывать описания промптов во всплывающем меню (отключено по умолчанию для более чистого всплывающего меню)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="258"/>
        <source>General</source>
        <translation>Общие</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="267"/>
        <source>Provider Profiles</source>
        <translation>Профили провайдеров</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="272"/>
        <source>Available Profiles:</source>
        <translation>Доступные профили:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>+ Add</source>
        <translation>+ Добавить</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="277"/>
        <source>Add a new provider profile</source>
        <translation>Добавить новый профиль провайдера</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="281"/>
        <source>- Remove</source>
        <translation>- Удалить</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="282"/>
        <source>Remove selected profile</source>
        <translation>Удалить выбранный профиль</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="286"/>
        <source>Set as Default</source>
        <translation>По умолчанию</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="287"/>
        <source>Set selected profile as default</source>
        <translation>Установить выбранный профиль как профиль по умолчанию</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="302"/>
        <source>Profile Configuration</source>
        <translation>Конфигурация профиля</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="306"/>
        <source>e.g., OpenRouter (Main)</source>
        <translation>например, OpenRouter (Основной)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="308"/>
        <source>Profile Name:</source>
        <translation>Имя профиля:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="313"/>
        <source>Select template or enter custom URL (e.g., http://.../v1/chat/completions)</source>
        <translation>Выберите шаблон или введите пользовательский URL (например, http://.../v1/chat/completions)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="325"/>
        <source>Template...</source>
        <translation>Шаблон...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="331"/>
        <source>API URL:</source>
        <translation>API URL:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="352"/>
        <source>Leave empty for local providers (e.g., Ollama)</source>
        <translation>Оставьте пустым для локальных провайдеров (например, Ollama)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="357"/>
        <source>http://host:port or socks5://host:port (optional)</source>
        <translation>http://host:port или socks5://host:port (опционально)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="366"/>
        <source>Proxy:</source>
        <translation>Прокси:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="369"/>
        <source>Override Global Defaults (optional, leave empty for default)</source>
        <translation>Переопределить глобальные настройки (опционально, оставьте пустым для настроек по умолчанию)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="375"/>
        <location filename="../src/ui/settingsdialog.cpp" line="382"/>
        <source>(use global)</source>
        <translation>(использовать глобальные)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="389"/>
        <source>Enabled</source>
        <translation>Включено</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="399"/>
        <source>Global Defaults (optional, leave empty for provider defaults)</source>
        <translation>Глобальные настройки (опционально, оставьте пустым для настроек провайдера)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="405"/>
        <location filename="../src/ui/settingsdialog.cpp" line="415"/>
        <source>(provider default)</source>
        <translation>(настройки провайдера)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="407"/>
        <location filename="../src/ui/settingsdialog.cpp" line="417"/>
        <source>Recommended: Leave empty to let provider use its defaults</source>
        <translation>Рекомендуется: оставьте пустым, чтобы провайдер использовал свои настройки</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="426"/>
        <source>Test Model Connection</source>
        <translation>Проверить соединение с моделью</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="437"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Hotkey</source>
        <translation>Хоткей</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="480"/>
        <source>Change Group</source>
        <translation>Изменить группу</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="484"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1216"/>
        <source>Change Priority</source>
        <translation>Изменить приоритет</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="767"/>
        <source>(custom)</source>
        <translation>(пользовательский)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="769"/>
        <source>(default)</source>
        <translation>(по умолчанию)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="779"/>
        <source>(none)</source>
        <translation>(нет)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="887"/>
        <source>Error: No model selected</source>
        <translation>Ошибка: Модель не выбрана</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1045"/>
        <source>• %1 (references %2)</source>
        <translation>• %1 (ссылается на %2)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1054"/>
        <source>Delete prompt &quot;%1&quot;?</source>
        <translation>Удалить промпт &quot;%1&quot;?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1056"/>
        <source>Delete %1 prompts?</source>
        <translation>Удалить %1 промптов?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1060"/>
        <source>

Warning: The following prompts reference the deleted prompts in their chains:
%1
These references will be cleared.</source>
        <translation>

Предупреждение: Следующие промпты ссылаются на удаляемые промпты в своих цепочках:
%1
Эти ссылки будут очищены.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1066"/>
        <source>Delete Prompts</source>
        <translation>Удалить промпты</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1136"/>
        <source>Move to Group</source>
        <translation>Переместить в группу</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1153"/>
        <source>Select new group for %1 prompts:</source>
        <translation>Выберите новую группу для %1 промптов:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1217"/>
        <source>New priority for %1 prompts (0-1000):</source>
        <translation>Новый приоритет для %1 промптов (0-1000):</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1328"/>
        <source>Export Selected Prompts</source>
        <translation>Экспорт выделенных промптов</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1333"/>
        <source>Export All Prompts</source>
        <translation>Экспорт всех промптов</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1367"/>
        <source>Failed to open file for writing: %1</source>
        <translation>Не удалось открыть файл для записи: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1374"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1380"/>
        <source>Exported %1 prompts to %2</source>
        <translation>Экспортировано %1 промптов в %2</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1424"/>
        <source>Selected: %1</source>
        <translation>Выделено: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="2148"/>
        <source>Hotkey Conflict</source>
        <translation>Конфликт хоткеев</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="2149"/>
        <source>This hotkey is already in use by a prompt.

Please choose a different hotkey.</source>
        <translation>Этот хоткей уже используется промптом.

Пожалуйста, выберите другой хоткей.</translation>
    </message>
    <message>
        <source>Hotkeys</source>
        <translation type="vanished">Горячие клавиши</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="527"/>
        <source>Prompts</source>
        <translation>Промпты</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="588"/>
        <source>History</source>
        <translation>История</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="125"/>
        <location filename="../src/ui/settingsdialog.cpp" line="517"/>
        <source>Reset to Defaults</source>
        <translation>Сбросить настройки</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="143"/>
        <source>Language</source>
        <translation>Язык</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="150"/>
        <source>Interface Language:</source>
        <translation>Язык интерфейса:</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Показывать описания промптов во всплывающем меню (по умолчанию отключено для более чистого меню)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="188"/>
        <source>Prompt Chains</source>
        <translation>Цепочки промптов</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="194"/>
        <source>Maximum number of prompts in a chain to prevent infinite loops</source>
        <translation>Максимальное количество промптов в цепочке для предотвращения бесконечных циклов</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="195"/>
        <source>Maximum Chain Depth:</source>
        <translation>Максимальная глубина цепочки:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="200"/>
        <source>Debug</source>
        <translation>Отладка</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="203"/>
        <source>Record debug messages</source>
        <translation>Записывать отладочные сообщения</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="204"/>
        <source>Write debug information to debug.log file in the configuration directory</source>
        <translation>Записывать отладочную информацию в файл debug.log в каталоге конфигурации</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="212"/>
        <source>Normal</source>
        <translation>Обычный</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="213"/>
        <source>Basic debug information</source>
        <translation>Базовая отладочная информация</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="214"/>
        <source>Trace</source>
        <translation>Трассировка</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="215"/>
        <source>Full request/response logging for LLM</source>
        <translation>Полное логирование запросов/ответов LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="224"/>
        <source>Debug Level:</source>
        <translation>Уровень отладки:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="235"/>
        <source>Log file:</source>
        <translation>Файл журнала:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="238"/>
        <source>Copy</source>
        <translation>Копировать</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="536"/>
        <source>Automatically save to history after generation</source>
        <translation>Автоматически сохранять в историю после генерации</translation>
    </message>
    <message>
        <source>LLM Provider</source>
        <translation type="vanished">LLM провайдер</translation>
    </message>
    <message>
        <source>Provider:</source>
        <translation type="vanished">Провайдер:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="337"/>
        <source>Select or enter model name...</source>
        <translation>Выберите или введите имя модели...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="342"/>
        <source>Refresh</source>
        <translation>Обновить</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="348"/>
        <source>Model:</source>
        <translation>Модель:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="354"/>
        <source>API Key:</source>
        <translation>API ключ:</translation>
    </message>
    <message>
        <source>http://localhost:11434/v1/chat/completions</source>
        <translation type="vanished">http://localhost:11434/v1/chat/completions</translation>
    </message>
    <message>
        <source>Used only when Provider is set to Custom.

Examples:
• Ollama: http://localhost:11434/v1/chat/completions
• LM Studio: http://localhost:1234/v1/chat/completions
• LocalAI: http://localhost:8080/v1/chat/completions</source>
        <translation type="vanished">Используется только когда Провайдер установлен на «Кастомный».

Примеры:
• Ollama: http://localhost:11434/v1/chat/completions
• LM Studio: http://localhost:1234/v1/chat/completions
• LocalAI: http://localhost:8080/v1/chat/completions</translation>
    </message>
    <message>
        <source>Custom API URL:</source>
        <translation type="vanished">Пользовательский API URL:</translation>
    </message>
    <message>
        <source>http://host:port or socks5://host:port</source>
        <translation type="vanished">http://host:port or socks5://host:port</translation>
    </message>
    <message>
        <source>Proxy (optional):</source>
        <translation type="vanished">Прокси (необязательно):</translation>
    </message>
    <message>
        <source>Options</source>
        <translation type="vanished">Опции</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="377"/>
        <location filename="../src/ui/settingsdialog.cpp" line="410"/>
        <source>Temperature:</source>
        <translation>Температура:</translation>
    </message>
    <message>
        <source>Override temperature</source>
        <translation type="vanished">Переопределить температуру</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="384"/>
        <location filename="../src/ui/settingsdialog.cpp" line="420"/>
        <source>Max Tokens:</source>
        <translation>Макс. токенов:</translation>
    </message>
    <message>
        <source>Enable streaming responses</source>
        <translation type="vanished">Включить потоковые ответы</translation>
    </message>
    <message>
        <source>Test Connection</source>
        <translation type="vanished">Проверить соединение</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="155"/>
        <source>Global Hotkey</source>
        <translation>Глобальная горячая клавиша</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="172"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Активация обработки буфера обмена:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="175"/>
        <source>&lt;b&gt;Note:&lt;/b&gt; Global hotkeys may not work on Wayland. On X11, the hotkey works globally. On Windows and macOS, global hotkeys are fully supported.</source>
        <translation>&lt;b&gt;Примечание:&lt;/b&gt; Глобальные горячие клавиши могут не работать на Wayland. На X11 горячая клавиша работает глобально. На Windows и macOS глобальные горячие клавиши полностью поддерживаются.</translation>
    </message>
    <message>
        <source>Menu Settings</source>
        <translation type="vanished">Настройки меню</translation>
    </message>
    <message>
        <source>Maximum number of prompts to show in the menu</source>
        <translation type="vanished">Максимальное количество промптов для отображения в меню</translation>
    </message>
    <message>
        <source>Max Prompts in Menu:</source>
        <translation type="vanished">Макс. промптов в меню:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Name</source>
        <translation>Имя</translation>
    </message>
    <message>
        <source>Description</source>
        <translation type="vanished">Описание</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Content Type</source>
        <translation>Тип содержимого</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Model</source>
        <translation>Модель</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Priority</source>
        <translation>Приоритет</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Group</source>
        <translation>Группа</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="466"/>
        <source>Add</source>
        <translation>Добавить</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="470"/>
        <source>Edit</source>
        <translation>Редактировать</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="475"/>
        <source>Delete</source>
        <translation>Удалить</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="488"/>
        <source>Manage Groups...</source>
        <translation>Управление группами...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="509"/>
        <source>Import</source>
        <translation>Импорт</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="513"/>
        <source>Export</source>
        <translation>Экспорт</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="539"/>
        <source>History Settings</source>
        <translation>Настройки истории</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="551"/>
        <source>Unlimited</source>
        <translation>Без ограничений</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="555"/>
        <source>Maximum entries:</source>
        <translation>Макс. записей:</translation>
    </message>
    <message>
        <source>Automatically clean up old entries</source>
        <translation type="vanished">Автоматически очищать старые записи</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="542"/>
        <source>Auto-cleanup by max entries</source>
        <translation>Автоочистка по лимиту записей</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="543"/>
        <source>Automatically remove oldest entries when limit is exceeded</source>
        <translation>Автоматически удалять самые старые записи при превышении лимита</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="557"/>
        <source>Auto-cleanup by date</source>
        <translation>Автоочистка по дате</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="558"/>
        <source>Automatically remove entries older than the specified number of days</source>
        <translation>Автоматически удалять записи старше указанного количества дней</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="569"/>
        <source>Days to keep:</source>
        <translation>Дней для хранения:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="573"/>
        <source>Actions</source>
        <translation>Действия</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="576"/>
        <source>Clear All History</source>
        <translation>Очистить всю историю</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="720"/>
        <source>English</source>
        <translation>Английский</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="721"/>
        <source>Russian</source>
        <translation>Русский</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="722"/>
        <source>German</source>
        <translation>Немецкий</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="723"/>
        <source>French</source>
        <translation>Французский</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="724"/>
        <source>Spanish</source>
        <translation>Испанский</translation>
    </message>
    <message>
        <source>OpenRouter</source>
        <translation type="vanished">OpenRouter</translation>
    </message>
    <message>
        <source>OpenAI</source>
        <translation type="vanished">OpenAI</translation>
    </message>
    <message>
        <source>Anthropic</source>
        <translation type="vanished">Anthropic</translation>
    </message>
    <message>
        <source>Custom</source>
        <translation type="vanished">Пользовательский</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="773"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1141"/>
        <source>(root)</source>
        <translation>(корень)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="811"/>
        <source>Reset Settings</source>
        <translation>Сбросить настройки</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="812"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>Вы уверены, что хотите сбросить все настройки к значениям по умолчанию?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="837"/>
        <source>Language Changed</source>
        <translation>Язык изменён</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="838"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>Язык будет изменён после перезапуска приложения.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="850"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1472"/>
        <source>No profile selected</source>
        <translation>Профиль не выбран</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="859"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1478"/>
        <source>Profile not found</source>
        <translation>Профиль не найден</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="867"/>
        <source>Invalid API URL</source>
        <translation>Неверный API URL</translation>
    </message>
    <message>
        <source>Configuration valid</source>
        <translation type="vanished">Конфигурация верна</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1265"/>
        <source>Failed to open file: %1</source>
        <translation>Не удалось открыть файл: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1275"/>
        <source>Failed to parse JSON file: %1</source>
        <translation>Не удалось разобрать файл JSON: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1289"/>
        <source>Prompts imported successfully.</source>
        <translation>Промпты успешно импортированы.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1486"/>
        <source>No API URL set</source>
        <translation>URL API не задан</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1678"/>
        <source>No provider profiles configured.
Click &apos;+ Add&apos; to create one.</source>
        <translation>Профили провайдеров не настроены.
Нажмите &apos;+ Добавить&apos; для создания.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1693"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1798"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1872"/>
        <source> [Default]</source>
        <translation> [По умолчанию]</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1699"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1798"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1875"/>
        <source> (disabled)</source>
        <translation> (отключено)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1736"/>
        <source>Add Provider Profile</source>
        <translation>Добавить профиль провайдера</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1737"/>
        <source>Select a template or create custom:</source>
        <translation>Выберите шаблон или создайте свой:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1802"/>
        <source>Remove Profile</source>
        <translation>Удалить профиль</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1803"/>
        <source>Are you sure you want to remove the profile &quot;%1&quot;?</source>
        <translation>Вы уверены, что хотите удалить профиль &quot;%1&quot;?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1946"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2023"/>
        <source>API key set</source>
        <translation>API ключ установлен</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1946"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2023"/>
        <source>No API key</source>
        <translation>Нет API ключа</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="844"/>
        <source>Testing...</source>
        <translation>Проверка...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="880"/>
        <source>Error: No API key</source>
        <translation>Ошибка: Нет API ключа</translation>
    </message>
    <message>
        <source>Connected</source>
        <translation type="vanished">Подключено</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="962"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1000"/>
        <source>Error</source>
        <translation>Ошибка</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="963"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation>Не удалось добавить промпт. ID может уже существовать.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1001"/>
        <source>Failed to update prompt.</source>
        <translation>Не удалось обновить промпт.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1066"/>
        <source>Delete Prompt</source>
        <translation>Удалить промпт</translation>
    </message>
    <message>
        <source>Are you sure you want to delete this prompt?</source>
        <translation type="vanished">Вы уверены, что хотите удалить этот промпт?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1247"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1264"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1274"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1288"/>
        <source>Import Prompts</source>
        <translation>Импорт промптов</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1249"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1340"/>
        <source>JSON Files (*.json)</source>
        <translation>JSON файлы (*.json)</translation>
    </message>
    <message>
        <source>Import will be implemented in a future version.</source>
        <translation type="vanished">Импорт будет реализован в будущей версии.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1366"/>
        <source>Export Prompts</source>
        <translation>Экспорт промптов</translation>
    </message>
    <message>
        <source>Prompts exported to %1</source>
        <translation type="vanished">Промпты экспортированы в %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1388"/>
        <source>Reset Prompts</source>
        <translation>Сбросить промпты</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1389"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation>Вы уверены, что хотите сбросить промпты к значениям по умолчанию? Все пользовательские промпты будут потеряны.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1435"/>
        <source>Clear History</source>
        <translation>Очистить историю</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1436"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Вы уверены, что хотите удалить все записи истории? Это действие нельзя отменить.</translation>
    </message>
    <message>
        <source>Model fetching not supported for this provider</source>
        <translation type="vanished">Получение моделей не поддерживается для этого провайдера</translation>
    </message>
    <message>
        <source>Fetch not supported for this provider</source>
        <translation type="vanished">Получение не поддерживается для этого провайдера</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1561"/>
        <source>Fetching models...</source>
        <translation>Получение моделей...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="927"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1572"/>
        <source>Error: %1</source>
        <translation>Ошибка: %1</translation>
    </message>
    <message>
        <source>Error: LLM client not available</source>
        <translation type="vanished">Ошибка: Клиент LLM недоступен</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="924"/>
        <source>Connection successful</source>
        <translation>Соединение успешно</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1582"/>
        <source>Error: Invalid response</source>
        <translation>Ошибка: Неверный ответ</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1623"/>
        <source>No models found</source>
        <translation>Модели не найдены</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1655"/>
        <source>Loaded %1 models</source>
        <translation>Загружено моделей: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="110"/>
        <source>OK</source>
        <translation>ОК</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="114"/>
        <source>Cancel</source>
        <translation>Отмена</translation>
    </message>
    <message>
        <source>Apply</source>
        <translation type="vanished">Применить</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="59"/>
        <location filename="../src/ui/trayicon.cpp" line="257"/>
        <location filename="../src/ui/trayicon.cpp" line="368"/>
        <source>ClipLLM - LLM Clipboard Utility</source>
        <translation>ClipLLM — Утилита для буфера обмена LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="92"/>
        <location filename="../src/ui/trayicon.cpp" line="372"/>
        <source>&amp;Settings</source>
        <translation>&amp;Настройки</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="96"/>
        <location filename="../src/ui/trayicon.cpp" line="375"/>
        <source>&amp;History</source>
        <translation>&amp;История</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="118"/>
        <location filename="../src/ui/trayicon.cpp" line="386"/>
        <source>&amp;Prompts</source>
        <translation>&amp;Промпты</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="321"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Project website:&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Версия %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; — кроссплатформенная утилита для работы с буфером обмена, интегрирующая большие языковые модели (LLM) непосредственно в ваш рабочий процесс. Работая как служба в системном трее, она позволяет обрабатывать содержимое буфера обмена (текст и изображения) с помощью настраиваемых AI-промптов, используя глобальные горячие клавиши.&lt;/p&gt;&lt;p&gt;Нужно ли вам суммировать текст, перевести содержимое, переписать код, извлечь информацию из изображений или выполнить любое другое AI-преобразование — ClipLLM делает это мгновенно доступным с помощью одного нажатия клавиши. Скопируйте содержимое, нажмите горячую клавишу и получите AI-результат обратно в буфер обмена.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Сайт проекта:&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Версия %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; — кроссплатформенная утилита для работы с буфером обмена, интегрирующая большие языковые модели (LLM) непосредственно в ваш рабочий процесс. Работая как служба в системном трее, она позволяет обрабатывать содержимое буфера обмена (текст и изображения) с помощью настраиваемых AI-промптов, используя глобальные горячие клавиши.&lt;/p&gt;&lt;p&gt;Нужно ли вам суммировать текст, перевести содержимое, переписать код, извлечь информацию из изображений или выполнить любое другое AI-преобразование — ClipLLM делает это мгновенно доступным с помощью одного нажатия клавиши. Скопируйте содержимое, нажмите горячую клавишу и получите AI-результат обратно в буфер обмена.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="100"/>
        <location filename="../src/ui/trayicon.cpp" line="378"/>
        <source>&amp;About</source>
        <translation>&amp;О программе</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="110"/>
        <location filename="../src/ui/trayicon.cpp" line="381"/>
        <source>&amp;Quit</source>
        <translation>&amp;Выход</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="140"/>
        <location filename="../src/ui/trayicon.cpp" line="148"/>
        <source>No prompts available</source>
        <translation>Нет доступных промптов</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="259"/>
        <source>Hotkey: </source>
        <translation>Горячая клавиша: </translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Версия 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; — это кроссплатформенная утилита для работы с буфером обмена, которая интегрирует большие языковые модели (LLM) непосредственно в ваш рабочий процесс. Работая как служба в системном трее, она позволяет обрабатывать содержимое буфера обмена (текст и изображения) с помощью настраиваемых AI промптов, используя глобальные горячие клавиши.&lt;/p&gt;&lt;p&gt;Нужно ли вам резюмировать текст, переводить содержимое, переписывать код, извлекать информацию из изображений или выполнять любое другое AI-преобразование, ClipLLM делает это мгновенно доступным с помощью нажатия одной клавиши. Скопируйте содержимое, нажмите горячую клавишу и получите AI-результат обратно в буфере обмена.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="343"/>
        <source>About ClipLLM</source>
        <translation>О ClipLLM</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="92"/>
        <source>[Image: %1 bytes]</source>
        <translation>[Изображение: %1 байт]</translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="96"/>
        <location filename="../src/core/historymanager.cpp" line="108"/>
        <source>[Empty]</source>
        <translation>[Пусто]</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="32"/>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation>ClipLLM — Кроссплатформенная утилита для работы с буфером обмена через LLM</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="38"/>
        <source>Start minimized to system tray</source>
        <translation>Запустить свернутым в системный трей</translation>
    </message>
</context>
</TS>
