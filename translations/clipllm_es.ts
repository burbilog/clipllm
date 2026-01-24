<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="es_ES">
<context>
    <name>ClipLLM::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="253"/>
        <source>System Tray</source>
        <translation>Bandeja del sistema</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="254"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation>No se pudo detectar ninguna bandeja del sistema en este sistema.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="264"/>
        <source>Welcome to ClipLLM</source>
        <translation>Bienvenido a ClipLLM</translation>
    </message>
    <message>
        <source>ClipLLM is running in the system tray. Press the global hotkey to start.</source>
        <translation type="vanished">ClipLLM se está ejecutando en la bandeja del sistema. Presione el atajo global para comenzar.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="265"/>
        <source>ClipLLM is running in the system tray. Click the tray icon or configure a hotkey in settings.</source>
        <translation>ClipLLM se ejecuta en la bandeja del sistema. Haga clic en el icono o configure un atajo en la configuración.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="357"/>
        <source>Hotkey Not Supported</source>
        <translation>Atajo de teclado no compatible</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="358"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation>Los atajos de teclado globales no son compatibles con esta plataforma (¿Wayland?).</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="383"/>
        <source>Hotkey Registration Failed</source>
        <translation>Error en el registro del atajo de teclado</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="384"/>
        <source>Could not register global hotkey: %1</source>
        <translation>No se pudo registrar el atajo de teclado global: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="565"/>
        <location filename="../src/core/app.cpp" line="586"/>
        <source>Clipboard Empty</source>
        <translation>Portapapeles vacío</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="566"/>
        <source>No content found in clipboard.</source>
        <translation>No se encontró contenido en el portapapeles.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="587"/>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="594"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="595"/>
        <source>Prompt not found: %1</source>
        <translation>Prompt no encontrado: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="618"/>
        <location filename="../src/core/app.cpp" line="623"/>
        <location filename="../src/core/app.cpp" line="634"/>
        <location filename="../src/core/app.cpp" line="639"/>
        <source>Provider Error</source>
        <translation>Error de proveedor</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="619"/>
        <source>No valid LLM provider configured.</source>
        <translation>No hay ningún proveedor LLM válido configurado.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="624"/>
        <location filename="../src/core/app.cpp" line="640"/>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation>No hay ningún proveedor LLM configurado. Configure uno en Configuración.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="635"/>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation>No se encontró el proveedor LLM predeterminado. Configure uno en Configuración.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="657"/>
        <source>Model Error</source>
        <translation>Error de modelo</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="658"/>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation>No hay modelo seleccionado. Seleccione un modelo en Configuración → LLM → Perfiles de proveedores.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="687"/>
        <source>Incompatible Content</source>
        <translation>Contenido incompatible</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="688"/>
        <source>This prompt requires %1 content.</source>
        <translation>Este prompt requiere contenido %1.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="721"/>
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
        <location filename="../src/core/llmclient.cpp" line="274"/>
        <source>API key is not set</source>
        <translation>Clave API no configurada</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="339"/>
        <location filename="../src/core/llmclient.cpp" line="435"/>
        <source>Connection successful</source>
        <translation>Conexión exitosa</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="372"/>
        <source>HTTP %1: Authentication required. Please check your API key.</source>
        <translation>HTTP %1: Autenticación requerida. Verifique su clave API.</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="388"/>
        <location filename="../src/core/llmclient.cpp" line="438"/>
        <source>HTTP %1: %2</source>
        <translation>HTTP %1: %2</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="483"/>
        <source>HTTP %1: </source>
        <translation>HTTP %1: </translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="518"/>
        <source>SSL error: %1</source>
        <translation>Error SSL: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::PromptManager</name>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="69"/>
        <source>Failed to open prompts file</source>
        <translation>Error al abrir el archivo de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="79"/>
        <source>Failed to parse prompts file</source>
        <translation>Error al analizar el archivo de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="262"/>
        <source>ID is required</source>
        <translation>ID requerido</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="266"/>
        <source>Name is required</source>
        <translation>Nombre requerido</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="281"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Marcador de posición no válido en la plantilla de usuario: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="291"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Marcador de posición no válido en el prompt del sistema: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="359"/>
        <source>Summary</source>
        <translation>Resumen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="360"/>
        <source>Generate a structured summary of the text</source>
        <translation>Generar un resumen estructurado del texto</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="362"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Eres un analista profesional. Crea un resumen claro y estructurado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="363"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation>Por favor, proporciona un resumen completo del siguiente texto:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="374"/>
        <source>Translate to Russian</source>
        <translation>Traducir al ruso</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="375"/>
        <source>Translate the text to Russian</source>
        <translation>Traducir el texto al ruso</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="377"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Eres un traductor profesional. Traduce el texto al ruso conservando el estilo y el significado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="378"/>
        <location filename="../src/core/promptmanager.cpp" line="393"/>
        <source>{clipboard}</source>
        <translation>{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="389"/>
        <source>Translate to English</source>
        <translation>Traducir al inglés</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="390"/>
        <source>Translate the text to English</source>
        <translation>Traducir el texto al inglés</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="392"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Eres un traductor profesional. Traduce el texto al inglés conservando el estilo y el significado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="404"/>
        <source>Explain Code</source>
        <translation>Explicar código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="405"/>
        <source>Explain what the code does</source>
        <translation>Explicar qué hace el código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="407"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Eres un programador experto. Explica el código de forma clara y concisa.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="408"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation>Explica el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="419"/>
        <source>Code Review</source>
        <translation>Revisión de código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="420"/>
        <source>Review code and suggest improvements</source>
        <translation>Revisar código y sugerir mejoras</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="422"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Eres un revisor de código. Analiza el código en busca de bugs, problemas de seguridad y sugiere mejoras.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="423"/>
        <source>Review the following code:

{clipboard}</source>
        <translation>Revisa el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="434"/>
        <source>Refactor Code</source>
        <translation>Refactorizar código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="435"/>
        <source>Suggest refactoring improvements</source>
        <translation>Sugerir mejoras de refactorización</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="437"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Eres un experto en optimización de código. Sugiere refactorización para mejorar la legibilidad, el mantenimiento y el rendimiento.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="438"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation>Refactoriza el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="449"/>
        <source>Describe Image</source>
        <translation>Describir imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="450"/>
        <source>Generate a detailed description of the image</source>
        <translation>Generar una descripción detallada de la imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="452"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Eres un analista visual. Proporciona una descripción detallada de la imagen.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="453"/>
        <source>Describe this image in detail.</source>
        <translation>Describe esta imagen en detalle.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="464"/>
        <source>Extract Text</source>
        <translation>Extraer texto</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="465"/>
        <source>Extract all text from the image</source>
        <translation>Extraer todo el texto de la imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="467"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Extrae todo el texto de la imagen preservando el formato cuando sea posible.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="468"/>
        <source>Extract all text from this image.</source>
        <translation>Extrae todo el texto de esta imagen.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::GroupsDialog</name>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="53"/>
        <source>Manage Groups</source>
        <translation>Administrar grupos</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="59"/>
        <source>Right-click to add, rename, or delete groups. Drag and drop to move groups.</source>
        <translation>Clic derecho para agregar, renombrar o eliminar grupos. Arrastrar y soltar para mover grupos.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="67"/>
        <source>Group Name</source>
        <translation>Nombre del grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="90"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="104"/>
        <source>Root</source>
        <translation>Raíz</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="198"/>
        <source>New Group...</source>
        <translation>Nuevo grupo...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="202"/>
        <source>New Subgroup...</source>
        <translation>Nuevo subgrupo...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="205"/>
        <source>Rename...</source>
        <translation>Renombrar...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="210"/>
        <source>Delete...</source>
        <translation>Eliminar...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="221"/>
        <source>New Group</source>
        <translation>Nuevo grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="222"/>
        <source>Enter group name:</source>
        <translation>Ingrese el nombre del grupo:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="232"/>
        <location filename="../src/ui/groupsdialog.cpp" line="269"/>
        <source>Duplicate Group</source>
        <translation>Grupo duplicado</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="233"/>
        <source>A group with this name already exists.</source>
        <translation>Ya existe un grupo con este nombre.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="258"/>
        <source>New Subgroup</source>
        <translation>Nuevo subgrupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="259"/>
        <source>Enter subgroup name:</source>
        <translation>Ingrese el nombre del subgrupo:</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="270"/>
        <source>A subgroup with this name already exists.</source>
        <translation>Ya existe un subgrupo con este nombre.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="309"/>
        <source>(root)</source>
        <translation>(raíz)</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="321"/>
        <source>Delete group &apos;%1&apos;?

%2 prompt(s) in this group will be moved to root.</source>
        <translation>¿Eliminar el grupo &apos;%1&apos;?

%2 prompt(s) de este grupo se moverán a la raíz.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="324"/>
        <source>Delete group &apos;%1&apos;?</source>
        <translation>¿Eliminar el grupo &apos;%1&apos;?</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="328"/>
        <source>Delete Group</source>
        <translation>Eliminar grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="372"/>
        <source>Invalid Name</source>
        <translation>Nombre inválido</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="373"/>
        <source>Group name cannot be empty.</source>
        <translation>El nombre del grupo no puede estar vacío.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="393"/>
        <source>Duplicate Name</source>
        <translation>Nombre duplicado</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="394"/>
        <source>A group with this name already exists in this location.</source>
        <translation>Ya existe un grupo con este nombre en esta ubicación.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="54"/>
        <source>ClipLLM - History</source>
        <translation>ClipLLM - Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="63"/>
        <source>Search in history...</source>
        <translation>Buscar en el historial...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="69"/>
        <source>Filters</source>
        <translation>Filtros</translation>
    </message>
    <message>
        <source>Search...</source>
        <translation type="vanished">Buscar...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="73"/>
        <location filename="../src/ui/historydialog.cpp" line="280"/>
        <source>All Models</source>
        <translation>Todos los modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="78"/>
        <location filename="../src/ui/historydialog.cpp" line="287"/>
        <source>All Prompts</source>
        <translation>Todos los prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="82"/>
        <source>Favorites only</source>
        <translation>Solo favoritos</translation>
    </message>
    <message>
        <source>Search:</source>
        <translation type="vanished">Buscar:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="100"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="102"/>
        <source>Prompt:</source>
        <translation>Prompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="105"/>
        <source>From:</source>
        <translation>De:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="107"/>
        <source>To:</source>
        <translation>Hasta:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="130"/>
        <source>Preview</source>
        <translation>Vista previa</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="133"/>
        <location filename="../src/ui/historydialog.cpp" line="137"/>
        <location filename="../src/ui/historydialog.cpp" line="586"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="137"/>
        <location filename="../src/ui/historydialog.cpp" line="586"/>
        <source>Raw</source>
        <translation>Sin formato</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="158"/>
        <source>View Details</source>
        <translation>Ver detalles</translation>
    </message>
    <message>
        <source>Copy Output</source>
        <translation type="vanished">Copiar salida</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="163"/>
        <location filename="../src/ui/historydialog.cpp" line="413"/>
        <source>Favorite</source>
        <translation>Favorito</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="168"/>
        <source>Delete</source>
        <translation>Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="173"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="177"/>
        <source>Clear All</source>
        <translation>Limpiar todo</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="181"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="197"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="198"/>
        <source>Zoom out</source>
        <translation>Reducir</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="202"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="203"/>
        <source>Zoom in</source>
        <translation>Ampliar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="228"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="229"/>
        <source>Prompt</source>
        <translation>Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="230"/>
        <source>Model</source>
        <translation>Modelo</translation>
    </message>
    <message>
        <source>Input Preview</source>
        <translation type="vanished">Vista previa de entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="231"/>
        <source>Output Preview</source>
        <translation>Vista previa de salida</translation>
    </message>
    <message>
        <source>Duration</source>
        <translation type="vanished">Duración</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="232"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="305"/>
        <source>Total entries: %1</source>
        <translation>Total de entradas: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="537"/>
        <location filename="../src/ui/historydialog.cpp" line="546"/>
        <source>Unknown</source>
        <translation>Desconocido</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="355"/>
        <source>Showing %1 entries</source>
        <translation>Mostrando %1 entradas</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="566"/>
        <source>Prompt: %1
</source>
        <translation>Prompt: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="567"/>
        <source>Model: %1
</source>
        <translation>Modelo: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="568"/>
        <source>Date: %1
</source>
        <translation>Fecha: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="569"/>
        <source>Duration: %1
</source>
        <translation>Duración: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="570"/>
        <source>Tokens: %1 input / %2 output
</source>
        <translation>Tokens: %1 entrada / %2 salida
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="574"/>
        <source>Input:
</source>
        <translation>Entrada:
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="576"/>
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
        <location filename="../src/ui/historydialog.cpp" line="413"/>
        <source>Unfavorite</source>
        <translation>Eliminar de favoritos</translation>
    </message>
    <message>
        <source>Copied to clipboard</source>
        <translation type="vanished">Copiado al portapapeles</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="429"/>
        <source>Delete Entry</source>
        <translation>Eliminar entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="430"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>¿Estás seguro de que deseas eliminar esta entrada?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="458"/>
        <source>Export History</source>
        <translation>Exportar historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="460"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="481"/>
        <source>Exported to %1</source>
        <translation>Exportado a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="483"/>
        <source>Export Failed</source>
        <translation>Error al exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="484"/>
        <source>Failed to write to file: %1</source>
        <translation>Error al escribir en el archivo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="492"/>
        <source>Clear All History</source>
        <translation>Limpiar todo el historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="493"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>¿Estás seguro de que deseas eliminar todas las entradas del historial? Esto no se puede deshacer.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="524"/>
        <source>%1 ms</source>
        <translation>%1 ms</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="526"/>
        <source>%1 s</source>
        <translation>%1 s</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="530"/>
        <source>%1m %2s</source>
        <translation>%1m %2s</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HotkeyEdit</name>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="36"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="93"/>
        <source>Press hotkey...</source>
        <translation>Presionar atajo...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="38"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="193"/>
        <source>Record</source>
        <translation>Grabar</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="45"/>
        <source>Clear</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="172"/>
        <source>Stop</source>
        <translation>Detener</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="173"/>
        <source>Press key combination...</source>
        <translation>Presionar combinación de teclas...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="205"/>
        <source>None</source>
        <translation>Ninguno</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ImageViewDialog</name>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="45"/>
        <source>Clipboard Image</source>
        <translation>Imagen del portapapeles</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="62"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Tamaño: %1 x %2 píxeles</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="72"/>
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
        <location filename="../src/ui/prompteditordialog.cpp" line="66"/>
        <source>Add Prompt</source>
        <translation>Agregar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="111"/>
        <source>Edit Prompt</source>
        <translation>Editar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="141"/>
        <source>Basic Information</source>
        <translation>Información básica</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="145"/>
        <source>e.g., custom_prompt</source>
        <translation>ej., custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="147"/>
        <source>ID:</source>
        <translation>ID:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="150"/>
        <source>e.g., My Custom Prompt</source>
        <translation>ej., Mi prompt personalizado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="152"/>
        <source>Name:</source>
        <translation>Nombre:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="155"/>
        <source>e.g., Does something useful</source>
        <translation>ej., Hace algo útil</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="156"/>
        <source>Description:</source>
        <translation>Descripción:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="159"/>
        <source>(root)</source>
        <translation>(raíz)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="180"/>
        <source>Group:</source>
        <translation>Grupo:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="185"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="188"/>
        <source>System Prompt:</source>
        <translation>Prompt del sistema:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="191"/>
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
        <location filename="../src/ui/prompteditordialog.cpp" line="206"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation>Usa {clipboard} para insertar contenido del portapapeles, {clipboard:1000} para contenido truncado, {language} para el idioma del usuario.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="214"/>
        <source>Settings</source>
        <translation>Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="218"/>
        <source>Text</source>
        <translation>Texto</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="219"/>
        <source>Image</source>
        <translation>Imagen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="220"/>
        <source>Any</source>
        <translation>Cualquiera</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="221"/>
        <source>Content Type:</source>
        <translation>Tipo de contenido:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="224"/>
        <source>Override provider and model</source>
        <translation>Anular proveedor y modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="225"/>
        <source>When checked, use specific provider and model instead of defaults</source>
        <translation>Cuando está marcado, usa un proveedor y modelo específicos en lugar de los predeterminados</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="231"/>
        <source>Select provider for this prompt</source>
        <translation>Seleccionar proveedor para este prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="240"/>
        <source>Select or enter model name</source>
        <translation>Seleccionar o ingresar nombre del modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="243"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="285"/>
        <source>Optional global hotkey to directly execute this prompt</source>
        <translation>Atajo de teclado global opcional para ejecutar directamente este prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="297"/>
        <source>Hotkey:</source>
        <translation>Atajo:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="314"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="496"/>
        <source>(Select provider first)</source>
        <translation>(seleccione proveedor primero)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="503"/>
        <source>(Provider not found)</source>
        <translation>(proveedor no encontrado)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="521"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="532"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="905"/>
        <source>(Custom model...)</source>
        <translation>(Modelo personalizado...)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="711"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="723"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="745"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="753"/>
        <source>Export Prompt</source>
        <translation>Exportar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="712"/>
        <source>Cannot export: prompt is not valid.</source>
        <translation>No se puede exportar: el prompt no es válido.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="725"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="746"/>
        <source>Failed to open file for writing: %1</source>
        <translation>Error al abrir archivo para escritura: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="754"/>
        <source>Prompt exported to %1</source>
        <translation>Prompt exportado a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="780"/>
        <source>No provider selected</source>
        <translation>No hay proveedor seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="787"/>
        <source>Provider not found</source>
        <translation>Proveedor no encontrado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="795"/>
        <source>Model fetching not supported for this provider</source>
        <translation>Obtención de modelos no soportada para este proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="850"/>
        <source>Fetching models...</source>
        <translation>Obteniendo modelos...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="869"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="882"/>
        <source>Error: Invalid response</source>
        <translation>Error: respuesta inválida</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="894"/>
        <source>No models found</source>
        <translation>No se encontraron modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="928"/>
        <source>Loaded %1 models</source>
        <translation>%1 modelos cargados</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="966"/>
        <source>Hotkey Conflict</source>
        <translation>Conflicto de atajos</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="967"/>
        <source>This hotkey is already in use by another prompt or the global hotkey.

Please choose a different hotkey.</source>
        <translation>Este atajo ya está siendo usado por otro prompt o el atajo global.

Por favor elija un atajo diferente.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="234"/>
        <source>Provider:</source>
        <translation>Proveedor:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="284"/>
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
        <location filename="../src/ui/prompteditordialog.cpp" line="254"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="257"/>
        <source>Use default temperature from settings</source>
        <translation>Usar temperatura predeterminada de la configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="265"/>
        <source>Temperature:</source>
        <translation>Temperatura:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="270"/>
        <source>Max Tokens:</source>
        <translation>Tokens máximos:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="272"/>
        <source>Enabled</source>
        <translation>Habilitado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="280"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation>Los prompts con mayor prioridad aparecen primero en el menú</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="281"/>
        <source>Priority (higher = first):</source>
        <translation>Prioridad (mayor = primero):</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="318"/>
        <source>Prompt Preview</source>
        <translation>Vista previa del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="322"/>
        <source>OK</source>
        <translation>Aceptar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="327"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
    <message>
        <source>Uses global default model</source>
        <translation type="vanished">Usa modelo global predeterminado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="550"/>
        <source>(No providers available)</source>
        <translation>(no hay proveedores disponibles)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="559"/>
        <source>(No providers configured)</source>
        <translation>(no hay proveedores configurados)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="626"/>
        <source>Name is required</source>
        <translation>Nombre requerido</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="630"/>
        <source>ID is required</source>
        <translation>ID requerido</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="645"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Marcador de posición no válido en la plantilla de usuario: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="655"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Marcador de posición no válido en el prompt del sistema: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="665"/>
        <source>ID already exists: %1</source>
        <translation>El ID ya existe: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="687"/>
        <source>Validation Error</source>
        <translation>Error de validación</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="688"/>
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
        <location filename="../src/ui/promptpreviewdialog.cpp" line="75"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de texto, pero hay una imagen en el portapapeles. La imagen será ignorada.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="84"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de imagen, pero hay texto en el portapapeles. Solo se enviará la imagen al modelo.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="87"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de imagen, pero el portapapeles está vacío o no contiene una imagen.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="181"/>
        <source>%1x%2</source>
        <translation>%1x%2</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="221"/>
        <source>Prompt Preview</source>
        <translation>Vista previa del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="233"/>
        <source>Request that will be sent to the API</source>
        <translation>Solicitud que se enviará a la API</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="246"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation>Este es el JSON exacto que se enviará a la API del LLM. El contenido del portapapeles se sustituye por el marcador {clipboard}. Haz clic en el enlace de la imagen para ver la imagen completa.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="258"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="262"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="44"/>
        <source>ClipLLM - Result</source>
        <translation>ClipLLM - Resultado</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="85"/>
        <location filename="../src/ui/resultdialog.cpp" line="236"/>
        <source>Model: -</source>
        <translation>Modelo: -</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="87"/>
        <source>Tokens: 0 / 0</source>
        <translation>Tokens: 0 / 0</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="88"/>
        <location filename="../src/ui/resultdialog.cpp" line="263"/>
        <source>Traffic: 0 B</source>
        <translation>Tráfico: 0 B</translation>
    </message>
    <message>
        <source>Settings</source>
        <translation type="obsolete">Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="105"/>
        <source>Ready</source>
        <translation>Listo</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="110"/>
        <location filename="../src/ui/resultdialog.cpp" line="114"/>
        <location filename="../src/ui/resultdialog.cpp" line="257"/>
        <location filename="../src/ui/resultdialog.cpp" line="552"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="114"/>
        <location filename="../src/ui/resultdialog.cpp" line="257"/>
        <location filename="../src/ui/resultdialog.cpp" line="552"/>
        <source>Raw</source>
        <translation>Sin formato</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="117"/>
        <location filename="../src/ui/resultdialog.cpp" line="575"/>
        <source>Show Input</source>
        <translation>Mostrar entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="132"/>
        <source>Input</source>
        <translation>Entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="142"/>
        <source>Output</source>
        <translation>Salida</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="159"/>
        <source>Copy &amp;&amp; close</source>
        <translation>Copiar y cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="164"/>
        <source>Save to History</source>
        <translation>Guardar en historial</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="169"/>
        <source>Retry</source>
        <translation>Reintentar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="174"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="179"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="180"/>
        <source>Zoom out</source>
        <translation>Reducir</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="184"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="185"/>
        <source>Zoom in</source>
        <translation>Ampliar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="211"/>
        <source>ClipLLM - %1</source>
        <translation>ClipLLM - %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="238"/>
        <location filename="../src/ui/resultdialog.cpp" line="240"/>
        <source>Model: %1</source>
        <translation>Modelo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="242"/>
        <source>Model: %1 / %2</source>
        <translation>Modelo: %1 / %2</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="264"/>
        <source>Connecting...</source>
        <translation>Conectando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="292"/>
        <source>Tokens: ~%1</source>
        <translation>Tokens: ~%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="305"/>
        <source>Completed in %1 seconds</source>
        <translation>Completado en %1 segundos</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="310"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation>Tokens: %1 entrada / %2 salida</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="333"/>
        <location filename="../src/ui/resultdialog.cpp" line="361"/>
        <source>API Error</source>
        <translation>Error de API</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="334"/>
        <location filename="../src/ui/resultdialog.cpp" line="362"/>
        <source>An error occurred while communicating with the API:

%1</source>
        <translation>Ocurrió un error al comunicarse con la API:

%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="337"/>
        <location filename="../src/ui/resultdialog.cpp" line="370"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="403"/>
        <source>Saved</source>
        <translation>Guardado</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="465"/>
        <source>Close During Generation</source>
        <translation>Cerrar durante generación</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="466"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation>Aún se está generando una respuesta. ¿Cerrar y cancelar la solicitud?</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="474"/>
        <source>Cancelling...</source>
        <translation>Cancelando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="515"/>
        <source>Model is thinking...</source>
        <translation>El modelo está pensando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="518"/>
        <source>Generating response...</source>
        <translation>Generando respuesta...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="527"/>
        <source>Traffic: %1</source>
        <translation>Tráfico: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="571"/>
        <source>Hide Input</source>
        <translation>Ocultar entrada</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="86"/>
        <source>ClipLLM - Settings</source>
        <translation>ClipLLM - Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="119"/>
        <location filename="../src/ui/settingsdialog.cpp" line="424"/>
        <source>Reset to Defaults</source>
        <translation>Restablecer valores predeterminados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="137"/>
        <source>Language</source>
        <translation>Idioma</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="144"/>
        <source>Interface Language:</source>
        <translation>Idioma de la interfaz:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="495"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="443"/>
        <source>Automatically save to history after generation</source>
        <translation>Guardar automáticamente en el historial después de la generación</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="180"/>
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
        <location filename="../src/ui/settingsdialog.cpp" line="259"/>
        <source>Select or enter model name...</source>
        <translation>Seleccionar o ingresar nombre del modelo...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="264"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="270"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
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
        <location filename="../src/ui/settingsdialog.cpp" line="299"/>
        <location filename="../src/ui/settingsdialog.cpp" line="332"/>
        <source>Temperature:</source>
        <translation>Temperatura:</translation>
    </message>
    <message>
        <source>Override temperature</source>
        <translation type="vanished">Anular temperatura</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="306"/>
        <location filename="../src/ui/settingsdialog.cpp" line="342"/>
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
        <location filename="../src/ui/settingsdialog.cpp" line="359"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="149"/>
        <source>Global Hotkey</source>
        <translation>Atajo global</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="166"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Activar procesamiento del portapapeles:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="169"/>
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
        <location filename="../src/ui/settingsdialog.cpp" line="371"/>
        <source>Name</source>
        <translation>Nombre</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="371"/>
        <source>Description</source>
        <translation>Descripción</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="371"/>
        <source>Content Type</source>
        <translation>Tipo de contenido</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="371"/>
        <source>Model</source>
        <translation>Modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="371"/>
        <source>Priority</source>
        <translation>Prioridad</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="371"/>
        <source>Group</source>
        <translation>Grupo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="388"/>
        <source>Add</source>
        <translation>Agregar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="392"/>
        <source>Edit</source>
        <translation>Editar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="397"/>
        <source>Delete</source>
        <translation>Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="402"/>
        <source>Manage Groups...</source>
        <translation>Administrar grupos...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="416"/>
        <source>Import</source>
        <translation>Importar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="420"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="434"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="446"/>
        <source>History Settings</source>
        <translation>Configuración del historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="458"/>
        <source>Unlimited</source>
        <translation>Ilimitado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="462"/>
        <source>Maximum entries:</source>
        <translation>Entradas máximas:</translation>
    </message>
    <message>
        <source>Automatically clean up old entries</source>
        <translation type="vanished">Limpiar automáticamente entradas antiguas</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Auto-cleanup by max entries</source>
        <translation>Limpieza automática por máximo de entradas</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="450"/>
        <source>Automatically remove oldest entries when limit is exceeded</source>
        <translation>Eliminar automáticamente las entradas más antiguas cuando se exceda el límite</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="464"/>
        <source>Auto-cleanup by date</source>
        <translation>Limpieza automática por fecha</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="465"/>
        <source>Automatically remove entries older than the specified number of days</source>
        <translation>Eliminar automáticamente las entradas más antiguas que el número de días especificado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="476"/>
        <source>Days to keep:</source>
        <translation>Días a mantener:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="480"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="483"/>
        <source>Clear All History</source>
        <translation>Limpiar todo el historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="605"/>
        <source>English</source>
        <translation>Inglés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="606"/>
        <source>Russian</source>
        <translation>Ruso</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="607"/>
        <source>German</source>
        <translation>Alemán</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="608"/>
        <source>French</source>
        <translation>Francés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="609"/>
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
        <location filename="../src/ui/settingsdialog.cpp" line="652"/>
        <source>(root)</source>
        <translation>(raíz)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="690"/>
        <source>Reset Settings</source>
        <translation>Restablecer configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="691"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>¿Estás seguro de que deseas restablecer toda la configuración a los valores predeterminados?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="716"/>
        <source>Language Changed</source>
        <translation>Idioma cambiado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="717"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>El idioma se cambiará después de reiniciar la aplicación.</translation>
    </message>
    <message>
        <source>Configuration valid</source>
        <translation type="vanished">Configuración válida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="951"/>
        <source>Failed to open file: %1</source>
        <translation>Error al abrir archivo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="961"/>
        <source>Failed to parse JSON file: %1</source>
        <translation>Error al analizar archivo JSON: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="975"/>
        <source>Prompts imported successfully.</source>
        <translation>Prompts importados exitosamente.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1088"/>
        <source>No API URL set</source>
        <translation>URL de API no establecida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1281"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1386"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1459"/>
        <source> [Default]</source>
        <translation> [Predeterminado]</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1287"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1386"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1462"/>
        <source> (disabled)</source>
        <translation> (deshabilitado)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1324"/>
        <source>Add Provider Profile</source>
        <translation>Agregar perfil de proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1325"/>
        <source>Select a template or create custom:</source>
        <translation>Seleccionar una plantilla o crear personalizada:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1390"/>
        <source>Remove Profile</source>
        <translation>Eliminar perfil</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1391"/>
        <source>Are you sure you want to remove the profile &quot;%1&quot;?</source>
        <translation>¿Está seguro de que desea eliminar el perfil &quot;%1&quot;?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1533"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1610"/>
        <source>API key set</source>
        <translation>Clave API configurada</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1533"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1610"/>
        <source>No API key</source>
        <translation>Sin clave API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="723"/>
        <source>Testing...</source>
        <translation>Probando...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="189"/>
        <source>Provider Profiles</source>
        <translation>Perfiles de proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="194"/>
        <source>Available Profiles:</source>
        <translation>Perfiles disponibles:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="198"/>
        <source>+ Add</source>
        <translation>+ Agregar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="199"/>
        <source>Add a new provider profile</source>
        <translation>Agregar un nuevo perfil de proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="203"/>
        <source>- Remove</source>
        <translation>- Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="204"/>
        <source>Remove selected profile</source>
        <translation>Eliminar perfil seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="208"/>
        <source>Set as Default</source>
        <translation>Establecer como predeterminado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="209"/>
        <source>Set selected profile as default</source>
        <translation>Establecer perfil seleccionado como predeterminado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="224"/>
        <source>Profile Configuration</source>
        <translation>Configuración del perfil</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="228"/>
        <source>e.g., OpenRouter (Main)</source>
        <translation>ej., OpenRouter (Principal)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="230"/>
        <source>Profile Name:</source>
        <translation>Nombre del perfil:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="235"/>
        <source>Select template or enter custom URL (e.g., http://.../v1/chat/completions)</source>
        <translation>Seleccionar plantilla o ingresar URL personalizada (ej., http://.../v1/chat/completions)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="247"/>
        <source>Template...</source>
        <translation>Plantilla...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="253"/>
        <source>API URL:</source>
        <translation>URL de API:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="274"/>
        <source>Leave empty for local providers (e.g., Ollama)</source>
        <translation>Dejar vacío para proveedores locales (ej., Ollama)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="279"/>
        <source>http://host:port or socks5://host:port (optional)</source>
        <translation>http://host:port o socks5://host:port (opcional)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="288"/>
        <source>Proxy:</source>
        <translation>Proxy:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="291"/>
        <source>Override Global Defaults (optional, leave empty for default)</source>
        <translation>Anular valores globales predeterminados (opcional, dejar vacío para usar predeterminados)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="297"/>
        <location filename="../src/ui/settingsdialog.cpp" line="304"/>
        <source>(use global)</source>
        <translation>(usar global)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="311"/>
        <source>Enabled</source>
        <translation>Habilitado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="321"/>
        <source>Global Defaults (optional, leave empty for provider defaults)</source>
        <translation>Valores globales predeterminados (opcional, dejar vacío para valores del proveedor)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="327"/>
        <location filename="../src/ui/settingsdialog.cpp" line="337"/>
        <source>(provider default)</source>
        <translation>(valor predeterminado del proveedor)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="329"/>
        <location filename="../src/ui/settingsdialog.cpp" line="339"/>
        <source>Recommended: Leave empty to let provider use its defaults</source>
        <translation>Recomendado: dejar vacío para permitir que el proveedor use sus valores predeterminados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="348"/>
        <source>Test Model Connection</source>
        <translation>Probar conexión con el modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="371"/>
        <source>Hotkey</source>
        <translation>Atajo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="658"/>
        <source>(none)</source>
        <translation>(ninguno)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="729"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1074"/>
        <source>No profile selected</source>
        <translation>No hay perfil seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="738"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1080"/>
        <source>Profile not found</source>
        <translation>Perfil no encontrado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="746"/>
        <source>Invalid API URL</source>
        <translation>URL de API inválida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="759"/>
        <source>Error: No API key</source>
        <translation>Error: Sin clave API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="766"/>
        <source>Error: No model selected</source>
        <translation>Error: Ningún modelo seleccionado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1735"/>
        <source>Hotkey Conflict</source>
        <translation>Conflicto de atajos</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1736"/>
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
        <location filename="../src/ui/settingsdialog.cpp" line="841"/>
        <location filename="../src/ui/settingsdialog.cpp" line="878"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="842"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation>Error al agregar prompt. El ID puede ya existir.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="879"/>
        <source>Failed to update prompt.</source>
        <translation>Error al actualizar prompt.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="903"/>
        <source>Delete Prompt</source>
        <translation>Eliminar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="904"/>
        <source>Are you sure you want to delete this prompt?</source>
        <translation>¿Estás seguro de que deseas eliminar este prompt?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="933"/>
        <location filename="../src/ui/settingsdialog.cpp" line="950"/>
        <location filename="../src/ui/settingsdialog.cpp" line="960"/>
        <location filename="../src/ui/settingsdialog.cpp" line="974"/>
        <source>Import Prompts</source>
        <translation>Importar prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="935"/>
        <location filename="../src/ui/settingsdialog.cpp" line="989"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <source>Import will be implemented in a future version.</source>
        <translation type="vanished">La importación se implementará en una versión futura.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="987"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1003"/>
        <source>Export Prompts</source>
        <translation>Exportar prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1004"/>
        <source>Prompts exported to %1</source>
        <translation>Prompts exportados a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1011"/>
        <source>Reset Prompts</source>
        <translation>Restablecer prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1012"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation>¿Estás seguro de que deseas restablecer los prompts a los valores predeterminados? Se perderán todos los prompts personalizados.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1037"/>
        <source>Clear History</source>
        <translation>Limpiar historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1038"/>
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
        <location filename="../src/ui/settingsdialog.cpp" line="1163"/>
        <source>Fetching models...</source>
        <translation>Obteniendo modelos...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="806"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1174"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <source>Error: LLM client not available</source>
        <translation type="vanished">Error: Cliente LLM no disponible</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="803"/>
        <source>Connection successful</source>
        <translation>Conexión exitosa</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1184"/>
        <source>Error: Invalid response</source>
        <translation>Error: Respuesta no válida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1225"/>
        <source>No models found</source>
        <translation>No se encontraron modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1257"/>
        <source>Loaded %1 models</source>
        <translation>%1 modelos cargados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="104"/>
        <source>OK</source>
        <translation>Aceptar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="108"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="57"/>
        <location filename="../src/ui/trayicon.cpp" line="261"/>
        <location filename="../src/ui/trayicon.cpp" line="371"/>
        <source>ClipLLM - LLM Clipboard Utility</source>
        <translation>ClipLLM - Utilidad de portapapeles LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="90"/>
        <location filename="../src/ui/trayicon.cpp" line="375"/>
        <source>&amp;Settings</source>
        <translation>&amp;Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="94"/>
        <location filename="../src/ui/trayicon.cpp" line="378"/>
        <source>&amp;History</source>
        <translation>&amp;Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="98"/>
        <location filename="../src/ui/trayicon.cpp" line="381"/>
        <source>&amp;About</source>
        <translation>&amp;Acerca de</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="108"/>
        <location filename="../src/ui/trayicon.cpp" line="384"/>
        <source>&amp;Quit</source>
        <translation>&amp;Salir</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="116"/>
        <location filename="../src/ui/trayicon.cpp" line="389"/>
        <source>&amp;Prompts</source>
        <translation>&amp;Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="138"/>
        <location filename="../src/ui/trayicon.cpp" line="146"/>
        <source>No prompts available</source>
        <translation>No hay prompts disponibles</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="263"/>
        <source>Hotkey: </source>
        <translation>Atajo de teclado: </translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="325"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Versión %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; es una utilidad de portapapeles multiplataforma que integra modelos de lenguaje grandes (LLM) directamente en tu flujo de trabajo. Funcionando como un servicio en la bandeja del sistema, te permite procesar contenido del portapapeles (tanto texto como imágenes) con prompts de IA personalizados usando atajos de teclado globales.&lt;/p&gt;&lt;p&gt;Ya sea que necesites resumir texto, traducir contenido, reescribir código, extraer información de imágenes o realizar cualquier otra transformación potenciada por IA, ClipLLM lo hace instantáneamente accesible con una sola pulsación de tecla. Copia contenido, presiona tu atajo y obtén resultados generados por IA de vuelta en tu portapapeles.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Versión 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; es una utilidad de portapapeles multiplataforma que integra modelos de lenguaje grandes (LLM) directamente en tu flujo de trabajo. Funcionando como un servicio en la bandeja del sistema, te permite procesar contenido del portapapeles (tanto texto como imágenes) con prompts de IA personalizados usando atajos de teclado globales.&lt;/p&gt;&lt;p&gt;Ya sea que necesites resumir texto, traducir contenido, reescribir código, extraer información de imágenes o realizar cualquier otra transformación potenciada por IA, ClipLLM lo hace instantáneamente accesible con una sola pulsación de tecla. Copia contenido, presiona tu atajo y obtén resultados generados por IA de vuelta en tu portapapeles.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="346"/>
        <source>About ClipLLM</source>
        <translation>Acerca de ClipLLM</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="89"/>
        <source>[Image: %1 bytes]</source>
        <translation>[Imagen: %1 bytes]</translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="93"/>
        <location filename="../src/core/historymanager.cpp" line="105"/>
        <source>[Empty]</source>
        <translation>[Vacío]</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="32"/>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation>ClipLLM - Utilidad de portapapeles LLM multiplataforma</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="38"/>
        <source>Start minimized to system tray</source>
        <translation>Iniciar minimizado en la bandeja del sistema</translation>
    </message>
</context>
</TS>
