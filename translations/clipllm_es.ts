<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="es_ES">
<context>
    <name>ClipLLM</name>
    <message>
        <source>Clipboard Empty</source>
        <translation type="obsolete">Portapapeles vacío</translation>
    </message>
    <message>
        <source>No content found in clipboard.</source>
        <translation type="obsolete">No se encontró contenido en el portapapeles.</translation>
    </message>
    <message>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation type="obsolete">No se puede ejecutar el prompt: el portapapeles está vacío.

Copie texto o una imagen primero.</translation>
    </message>
    <message>
        <source>Error</source>
        <translation type="obsolete">Error</translation>
    </message>
    <message>
        <source>Prompt not found: %1</source>
        <translation type="obsolete">Prompt no encontrado: %1</translation>
    </message>
    <message>
        <source>Provider Error</source>
        <translation type="obsolete">Error de proveedor</translation>
    </message>
    <message>
        <source>No valid LLM provider configured.</source>
        <translation type="obsolete">No hay ningún proveedor LLM válido configurado.</translation>
    </message>
    <message>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation type="obsolete">No hay ningún proveedor LLM configurado. Configure uno en Configuración.</translation>
    </message>
    <message>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation type="obsolete">No se encontró el proveedor LLM predeterminado. Configure uno en Configuración.</translation>
    </message>
    <message>
        <source>Model Error</source>
        <translation type="obsolete">Error de modelo</translation>
    </message>
    <message>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation type="obsolete">No hay modelo seleccionado. Seleccione un modelo en Configuración → LLM → Perfiles de proveedores.</translation>
    </message>
    <message>
        <source>Incompatible Content</source>
        <translation type="obsolete">Contenido incompatible</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="obsolete">Este prompt requiere contenido %1.</translation>
    </message>
    <message>
        <source>[Image content]</source>
        <translation type="obsolete">[Contenido de imagen]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="266"/>
        <source>System Tray</source>
        <translation>Bandeja del sistema</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="267"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation>No se pudo detectar ninguna bandeja del sistema en este sistema.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="277"/>
        <source>Welcome to ClipLLM</source>
        <translation>Bienvenido a ClipLLM</translation>
    </message>
    <message>
        <source>ClipLLM is running in the system tray. Press the global hotkey to start.</source>
        <translation type="vanished">ClipLLM se está ejecutando en la bandeja del sistema. Presione el atajo global para comenzar.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="278"/>
        <source>ClipLLM is running in the system tray. Click the tray icon or configure a hotkey in settings.</source>
        <translation>ClipLLM se ejecuta en la bandeja del sistema. Haga clic en el icono o configure un atajo en la configuración.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="370"/>
        <source>Hotkey Not Supported</source>
        <translation>Atajo de teclado no compatible</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="371"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation>Los atajos de teclado globales no son compatibles con esta plataforma (¿Wayland?).</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="396"/>
        <source>Hotkey Registration Failed</source>
        <translation>Error en el registro del atajo de teclado</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="397"/>
        <source>Could not register global hotkey: %1</source>
        <translation>No se pudo registrar el atajo de teclado global: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="564"/>
        <source>Screenshot Failed</source>
        <translation>Captura de pantalla fallida</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="564"/>
        <source>Could not capture screen</source>
        <translation>No se pudo capturar la pantalla</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="740"/>
        <location filename="../src/core/app.cpp" line="792"/>
        <source>Clipboard Empty</source>
        <translation>Portapapeles vacío</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="741"/>
        <source>No content found in clipboard.</source>
        <translation>No se encontró contenido en el portapapeles.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="764"/>
        <source>Chain Cycle Detected</source>
        <translation>Ciclo de cadena detectado</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="765"/>
        <source>The prompt chain would create a cycle. Execution stopped.

Prompt &apos;%1&apos; was already executed in this chain.</source>
        <translation>La cadena de prompts crearía un ciclo. Ejecución detenida.

El prompt &apos;%1&apos; ya fue ejecutado en esta cadena.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="773"/>
        <source>Chain Depth Limit</source>
        <translation>Límite de profundidad de cadena</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="774"/>
        <source>Maximum chain depth (%1) reached. Execution stopped.

You can increase this limit in Settings → General → Prompt Chains.</source>
        <translation>Profundidad máxima de cadena (%1) alcanzada. Ejecución detenida.

Puede aumentar este límite en Configuración → General → Cadenas de prompts.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="793"/>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation>No se puede ejecutar el prompt: el portapapeles está vacío.

Copie texto o una imagen primero.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="808"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="809"/>
        <source>Prompt not found: %1</source>
        <translation>Prompt no encontrado: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="818"/>
        <source>Provider Error</source>
        <translation>Error de proveedor</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="1112"/>
        <source>Prompt Not Found</source>
        <translation>Prompt no encontrado</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="1113"/>
        <source>Prompt with ID &apos;%1&apos; not found.</source>
        <translation>Prompt con ID &apos;%1&apos; no encontrado.</translation>
    </message>
    <message>
        <source>No valid LLM provider configured.</source>
        <translation type="vanished">No hay ningún proveedor LLM válido configurado.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="819"/>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation>No hay ningún proveedor LLM configurado. Configure uno en Configuración.</translation>
    </message>
    <message>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation type="vanished">No se encontró el proveedor LLM predeterminado. Configure uno en Configuración.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="856"/>
        <source>This prompt requires text content.</source>
        <translation>Este prompt requiere contenido de texto.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="207"/>
        <source>No LLM Provider Configured</source>
        <translation>No hay proveedor LLM configurado</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="208"/>
        <source>No LLM provider profile has been configured.

Please add at least one provider profile in Settings to use ClipLLM.</source>
        <translation>No se ha configurado ningún perfil de proveedor LLM.

Por favor, agregue al menos un perfil de proveedor en Configuración para usar ClipLLM.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="836"/>
        <source>Model Error</source>
        <translation>Error de modelo</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="837"/>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation>No hay modelo seleccionado. Seleccione un modelo en Configuración → LLM → Perfiles de proveedores.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="855"/>
        <source>Incompatible Content</source>
        <translation>Contenido incompatible</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="vanished">Este prompt requiere contenido %1.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="881"/>
        <source>[Image content]</source>
        <translation>[Contenido de imagen]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::App</name>
    <message>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation type="vanished">ClipLLM - Utilidad de portapapeles LLM multiplataforma</translation>
    </message>
    <message>
        <source>Another instance of ClipLLM is already running</source>
        <translation type="vanished">Otra instancia de ClipLLM ya se está ejecutando</translation>
    </message>
    <message>
        <source>Failed to initialize application</source>
        <translation type="vanished">Error al inicializar la aplicación</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::LLMClient</name>
    <message>
        <location filename="../src/core/llmclient.cpp" line="290"/>
        <source>API key is not set</source>
        <translation>Clave API no configurada</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="362"/>
        <location filename="../src/core/llmclient.cpp" line="458"/>
        <source>Connection successful</source>
        <translation>Conexión exitosa</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="395"/>
        <source>HTTP %1: Authentication required. Please check your API key.</source>
        <translation>HTTP %1: Autenticación requerida. Verifique su clave API.</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="411"/>
        <location filename="../src/core/llmclient.cpp" line="461"/>
        <source>HTTP %1: %2</source>
        <translation>HTTP %1: %2</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="506"/>
        <source>HTTP %1: </source>
        <translation>HTTP %1: </translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="541"/>
        <source>SSL error: %1</source>
        <translation>Error SSL: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::PromptManager</name>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="66"/>
        <source>Failed to load default prompts</source>
        <translation>Error al cargar los prompts predeterminados</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="125"/>
        <source>Failed to open prompts file</source>
        <translation>Error al abrir el archivo de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="135"/>
        <source>Failed to parse prompts file</source>
        <translation>Error al analizar el archivo de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="354"/>
        <source>ID is required</source>
        <translation>ID requerido</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="358"/>
        <source>Name is required</source>
        <translation>Nombre requerido</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="373"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Marcador de posición no válido en la plantilla de usuario: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="383"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Marcador de posición no válido en el prompt del sistema: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="451"/>
        <source>Summary</source>
        <translation>Resumen</translation>
    </message>
    <message>
        <source>Generate a structured summary of the text</source>
        <translation type="vanished">Generar un resumen estructurado del texto</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="453"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Eres un analista profesional. Crea un resumen claro y estructurado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="454"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation>Por favor, proporciona un resumen completo del siguiente texto:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="465"/>
        <source>Translate to Russian</source>
        <translation>Traducir al ruso</translation>
    </message>
    <message>
        <source>Translate the text to Russian</source>
        <translation type="vanished">Traducir el texto al ruso</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="467"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Eres un traductor profesional. Traduce el texto al ruso conservando el estilo y el significado.</translation>
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
        <translation>Traducir al inglés</translation>
    </message>
    <message>
        <source>Translate the text to English</source>
        <translation type="vanished">Traducir el texto al inglés</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="481"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Eres un traductor profesional. Traduce el texto al inglés conservando el estilo y el significado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="493"/>
        <source>Explain Code</source>
        <translation>Explicar código</translation>
    </message>
    <message>
        <source>Explain what the code does</source>
        <translation type="vanished">Explicar qué hace el código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="495"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Eres un programador experto. Explica el código de forma clara y concisa.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="496"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation>Explica el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="507"/>
        <source>Code Review</source>
        <translation>Revisión de código</translation>
    </message>
    <message>
        <source>Review code and suggest improvements</source>
        <translation type="vanished">Revisar código y sugerir mejoras</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="509"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Eres un revisor de código. Analiza el código en busca de bugs, problemas de seguridad y sugiere mejoras.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="510"/>
        <source>Review the following code:

