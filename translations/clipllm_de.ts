<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="de_DE">
<context>
    <name>ClipLLM</name>
    <message>
        <source>Clipboard Empty</source>
        <translation type="obsolete">Zwischenablage leer</translation>
    </message>
    <message>
        <source>No content found in clipboard.</source>
        <translation type="obsolete">Kein Inhalt in der Zwischenablage gefunden.</translation>
    </message>
    <message>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation type="obsolete">Prompt kann nicht ausgeführt werden: Zwischenablage ist leer.

Kopieren Sie zuerst Text oder ein Bild.</translation>
    </message>
    <message>
        <source>Error</source>
        <translation type="obsolete">Fehler</translation>
    </message>
    <message>
        <source>Prompt not found: %1</source>
        <translation type="obsolete">Prompt nicht gefunden: %1</translation>
    </message>
    <message>
        <source>Provider Error</source>
        <translation type="obsolete">Provider-Fehler</translation>
    </message>
    <message>
        <source>No valid LLM provider configured.</source>
        <translation type="obsolete">Kein gültiger LLM-Anbieter konfiguriert.</translation>
    </message>
    <message>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation type="obsolete">Kein LLM-Anbieter konfiguriert. Bitte in den Einstellungen konfigurieren.</translation>
    </message>
    <message>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation type="obsolete">Standard-LLM-Anbieter nicht gefunden. Bitte in den Einstellungen konfigurieren.</translation>
    </message>
    <message>
        <source>Model Error</source>
        <translation type="obsolete">Modellfehler</translation>
    </message>
    <message>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation type="obsolete">Kein Modell ausgewählt. Bitte wählen Sie ein Modell unter Einstellungen → LLM → Anbieterprofile.</translation>
    </message>
    <message>
        <source>Incompatible Content</source>
        <translation type="obsolete">Inkompatibler Inhalt</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="obsolete">Dieser Prompt erfordert %1-Inhalt.</translation>
    </message>
    <message>
        <source>[Image content]</source>
        <translation type="obsolete">[Bildinhalt]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="272"/>
        <source>System Tray</source>
        <translation>Systemleiste</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="273"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation>Konnte keine Systemleiste auf diesem System erkennen.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="283"/>
        <source>Welcome to ClipLLM</source>
        <translation>Willkommen bei ClipLLM</translation>
    </message>
    <message>
        <source>ClipLLM is running in the system tray. Press the global hotkey to start.</source>
        <translation type="vanished">ClipLLM läuft in der Systemleiste. Drücken Sie die globale Tastenkombination, um zu starten.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="284"/>
        <source>ClipLLM is running in the system tray. Click the tray icon or configure a hotkey in settings.</source>
        <translation>ClipLLM läuft in der Systemleiste. Klicken Sie auf das Symbol oder konfigurieren Sie einen Hotkey in den Einstellungen.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="376"/>
        <source>Hotkey Not Supported</source>
        <translation>Hotkey nicht unterstützt</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="377"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation>Globale Hotkeys werden auf dieser Plattform nicht unterstützt (Wayland?).</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="402"/>
        <source>Hotkey Registration Failed</source>
        <translation>Hotkey-Registrierung fehlgeschlagen</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="403"/>
        <source>Could not register global hotkey: %1</source>
        <translation>Globaler Hotkey konnte nicht registriert werden: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="570"/>
        <source>Screenshot Failed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="570"/>
        <source>Could not capture screen</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="746"/>
        <location filename="../src/core/app.cpp" line="798"/>
        <source>Clipboard Empty</source>
        <translation>Zwischenablage leer</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="747"/>
        <source>No content found in clipboard.</source>
        <translation>Kein Inhalt in der Zwischenablage gefunden.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="770"/>
        <source>Chain Cycle Detected</source>
        <translation>Kettenzyklus erkannt</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="771"/>
        <source>The prompt chain would create a cycle. Execution stopped.

Prompt &apos;%1&apos; was already executed in this chain.</source>
        <translation>Die Prompt-Kette würde einen Zyklus erstellen. Ausführung gestoppt.

Prompt &apos;%1&apos; wurde bereits in dieser Kette ausgeführt.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="779"/>
        <source>Chain Depth Limit</source>
        <translation>Kettentiefenlimit</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="780"/>
        <source>Maximum chain depth (%1) reached. Execution stopped.

You can increase this limit in Settings → General → Prompt Chains.</source>
        <translation>Maximale Kettentiefe (%1) erreicht. Ausführung gestoppt.

Sie können dieses Limit unter Einstellungen → Allgemein → Prompt-Ketten erhöhen.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="799"/>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation>Prompt kann nicht ausgeführt werden: Zwischenablage ist leer.

Kopieren Sie zuerst Text oder ein Bild.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="814"/>
        <source>Error</source>
        <translation>Fehler</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="815"/>
        <source>Prompt not found: %1</source>
        <translation>Prompt nicht gefunden: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="837"/>
        <location filename="../src/core/app.cpp" line="842"/>
        <location filename="../src/core/app.cpp" line="853"/>
        <location filename="../src/core/app.cpp" line="858"/>
        <source>Provider Error</source>
        <translation>Provider-Fehler</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="838"/>
        <source>No valid LLM provider configured.</source>
        <translation>Kein gültiger LLM-Anbieter konfiguriert.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="843"/>
        <location filename="../src/core/app.cpp" line="859"/>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation>Kein LLM-Anbieter konfiguriert. Bitte in den Einstellungen konfigurieren.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="854"/>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation>Standard-LLM-Anbieter nicht gefunden. Bitte in den Einstellungen konfigurieren.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="896"/>
        <source>This prompt requires text content.</source>
        <translation>Dieser Prompt erfordert Textinhalt.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="211"/>
        <source>No LLM Provider Configured</source>
        <translation>Kein LLM-Anbieter konfiguriert</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="212"/>
        <source>No LLM provider profile has been configured.

Please add at least one provider profile in Settings to use ClipLLM.</source>
        <translation>Es wurde kein LLM-Anbieterprofil konfiguriert.