{clipboard}</source>
        <translation>Revisa el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="521"/>
        <source>Refactor Code</source>
        <translation>Refactorizar código</translation>
    </message>
    <message>
        <source>Suggest refactoring improvements</source>
        <translation type="vanished">Sugerir mejoras de refactorización</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="523"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Eres un experto en optimización de código. Sugiere refactorización para mejorar la legibilidad, el mantenimiento y el rendimiento.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="524"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation>Refactoriza el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="535"/>
        <source>Describe Image</source>
        <translation>Describir imagen</translation>
    </message>
    <message>
        <source>Generate a detailed description of the image</source>
        <translation type="vanished">Generar una descripción detallada de la imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="537"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Eres un analista visual. Proporciona una descripción detallada de la imagen.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="538"/>
        <source>Describe this image in detail.</source>
        <translation>Describe esta imagen en detalle.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="549"/>
        <source>Extract Text</source>
        <translation>Extraer texto</translation>
    </message>
    <message>
        <source>Extract all text from the image</source>
        <translation type="vanished">Extraer todo el texto de la imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="551"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Extrae todo el texto de la imagen preservando el formato cuando sea posible.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="552"/>
        <source>Extract all text from this image.</source>
        <translation>Extrae todo el texto de esta imagen.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::GroupsDialog</name>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="51"/>
        <source>Manage Groups</source>
        <translation>Administrar grupos</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="57"/>
        <source>Right-click to add, rename, or delete groups. Drag and drop to move groups.</source>
        <translation>Clic derecho para agregar, renombrar o eliminar grupos. Arrastrar y soltar para mover grupos.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="65"/>
        <source>Group Name</source>
        <translation>Nombre del grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="88"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="102"/>
        <source>Root</source>
        <translation>Raíz</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="196"/>
        <source>New Group...</source>
        <translation>Nuevo grupo...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="200"/>
        <source>New Subgroup...</source>
        <translation>Nuevo subgrupo...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="203"/>
        <source>Rename...</source>
        <translation>Renombrar...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="208"/>
        <source>Delete...</source>
        <translation>Eliminar...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="219"/>
        <source>New Group</source>
        <translation>Nuevo grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="220"/>
        <source>Enter group name:</source>
        <translation>Ingrese el nombre del grupo:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="230"/>
        <location filename="../src/ui/groupsdialog.cpp" line="267"/>
        <source>Duplicate Group</source>
        <translation>Grupo duplicado</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="231"/>
        <source>A group with this name already exists.</source>
        <translation>Ya existe un grupo con este nombre.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="256"/>
        <source>New Subgroup</source>
        <translation>Nuevo subgrupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="257"/>
        <source>Enter subgroup name:</source>
        <translation>Ingrese el nombre del subgrupo:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="268"/>
        <source>A subgroup with this name already exists.</source>
        <translation>Ya existe un subgrupo con este nombre.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="307"/>
        <source>(root)</source>
        <translation>(raíz)</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="319"/>
        <source>Delete group &apos;%1&apos;?

%2 prompt(s) in this group will be moved to root.</source>
        <translation>¿Eliminar el grupo &apos;%1&apos;?

%2 prompt(s) de este grupo se moverán a la raíz.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="322"/>
        <source>Delete group &apos;%1&apos;?</source>
        <translation>¿Eliminar el grupo &apos;%1&apos;?</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="326"/>
        <source>Delete Group</source>
        <translation>Eliminar grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="370"/>
        <source>Invalid Name</source>
        <translation>Nombre inválido</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="371"/>
        <source>Group name cannot be empty.</source>
        <translation>El nombre del grupo no puede estar vacío.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="391"/>
        <source>Duplicate Name</source>
        <translation>Nombre duplicado</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="392"/>
        <source>A group with this name already exists in this location.</source>
        <translation>Ya existe un grupo con este nombre en esta ubicación.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="72"/>
        <source>ClipLLM - History</source>
        <translation>ClipLLM - Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="81"/>
        <source>Search in history...</source>
        <translation>Buscar en el historial...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="87"/>
        <source>Filters</source>
        <translation>Filtros</translation>
    </message>
    <message>
        <source>Search...</source>
        <translation type="vanished">Buscar...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="91"/>
        <location filename="../src/ui/historydialog.cpp" line="327"/>
        <source>All Models</source>
        <translation>Todos los modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="96"/>
        <location filename="../src/ui/historydialog.cpp" line="334"/>
        <source>All Prompts</source>
        <translation>Todos los prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="100"/>
        <source>Favorites only</source>
        <translation>Solo favoritos</translation>
    </message>
    <message>
        <source>Search:</source>
        <translation type="vanished">Buscar:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="118"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="120"/>
        <source>Prompt:</source>
        <translation>Prompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="123"/>
        <source>From:</source>
        <translation>De:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="125"/>
        <source>To:</source>
        <translation>Hasta:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="148"/>
        <source>Preview</source>
        <translation>Vista previa</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="154"/>
        <location filename="../src/ui/historydialog.cpp" line="158"/>
        <location filename="../src/ui/historydialog.cpp" line="694"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="158"/>
        <location filename="../src/ui/historydialog.cpp" line="694"/>
        <source>Raw</source>
        <translation>Sin formato</translation>
    </message>
    <message>
        <source>View Details</source>
        <translation type="vanished">Ver detalles</translation>
    </message>
    <message>
        <source>Copy Output</source>
        <translation type="vanished">Copiar salida</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="196"/>
        <location filename="../src/ui/historydialog.cpp" line="460"/>
        <source>Favorite</source>
        <translation>Favorito</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="201"/>
        <source>Delete</source>
        <translation>Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="206"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="210"/>
        <source>Clear All</source>
        <translation>Limpiar todo</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="214"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="230"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="231"/>
        <source>Zoom out</source>
        <translation>Reducir</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="235"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="236"/>
        <source>Zoom in</source>
        <translation>Ampliar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="261"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="262"/>
        <source>Prompt</source>
        <translation>Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="263"/>
        <source>Model</source>
        <translation>Modelo</translation>
    </message>
    <message>
        <source>Input Preview</source>
        <translation type="vanished">Vista previa de entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="264"/>
        <source>Output Preview</source>
        <translation>Vista previa de salida</translation>
    </message>
    <message>
        <source>Duration</source>
        <translation type="vanished">Duración</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="265"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="352"/>
        <source>Total entries: %1</source>
        <translation>Total de entradas: %1</translation>
    </message>
    <message>
        <source>No history entries.\nEnable &apos;Automatically save to history&apos; in Settings\nor save prompts manually to populate this list.</source>
        <translation type="vanished">No hay entradas de historial.\nActive &apos;Guardar automáticamente en el historial&apos; en Configuración\no guarde prompts manualmente para llenar esta lista.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="590"/>
        <location filename="../src/ui/historydialog.cpp" line="599"/>
        <source>Unknown</source>
        <translation>Desconocido</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="402"/>
        <source>Showing %1 entries</source>
        <translation>Mostrando %1 entradas</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="162"/>
        <source>Furigana</source>
        <translation>Furigana</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="165"/>
        <source>Show furigana (reading annotations) for Japanese text</source>
        <translation>Mostrar furigana (anotaciones de lectura) para texto japonés</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="190"/>
        <source>Save as...</source>
        <translation type="unfinished">Guardar como...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="193"/>
        <source>Save output to a file</source>
        <translation type="unfinished">Guardar salida en archivo</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="297"/>
        <source>No history entries.