Bitte fügen Sie mindestens ein Anbieterprofil in den Einstellungen hinzu, um ClipLLM zu nutzen.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="876"/>
        <source>Model Error</source>
        <translation>Modellfehler</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="877"/>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation>Kein Modell ausgewählt. Bitte wählen Sie ein Modell unter Einstellungen → LLM → Anbieterprofile.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="895"/>
        <source>Incompatible Content</source>
        <translation>Inkompatibler Inhalt</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="vanished">Dieser Prompt erfordert %1-Inhalt.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="921"/>
        <source>[Image content]</source>
        <translation>[Bildinhalt]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::App</name>
    <message>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation type="vanished">ClipLLM - Plattformübergreifendes LLM-Zwischenablage-Dienstprogramm</translation>
    </message>
    <message>
        <source>Another instance of ClipLLM is already running</source>
        <translation type="vanished">Eine weitere Instanz von ClipLLM läuft bereits</translation>
    </message>
    <message>
        <source>Failed to initialize application</source>
        <translation type="vanished">Anwendung konnte nicht initialisiert werden</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::LLMClient</name>
    <message>
        <location filename="../src/core/llmclient.cpp" line="280"/>
        <source>API key is not set</source>
        <translation>API-Schlüssel nicht festgelegt</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="352"/>
        <location filename="../src/core/llmclient.cpp" line="448"/>
        <source>Connection successful</source>
        <translation>Verbindung erfolgreich</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="385"/>
        <source>HTTP %1: Authentication required. Please check your API key.</source>
        <translation>HTTP %1: Authentifizierung erforderlich. Bitte überprüfen Sie Ihren API-Schlüssel.</translation>
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
        <translation>SSL-Fehler: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::PromptManager</name>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="66"/>
        <source>Failed to load default prompts</source>
        <translation>Standard-Prompts konnten nicht geladen werden</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="125"/>
        <source>Failed to open prompts file</source>
        <translation>Promptdatei konnte nicht geöffnet werden</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="135"/>
        <source>Failed to parse prompts file</source>
        <translation>Promptdatei konnte nicht analysiert werden</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="354"/>
        <source>ID is required</source>
        <translation>ID erforderlich</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="358"/>
        <source>Name is required</source>
        <translation>Name erforderlich</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="373"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Ungültiger Platzhalter in Benutzervorlage: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="383"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Ungültiger Platzhalter im Systemprompt: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="451"/>
        <source>Summary</source>
        <translation>Zusammenfassung</translation>
    </message>
    <message>
        <source>Generate a structured summary of the text</source>
        <translation type="vanished">Erstellen Sie eine strukturierte Zusammenfassung des Textes</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="453"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Sie sind ein professioneller Analyst. Erstellen Sie eine klare, strukturierte Zusammenfassung.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="454"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation>Bitte geben Sie eine umfassende Zusammenfassung des folgenden Textes:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="465"/>
        <source>Translate to Russian</source>
        <translation>Ins Russische übersetzen</translation>
    </message>
    <message>
        <source>Translate the text to Russian</source>
        <translation type="vanished">Übersetzen Sie den Text ins Russische</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="467"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Sie sind ein professioneller Übersetzer. Übersetzen Sie den Text ins Russische unter Beibehaltung von Stil und Bedeutung.</translation>
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
        <translation>Ins Englische übersetzen</translation>
    </message>
    <message>
        <source>Translate the text to English</source>
        <translation type="vanished">Übersetzen Sie den Text ins Englische</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="481"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Sie sind ein professioneller Übersetzer. Übersetzen Sie den Text ins Englische unter Beibehaltung von Stil und Bedeutung.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="493"/>
        <source>Explain Code</source>
        <translation>Code erklären</translation>
    </message>
    <message>
        <source>Explain what the code does</source>
        <translation type="vanished">Erklären Sie, was der Code tut</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="495"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Sie sind ein Experte Programmierer. Erklären Sie den Code klar und prägnant.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="496"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation>Erklären Sie folgenden Code:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="507"/>
        <source>Code Review</source>
        <translation>Code-Review</translation>
    </message>
    <message>
        <source>Review code and suggest improvements</source>
        <translation type="vanished">Code überprüfen und Verbesserungen vorschlagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="509"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Sie sind ein Code-Reviewer. Analysieren Sie den Code auf Bugs, Sicherheitsprobleme und schlagen Sie Verbesserungen vor.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="510"/>
        <source>Review the following code:

{clipboard}</source>
        <translation>Überprüfen Sie folgenden Code:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="521"/>
        <source>Refactor Code</source>
        <translation>Code refaktorieren</translation>
    </message>
    <message>
        <source>Suggest refactoring improvements</source>
        <translation type="vanished">Verbesserungen für das Refactoring vorschlagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="523"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Sie sind ein Experte für Code-Optimierung. Schlagen Sie Refactoring vor, um die Lesbarkeit, Wartbarkeit und Leistung zu verbessern.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="524"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation>Refaktorieren Sie folgenden Code:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="535"/>
        <source>Describe Image</source>
        <translation>Bild beschreiben</translation>
    </message>
    <message>
        <source>Generate a detailed description of the image</source>
        <translation type="vanished">Erstellen Sie eine detaillierte Beschreibung des Bildes</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="537"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Sie sind ein visueller Analyst. Erstellen Sie eine detaillierte Beschreibung des Bildes.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="538"/>
        <source>Describe this image in detail.</source>
        <translation>Beschreiben Sie dieses Bild im Detail.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="549"/>
        <source>Extract Text</source>
        <translation>Text extrahieren</translation>
    </message>
    <message>
        <source>Extract all text from the image</source>
        <translation type="vanished">Extrahieren Sie den gesamten Text aus dem Bild</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="551"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Extrahieren Sie den gesamten Text aus dem Bild, wobei Sie die Formatierung möglichst beibehalten.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="552"/>
        <source>Extract all text from this image.</source>
        <translation>Extrahieren Sie den gesamten Text aus diesem Bild.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::GroupsDialog</name>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="53"/>
        <source>Manage Groups</source>
        <translation>Gruppen verwalten</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="59"/>
        <source>Right-click to add, rename, or delete groups. Drag and drop to move groups.</source>
        <translation>Rechtsklick zum Hinzufügen, Umbenennen oder Löschen von Gruppen. Drag &amp; Drop zum Verschieben.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="67"/>
        <source>Group Name</source>
        <translation>Gruppenname</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="90"/>
        <source>Close</source>
        <translation>Schließen</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="104"/>
        <source>Root</source>
        <translation>Stamm</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="198"/>
        <source>New Group...</source>
        <translation>Neue Gruppe...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="202"/>
        <source>New Subgroup...</source>
        <translation>Neue Untergruppe...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="205"/>
        <source>Rename...</source>
        <translation>Umbenennen...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="210"/>
        <source>Delete...</source>
        <translation>Löschen...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="221"/>
        <source>New Group</source>
        <translation>Neue Gruppe</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="222"/>
        <source>Enter group name:</source>
        <translation>Gruppenname eingeben:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="232"/>
        <location filename="../src/ui/groupsdialog.cpp" line="269"/>
        <source>Duplicate Group</source>
        <translation>Doppelte Gruppe</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="233"/>
        <source>A group with this name already exists.</source>
        <translation>Eine Gruppe mit diesem Namen existiert bereits.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="258"/>
        <source>New Subgroup</source>
        <translation>Neue Untergruppe</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="259"/>
        <source>Enter subgroup name:</source>
        <translation>Untergruppenname eingeben:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="270"/>
        <source>A subgroup with this name already exists.</source>
        <translation>Eine Untergruppe mit diesem Namen existiert bereits.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="309"/>
        <source>(root)</source>
        <translation>(Stamm)</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="321"/>
        <source>Delete group &apos;%1&apos;?

%2 prompt(s) in this group will be moved to root.</source>
        <translation>Gruppe &apos;%1&apos; löschen?

%2 Prompt(s) in dieser Gruppe werden in den Stamm verschoben.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="324"/>
        <source>Delete group &apos;%1&apos;?</source>
        <translation>Gruppe &apos;%1&apos; löschen?</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="328"/>
        <source>Delete Group</source>
        <translation>Gruppe löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="372"/>
        <source>Invalid Name</source>
        <translation>Ungültiger Name</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="373"/>
        <source>Group name cannot be empty.</source>
        <translation>Der Gruppenname darf nicht leer sein.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="393"/>
        <source>Duplicate Name</source>
        <translation>Doppelter Name</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="394"/>
        <source>A group with this name already exists in this location.</source>
        <translation>Eine Gruppe mit diesem Namen existiert bereits an diesem Ort.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="54"/>
        <source>ClipLLM - History</source>
        <translation>ClipLLM - Verlauf</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="63"/>
        <source>Search in history...</source>
        <translation>In Verlauf suchen...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="69"/>
        <source>Filters</source>
        <translation>Filter</translation>
    </message>
    <message>
        <source>Search...</source>
        <translation type="vanished">Suchen...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="73"/>
        <location filename="../src/ui/historydialog.cpp" line="294"/>
        <source>All Models</source>
        <translation>Alle Modelle</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="78"/>
        <location filename="../src/ui/historydialog.cpp" line="301"/>
        <source>All Prompts</source>
        <translation>Alle Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="82"/>
        <source>Favorites only</source>
        <translation>Nur Favoriten</translation>
    </message>
    <message>
        <source>Search:</source>
        <translation type="vanished">Suche:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="100"/>
        <source>Model:</source>
        <translation>Modell:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="102"/>
        <source>Prompt:</source>
        <translation>Prompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="105"/>
        <source>From:</source>
        <translation>Von:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="107"/>
        <source>To:</source>
        <translation>Bis:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="130"/>
        <source>Preview</source>
        <translation>Vorschau</translation>
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
        <translation>Roh</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="158"/>
        <source>View Details</source>
        <translation>Details anzeigen</translation>
    </message>
    <message>
        <source>Copy Output</source>
        <translation type="vanished">Ausgabe kopieren</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="163"/>
        <location filename="../src/ui/historydialog.cpp" line="427"/>
        <source>Favorite</source>
        <translation>Favorit</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="168"/>
        <source>Delete</source>
        <translation>Löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="173"/>
        <source>Export</source>
        <translation>Exportieren</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="177"/>
        <source>Clear All</source>
        <translation>Alle löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="181"/>
        <source>Close</source>
        <translation>Schließen</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="197"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="198"/>
        <source>Zoom out</source>
        <translation>Verkleinern</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="202"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="203"/>
        <source>Zoom in</source>
        <translation>Vergrößern</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="228"/>
        <source>Date</source>
        <translation>Datum</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="229"/>
        <source>Prompt</source>
        <translation>Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="230"/>
        <source>Model</source>
        <translation>Modell</translation>
    </message>
    <message>
        <source>Input Preview</source>
        <translation type="vanished">Eingabevorschau</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="231"/>
        <source>Output Preview</source>
        <translation>Ausgabevorschau</translation>
    </message>
    <message>
        <source>Duration</source>
        <translation type="vanished">Dauer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="232"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="319"/>
        <source>Total entries: %1</source>
        <translation>Gesamteinträge: %1</translation>
    </message>
    <message>
        <source>No history entries.\nEnable &apos;Automatically save to history&apos; in Settings\nor save prompts manually to populate this list.</source>
        <translation type="vanished">Keine Historieneinträge vorhanden.\nAktivieren Sie &apos;Automatisch in Historie speichern&apos; in Einstellungen\noder speichern Sie Prompts manuell, um diese Liste zu füllen.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="551"/>
        <location filename="../src/ui/historydialog.cpp" line="560"/>
        <source>Unknown</source>
        <translation>Unbekannt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="369"/>
        <source>Showing %1 entries</source>
        <translation>%1 Einträge anzeigen</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="264"/>
        <source>No history entries.