Enable &apos;Automatically save to history&apos; in Settings
or save prompts manually to populate this list.</source>
        <translation>Sin entradas de historial.
Active &apos;Guardar automáticamente en historial&apos; en Configuración
o guarde prompts manualmente para llenar esta lista.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="303"/>
        <source>Total entries: 0</source>
        <translation>Total de entradas: 0</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="565"/>
        <source>Saved to %1</source>
        <translation type="unfinished">Guardado en %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="619"/>
        <source>Prompt: %1
</source>
        <translation>Prompt: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="620"/>
        <source>Model: %1
</source>
        <translation>Modelo: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="621"/>
        <source>Date: %1
</source>
        <translation>Fecha: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="622"/>
        <source>Duration: %1
</source>
        <translation>Duración: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="623"/>
        <source>Tokens: %1 input / %2 output
</source>
        <translation>Tokens: %1 entrada / %2 salida
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="627"/>
        <source>Input:
</source>
        <translation>Entrada:
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="629"/>
        <source>Output:
</source>
        <translation>Salida:
</translation>
    </message>
    <message>
        <source>&lt;b&gt;Prompt:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Prompt:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Model:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Modelo:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Date:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Fecha:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Duration:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Duración:&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Tokens:&lt;/b&gt; %1 input / %2 output&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Tokens:&lt;/b&gt; %1 entrada / %2 salida&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Input:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Entrada:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Output:&lt;/b&gt;&lt;br&gt;%1</source>
        <translation type="vanished">&lt;b&gt;Salida:&lt;/b&gt;&lt;br&gt;%1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="460"/>
        <source>Unfavorite</source>
        <translation>Eliminar de favoritos</translation>
    </message>
    <message>
        <source>Copied to clipboard</source>
        <translation type="vanished">Copiado al portapapeles</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="476"/>
        <source>Delete Entry</source>
        <translation>Eliminar entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="477"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>¿Estás seguro de que deseas eliminar esta entrada?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="505"/>
        <source>Export History</source>
        <translation>Exportar historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="507"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="528"/>
        <source>Exported to %1</source>
        <translation>Exportado a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="530"/>
        <source>Export Failed</source>
        <translation>Error al exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="531"/>
        <source>Failed to write to file: %1</source>
        <translation>Error al escribir en el archivo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="539"/>
        <source>Clear All History</source>
        <translation>Limpiar todo el historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="540"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>¿Estás seguro de que deseas eliminar todas las entradas del historial? Esto no se puede deshacer.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="577"/>
        <source>%1 ms</source>
        <translation>%1 ms</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="579"/>
        <source>%1 s</source>
        <translation>%1 s</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="583"/>
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
        <translation>Presionar atajo...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="41"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="196"/>
        <source>Record</source>
        <translation>Grabar</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="48"/>
        <source>Clear</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="175"/>
        <source>Stop</source>
        <translation>Detener</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="176"/>
        <source>Press key combination...</source>
        <translation>Presionar combinación de teclas...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="208"/>
        <source>None</source>
        <translation>Ninguno</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ImageViewDialog</name>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="43"/>
        <source>Clipboard Image</source>
        <translation>Imagen del portapapeles</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="60"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Tamaño: %1 x %2 píxeles</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="70"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptConflictDialog</name>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="32"/>
        <source>Prompt Conflict</source>
        <translation>Conflicto de prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="39"/>
        <source>A prompt named &quot;%1&quot; already exists.</source>
        <translation>Ya existe un prompt llamado &quot;%1&quot;.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="47"/>
        <source>&lt;b&gt;Existing:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Existente:&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="53"/>
        <source>&lt;b&gt;New:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Nuevo:&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="60"/>
        <source>Do you want to replace it?</source>
        <translation>¿Desea reemplazarlo?</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="69"/>
        <source>Yes</source>
        <translation>Sí</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="70"/>
        <source>Yes for all</source>
        <translation>Sí a todos</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="71"/>
        <source>No</source>
        <translation>No</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="72"/>
        <source>No for all</source>
        <translation>No a todos</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="73"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptEditorDialog</name>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="72"/>
        <source>Add Prompt</source>
        <translation>Agregar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="117"/>
        <source>Edit Prompt</source>
        <translation>Editar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="219"/>
        <source>Basic Information</source>
        <translation>Información básica</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="223"/>
        <source>e.g., custom_prompt</source>
        <translation>ej., custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="236"/>
        <source>ID:</source>
        <translation>ID:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="239"/>
        <source>e.g., My Custom Prompt</source>
        <translation>ej., Mi prompt personalizado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="241"/>
        <source>Name:</source>
        <translation>Nombre:</translation>
    </message>
    <message>
        <source>e.g., Does something useful</source>
        <translation type="vanished">ej., Hace algo útil</translation>
    </message>
    <message>
        <source>Description:</source>
        <translation type="vanished">Descripción:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="245"/>
        <source>(root)</source>
        <translation>(raíz)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="266"/>
        <source>Group:</source>
        <translation>Grupo:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="210"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="189"/>
        <source>System Prompt:</source>
        <translation>Prompt del sistema:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="192"/>
        <source>You are a helpful assistant...</source>
        <translation>Eres un asistente útil...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="196"/>
        <source>User Prompt Template:</source>
        <translation>Plantilla de prompt de usuario:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="199"/>
        <source>Process the following text:

{clipboard}</source>
        <translation>Procesa el siguiente texto:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="205"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation>Usa {clipboard} para insertar contenido del portapapeles, {clipboard:1000} para contenido truncado, {language} para el idioma del usuario.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="404"/>
        <source>Settings</source>
        <translation>Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="269"/>
        <source>Text</source>
        <translation>Texto</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="270"/>
        <source>Image</source>
        <translation>Imagen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="271"/>
        <source>Any</source>
        <translation>Cualquiera</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="272"/>
        <source>Content Type:</source>
        <translation>Tipo de contenido:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="325"/>
        <source>Override provider and model</source>
        <translation>Anular proveedor y modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="326"/>
        <source>When checked, use specific provider and model instead of defaults</source>
        <translation>Cuando está marcado, usa un proveedor y modelo específicos en lugar de los predeterminados</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="332"/>
        <source>Select provider for this prompt</source>
        <translation>Seleccionar proveedor para este prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="341"/>
        <source>Select or enter model name</source>
        <translation>Seleccionar o ingresar nombre del modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="344"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="287"/>
        <source>Optional global hotkey to directly execute this prompt</source>
        <translation>Atajo de teclado global opcional para ejecutar directamente este prompt</translation>
    </message>
    <message>
        <source>Hotkey:</source>
        <translation type="vanished">Atajo:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="380"/>
        <source>Select next prompt in the chain (only text prompts available)</source>
        <translation>Seleccionar siguiente prompt en la cadena (solo prompts de texto disponibles)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="383"/>
        <source>Next Prompt:</source>
        <translation>Siguiente prompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="385"/>
        <source>Auto-continue to next prompt</source>
        <translation>Continuar automáticamente al siguiente prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="386"/>
        <source>Automatically run the next prompt after this one completes</source>
        <translation>Ejecutar automáticamente el siguiente prompt después de que este termine</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="164"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="227"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="890"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="898"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="940"/>
        <source>Rename ID</source>
        <translation>Renombrar ID</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="228"/>
        <source>Change the prompt ID</source>
        <translation>Cambiar el ID del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="299"/>
        <source>Hotkey (Clipboard):</source>
        <translation>Tecla rápida (Portapapeles):</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="304"/>
        <source>Optional global hotkey to capture screenshot and execute this prompt</source>
        <translation>Tecla rápida global opcional para capturar pantalla y ejecutar este prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="316"/>
        <source>Hotkey (Screenshot):</source>
        <translation>Tecla rápida (Captura):</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="321"/>
        <source>LLM Settings</source>
        <translation>Configuración de LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="376"/>
        <source>Chain Settings</source>
        <translation>Configuración de cadena</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="589"/>
        <source>(Select provider first)</source>
        <translation>(seleccione proveedor primero)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="596"/>
        <source>(Provider not found)</source>
        <translation>(proveedor no encontrado)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="614"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="625"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1087"/>
        <source>(Custom model...)</source>
        <translation>(Modelo personalizado...)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="782"/>
        <source>Chain Cycle Detected</source>
        <translation>Ciclo de cadena detectado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="783"/>
        <source>This prompt would create a cycle in the chain.

Please select a different &apos;Next Prompt&apos; or set it to &apos;(None)&apos;.</source>
        <translation>Este prompt crearía un ciclo en la cadena.

Por favor seleccione un &apos;Siguiente prompt&apos; diferente o establézcalo en &apos;(Ninguno)&apos;.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="818"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="830"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="852"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="860"/>
        <source>Export Prompt</source>
        <translation>Exportar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="819"/>
        <source>Cannot export: prompt is not valid.</source>
        <translation>No se puede exportar: el prompt no es válido.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="832"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="853"/>
        <source>Failed to open file for writing: %1</source>
        <translation>Error al abrir archivo para escritura: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="861"/>
        <source>Prompt exported to %1</source>
        <translation>Prompt exportado a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="875"/>
        <source>Rename Prompt ID</source>
        <translation>Cambiar nombre del ID del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="876"/>
        <source>Enter new ID for this prompt:</source>
        <translation>Ingrese el nuevo ID para este prompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="891"/>
        <source>New ID is the same as the current ID.</source>
        <translation>El nuevo ID es igual que el ID actual.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="906"/>
        <source>Rename ID - Historical Records</source>
        <translation>Cambiar nombre del ID — Registros históricos</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="907"/>
        <source>Historical records of this prompt will remain with the old ID &quot;%1&quot;.

When re-running prompts from history, they will use the old ID.

Continue with renaming?</source>
        <translation>Los registros históricos de este prompt mantendrán el ID antiguo &quot;%1&quot;.

Al volver a ejecutar prompts desde el historial, se utilizará el ID antiguo.

¿Continuar con el cambio de nombre?</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="941"/>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.

Click OK to save the changes.</source>
        <translation>El ID del prompt se ha cambiado de &quot;%1&quot; a &quot;%2&quot;.

Todas las referencias de cadena se han actualizado.

Haga clic en Aceptar para guardar los cambios.</translation>
    </message>
    <message>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.</source>
        <translation type="vanished">El ID del prompt se ha cambiado de &quot;%1&quot; a &quot;%2&quot;.

Todas las referencias de cadena se han actualizado.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="965"/>
        <source>No provider selected</source>
        <translation>No hay proveedor seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="972"/>
        <source>Provider not found</source>
        <translation>Proveedor no encontrado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="980"/>
        <source>Model fetching not supported for this provider</source>
        <translation>Obtención de modelos no soportada para este proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1035"/>
        <source>Fetching models...</source>
        <translation>Obteniendo modelos...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1051"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1064"/>
        <source>Error: Invalid response</source>
        <translation>Error: respuesta inválida</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1076"/>
        <source>No models found</source>
        <translation>No se encontraron modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1113"/>
        <source>Loaded %1 models</source>
        <translation>%1 modelos cargados</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1151"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1242"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1254"/>
        <source>Hotkey Conflict</source>
        <translation>Conflicto de atajos</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1152"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1255"/>
        <source>This hotkey is already in use by another prompt or the global hotkey.

Please choose a different hotkey.</source>
        <translation>Este atajo ya está siendo usado por otro prompt o el atajo global.

Por favor elija un atajo diferente.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1243"/>
        <source>Screenshot hotkey cannot be the same as clipboard hotkey.

Please choose a different hotkey.</source>
        <translation>El atajo de captura no puede ser igual al atajo del portapapeles.

Por favor elija un atajo diferente.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1316"/>
        <source>(None)</source>
        <translation>(Ninguno)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1346"/>
        <source> (disabled)</source>
        <translation> (deshabilitado)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1419"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1437"/>
        <source>Warning: This would create a cycle in the chain!</source>
        <translation>¡Advertencia: Esto crearía un ciclo en la cadena!</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1431"/>
        <source>Warning: Target prompt is part of an existing cycle!</source>
        <translation>¡Advertencia: El prompt objetivo es parte de un ciclo existente!</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="335"/>
        <source>Provider:</source>
        <translation>Proveedor:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="286"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="303"/>
        <source>None</source>
        <translation>Ninguno</translation>
    </message>
    <message>
        <source>Text Summary</source>
        <translation type="vanished">Resumen</translation>
    </message>
    <message>
        <source>Translate</source>
        <translation type="vanished">Traducir</translation>
    </message>
    <message>
        <source>Code Review</source>
        <translation type="vanished">Revisión de código</translation>
    </message>
    <message>
        <source>Refactor</source>
        <translation type="vanished">Refactorizar</translation>
    </message>
    <message>
        <source>Explain</source>
        <translation type="vanished">Explicar</translation>
    </message>
    <message>
        <source>Custom</source>
        <translation type="vanished">Personalizado</translation>
    </message>
    <message>
        <source>Icon:</source>
        <translation type="vanished">Icono:</translation>
    </message>
    <message>
        <source>Use default model from settings</source>
        <translation type="vanished">Usar modelo predeterminado de la configuración</translation>
    </message>
    <message>
        <source>e.g., openai/gpt-4, anthropic/claude-3-opus</source>
        <translation type="vanished">ej., openai/gpt-4, anthropic/claude-3-opus</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="355"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="358"/>
        <source>Use default temperature from settings</source>
        <translation>Usar temperatura predeterminada de la configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="366"/>
        <source>Temperature:</source>
        <translation>Temperatura:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="371"/>
        <source>Max Tokens:</source>
        <translation>Tokens máximos:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="274"/>
        <source>Enabled</source>
        <translation>Habilitado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="282"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation>Los prompts con mayor prioridad aparecen primero en el menú</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="283"/>
        <source>Priority (higher = first):</source>
        <translation>Prioridad (mayor = primero):</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="168"/>
        <source>Prompt Preview</source>
        <translation>Vista previa del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="172"/>
        <source>OK</source>
        <translation>Aceptar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="177"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
    <message>
        <source>Uses global default model</source>
        <translation type="vanished">Usa modelo global predeterminado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="643"/>
        <source>(No providers available)</source>
        <translation>(no hay proveedores disponibles)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="652"/>
        <source>(No providers configured)</source>
        <translation>(no hay proveedores configurados)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="719"/>
        <source>Name is required</source>
        <translation>Nombre requerido</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="723"/>
        <source>ID is required</source>
        <translation>ID requerido</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="738"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Marcador de posición no válido en la plantilla de usuario: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="748"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Marcador de posición no válido en el prompt del sistema: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="758"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="899"/>
        <source>ID already exists: %1</source>
        <translation>El ID ya existe: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="792"/>
        <source>Validation Error</source>
        <translation>Error de validación</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="793"/>
        <source>The prompt has validation errors:

%1</source>
        <translation>El prompt tiene errores de validación:

%1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptMenu</name>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="59"/>
        <source>Search prompts...</source>
        <translation>Buscar prompts...</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="69"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="77"/>
        <source>Settings</source>
        <translation>Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="143"/>
        <source>No prompts available</source>
        <translation>No hay prompts disponibles</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="172"/>
        <source>No prompts available for this content type</source>
        <translation>No hay prompts disponibles para este tipo de contenido</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="194"/>
        <source>No prompts found</source>
        <translation>No se encontraron prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="213"/>
        <source>Add priority to prompts to see them here</source>
        <translation>Agregue prioridad a los prompts para verlos aquí</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptPreviewDialog</name>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="73"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de texto, pero hay una imagen en el portapapeles. La imagen será ignorada.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="82"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de imagen, pero hay texto en el portapapeles. Solo se enviará la imagen al modelo.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="85"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de imagen, pero el portapapeles está vacío o no contiene una imagen.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="179"/>
        <source>%1x%2</source>
        <translation>%1x%2</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="219"/>
        <source>Prompt Preview</source>
        <translation>Vista previa del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="231"/>
        <source>Request that will be sent to the API</source>
        <translation>Solicitud que se enviará a la API</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="244"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation>Este es el JSON exacto que se enviará a la API del LLM. El contenido del portapapeles se sustituye por el marcador {clipboard}. Haz clic en el enlace de la imagen para ver la imagen completa.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="256"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="260"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="51"/>
        <source>ClipLLM - Result</source>
        <translation>ClipLLM - Resultado</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="101"/>
        <location filename="../src/ui/resultdialog.cpp" line="293"/>
        <source>Model: -</source>
        <translation>Modelo: -</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="103"/>
        <source>Tokens: 0 / 0</source>
        <translation>Tokens: 0 / 0</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="104"/>
        <location filename="../src/ui/resultdialog.cpp" line="320"/>
        <source>Traffic: 0 B</source>
        <translation>Tráfico: 0 B</translation>
    </message>
    <message>
        <source>Settings</source>
        <translation type="obsolete">Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="121"/>
        <source>Ready</source>
        <translation>Listo</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="133"/>
        <location filename="../src/ui/resultdialog.cpp" line="137"/>
        <location filename="../src/ui/resultdialog.cpp" line="314"/>
        <location filename="../src/ui/resultdialog.cpp" line="688"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="137"/>
        <location filename="../src/ui/resultdialog.cpp" line="314"/>
        <location filename="../src/ui/resultdialog.cpp" line="688"/>
        <source>Raw</source>
        <translation>Sin formato</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="140"/>
        <source>Furigana</source>
        <translation>Furigana</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="143"/>
        <source>Show furigana (reading annotations) for Japanese text</source>
        <translation>Mostrar furigana (anotaciones de lectura) para texto japonés</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="147"/>
        <location filename="../src/ui/resultdialog.cpp" line="729"/>
        <source>Show Input</source>
        <translation>Mostrar entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="163"/>
        <source>Input</source>
        <translation>Entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="173"/>
        <source>Output</source>
        <translation>Salida</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="190"/>
        <source>Copy &amp;&amp; close</source>
        <translation>Copiar y cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="195"/>
        <source>Save to History</source>
        <translation>Guardar en historial</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="200"/>
        <source>Save as...</source>
        <translation>Guardar como...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="203"/>
        <source>Save output to a file</source>
        <translation>Guardar salida en archivo</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="206"/>
        <source>Retry</source>
        <translation>Reintentar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="211"/>
        <source>Continue</source>
        <translation>Continuar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="217"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="222"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="223"/>
        <source>Zoom out</source>
        <translation>Reducir</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="227"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="228"/>
        <source>Zoom in</source>
        <translation>Ampliar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="256"/>
        <source>ClipLLM - %1</source>
        <translation>ClipLLM - %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="295"/>
        <location filename="../src/ui/resultdialog.cpp" line="297"/>
        <source>Model: %1</source>
        <translation>Modelo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="299"/>
        <source>Model: %1 / %2</source>
        <translation>Modelo: %1 / %2</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="321"/>
        <source>Connecting...</source>
        <translation>Conectando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="406"/>
        <source>Tokens: ~%1</source>
        <translation>Tokens: ~%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="419"/>
        <source>Completed in %1 seconds</source>
        <translation>Completado en %1 segundos</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="424"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation>Tokens: %1 entrada / %2 salida</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="462"/>
        <location filename="../src/ui/resultdialog.cpp" line="490"/>
        <source>API Error</source>
        <translation>Error de API</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="463"/>
        <location filename="../src/ui/resultdialog.cpp" line="491"/>
        <source>An error occurred while communicating with the API:

%1</source>
        <translation>Ocurrió un error al comunicarse con la API:

%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="466"/>
        <location filename="../src/ui/resultdialog.cpp" line="499"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="532"/>
        <source>Saved</source>
        <translation>Guardado</translation>
    </message>
    <message>
        <source>Save Output As</source>
        <translation type="vanished">Guardar salida como</translation>
    </message>
    <message>
        <source>Text Files (*.txt);;All Files (*)</source>
        <translation type="vanished">Archivos de texto (*.txt);;Todos los archivos (*)</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="542"/>
        <source>Saved to %1</source>
        <translation>Guardado en %1</translation>
    </message>
    <message>
        <source>Save Failed</source>
        <translation type="vanished">Error al guardar</translation>
    </message>
    <message>
        <source>Could not write to file:
%1</source>
        <translation type="vanished">No se pudo escribir en el archivo:
%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="601"/>
        <source>Close During Generation</source>
        <translation>Cerrar durante generación</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="602"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation>Aún se está generando una respuesta. ¿Cerrar y cancelar la solicitud?</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="610"/>
        <source>Cancelling...</source>
        <translation>Cancelando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="651"/>
        <source>Model is thinking...</source>
        <translation>El modelo está pensando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="654"/>
        <source>Generating response...</source>
        <translation>Generando respuesta...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="663"/>
        <source>Traffic: %1</source>
        <translation>Tráfico: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="725"/>
        <source>Hide Input</source>
        <translation>Ocultar entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="875"/>
        <source>Chain: %1</source>
        <translation>Cadena: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ScreenshotSelector</name>
    <message>
        <location filename="../src/ui/screenshotselector.cpp" line="39"/>
        <source>Select an area to capture
Right-click = cancel</source>
        <translation>Seleccione un área para capturar