Enable &apos;Automatically save to history&apos; in Settings
or save prompts manually to populate this list.</source>
        <translation>Keine Historieneinträge.
Aktivieren Sie &apos;Automatisch in Historie speichern&apos; in Einstellungen
oder speichern Sie Prompts manuell, um diese Liste zu füllen.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="270"/>
        <source>Total entries: 0</source>
        <translation>Gesamt: 0 Einträge</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="580"/>
        <source>Prompt: %1
</source>
        <translation>Prompt: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="581"/>
        <source>Model: %1
</source>
        <translation>Modell: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="582"/>
        <source>Date: %1
</source>
        <translation>Datum: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="583"/>
        <source>Duration: %1
</source>
        <translation>Dauer: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="584"/>
        <source>Tokens: %1 input / %2 output
</source>
        <translation>Tokens: %1 Eingabe / %2 Ausgabe
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="588"/>
        <source>Input:
</source>
        <translation>Eingabe:
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="590"/>
        <source>Output:
</source>
        <translation>Ausgabe:
</translation>
    </message>
    <message>
        <source>&lt;b&gt;Prompt:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Prompt:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Model:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Modell:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Date:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Datum:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Duration:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Dauer:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Tokens:&lt;/b&gt; %1 input / %2 output&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Tokens:&lt;/b&gt; %1 Eingabe / %2 Ausgabe&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Input:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Eingabe:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Output:&lt;/b&gt;&lt;br&gt;%1</source>
        <translation type="vanished">&lt;b&gt;Ausgabe:&lt;/b&gt;&lt;br&gt;%1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="427"/>
        <source>Unfavorite</source>
        <translation>Aus Favoriten entfernen</translation>
    </message>
    <message>
        <source>Copied to clipboard</source>
        <translation type="vanished">In die Zwischenablage kopiert</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="443"/>
        <source>Delete Entry</source>
        <translation>Eintrag löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="444"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>Möchten Sie diesen Eintrag wirklich löschen?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="472"/>
        <source>Export History</source>
        <translation>Verlauf exportieren</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="474"/>
        <source>JSON Files (*.json)</source>
        <translation>JSON-Dateien (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="495"/>
        <source>Exported to %1</source>
        <translation>Nach %1 exportiert</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="497"/>
        <source>Export Failed</source>
        <translation>Export fehlgeschlagen</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="498"/>
        <source>Failed to write to file: %1</source>
        <translation>Fehler beim Schreiben in Datei: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="506"/>
        <source>Clear All History</source>
        <translation>Gesamten Verlauf löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="507"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Möchten Sie wirklich alle Verlaufseinträge löschen? Dies kann nicht rückgängig gemacht werden.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="538"/>
        <source>%1 ms</source>
        <translation>%1 ms</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="540"/>
        <source>%1 s</source>
        <translation>%1 s</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="544"/>
        <source>%1m %2s</source>
        <translation>%1m %2s</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HotkeyEdit</name>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="39"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="96"/>
        <source>Press hotkey...</source>
        <translation>Tastenkombination drücken...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="41"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="196"/>
        <source>Record</source>
        <translation>Aufnehmen</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="48"/>
        <source>Clear</source>
        <translation>Löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="175"/>
        <source>Stop</source>
        <translation>Stop</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="176"/>
        <source>Press key combination...</source>
        <translation>Tastenkombination drücken...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="208"/>
        <source>None</source>
        <translation>Keine</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ImageViewDialog</name>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="45"/>
        <source>Clipboard Image</source>
        <translation>Zwischenablage-Bild</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="62"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Größe: %1 x %2 Pixel</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="72"/>
        <source>Close</source>
        <translation>Schließen</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptConflictDialog</name>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="32"/>
        <source>Prompt Conflict</source>
        <translation>Prompt-Konflikt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="39"/>
        <source>A prompt named &quot;%1&quot; already exists.</source>
        <translation>Ein Prompt mit dem Namen &quot;%1&quot; existiert bereits.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="47"/>
        <source>&lt;b&gt;Existing:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Vorhanden:&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="53"/>
        <source>&lt;b&gt;New:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Neu:&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="60"/>
        <source>Do you want to replace it?</source>
        <translation>Möchten Sie ihn ersetzen?</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="69"/>
        <source>Yes</source>
        <translation>Ja</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="70"/>
        <source>Yes for all</source>
        <translation>Ja für alle</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="71"/>
        <source>No</source>
        <translation>Nein</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="72"/>
        <source>No for all</source>
        <translation>Nein für alle</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="73"/>
        <source>Cancel</source>
        <translation>Abbrechen</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptEditorDialog</name>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="71"/>
        <source>Add Prompt</source>
        <translation>Prompt hinzufügen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="119"/>
        <source>Edit Prompt</source>
        <translation>Prompt bearbeiten</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="224"/>
        <source>Basic Information</source>
        <translation>Grundlegende Informationen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="228"/>
        <source>e.g., custom_prompt</source>
        <translation>z. B. custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="241"/>
        <source>ID:</source>
        <translation>ID:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="244"/>
        <source>e.g., My Custom Prompt</source>
        <translation>z. B. Mein benutzerdefinierter Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="246"/>
        <source>Name:</source>
        <translation>Name:</translation>
    </message>
    <message>
        <source>e.g., Does something useful</source>
        <translation type="vanished">z. B. Macht etwas Nützliches</translation>
    </message>
    <message>
        <source>Description:</source>
        <translation type="vanished">Beschreibung:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="250"/>
        <source>(root)</source>
        <translation>(Stamm)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="271"/>
        <source>Group:</source>
        <translation>Gruppe:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="215"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="194"/>
        <source>System Prompt:</source>
        <translation>Systemprompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="197"/>
        <source>You are a helpful assistant...</source>
        <translation>Sie sind ein hilfreicher Assistent...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="201"/>
        <source>User Prompt Template:</source>
        <translation>Benutzervorlage:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="204"/>
        <source>Process the following text:

{clipboard}</source>
        <translation>Verarbeiten Sie den folgenden Text:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="210"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation>Verwenden Sie {clipboard}, um Zwischenablagetext einzufügen, {clipboard:1000} für gekürzten Text, {language} für die Benutzersprache.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="409"/>
        <source>Settings</source>
        <translation>Einstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="274"/>
        <source>Text</source>
        <translation>Text</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="275"/>
        <source>Image</source>
        <translation>Bild</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="276"/>
        <source>Any</source>
        <translation>Beliebig</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="277"/>
        <source>Content Type:</source>
        <translation>Inhaltstyp:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="330"/>
        <source>Override provider and model</source>
        <translation>Provider und Modell überschreiben</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="331"/>
        <source>When checked, use specific provider and model instead of defaults</source>
        <translation>Wenn aktiviert, bestimmten Provider und Modell anstelle der Standardwerte verwenden</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="337"/>
        <source>Select provider for this prompt</source>
        <translation>Provider für diesen Prompt auswählen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="346"/>
        <source>Select or enter model name</source>
        <translation>Modellname auswählen oder eingeben</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="349"/>
        <source>Refresh</source>
        <translation>Aktualisieren</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="292"/>
        <source>Optional global hotkey to directly execute this prompt</source>
        <translation>Optionaler globaler Hotkey zur direkten Ausführung dieses Prompts</translation>
    </message>
    <message>
        <source>Hotkey:</source>
        <translation type="vanished">Hotkey:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="385"/>
        <source>Select next prompt in the chain (only text prompts available)</source>
        <translation>Nächsten Prompt in der Kette auswählen (nur Text-Prompts verfügbar)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="388"/>
        <source>Next Prompt:</source>
        <translation>Nächster Prompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="390"/>
        <source>Auto-continue to next prompt</source>
        <translation>Automatisch zum nächsten Prompt fortfahren</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="391"/>
        <source>Automatically run the next prompt after this one completes</source>
        <translation>Automatisch den nächsten Prompt ausführen, nachdem dieser abgeschlossen ist</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="169"/>
        <source>Export</source>
        <translation>Exportieren</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="232"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="895"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="903"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="945"/>
        <source>Rename ID</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="233"/>
        <source>Change the prompt ID</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="304"/>
        <source>Hotkey (Clipboard):</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="309"/>
        <source>Optional global hotkey to capture screenshot and execute this prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="321"/>
        <source>Hotkey (Screenshot):</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="326"/>
        <source>LLM Settings</source>
        <translation>LLM-Einstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="381"/>
        <source>Chain Settings</source>
        <translation>Ketteneinstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="594"/>
        <source>(Select provider first)</source>
        <translation>(Zuerst Provider auswählen)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="601"/>
        <source>(Provider not found)</source>
        <translation>(Provider nicht gefunden)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="619"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="630"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1096"/>
        <source>(Custom model...)</source>
        <translation>(Benutzerdefiniertes Modell...)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="787"/>
        <source>Chain Cycle Detected</source>
        <translation>Kettenzyklus erkannt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="788"/>
        <source>This prompt would create a cycle in the chain.

Please select a different &apos;Next Prompt&apos; or set it to &apos;(None)&apos;.</source>
        <translation>Dieser Prompt würde einen Zyklus in der Kette erstellen.

Bitte wählen Sie einen anderen &apos;Nächsten Prompt&apos; oder setzen Sie ihn auf &apos;(Keiner)&apos;.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="823"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="835"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="857"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="865"/>
        <source>Export Prompt</source>
        <translation>Prompt exportieren</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="824"/>
        <source>Cannot export: prompt is not valid.</source>
        <translation>Export nicht möglich: Prompt ist ungültig.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="837"/>
        <source>JSON Files (*.json)</source>
        <translation>JSON-Dateien (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="858"/>
        <source>Failed to open file for writing: %1</source>
        <translation>Datei konnte nicht zum Schreiben geöffnet werden: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="866"/>
        <source>Prompt exported to %1</source>
        <translation>Prompt nach %1 exportiert</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="880"/>
        <source>Rename Prompt ID</source>
        <translation>Prompt-ID umbenennen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="881"/>
        <source>Enter new ID for this prompt:</source>
        <translation>Neue ID für diesen Prompt eingeben:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="896"/>
        <source>New ID is the same as the current ID.</source>
        <translation>Die neue ID ist identisch mit der aktuellen ID.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="911"/>
        <source>Rename ID - Historical Records</source>
        <translation>ID umbenennen — Historische Einträge</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="912"/>
        <source>Historical records of this prompt will remain with the old ID &quot;%1&quot;.

When re-running prompts from history, they will use the old ID.

Continue with renaming?</source>
        <translation>Historische Einträge dieses Prompts bleiben mit der alten ID &quot;%1&quot;.

Beim erneuten Ausführen von Prompts aus dem Verlauf wird die alte ID verwendet.

Umbenennung fortsetzen?</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="946"/>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.

Click OK to save the changes.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.</source>
        <translation type="vanished">Die Prompt-ID wurde von &quot;%1&quot; in &quot;%2&quot; umbenannt.

Alle Kettenreferenzen wurden aktualisiert.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="974"/>
        <source>No provider selected</source>
        <translation>Kein Provider ausgewählt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="981"/>
        <source>Provider not found</source>
        <translation>Provider nicht gefunden</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="989"/>
        <source>Model fetching not supported for this provider</source>
        <translation>Modell-Abruf für diesen Provider nicht unterstützt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1044"/>
        <source>Fetching models...</source>
        <translation>Modelle werden abgerufen...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1060"/>
        <source>Error: %1</source>
        <translation>Fehler: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1073"/>
        <source>Error: Invalid response</source>
        <translation>Fehler: Ungültige Antwort</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1085"/>
        <source>No models found</source>
        <translation>Keine Modelle gefunden</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1122"/>
        <source>Loaded %1 models</source>
        <translation>%1 Modelle geladen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1160"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1251"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1263"/>
        <source>Hotkey Conflict</source>
        <translation>Hotkey-Konflikt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1161"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1264"/>
        <source>This hotkey is already in use by another prompt or the global hotkey.

Please choose a different hotkey.</source>
        <translation>Dieser Hotkey wird bereits von einem anderen Prompt oder dem globalen Hotkey verwendet.

Bitte wählen Sie einen anderen Hotkey.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1252"/>
        <source>Screenshot hotkey cannot be the same as clipboard hotkey.

Please choose a different hotkey.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1325"/>
        <source>(None)</source>
        <translation>(Keiner)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1355"/>
        <source> (disabled)</source>
        <translation> (deaktiviert)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1428"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1446"/>
        <source>Warning: This would create a cycle in the chain!</source>
        <translation>Warnung: Dies würde einen Zyklus in der Kette erstellen!</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1440"/>
        <source>Warning: Target prompt is part of an existing cycle!</source>
        <translation>Warnung: Der Ziel-Prompt ist Teil eines bestehenden Zyklus!</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="340"/>
        <source>Provider:</source>
        <translation>Provider:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="291"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="308"/>
        <source>None</source>
        <translation>Keine</translation>
    </message>
    <message>
        <source>Text Summary</source>
        <translation type="vanished">Zusammenfassung</translation>
    </message>
    <message>
        <source>Translate</source>
        <translation type="vanished">Übersetzen</translation>
    </message>
    <message>
        <source>Code Review</source>
        <translation type="vanished">Code-Review</translation>
    </message>
    <message>
        <source>Refactor</source>
        <translation type="vanished">Refactoring</translation>
    </message>
    <message>
        <source>Explain</source>
        <translation type="vanished">Erklären</translation>
    </message>
    <message>
        <source>Custom</source>
        <translation type="vanished">Benutzerdefiniert</translation>
    </message>
    <message>
        <source>Icon:</source>
        <translation type="vanished">Symbol:</translation>
    </message>
    <message>
        <source>Use default model from settings</source>
        <translation type="vanished">Standardmodell aus Einstellungen verwenden</translation>
    </message>
    <message>
        <source>e.g., openai/gpt-4, anthropic/claude-3-opus</source>
        <translation type="vanished">z. B. openai/gpt-4, anthropic/claude-3-opus</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="360"/>
        <source>Model:</source>
        <translation>Modell:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="363"/>
        <source>Use default temperature from settings</source>
        <translation>Standardtemperatur aus Einstellungen verwenden</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="371"/>
        <source>Temperature:</source>
        <translation>Temperatur:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="376"/>
        <source>Max Tokens:</source>
        <translation>Maximale Token:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="279"/>
        <source>Enabled</source>
        <translation>Aktiviert</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="287"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation>Prompts mit höherer Priorität erscheinen zuerst im Menü</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="288"/>
        <source>Priority (higher = first):</source>
        <translation>Priorität (höher = zuerst):</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="173"/>
        <source>Prompt Preview</source>
        <translation>Prompt-Vorschau</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="177"/>
        <source>OK</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="182"/>
        <source>Cancel</source>
        <translation>Abbrechen</translation>
    </message>
    <message>
        <source>Uses global default model</source>
        <translation type="vanished">Verwendet globales Standardmodell</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="648"/>
        <source>(No providers available)</source>
        <translation>(Keine Provider verfügbar)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="657"/>
        <source>(No providers configured)</source>
        <translation>(Keine Provider konfiguriert)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="724"/>
        <source>Name is required</source>
        <translation>Name erforderlich</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="728"/>
        <source>ID is required</source>
        <translation>ID erforderlich</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="743"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Ungültiger Platzhalter in Benutzervorlage: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="753"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Ungültiger Platzhalter im Systemprompt: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="763"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="904"/>
        <source>ID already exists: %1</source>
        <translation>ID existiert bereits: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="797"/>
        <source>Validation Error</source>
        <translation>Validierungsfehler</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="798"/>
        <source>The prompt has validation errors:

%1</source>
        <translation>Der Prompt hat Validierungsfehler:

%1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptMenu</name>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="59"/>
        <source>Search prompts...</source>
        <translation>Prompts durchsuchen...</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="69"/>
        <source>History</source>
        <translation>Verlauf</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="77"/>
        <source>Settings</source>
        <translation>Einstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="143"/>
        <source>No prompts available</source>
        <translation>Keine Prompts verfügbar</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="172"/>
        <source>No prompts available for this content type</source>
        <translation>Keine Prompts für diesen Inhaltstyp verfügbar</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="194"/>
        <source>No prompts found</source>
        <translation>Keine Prompts gefunden</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="213"/>
        <source>Add priority to prompts to see them here</source>
        <translation>Priorität zu Prompts hinzufügen, um sie hier anzuzeigen</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptPreviewDialog</name>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="75"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation>⚠ Dieser Prompt ist nur für Textinhalte konfiguriert, aber es gibt ein Bild in der Zwischenablage. Das Bild wird ignoriert.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="84"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation>⚠ Dieser Prompt ist nur für Bildinhalte konfiguriert, aber es gibt Text in der Zwischenablage. Nur das Bild wird an das Modell gesendet.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="87"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation>⚠ Dieser Prompt ist nur für Bildinhalte konfiguriert, aber die Zwischenablage ist leer oder enthält kein Bild.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="181"/>
        <source>%1x%2</source>
        <translation>%1x%2</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="221"/>
        <source>Prompt Preview</source>
        <translation>Prompt-Vorschau</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="233"/>
        <source>Request that will be sent to the API</source>
        <translation>Anfrage, die an die API gesendet wird</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="246"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation>Dies ist das genaue JSON, das an die LLM-API gesendet wird. Der Zwischenablageinhalt wird für den Platzhalter {clipboard} ersetzt. Klicken Sie auf den Bildlink, um das gesamte Bild anzuzeigen.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="258"/>
        <source>Refresh</source>
        <translation>Aktualisieren</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="262"/>
        <source>Close</source>
        <translation>Schließen</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="49"/>
        <source>ClipLLM - Result</source>
        <translation>ClipLLM - Ergebnis</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="90"/>
        <location filename="../src/ui/resultdialog.cpp" line="274"/>
        <source>Model: -</source>
        <translation>Modell: -</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="92"/>
        <source>Tokens: 0 / 0</source>
        <translation>Tokens: 0 / 0</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="93"/>
        <location filename="../src/ui/resultdialog.cpp" line="301"/>
        <source>Traffic: 0 B</source>
        <translation>Datenvolumen: 0 B</translation>
    </message>
    <message>
        <source>Settings</source>
        <translation type="obsolete">Einstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="110"/>
        <source>Ready</source>
        <translation>Bereit</translation>
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
        <translation>Roh</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="129"/>
        <location filename="../src/ui/resultdialog.cpp" line="692"/>
        <source>Show Input</source>
        <translation>Eingabe anzeigen</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="144"/>
        <source>Input</source>
        <translation>Eingabe</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="154"/>
        <source>Output</source>
        <translation>Ausgabe</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="171"/>
        <source>Copy &amp;&amp; close</source>
        <translation>Kopieren und schließen</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="176"/>
        <source>Save to History</source>
        <translation>Im Verlauf speichern</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="181"/>
        <source>Save as...</source>
        <translation>Speichern unter...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="184"/>
        <source>Save output to a file</source>
        <translation>Ausgabe in Datei speichern</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="187"/>
        <source>Retry</source>
        <translation>Wiederholen</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="192"/>
        <source>Continue</source>
        <translation>Fortfahren</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="198"/>
        <source>Close</source>
        <translation>Schließen</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="203"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="204"/>
        <source>Zoom out</source>
        <translation>Verkleinern</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="208"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="209"/>
        <source>Zoom in</source>
        <translation>Vergrößern</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="237"/>
        <source>ClipLLM - %1</source>
        <translation>ClipLLM - %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="276"/>
        <location filename="../src/ui/resultdialog.cpp" line="278"/>
        <source>Model: %1</source>
        <translation>Modell: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="280"/>
        <source>Model: %1 / %2</source>
        <translation>Modell: %1 / %2</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="302"/>
        <source>Connecting...</source>
        <translation>Verbindung wird hergestellt...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="333"/>
        <source>Tokens: ~%1</source>
        <translation>Tokens: ~%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="346"/>
        <source>Completed in %1 seconds</source>
        <translation>Fertig gestellt in %1 Sekunden</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="351"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation>Tokens: %1 Eingabe / %2 Ausgabe</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="389"/>
        <location filename="../src/ui/resultdialog.cpp" line="417"/>
        <source>API Error</source>
        <translation>API-Fehler</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="390"/>
        <location filename="../src/ui/resultdialog.cpp" line="418"/>
        <source>An error occurred while communicating with the API:

%1</source>
        <translation>Ein Fehler ist bei der Kommunikation mit der API aufgetreten:

%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="393"/>
        <location filename="../src/ui/resultdialog.cpp" line="426"/>
        <source>Error: %1</source>
        <translation>Fehler: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="459"/>
        <source>Saved</source>
        <translation>Gespeichert</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="483"/>
        <source>Save Output As</source>
        <translation>Ausgabe speichern unter</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="485"/>
        <source>Text Files (*.txt);;All Files (*)</source>
        <translation>Textdateien (*.txt);;Alle Dateien (*)</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="512"/>
        <source>Saved to %1</source>
        <translation>Gespeichert unter %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="518"/>
        <source>Save Failed</source>
        <translation>Speichern fehlgeschlagen</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="519"/>
        <source>Could not write to file:
%1</source>
        <translation>Datei konnte nicht geschrieben werden:
%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="582"/>
        <source>Close During Generation</source>
        <translation>Schließen während der Generierung</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="583"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation>Es wird noch eine Antwort generiert. Schließen und Anfrage abbrechen?</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="591"/>
        <source>Cancelling...</source>
        <translation>Wird abgebrochen...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="632"/>
        <source>Model is thinking...</source>
        <translation>Modell denkt nach...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="635"/>
        <source>Generating response...</source>
        <translation>Antwort wird generiert...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="644"/>
        <source>Traffic: %1</source>
        <translation>Datenvolumen: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="688"/>
        <source>Hide Input</source>
        <translation>Eingabe ausblenden</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="795"/>
        <source>Chain: %1</source>
        <translation>Kette: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ScreenshotSelector</name>
    <message>
        <location filename="../src/ui/screenshotselector.cpp" line="31"/>
        <source>Select an area to capture
Enter = whole screen
Escape = cancel
Right-click = reset/cancel</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="92"/>
        <source>ClipLLM - Settings</source>
        <translation>ClipLLM - Einstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="125"/>
        <location filename="../src/ui/settingsdialog.cpp" line="517"/>
        <source>Reset to Defaults</source>
        <translation>Auf Standard zurücksetzen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="143"/>
        <source>Language</source>
        <translation>Sprache</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="150"/>
        <source>Interface Language:</source>
        <translation>Oberflächensprache:</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the tray menu (disabled by default for cleaner menu)</source>
        <translation type="vanished">Prompt-Beschreibungen im Tray-Menü anzeigen (standardmäßig deaktiviert für sauberes Menü)</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Prompt-Beschreibungen im Popup-Menü anzeigen (standardmäßig deaktiviert für sauberes Menü)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="188"/>
        <source>Prompt Chains</source>
        <translation>Prompt-Ketten</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="194"/>
        <source>Maximum number of prompts in a chain to prevent infinite loops</source>
        <translation>Maximale Anzahl von Prompts in einer Kette zur Verhinderung von Endlosschleifen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="195"/>
        <source>Maximum Chain Depth:</source>
        <translation>Maximale Kettentiefe:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="200"/>
        <source>Debug</source>
        <translation>Debug</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="203"/>
        <source>Record debug messages</source>
        <translation>Debug-Nachrichten aufzeichnen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="204"/>
        <source>Write debug information to debug.log file in the configuration directory</source>
        <translation>Debug-Informationen in debug.log-Datei im Konfigurationsverzeichnis schreiben</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="212"/>
        <source>Normal</source>
        <translation>Normal</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="213"/>
        <source>Basic debug information</source>
        <translation>Grundlegende Debug-Informationen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="214"/>
        <source>Trace</source>
        <translation>Ablaufverfolgung</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="215"/>
        <source>Full request/response logging for LLM</source>
        <translation>Vollständige Request/Response-Protokollierung für LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="224"/>
        <source>Debug Level:</source>
        <translation>Debug-Level:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="235"/>
        <source>Log file:</source>
        <translation>Logdatei:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="238"/>
        <source>Copy</source>
        <translation>Kopieren</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="588"/>
        <source>History</source>
        <translation>Verlauf</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="536"/>
        <source>Automatically save to history after generation</source>
        <translation>Automatisch in den Verlauf speichern nach der Generierung</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="258"/>
        <source>General</source>
        <translation>Allgemein</translation>
    </message>
    <message>
        <source>LLM Provider</source>
        <translation type="vanished">LLM-Anbieter</translation>
    </message>
    <message>
        <source>Provider:</source>
        <translation type="vanished">Anbieter:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="337"/>
        <source>Select or enter model name...</source>
        <translation>Modellname auswählen oder eingeben...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="342"/>
        <source>Refresh</source>
        <translation>Aktualisieren</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="348"/>
        <source>Model:</source>
        <translation>Modell:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="354"/>
        <source>API Key:</source>
        <translation>API-Schlüssel:</translation>
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
        <translation type="vanished">Wird nur verwendet, wenn der Anbieter auf „Benutzerdefiniert“ eingestellt ist.

Beispiele:
• Ollama: http://localhost:11434/v1/chat/completions
• LM Studio: http://localhost:1234/v1/chat/completions
• LocalAI: http://localhost:8080/v1/chat/completions</translation>
    </message>
    <message>
        <source>Custom API URL:</source>
        <translation type="vanished">Benutzerdefinierte API-URL:</translation>
    </message>
    <message>
        <source>http://host:port or socks5://host:port</source>
        <translation type="vanished">http://host:port or socks5://host:port</translation>
    </message>
    <message>
        <source>Proxy (optional):</source>
        <translation type="vanished">Proxy (optional):</translation>
    </message>
    <message>
        <source>Options</source>
        <translation type="vanished">Optionen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="377"/>
        <location filename="../src/ui/settingsdialog.cpp" line="410"/>
        <source>Temperature:</source>
        <translation>Temperatur:</translation>
    </message>
    <message>
        <source>Override temperature</source>
        <translation type="vanished">Temperatur überschreiben</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="384"/>
        <location filename="../src/ui/settingsdialog.cpp" line="420"/>
        <source>Max Tokens:</source>
        <translation>Maximale Token:</translation>
    </message>
    <message>
        <source>Enable streaming responses</source>
        <translation type="vanished">Streaming-Antworten aktivieren</translation>
    </message>
    <message>
        <source>Test Connection</source>
        <translation type="vanished">Verbindung testen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="437"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="155"/>
        <source>Global Hotkey</source>
        <translation>Globale Tastenkombination</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="172"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Zwischenablage-Verarbeitung aktivieren:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="175"/>
        <source>&lt;b&gt;Note:&lt;/b&gt; Global hotkeys may not work on Wayland. On X11, the hotkey works globally. On Windows and macOS, global hotkeys are fully supported.</source>
        <translation>&lt;b&gt;Hinweis:&lt;/b&gt; Globale Tastenkombinationen funktionieren möglicherweise nicht auf Wayland. Auf X11 funktioniert die Tastenkombination global. Unter Windows und macOS werden globale Tastenkombinationen vollständig unterstützt.</translation>
    </message>
    <message>
        <source>Hotkeys</source>
        <translation type="vanished">Tastenkombinationen</translation>
    </message>
    <message>
        <source>Menu Settings</source>
        <translation type="vanished">Menüeinstellungen</translation>
    </message>
    <message>
        <source>Maximum number of prompts to show in the menu</source>
        <translation type="vanished">Maximale Anzahl der Prompts, die im Menü angezeigt werden</translation>
    </message>
    <message>
        <source>Max Prompts in Menu:</source>
        <translation type="vanished">Max. Prompts im Menü:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Name</source>
        <translation>Name</translation>
    </message>
    <message>
        <source>Description</source>
        <translation type="vanished">Beschreibung</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Content Type</source>
        <translation>Inhaltstyp</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Model</source>
        <translation>Modell</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Priority</source>
        <translation>Priorität</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Group</source>
        <translation>Gruppe</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="466"/>
        <source>Add</source>
        <translation>Hinzufügen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="470"/>
        <source>Edit</source>
        <translation>Bearbeiten</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="475"/>
        <source>Delete</source>
        <translation>Löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="488"/>
        <source>Manage Groups...</source>
        <translation>Gruppen verwalten...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="509"/>
        <source>Import</source>
        <translation>Importieren</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="513"/>
        <source>Export</source>
        <translation>Exportieren</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="527"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="539"/>
        <source>History Settings</source>
        <translation>Verlaufseinstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="551"/>
        <source>Unlimited</source>
        <translation>Unbegrenzt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="555"/>
        <source>Maximum entries:</source>
        <translation>Maximale Einträge:</translation>
    </message>
    <message>
        <source>Automatically clean up old entries</source>
        <translation type="vanished">Alte Einträge automatisch bereinigen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="542"/>
        <source>Auto-cleanup by max entries</source>
        <translation>Automatische Bereinigung nach max. Einträgen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="543"/>
        <source>Automatically remove oldest entries when limit is exceeded</source>
        <translation>Automatisch älteste Einträge entfernen, wenn Limit überschritten</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="557"/>
        <source>Auto-cleanup by date</source>
        <translation>Automatische Bereinigung nach Datum</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="558"/>
        <source>Automatically remove entries older than the specified number of days</source>
        <translation>Automatisch Einträge entfernen, die älter als die angegebene Anzahl von Tagen sind</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="569"/>
        <source>Days to keep:</source>
        <translation>Tage zum Aufbewahren:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="573"/>
        <source>Actions</source>
        <translation>Aktionen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="576"/>
        <source>Clear All History</source>
        <translation>Gesamten Verlauf löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="720"/>
        <source>English</source>
        <translation>Englisch</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="721"/>
        <source>Russian</source>
        <translation>Russisch</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="722"/>
        <source>German</source>
        <translation>Deutsch</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="723"/>
        <source>French</source>
        <translation>Französisch</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="724"/>
        <source>Spanish</source>
        <translation>Spanisch</translation>
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
        <translation type="vanished">Benutzerdefiniert</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="773"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1141"/>
        <source>(root)</source>
        <translation>(Stamm)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="811"/>
        <source>Reset Settings</source>
        <translation>Einstellungen zurücksetzen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="812"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>Möchten Sie alle Einstellungen wirklich auf Standard zurücksetzen?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="837"/>
        <source>Language Changed</source>
        <translation>Sprache geändert</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="838"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>Die Sprache wird geändert, nachdem Sie die Anwendung neu gestartet haben.</translation>
    </message>
    <message>
        <source>Configuration valid</source>
        <translation type="vanished">Konfiguration gültig</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1265"/>
        <source>Failed to open file: %1</source>
        <translation>Datei konnte nicht geöffnet werden: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1275"/>
        <source>Failed to parse JSON file: %1</source>
        <translation>JSON-Datei konnte nicht geparst werden: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1289"/>
        <source>Prompts imported successfully.</source>
        <translation>Prompts erfolgreich importiert.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1486"/>
        <source>No API URL set</source>
        <translation>API-URL nicht festgelegt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1678"/>
        <source>No provider profiles configured.
Click &apos;+ Add&apos; to create one.</source>
        <translation>Keine Anbieterprofile konfiguriert.
Klicken Sie auf &apos;+ Hinzufügen&apos;, um eines zu erstellen.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1693"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1798"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1872"/>
        <source> [Default]</source>
        <translation> [Standard]</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1699"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1798"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1875"/>
        <source> (disabled)</source>
        <translation> (deaktiviert)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1736"/>
        <source>Add Provider Profile</source>
        <translation>Provider-Profil hinzufügen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1737"/>
        <source>Select a template or create custom:</source>
        <translation>Vorlage auswählen oder benutzerdefiniert erstellen:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1802"/>
        <source>Remove Profile</source>
        <translation>Profil entfernen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1803"/>
        <source>Are you sure you want to remove the profile &quot;%1&quot;?</source>
        <translation>Möchten Sie das Profil &quot;%1&quot; wirklich entfernen?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1946"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2023"/>
        <source>API key set</source>
        <translation>API-Schlüssel festgelegt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1946"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2023"/>
        <source>No API key</source>
        <translation>Kein API-Schlüssel</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="844"/>
        <source>Testing...</source>
        <translation>Wird getestet...</translation>
    </message>
    <message>
        <source>Miscellaneous</source>
        <translation type="vanished">Verschiedenes</translation>
    </message>
    <message>
        <source>Show prompt descriptions in menu</source>
        <translation type="vanished">Prompt-Beschreibungen im Menü anzeigen</translation>
    </message>
    <message>
        <source>Show prompt descriptions in tray menu (disabled by default for cleaner menu)</source>
        <translation type="vanished">Prompt-Beschreibungen im Tray-Menü anzeigen (standardmäßig deaktiviert für saubereres Menü)</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup</source>
        <translation type="vanished">Prompt-Beschreibungen im Popup anzeigen</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Prompt-Beschreibungen im Popup-Menü anzeigen (standardmäßig deaktiviert für sauberes Popup)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="267"/>
        <source>Provider Profiles</source>
        <translation>Provider-Profile</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="272"/>
        <source>Available Profiles:</source>
        <translation>Verfügbare Profile:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>+ Add</source>
        <translation>+ Hinzufügen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="277"/>
        <source>Add a new provider profile</source>
        <translation>Neues Provider-Profil hinzufügen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="281"/>
        <source>- Remove</source>
        <translation>- Entfernen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="282"/>
        <source>Remove selected profile</source>
        <translation>Ausgewähltes Profil entfernen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="286"/>
        <source>Set as Default</source>
        <translation>Als Standard festlegen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="287"/>
        <source>Set selected profile as default</source>
        <translation>Ausgewähltes Profil als Standard festlegen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="302"/>
        <source>Profile Configuration</source>
        <translation>Profilkonfiguration</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="306"/>
        <source>e.g., OpenRouter (Main)</source>
        <translation>z.B. OpenRouter (Haupt)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="308"/>
        <source>Profile Name:</source>
        <translation>Profilname:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="313"/>
        <source>Select template or enter custom URL (e.g., http://.../v1/chat/completions)</source>
        <translation>Vorlage auswählen oder benutzerdefinierte URL eingeben (z.B. http://.../v1/chat/completions)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="325"/>
        <source>Template...</source>
        <translation>Vorlage...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="331"/>
        <source>API URL:</source>
        <translation>API-URL:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="352"/>
        <source>Leave empty for local providers (e.g., Ollama)</source>
        <translation>Leer lassen für lokale Provider (z.B. Ollama)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="357"/>
        <source>http://host:port or socks5://host:port (optional)</source>
        <translation>http://host:port oder socks5://host:port (optional)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="366"/>
        <source>Proxy:</source>
        <translation>Proxy:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="369"/>
        <source>Override Global Defaults (optional, leave empty for default)</source>
        <translation>Globale Standardwerte überschreiben (optional, leer lassen für Standard)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="375"/>
        <location filename="../src/ui/settingsdialog.cpp" line="382"/>
        <source>(use global)</source>
        <translation>(global verwenden)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="389"/>
        <source>Enabled</source>
        <translation>Aktiviert</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="399"/>
        <source>Global Defaults (optional, leave empty for provider defaults)</source>
        <translation>Globale Standardwerte (optional, leer lassen für Provider-Standardwerte)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="405"/>
        <location filename="../src/ui/settingsdialog.cpp" line="415"/>
        <source>(provider default)</source>
        <translation>(Provider-Standard)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="407"/>
        <location filename="../src/ui/settingsdialog.cpp" line="417"/>
        <source>Recommended: Leave empty to let provider use its defaults</source>
        <translation>Empfohlen: Leer lassen, damit der Provider seine Standardwerte verwendet</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="426"/>
        <source>Test Model Connection</source>
        <translation>Modellverbindung testen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Hotkey</source>
        <translation>Hotkey</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="480"/>
        <source>Change Group</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="484"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1216"/>
        <source>Change Priority</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="767"/>
        <source>(custom)</source>
        <translation>(benutzerdefiniert)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="769"/>
        <source>(default)</source>
        <translation>(Standard)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="779"/>
        <source>(none)</source>
        <translation>(keiner)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="850"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1472"/>
        <source>No profile selected</source>
        <translation>Kein Profil ausgewählt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="859"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1478"/>
        <source>Profile not found</source>
        <translation>Profil nicht gefunden</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="867"/>
        <source>Invalid API URL</source>
        <translation>Ungültige API-URL</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="880"/>
        <source>Error: No API key</source>
        <translation>Fehler: Kein API-Schlüssel</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="887"/>
        <source>Error: No model selected</source>
        <translation>Fehler: Kein Modell ausgewählt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1045"/>
        <source>• %1 (references %2)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1054"/>
        <source>Delete prompt &quot;%1&quot;?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1056"/>
        <source>Delete %1 prompts?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1060"/>
        <source>

Warning: The following prompts reference the deleted prompts in their chains:
%1
These references will be cleared.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1066"/>
        <source>Delete Prompts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1136"/>
        <source>Move to Group</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1153"/>
        <source>Select new group for %1 prompts:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1217"/>
        <source>New priority for %1 prompts (0-1000):</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1328"/>
        <source>Export Selected Prompts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1333"/>
        <source>Export All Prompts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1367"/>
        <source>Failed to open file for writing: %1</source>
        <translation type="unfinished">Datei konnte nicht zum Schreiben geöffnet werden: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1374"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1380"/>
        <source>Exported %1 prompts to %2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1424"/>
        <source>Selected: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="2148"/>
        <source>Hotkey Conflict</source>
        <translation>Hotkey-Konflikt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="2149"/>
        <source>This hotkey is already in use by a prompt.

Please choose a different hotkey.</source>
        <translation>Dieser Hotkey wird bereits von einem Prompt verwendet.

Bitte wählen Sie einen anderen Hotkey.</translation>
    </message>
    <message>
        <source>Connected</source>
        <translation type="vanished">Verbunden</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="962"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1000"/>
        <source>Error</source>
        <translation>Fehler</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="963"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation>Fehler beim Hinzufügen des Prompts. Die ID existiert möglicherweise bereits.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1001"/>
        <source>Failed to update prompt.</source>
        <translation>Fehler beim Aktualisieren des Prompts.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1066"/>
        <source>Delete Prompt</source>
        <translation>Prompt löschen</translation>
    </message>
    <message>
        <source>Are you sure you want to delete this prompt?</source>
        <translation type="vanished">Möchten Sie diesen Prompt wirklich löschen?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1247"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1264"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1274"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1288"/>
        <source>Import Prompts</source>
        <translation>Prompts importieren</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1249"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1340"/>
        <source>JSON Files (*.json)</source>
        <translation>JSON-Dateien (*.json)</translation>
    </message>
    <message>
        <source>Import will be implemented in a future version.</source>
        <translation type="vanished">Import wird in einer zukünftigen Version implementiert.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1366"/>
        <source>Export Prompts</source>
        <translation>Prompts exportieren</translation>
    </message>
    <message>
        <source>Prompts exported to %1</source>
        <translation type="vanished">Prompts nach %1 exportiert</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1388"/>
        <source>Reset Prompts</source>
        <translation>Prompts zurücksetzen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1389"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation>Möchten Sie die Prompts wirklich auf Standard zurücksetzen? Alle benutzerdefinierten Prompts gehen verloren.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1435"/>
        <source>Clear History</source>
        <translation>Verlauf löschen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1436"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Möchten Sie wirklich alle Verlaufseinträge löschen? Dies kann nicht rückgängig gemacht werden.</translation>
    </message>
    <message>
        <source>Model fetching not supported for this provider</source>
        <translation type="vanished">Modell-Abruf für diesen Provider nicht unterstützt</translation>
    </message>
    <message>
        <source>Fetch not supported for this provider</source>
        <translation type="vanished">Abruf wird für diesen Anbieter nicht unterstützt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1561"/>
        <source>Fetching models...</source>
        <translation>Modelle werden abgerufen...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="927"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1572"/>
        <source>Error: %1</source>
        <translation>Fehler: %1</translation>
    </message>
    <message>
        <source>Error: LLM client not available</source>
        <translation type="vanished">Fehler: LLM-Client nicht verfugbar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="924"/>
        <source>Connection successful</source>
        <translation>Verbindung erfolgreich</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1582"/>
        <source>Error: Invalid response</source>
        <translation>Fehler: Ungültige Antwort</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1623"/>
        <source>No models found</source>
        <translation>Keine Modelle gefunden</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1655"/>
        <source>Loaded %1 models</source>
        <translation>%1 Modelle geladen</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="110"/>
        <source>OK</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="114"/>
        <source>Cancel</source>
        <translation>Abbrechen</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="59"/>
        <location filename="../src/ui/trayicon.cpp" line="257"/>
        <location filename="../src/ui/trayicon.cpp" line="368"/>
        <source>ClipLLM - LLM Clipboard Utility</source>
        <translation>ClipLLM - LLM-Zwischenablage-Dienstprogramm</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="92"/>
        <location filename="../src/ui/trayicon.cpp" line="372"/>
        <source>&amp;Settings</source>
        <translation>&amp;Einstellungen</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="96"/>
        <location filename="../src/ui/trayicon.cpp" line="375"/>
        <source>&amp;History</source>
        <translation>&amp;Verlauf</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="100"/>
        <location filename="../src/ui/trayicon.cpp" line="378"/>
        <source>&amp;About</source>
        <translation>&amp;Über</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="110"/>
        <location filename="../src/ui/trayicon.cpp" line="381"/>
        <source>&amp;Quit</source>
        <translation>&amp;Beenden</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="118"/>
        <location filename="../src/ui/trayicon.cpp" line="386"/>
        <source>&amp;Prompts</source>
        <translation>&amp;Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="140"/>
        <location filename="../src/ui/trayicon.cpp" line="148"/>
        <source>No prompts available</source>
        <translation>Keine Prompts verfügbar</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="259"/>
        <source>Hotkey: </source>
        <translation>Tastenkombination: </translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="321"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Project website:&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; ist ein plattformübergreifendes Zwischenablage-Dienstprogramm, das große Sprachmodelle (LLMs) direkt in Ihren Arbeitsablauf integriert. Wird als Systemleistendienst ausgeführt und ermöglicht es Ihnen, Zwischenablageinhalt (Text und Bilder) mit anpassbaren KI-Prompts unter Verwendung globaler Tastenkombinationen zu verarbeiten.&lt;/p&gt;&lt;p&gt;Egal ob Sie Text zusammenfassen, Inhalte übersetzen, Code umschreiben, Informationen aus Bildern extrahieren oder andere KI-gesteuerte Transformationen durchführen möchten – ClipLLM macht dies sofort mit einem einfachen Tastendruck zugänglich. Kopieren Sie Inhalt, drücken Sie Ihre Tastenkombination und erhalten Sie KI-generierte Ergebnisse in Ihrer Zwischenablage.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Projekt-Webseite:&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; ist ein plattformübergreifendes Zwischenablage-Dienstprogramm, das große Sprachmodelle (LLMs) direkt in Ihren Arbeitsablauf integriert. Wird als Systemleistendienst ausgeführt und ermöglicht es Ihnen, Zwischenablageinhalt (Text und Bilder) mit anpassbaren KI-Prompts unter Verwendung globaler Tastenkombinationen zu verarbeiten.&lt;/p&gt;&lt;p&gt;Egal ob Sie Text zusammenfassen, Inhalte übersetzen, Code umschreiben, Informationen aus Bildern extrahieren oder andere KI-gesteuerte Transformationen durchführen möchten – ClipLLM macht dies sofort mit einem einfachen Tastendruck zugänglich. Kopieren Sie Inhalt, drücken Sie Ihre Tastenkombination und erhalten Sie KI-generierte Ergebnisse in Ihrer Zwischenablage.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; ist ein plattformübergreifendes Zwischenablage-Dienstprogramm, das große Sprachmodelle (LLMs) direkt in Ihren Arbeitsablauf integriert. Wird als Systemleistendienst ausgeführt und ermöglicht es Ihnen, Zwischenablageinhalt (Text und Bilder) mit anpassbaren KI-Prompts unter Verwendung globaler Tastenkombinationen zu verarbeiten.&lt;/p&gt;&lt;p&gt;Egal ob Sie Text zusammenfassen, Inhalte übersetzen, Code umschreiben, Informationen aus Bildern extrahieren oder andere KI-gesteuerte Transformationen durchführen möchten – ClipLLM macht dies sofort mit einem einfachen Tastendruck zugänglich. Kopieren Sie Inhalt, drücken Sie Ihre Tastenkombination und erhalten Sie KI-generierte Ergebnisse in Ihrer Zwischenablage.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="343"/>
        <source>About ClipLLM</source>
        <translation>Über ClipLLM</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="92"/>
        <source>[Image: %1 bytes]</source>
        <translation>[Bild: %1 bytes]</translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="96"/>
        <location filename="../src/core/historymanager.cpp" line="108"/>
        <source>[Empty]</source>
        <translation>[Leer]</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="32"/>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation>ClipLLM - Plattformübergreifendes LLM-Zwischenablage-Dienstprogramm</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="38"/>
        <source>Start minimized to system tray</source>
        <translation>Minimiert in der Systemleiste starten</translation>
    </message>
</context>
</TS>