Clic derecho = cancelar</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="93"/>
        <source>ClipLLM - Settings</source>
        <translation>ClipLLM - Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="122"/>
        <location filename="../src/ui/settingsdialog.cpp" line="525"/>
        <source>Reset to Defaults</source>
        <translation>Restablecer valores predeterminados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="140"/>
        <source>Language</source>
        <translation>Idioma</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="147"/>
        <source>Interface Language:</source>
        <translation>Idioma de la interfaz:</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the tray menu (disabled by default for cleaner menu)</source>
        <translation type="vanished">Mostrar descripciones de prompts en el menú de bandeja (desactivado por defecto para un menú más limpio)</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Mostrar descripciones de prompts en el menú emergente (desactivado por defecto para un menú más limpio)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="183"/>
        <source>Prompt Chains</source>
        <translation>Cadenas de prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="189"/>
        <source>Maximum number of prompts in a chain to prevent infinite loops</source>
        <translation>Número máximo de prompts en una cadena para evitar bucles infinitos</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="190"/>
        <source>Maximum Chain Depth:</source>
        <translation>Profundidad máxima de cadena:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="195"/>
        <source>Furigana</source>
        <translation>Furigana</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="201"/>
        <source>%</source>
        <translation>%</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="202"/>
        <source>Size of furigana text relative to base text (20-80%)</source>
        <translation>Tamaño del texto furigana relativo al texto base (20-80%)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="203"/>
        <source>Furigana Size:</source>
        <translation>Tamaño Furigana:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="208"/>
        <source>Debug</source>
        <translation>Depuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="211"/>
        <source>Record debug messages</source>
        <translation>Registrar mensajes de depuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="212"/>
        <source>Write debug information to debug.log file in the configuration directory</source>
        <translation>Escribir información de depuración en el archivo debug.log en el directorio de configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="220"/>
        <source>Normal</source>
        <translation>Normal</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="221"/>
        <source>Basic debug information</source>
        <translation>Información básica de depuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="222"/>
        <source>Trace</source>
        <translation>Traza</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="223"/>
        <source>Full request/response logging for LLM</source>
        <translation>Registro completo de solicitudes/respuestas para LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="232"/>
        <source>Debug Level:</source>
        <translation>Nivel de depuración:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="243"/>
        <source>Log file:</source>
        <translation>Archivo de registro:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="246"/>
        <source>Copy</source>
        <translation>Copiar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="596"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="544"/>
        <source>Automatically save to history after generation</source>
        <translation>Guardar automáticamente en el historial después de la generación</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="266"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <source>LLM Provider</source>
        <translation type="vanished">Proveedor LLM</translation>
    </message>
    <message>
        <source>Provider:</source>
        <translation type="vanished">Proveedor:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="345"/>
        <source>Select or enter model name...</source>
        <translation>Seleccionar o ingresar nombre del modelo...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="350"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="356"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="362"/>
        <source>API Key:</source>
        <translation>Clave API:</translation>
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
        <translation type="vanished">Solo se usa cuando el proveedor está configurado como Personalizado.

Ejemplos:
• Ollama: http://localhost:11434/v1/chat/completions
• LM Studio: http://localhost:1234/v1/chat/completions
• LocalAI: http://localhost:8080/v1/chat/completions</translation>
    </message>
    <message>
        <source>Custom API URL:</source>
        <translation type="vanished">URL API personalizada:</translation>
    </message>
    <message>
        <source>http://host:port or socks5://host:port</source>
        <translation type="vanished">http://host:port or socks5://host:port</translation>
    </message>
    <message>
        <source>Proxy (optional):</source>
        <translation type="vanished">Proxy (opcional):</translation>
    </message>
    <message>
        <source>Options</source>
        <translation type="vanished">Opciones</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="385"/>
        <location filename="../src/ui/settingsdialog.cpp" line="418"/>
        <source>Temperature:</source>
        <translation>Temperatura:</translation>
    </message>
    <message>
        <source>Override temperature</source>
        <translation type="vanished">Anular temperatura</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="392"/>
        <location filename="../src/ui/settingsdialog.cpp" line="428"/>
        <source>Max Tokens:</source>
        <translation>Tokens máximos:</translation>
    </message>
    <message>
        <source>Enable streaming responses</source>
        <translation type="vanished">Habilitar respuestas en streaming</translation>
    </message>
    <message>
        <source>Test Connection</source>
        <translation type="vanished">Probar conexión</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="445"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="152"/>
        <source>Global Hotkey</source>
        <translation>Atajo global</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="169"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Activar procesamiento del portapapeles:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="172"/>
        <source>&lt;b&gt;Note:&lt;/b&gt; Global hotkeys may not work on Wayland. On X11, the hotkey works globally. On Windows and macOS, global hotkeys are fully supported.</source>
        <translation>&lt;b&gt;Nota:&lt;/b&gt; Los atajos de teclado globales pueden no funcionar en Wayland. En X11, el atajo funciona globalmente. En Windows y macOS, los atajos globales son totalmente compatibles.</translation>
    </message>
    <message>
        <source>Hotkeys</source>
        <translation type="vanished">Atajos</translation>
    </message>
    <message>
        <source>Menu Settings</source>
        <translation type="vanished">Configuración del menú</translation>
    </message>
    <message>
        <source>Maximum number of prompts to show in the menu</source>
        <translation type="vanished">Número máximo de prompts para mostrar en el menú</translation>
    </message>
    <message>
        <source>Max Prompts in Menu:</source>
        <translation type="vanished">Máx. prompts en el menú:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="457"/>
        <source>Name</source>
        <translation>Nombre</translation>
    </message>
    <message>
        <source>Description</source>
        <translation type="vanished">Descripción</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="457"/>
        <source>Content Type</source>
        <translation>Tipo de contenido</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="457"/>
        <source>Model</source>
        <translation>Modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="457"/>
        <source>Priority</source>
        <translation>Prioridad</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="457"/>
        <source>Group</source>
        <translation>Grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="474"/>
        <source>Add</source>
        <translation>Agregar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="478"/>
        <source>Edit</source>
        <translation>Editar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="483"/>
        <source>Delete</source>
        <translation>Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="496"/>
        <source>Manage Groups...</source>
        <translation>Administrar grupos...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="517"/>
        <source>Import</source>
        <translation>Importar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="521"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="535"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="547"/>
        <source>History Settings</source>
        <translation>Configuración del historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="559"/>
        <source>Unlimited</source>
        <translation>Ilimitado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="563"/>
        <source>Maximum entries:</source>
        <translation>Entradas máximas:</translation>
    </message>
    <message>
        <source>Automatically clean up old entries</source>
        <translation type="vanished">Limpiar automáticamente entradas antiguas</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="550"/>
        <source>Auto-cleanup by max entries</source>
        <translation>Limpieza automática por máximo de entradas</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="551"/>
        <source>Automatically remove oldest entries when limit is exceeded</source>
        <translation>Eliminar automáticamente las entradas más antiguas cuando se exceda el límite</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="565"/>
        <source>Auto-cleanup by date</source>
        <translation>Limpieza automática por fecha</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="566"/>
        <source>Automatically remove entries older than the specified number of days</source>
        <translation>Eliminar automáticamente las entradas más antiguas que el número de días especificado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="577"/>
        <source>Days to keep:</source>
        <translation>Días a mantener:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="581"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="584"/>
        <source>Clear All History</source>
        <translation>Limpiar todo el historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="734"/>
        <source>English</source>
        <translation>Inglés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="735"/>
        <source>Russian</source>
        <translation>Ruso</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="736"/>
        <source>German</source>
        <translation>Alemán</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="737"/>
        <source>French</source>
        <translation>Francés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="738"/>
        <source>Spanish</source>
        <translation>Español</translation>
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
        <translation type="vanished">Personalizado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="787"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1151"/>
        <source>(root)</source>
        <translation>(raíz)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="821"/>
        <source>Reset Settings</source>
        <translation>Restablecer configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="822"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>¿Estás seguro de que deseas restablecer toda la configuración a los valores predeterminados?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="847"/>
        <source>Language Changed</source>
        <translation>Idioma cambiado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="848"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>El idioma se cambiará después de reiniciar la aplicación.</translation>
    </message>
    <message>
        <source>Configuration valid</source>
        <translation type="vanished">Configuración válida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1275"/>
        <source>Failed to open file: %1</source>
        <translation>Error al abrir archivo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1285"/>
        <source>Failed to parse JSON file: %1</source>
        <translation>Error al analizar archivo JSON: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1299"/>
        <source>Prompts imported successfully.</source>
        <translation>Prompts importados exitosamente.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1496"/>
        <source>No API URL set</source>
        <translation>URL de API no establecida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1688"/>
        <source>No provider profiles configured.
Click &apos;+ Add&apos; to create one.</source>
        <translation>No hay perfiles de proveedor configurados.
Haga clic en &apos;+ Agregar&apos; para crear uno.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1703"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1808"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1882"/>
        <source> [Default]</source>
        <translation> [Predeterminado]</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1709"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1808"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1885"/>
        <source> (disabled)</source>
        <translation> (deshabilitado)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1746"/>
        <source>Add Provider Profile</source>
        <translation>Agregar perfil de proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1747"/>
        <source>Select a template or create custom:</source>
        <translation>Seleccionar una plantilla o crear personalizada:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1812"/>
        <source>Remove Profile</source>
        <translation>Eliminar perfil</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1813"/>
        <source>Are you sure you want to remove the profile &quot;%1&quot;?</source>
        <translation>¿Está seguro de que desea eliminar el perfil &quot;%1&quot;?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1956"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2033"/>
        <source>API key set</source>
        <translation>Clave API configurada</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1956"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2033"/>
        <source>No API key</source>
        <translation>Sin clave API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="854"/>
        <source>Testing...</source>
        <translation>Probando...</translation>
    </message>
    <message>
        <source>Miscellaneous</source>
        <translation type="vanished">Varios</translation>
    </message>
    <message>
        <source>Show prompt descriptions in menu</source>
        <translation type="vanished">Mostrar descripciones de prompt en el menú</translation>
    </message>
    <message>
        <source>Show prompt descriptions in tray menu (disabled by default for cleaner menu)</source>
        <translation type="vanished">Mostrar descripciones de prompt en el menú de la barra de tareas (desactivado por defecto para un menú más limpio)</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup</source>
        <translation type="vanished">Mostrar descripciones de prompt en la ventana emergente</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Mostrar descripciones de prompt en la ventana emergente (desactivado por defecto para una ventana más limpia)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="275"/>
        <source>Provider Profiles</source>
        <translation>Perfiles de proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="280"/>
        <source>Available Profiles:</source>
        <translation>Perfiles disponibles:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="284"/>
        <source>+ Add</source>
        <translation>+ Agregar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="285"/>
        <source>Add a new provider profile</source>
        <translation>Agregar un nuevo perfil de proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="289"/>
        <source>- Remove</source>
        <translation>- Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="290"/>
        <source>Remove selected profile</source>
        <translation>Eliminar perfil seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="294"/>
        <source>Set as Default</source>
        <translation>Establecer como predeterminado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="295"/>
        <source>Set selected profile as default</source>
        <translation>Establecer perfil seleccionado como predeterminado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="310"/>
        <source>Profile Configuration</source>
        <translation>Configuración del perfil</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="314"/>
        <source>e.g., OpenRouter (Main)</source>
        <translation>ej., OpenRouter (Principal)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="316"/>
        <source>Profile Name:</source>
        <translation>Nombre del perfil:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="321"/>
        <source>Select template or enter custom URL (e.g., http://.../v1/chat/completions)</source>
        <translation>Seleccionar plantilla o ingresar URL personalizada (ej., http://.../v1/chat/completions)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="333"/>
        <source>Template...</source>
        <translation>Plantilla...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="339"/>
        <source>API URL:</source>
        <translation>URL de API:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="360"/>
        <source>Leave empty for local providers (e.g., Ollama)</source>
        <translation>Dejar vacío para proveedores locales (ej., Ollama)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="365"/>
        <source>http://host:port or socks5://host:port (optional)</source>
        <translation>http://host:port o socks5://host:port (opcional)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="374"/>
        <source>Proxy:</source>
        <translation>Proxy:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="377"/>
        <source>Override Global Defaults (optional, leave empty for default)</source>
        <translation>Anular valores globales predeterminados (opcional, dejar vacío para usar predeterminados)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="383"/>
        <location filename="../src/ui/settingsdialog.cpp" line="390"/>
        <source>(use global)</source>
        <translation>(usar global)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="397"/>
        <source>Enabled</source>
        <translation>Habilitado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="407"/>
        <source>Global Defaults (optional, leave empty for provider defaults)</source>
        <translation>Valores globales predeterminados (opcional, dejar vacío para valores del proveedor)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="413"/>
        <location filename="../src/ui/settingsdialog.cpp" line="423"/>
        <source>(provider default)</source>
        <translation>(valor predeterminado del proveedor)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="415"/>
        <location filename="../src/ui/settingsdialog.cpp" line="425"/>
        <source>Recommended: Leave empty to let provider use its defaults</source>
        <translation>Recomendado: dejar vacío para permitir que el proveedor use sus valores predeterminados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="434"/>
        <source>Test Model Connection</source>
        <translation>Probar conexión con el modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="457"/>
        <source>Hotkey</source>
        <translation>Atajo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="488"/>
        <source>Change Group</source>
        <translation>Cambiar grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="492"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1226"/>
        <source>Change Priority</source>
        <translation>Cambiar prioridad</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="781"/>
        <source>(custom)</source>
        <translation>(personalizado)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="783"/>
        <source>(default)</source>
        <translation>(predeterminado)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="793"/>
        <source>(none)</source>
        <translation>(ninguno)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="860"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1482"/>
        <source>No profile selected</source>
        <translation>No hay perfil seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="869"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1488"/>
        <source>Profile not found</source>
        <translation>Perfil no encontrado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="877"/>
        <source>Invalid API URL</source>
        <translation>URL de API inválida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="890"/>
        <source>Error: No API key</source>
        <translation>Error: Sin clave API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="897"/>
        <source>Error: No model selected</source>
        <translation>Error: Ningún modelo seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1055"/>
        <source>• %1 (references %2)</source>
        <translation>• %1 (referencia %2)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1064"/>
        <source>Delete prompt &quot;%1&quot;?</source>
        <translation>¿Eliminar prompt &quot;%1&quot;?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1066"/>
        <source>Delete %1 prompts?</source>
        <translation>¿Eliminar %1 prompts?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1070"/>
        <source>

Warning: The following prompts reference the deleted prompts in their chains:
%1
These references will be cleared.</source>
        <translation>
Advertencia: Los siguientes prompts referencian los prompts eliminados en sus cadenas:
%1
Estas referencias serán eliminadas.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1076"/>
        <source>Delete Prompts</source>
        <translation>Eliminar prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1146"/>
        <source>Move to Group</source>
        <translation>Mover a grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1163"/>
        <source>Select new group for %1 prompts:</source>
        <translation>Seleccionar nuevo grupo para %1 prompts:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1227"/>
        <source>New priority for %1 prompts (0-1000):</source>
        <translation>Nueva prioridad para %1 prompts (0-1000):</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1338"/>
        <source>Export Selected Prompts</source>
        <translation>Exportar prompts seleccionados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1343"/>
        <source>Export All Prompts</source>
        <translation>Exportar todos los prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1377"/>
        <source>Failed to open file for writing: %1</source>
        <translation>Error al abrir archivo para escritura: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1384"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1390"/>
        <source>Exported %1 prompts to %2</source>
        <translation>%1 prompts exportados a %2</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1434"/>
        <source>Selected: %1</source>
        <translation>Seleccionados: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="2151"/>
        <source>Hotkey Conflict</source>
        <translation>Conflicto de atajos</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="2152"/>
        <source>This hotkey is already in use by a prompt.

Please choose a different hotkey.</source>
        <translation>Este atajo ya está siendo usado por un prompt.

Por favor elija un atajo diferente.</translation>
    </message>
    <message>
        <source>Connected</source>
        <translation type="vanished">Conectado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="972"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1010"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="973"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation>Error al agregar prompt. El ID puede ya existir.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1011"/>
        <source>Failed to update prompt.</source>
        <translation>Error al actualizar prompt.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1076"/>
        <source>Delete Prompt</source>
        <translation>Eliminar prompt</translation>
    </message>
    <message>
        <source>Are you sure you want to delete this prompt?</source>
        <translation type="vanished">¿Estás seguro de que deseas eliminar este prompt?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1257"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1274"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1284"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1298"/>
        <source>Import Prompts</source>
        <translation>Importar prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1259"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1350"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <source>Import will be implemented in a future version.</source>
        <translation type="vanished">La importación se implementará en una versión futura.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1376"/>
        <source>Export Prompts</source>
        <translation>Exportar prompts</translation>
    </message>
    <message>
        <source>Prompts exported to %1</source>
        <translation type="vanished">Prompts exportados a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1398"/>
        <source>Reset Prompts</source>
        <translation>Restablecer prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1399"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation>¿Estás seguro de que deseas restablecer los prompts a los valores predeterminados? Se perderán todos los prompts personalizados.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1445"/>
        <source>Clear History</source>
        <translation>Limpiar historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1446"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>¿Estás seguro de que deseas eliminar todas las entradas del historial? Esto no se puede deshacer.</translation>
    </message>
    <message>
        <source>Model fetching not supported for this provider</source>
        <translation type="vanished">Obtención de modelos no soportada para este proveedor</translation>
    </message>
    <message>
        <source>Fetch not supported for this provider</source>
        <translation type="vanished">Obtener modelos no compatible con este proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1571"/>
        <source>Fetching models...</source>
        <translation>Obteniendo modelos...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="937"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1582"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <source>Error: LLM client not available</source>
        <translation type="vanished">Error: Cliente LLM no disponible</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="934"/>
        <source>Connection successful</source>
        <translation>Conexión exitosa</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1592"/>
        <source>Error: Invalid response</source>
        <translation>Error: Respuesta no válida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1633"/>
        <source>No models found</source>
        <translation>No se encontraron modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1665"/>
        <source>Loaded %1 models</source>
        <translation>%1 modelos cargados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="111"/>
        <source>OK</source>
        <translation>Aceptar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="115"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="59"/>
        <location filename="../src/ui/trayicon.cpp" line="257"/>
        <location filename="../src/ui/trayicon.cpp" line="368"/>
        <source>ClipLLM - LLM Clipboard Utility</source>
        <translation>ClipLLM - Utilidad de portapapeles LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="92"/>
        <location filename="../src/ui/trayicon.cpp" line="372"/>
        <source>&amp;Settings</source>
        <translation>&amp;Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="96"/>
        <location filename="../src/ui/trayicon.cpp" line="375"/>
        <source>&amp;History</source>
        <translation>&amp;Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="100"/>
        <location filename="../src/ui/trayicon.cpp" line="378"/>
        <source>&amp;About</source>
        <translation>&amp;Acerca de</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="110"/>
        <location filename="../src/ui/trayicon.cpp" line="381"/>
        <source>&amp;Quit</source>
        <translation>&amp;Salir</translation>
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
        <translation>No hay prompts disponibles</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="259"/>
        <source>Hotkey: </source>
        <translation>Atajo de teclado: </translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="321"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Project website:&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Versión %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; es una utilidad de portapapeles multiplataforma que integra modelos de lenguaje grandes (LLM) directamente en tu flujo de trabajo. Funcionando como un servicio en la bandeja del sistema, te permite procesar contenido del portapapeles (tanto texto como imágenes) con prompts de IA personalizados usando atajos de teclado globales.&lt;/p&gt;&lt;p&gt;Ya sea que necesites resumir texto, traducir contenido, reescribir código, extraer información de imágenes o realizar cualquier otra transformación potenciada por IA, ClipLLM lo hace instantáneamente accesible con una sola pulsación de tecla. Copia contenido, presiona tu atajo y obtén resultados generados por IA de vuelta en tu portapapeles.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Sitio web del proyecto:&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Versión %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; es una utilidad de portapapeles multiplataforma que integra modelos de lenguaje grandes (LLM) directamente en tu flujo de trabajo. Funcionando como un servicio en la bandeja del sistema, te permite procesar contenido del portapapeles (tanto texto como imágenes) con prompts de IA personalizados usando atajos de teclado globales.&lt;/p&gt;&lt;p&gt;Ya sea que necesites resumir texto, traducir contenido, reescribir código, extraer información de imágenes o realizar cualquier otra transformación potenciada por IA, ClipLLM lo hace instantáneamente accesible con una sola pulsación de tecla. Copia contenido, presiona tu atajo y obtén resultados generados por IA de vuelta en tu portapapeles.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Versión 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; es una utilidad de portapapeles multiplataforma que integra modelos de lenguaje grandes (LLM) directamente en tu flujo de trabajo. Funcionando como un servicio en la bandeja del sistema, te permite procesar contenido del portapapeles (tanto texto como imágenes) con prompts de IA personalizados usando atajos de teclado globales.&lt;/p&gt;&lt;p&gt;Ya sea que necesites resumir texto, traducir contenido, reescribir código, extraer información de imágenes o realizar cualquier otra transformación potenciada por IA, ClipLLM lo hace instantáneamente accesible con una sola pulsación de tecla. Copia contenido, presiona tu atajo y obtén resultados generados por IA de vuelta en tu portapapeles.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="343"/>
        <source>About ClipLLM</source>
        <translation>Acerca de ClipLLM</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="92"/>
        <source>[Image: %1 bytes]</source>
        <translation>[Imagen: %1 bytes]</translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="96"/>
        <location filename="../src/core/historymanager.cpp" line="108"/>
        <source>[Empty]</source>
        <translation>[Vacío]</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="55"/>
        <source>Cannot open prompts file: %1</source>
        <translation>No se puede abrir el archivo de prompts: %1</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="66"/>
        <source>Invalid JSON in prompts file: %1</source>
        <translation>JSON inválido en el archivo de prompts: %1</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="79"/>
        <source>No prompts found</source>
        <translation>No se encontraron prompts</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="113"/>
        <source>Cannot connect to ClipLLM. Is it running?</source>
        <translation>No se puede conectar a ClipLLM. ¿Se está ejecutando?</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="124"/>
        <source>No response from ClipLLM</source>
        <translation>Sin respuesta de ClipLLM</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="137"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="154"/>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation>ClipLLM - Utilidad de portapapeles LLM multiplataforma</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="160"/>
        <source>Start minimized to system tray</source>
        <translation>Iniciar minimizado en la bandeja del sistema</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="165"/>
        <source>Show prompt popup menu (requires running instance)</source>
        <translation>Mostrar menú emergente de prompts (requiere instancia en ejecución)</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="169"/>
        <source>Execute prompt by ID with clipboard content (requires running instance)</source>
        <translation>Ejecutar prompt por ID con contenido del portapapeles (requiere instancia en ejecución)</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="170"/>
        <source>prompt-id</source>
        <translation>id-prompt</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="174"/>
        <source>List available prompts with their IDs</source>
        <translation>Listar prompts disponibles con sus IDs</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="194"/>
        <source>--run requires a prompt ID</source>
        <translation>--run requiere un ID de prompt</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="201"/>
        <source>Another instance of ClipLLM is already running</source>
        <translation>Otra instancia de ClipLLM ya se está ejecutando</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="207"/>
        <source>Failed to initialize application</source>
        <translation>Error al inicializar la aplicación</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="213"/>
        <source>Failed to start IPC server - CLI commands will not work</source>
        <translation>Error al iniciar servidor IPC - los comandos CLI no funcionarán</translation>
    </message>
    <message>
        <location filename="../src/ui/uiutils.h" line="175"/>
        <source>Save As</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/uiutils.h" line="177"/>
        <source>Text Files (*.txt);;All Files (*)</source>
        <translation type="unfinished">Archivos de texto (*.txt);;Todos los archivos (*)</translation>
    </message>
    <message>
        <location filename="../src/ui/uiutils.h" line="208"/>
        <source>Save Failed</source>
        <translation type="unfinished">Error al guardar</translation>
    </message>
    <message>
        <location filename="../src/ui/uiutils.h" line="209"/>
        <source>Could not write to file:
%1</source>
        <translation type="unfinished">No se pudo escribir en el archivo:
%1</translation>
    </message>
</context>
</TS>
