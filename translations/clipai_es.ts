<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="es_ES">
<context>
    <name>ClipAI::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="211"/>
        <source>System Tray</source>
        <translation>Bandeja del sistema</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="212"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation>No se pudo detectar ninguna bandeja del sistema en este sistema.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="222"/>
        <source>Welcome to ClipAI</source>
        <translation>Bienvenido a ClipAI</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="223"/>
        <source>ClipAI is running in the system tray. Press the global hotkey to start.</source>
        <translation>ClipAI se está ejecutando en la bandeja del sistema. Presione el atajo global para comenzar.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="315"/>
        <source>Hotkey Not Supported</source>
        <translation>Atajo de teclado no compatible</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="316"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation>Los atajos de teclado globales no son compatibles con esta plataforma (¿Wayland?).</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="341"/>
        <source>Hotkey Registration Failed</source>
        <translation>Error en el registro del atajo de teclado</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="342"/>
        <source>Could not register global hotkey: %1</source>
        <translation>No se pudo registrar el atajo de teclado global: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="439"/>
        <location filename="../src/core/app.cpp" line="469"/>
        <source>Clipboard Empty</source>
        <translation>Portapapeles vacío</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="440"/>
        <location filename="../src/core/app.cpp" line="470"/>
        <source>No content found in clipboard.</source>
        <translation>No se encontró contenido en el portapapeles.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="459"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="460"/>
        <source>Prompt not found: %1</source>
        <translation>Prompt no encontrado: %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="487"/>
        <source>Incompatible Content</source>
        <translation>Contenido incompatible</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="488"/>
        <source>This prompt requires %1 content.</source>
        <translation>Este prompt requiere contenido %1.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="521"/>
        <source>[Image content]</source>
        <translation>[Contenido de imagen]</translation>
    </message>
</context>
<context>
    <name>ClipAI::Core::App</name>
    <message>
        <source>ClipAI - Cross-platform LLM clipboard utility</source>
        <translation type="vanished">ClipAI - Utilidad de portapapeles LLM multiplataforma</translation>
    </message>
    <message>
        <source>Another instance of ClipAI is already running</source>
        <translation type="vanished">Otra instancia de ClipAI ya se está ejecutando</translation>
    </message>
    <message>
        <source>Failed to initialize application</source>
        <translation type="vanished">Error al inicializar la aplicación</translation>
    </message>
</context>
<context>
    <name>ClipAI::Core::LLMClient</name>
    <message>
        <location filename="../src/core/llmclient.cpp" line="143"/>
        <source>API key is not set</source>
        <translation>Clave API no configurada</translation>
    </message>
</context>
<context>
    <name>ClipAI::Core::PromptManager</name>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="48"/>
        <source>Failed to open prompts file</source>
        <translation>Error al abrir el archivo de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="58"/>
        <source>Failed to parse prompts file</source>
        <translation>Error al analizar el archivo de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="241"/>
        <source>ID is required</source>
        <translation>ID requerido</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="245"/>
        <source>Name is required</source>
        <translation>Nombre requerido</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="260"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Marcador de posición no válido en la plantilla de usuario: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="270"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Marcador de posición no válido en el prompt del sistema: %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="308"/>
        <source>Summary</source>
        <translation>Resumen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="309"/>
        <source>Generate a structured summary of the text</source>
        <translation>Generar un resumen estructurado del texto</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="311"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Eres un analista profesional. Crea un resumen claro y estructurado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="312"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation>Por favor, proporciona un resumen completo del siguiente texto:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="323"/>
        <source>Translate to Russian</source>
        <translation>Traducir al ruso</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="324"/>
        <source>Translate the text to Russian</source>
        <translation>Traducir el texto al ruso</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="326"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Eres un traductor profesional. Traduce el texto al ruso conservando el estilo y el significado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="327"/>
        <location filename="../src/core/promptmanager.cpp" line="342"/>
        <source>{clipboard}</source>
        <translation>{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="338"/>
        <source>Translate to English</source>
        <translation>Traducir al inglés</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="339"/>
        <source>Translate the text to English</source>
        <translation>Traducir el texto al inglés</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="341"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Eres un traductor profesional. Traduce el texto al inglés conservando el estilo y el significado.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="353"/>
        <source>Explain Code</source>
        <translation>Explicar código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="354"/>
        <source>Explain what the code does</source>
        <translation>Explicar qué hace el código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="356"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Eres un programador experto. Explica el código de forma clara y concisa.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="357"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation>Explica el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="368"/>
        <source>Code Review</source>
        <translation>Revisión de código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="369"/>
        <source>Review code and suggest improvements</source>
        <translation>Revisar código y sugerir mejoras</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="371"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Eres un revisor de código. Analiza el código en busca de bugs, problemas de seguridad y sugiere mejoras.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="372"/>
        <source>Review the following code:

{clipboard}</source>
        <translation>Revisa el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="383"/>
        <source>Refactor Code</source>
        <translation>Refactorizar código</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="384"/>
        <source>Suggest refactoring improvements</source>
        <translation>Sugerir mejoras de refactorización</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="386"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Eres un experto en optimización de código. Sugiere refactorización para mejorar la legibilidad, el mantenimiento y el rendimiento.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="387"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation>Refactoriza el siguiente código:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="398"/>
        <source>Describe Image</source>
        <translation>Describir imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="399"/>
        <source>Generate a detailed description of the image</source>
        <translation>Generar una descripción detallada de la imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="401"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Eres un analista visual. Proporciona una descripción detallada de la imagen.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="402"/>
        <source>Describe this image in detail.</source>
        <translation>Describe esta imagen en detalle.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="413"/>
        <source>Extract Text</source>
        <translation>Extraer texto</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="414"/>
        <source>Extract all text from the image</source>
        <translation>Extraer todo el texto de la imagen</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="416"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Extrae todo el texto de la imagen preservando el formato cuando sea posible.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="417"/>
        <source>Extract all text from this image.</source>
        <translation>Extrae todo el texto de esta imagen.</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="30"/>
        <source>ClipAI - History</source>
        <translation>ClipAI - Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="36"/>
        <source>Filters</source>
        <translation>Filtros</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="40"/>
        <source>Search...</source>
        <translation>Buscar...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="44"/>
        <location filename="../src/ui/historydialog.cpp" line="234"/>
        <source>All Models</source>
        <translation>Todos los modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="49"/>
        <location filename="../src/ui/historydialog.cpp" line="241"/>
        <source>All Prompts</source>
        <translation>Todos los prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="53"/>
        <source>Favorites only</source>
        <translation>Solo favoritos</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="71"/>
        <source>Search:</source>
        <translation>Buscar:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="73"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="75"/>
        <source>Prompt:</source>
        <translation>Prompt:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="78"/>
        <source>From:</source>
        <translation>De:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="80"/>
        <source>To:</source>
        <translation>Hasta:</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="103"/>
        <source>Preview</source>
        <translation>Vista previa</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="106"/>
        <location filename="../src/ui/historydialog.cpp" line="110"/>
        <location filename="../src/ui/historydialog.cpp" line="548"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="110"/>
        <location filename="../src/ui/historydialog.cpp" line="548"/>
        <source>Raw</source>
        <translation>Sin formato</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="130"/>
        <source>View Details</source>
        <translation>Ver detalles</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="135"/>
        <source>Copy Output</source>
        <translation>Copiar salida</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="140"/>
        <location filename="../src/ui/historydialog.cpp" line="375"/>
        <source>Favorite</source>
        <translation>Favorito</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="145"/>
        <source>Delete</source>
        <translation>Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="150"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="154"/>
        <source>Clear All</source>
        <translation>Limpiar todo</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="158"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="178"/>
        <source>Date</source>
        <translation>Fecha</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="179"/>
        <source>Prompt</source>
        <translation>Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="180"/>
        <source>Model</source>
        <translation>Modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="181"/>
        <source>Input Preview</source>
        <translation>Vista previa de entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="182"/>
        <source>Output Preview</source>
        <translation>Vista previa de salida</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="183"/>
        <source>Duration</source>
        <translation>Duración</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="184"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="259"/>
        <source>Total entries: %1</source>
        <translation>Total de entradas: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="315"/>
        <source>Showing %1 entries</source>
        <translation>Mostrando %1 entradas</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="528"/>
        <source>Prompt: %1
</source>
        <translation>Prompt: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="529"/>
        <source>Model: %1
</source>
        <translation>Modelo: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="530"/>
        <source>Date: %1
</source>
        <translation>Fecha: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="531"/>
        <source>Duration: %1
</source>
        <translation>Duración: %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="532"/>
        <source>Tokens: %1 input / %2 output
</source>
        <translation>Tokens: %1 entrada / %2 salida
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="536"/>
        <source>Input:
</source>
        <translation>Entrada:
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="538"/>
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
        <location filename="../src/ui/historydialog.cpp" line="375"/>
        <source>Unfavorite</source>
        <translation>Eliminar de favoritos</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="392"/>
        <source>Copied to clipboard</source>
        <translation>Copiado al portapapeles</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="404"/>
        <source>Delete Entry</source>
        <translation>Eliminar entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="405"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>¿Estás seguro de que deseas eliminar esta entrada?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="433"/>
        <source>Export History</source>
        <translation>Exportar historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="435"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="456"/>
        <source>Exported to %1</source>
        <translation>Exportado a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="458"/>
        <source>Export Failed</source>
        <translation>Error al exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="459"/>
        <source>Failed to write to file: %1</source>
        <translation>Error al escribir en el archivo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="467"/>
        <source>Clear All History</source>
        <translation>Limpiar todo el historial</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="468"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>¿Estás seguro de que deseas eliminar todas las entradas del historial? Esto no se puede deshacer.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="499"/>
        <source>%1 ms</source>
        <translation>%1 ms</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="501"/>
        <source>%1 s</source>
        <translation>%1 s</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="505"/>
        <source>%1m %2s</source>
        <translation>%1m %2s</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::HotkeyEdit</name>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="20"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="77"/>
        <source>Press hotkey...</source>
        <translation>Presionar atajo...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="22"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="177"/>
        <source>Record</source>
        <translation>Grabar</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="29"/>
        <source>Clear</source>
        <translation>Limpiar</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="156"/>
        <source>Stop</source>
        <translation>Detener</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="157"/>
        <source>Press key combination...</source>
        <translation>Presionar combinación de teclas...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="189"/>
        <source>None</source>
        <translation>Ninguno</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::ImageViewDialog</name>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="22"/>
        <source>Clipboard Image</source>
        <translation>Imagen del portapapeles</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="39"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Tamaño: %1 x %2 píxeles</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="49"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptEditorDialog</name>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="24"/>
        <source>Add Prompt</source>
        <translation>Agregar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="52"/>
        <source>Edit Prompt</source>
        <translation>Editar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="76"/>
        <source>Basic Information</source>
        <translation>Información básica</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="80"/>
        <source>e.g., custom_prompt</source>
        <translation>ej., custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="82"/>
        <source>ID:</source>
        <translation>ID:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="85"/>
        <source>e.g., My Custom Prompt</source>
        <translation>ej., Mi prompt personalizado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="87"/>
        <source>Name:</source>
        <translation>Nombre:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="90"/>
        <source>e.g., Does something useful</source>
        <translation>ej., Hace algo útil</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="91"/>
        <source>Description:</source>
        <translation>Descripción:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="96"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="99"/>
        <source>System Prompt:</source>
        <translation>Prompt del sistema:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="102"/>
        <source>You are a helpful assistant...</source>
        <translation>Eres un asistente útil...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="107"/>
        <source>User Prompt Template:</source>
        <translation>Plantilla de prompt de usuario:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="110"/>
        <source>Process the following text:

{clipboard}</source>
        <translation>Procesa el siguiente texto:

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="117"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation>Usa {clipboard} para insertar contenido del portapapeles, {clipboard:1000} para contenido truncado, {language} para el idioma del usuario.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="125"/>
        <source>Settings</source>
        <translation>Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="129"/>
        <source>Text</source>
        <translation>Texto</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="130"/>
        <source>Image</source>
        <translation>Imagen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="131"/>
        <source>Any</source>
        <translation>Cualquiera</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="132"/>
        <source>Content Type:</source>
        <translation>Tipo de contenido:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="135"/>
        <source>None</source>
        <translation>Ninguno</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="136"/>
        <source>Text Summary</source>
        <translation>Resumen</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="137"/>
        <source>Translate</source>
        <translation>Traducir</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="138"/>
        <source>Code Review</source>
        <translation>Revisión de código</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="139"/>
        <source>Refactor</source>
        <translation>Refactorizar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="140"/>
        <source>Explain</source>
        <translation>Explicar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="141"/>
        <source>Custom</source>
        <translation>Personalizado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="142"/>
        <source>Icon:</source>
        <translation>Icono:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="145"/>
        <source>Use default model from settings</source>
        <translation>Usar modelo predeterminado de la configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="151"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="294"/>
        <source>e.g., openai/gpt-4, anthropic/claude-3-opus</source>
        <translation>ej., openai/gpt-4, anthropic/claude-3-opus</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="152"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="155"/>
        <source>Use default temperature from settings</source>
        <translation>Usar temperatura predeterminada de la configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="163"/>
        <source>Temperature:</source>
        <translation>Temperatura:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="168"/>
        <source>Max Tokens:</source>
        <translation>Tokens máximos:</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="170"/>
        <source>Enabled</source>
        <translation>Habilitado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="178"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation>Los prompts con mayor prioridad aparecen primero en el menú</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="179"/>
        <source>Priority (higher = first):</source>
        <translation>Prioridad (mayor = primero):</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="193"/>
        <source>Prompt Preview</source>
        <translation>Vista previa del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="197"/>
        <source>OK</source>
        <translation>Aceptar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="202"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="291"/>
        <source>Uses global default model</source>
        <translation>Usa modelo global predeterminado</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="346"/>
        <source>Name is required</source>
        <translation>Nombre requerido</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="350"/>
        <source>ID is required</source>
        <translation>ID requerido</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="365"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Marcador de posición no válido en la plantilla de usuario: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="375"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Marcador de posición no válido en el prompt del sistema: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="385"/>
        <source>ID already exists: %1</source>
        <translation>El ID ya existe: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="407"/>
        <source>Validation Error</source>
        <translation>Error de validación</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="408"/>
        <source>The prompt has validation errors:

%1</source>
        <translation>El prompt tiene errores de validación:

%1</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptMenu</name>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="36"/>
        <source>Search prompts...</source>
        <translation>Buscar prompts...</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="101"/>
        <source>No prompts available</source>
        <translation>No hay prompts disponibles</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="119"/>
        <source>No prompts available for this content type</source>
        <translation>No hay prompts disponibles para este tipo de contenido</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptPreviewDialog</name>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="51"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de texto, pero hay una imagen en el portapapeles. La imagen será ignorada.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="60"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de imagen, pero hay texto en el portapapeles. Solo se enviará la imagen al modelo.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="63"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation>⚠ Este prompt está configurado solo para contenido de imagen, pero el portapapeles está vacío o no contiene una imagen.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="157"/>
        <source>%1x%2</source>
        <translation>%1x%2</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="197"/>
        <source>Prompt Preview</source>
        <translation>Vista previa del prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="209"/>
        <source>Request that will be sent to the API</source>
        <translation>Solicitud que se enviará a la API</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="222"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation>Este es el JSON exacto que se enviará a la API del LLM. El contenido del portapapeles se sustituye por el marcador {clipboard}. Haz clic en el enlace de la imagen para ver la imagen completa.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="234"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="238"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="25"/>
        <source>ClipAI - Result</source>
        <translation>ClipAI - Resultado</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="56"/>
        <source>Model: -</source>
        <translation>Modelo: -</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="58"/>
        <source>Tokens: 0 / 0</source>
        <translation>Tokens: 0 / 0</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="59"/>
        <location filename="../src/ui/resultdialog.cpp" line="181"/>
        <source>Traffic: 0 B</source>
        <translation>Tráfico: 0 B</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="76"/>
        <source>Ready</source>
        <translation>Listo</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="81"/>
        <location filename="../src/ui/resultdialog.cpp" line="85"/>
        <location filename="../src/ui/resultdialog.cpp" line="175"/>
        <location filename="../src/ui/resultdialog.cpp" line="426"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="85"/>
        <location filename="../src/ui/resultdialog.cpp" line="175"/>
        <location filename="../src/ui/resultdialog.cpp" line="426"/>
        <source>Raw</source>
        <translation>Sin formato</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="92"/>
        <source>Input</source>
        <translation>Entrada</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="101"/>
        <source>Output</source>
        <translation>Salida</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="115"/>
        <source>Copy &amp;&amp; close</source>
        <translation>Copiar y cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="120"/>
        <source>Save to History</source>
        <translation>Guardar en historial</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="125"/>
        <source>Retry</source>
        <translation>Reintentar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="130"/>
        <source>Close</source>
        <translation>Cerrar</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="149"/>
        <source>ClipAI - %1</source>
        <translation>ClipAI - %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="161"/>
        <location filename="../src/ui/resultdialog.cpp" line="226"/>
        <source>Model: %1</source>
        <translation>Modelo: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="182"/>
        <source>Connecting...</source>
        <translation>Conectando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="210"/>
        <source>Tokens: ~%1</source>
        <translation>Tokens: ~%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="223"/>
        <source>Completed in %1 seconds</source>
        <translation>Completado en %1 segundos</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="228"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation>Tokens: %1 entrada / %2 salida</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="241"/>
        <location filename="../src/ui/resultdialog.cpp" line="256"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="287"/>
        <source>Saved</source>
        <translation>Guardado</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="339"/>
        <source>Close During Generation</source>
        <translation>Cerrar durante generación</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="340"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation>Aún se está generando una respuesta. ¿Cerrar y cancelar la solicitud?</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="348"/>
        <source>Cancelling...</source>
        <translation>Cancelando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="389"/>
        <source>Model is thinking...</source>
        <translation>El modelo está pensando...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="392"/>
        <source>Generating response...</source>
        <translation>Generando respuesta...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="401"/>
        <source>Traffic: %1</source>
        <translation>Tráfico: %1</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="56"/>
        <source>ClipAI - Settings</source>
        <translation>ClipAI - Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="82"/>
        <location filename="../src/ui/settingsdialog.cpp" line="307"/>
        <source>Reset to Defaults</source>
        <translation>Restablecer valores predeterminados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="100"/>
        <source>Language</source>
        <translation>Idioma</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="103"/>
        <source>Interface Language:</source>
        <translation>Idioma de la interfaz:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="114"/>
        <location filename="../src/ui/settingsdialog.cpp" line="365"/>
        <source>History</source>
        <translation>Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="117"/>
        <source>Automatically save to history after generation</source>
        <translation>Guardar automáticamente en el historial después de la generación</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="124"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="132"/>
        <source>LLM Provider</source>
        <translation>Proveedor LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="138"/>
        <source>Provider:</source>
        <translation>Proveedor:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="144"/>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Select or enter model name...</source>
        <translation>Seleccionar o ingresar nombre del modelo...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="145"/>
        <source>Refresh</source>
        <translation>Actualizar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="151"/>
        <source>Model:</source>
        <translation>Modelo:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="156"/>
        <source>API Key:</source>
        <translation>Clave API:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="159"/>
        <source>Custom API URL:</source>
        <translation>URL API personalizada:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="162"/>
        <source>Proxy (optional):</source>
        <translation>Proxy (opcional):</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="166"/>
        <source>Options</source>
        <translation>Opciones</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="174"/>
        <source>Temperature:</source>
        <translation>Temperatura:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="176"/>
        <source>Override temperature</source>
        <translation>Anular temperatura</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="187"/>
        <source>Max Tokens:</source>
        <translation>Tokens máximos:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="189"/>
        <source>Enable streaming responses</source>
        <translation>Habilitar respuestas en streaming</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="197"/>
        <source>Test Connection</source>
        <translation>Probar conexión</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="208"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="216"/>
        <source>Global Hotkey</source>
        <translation>Atajo global</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="223"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Activar procesamiento del portapapeles:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="226"/>
        <source>&lt;b&gt;Note:&lt;/b&gt; Global hotkeys may not work on Wayland. On X11, the hotkey works globally. On Windows and macOS, global hotkeys are fully supported.</source>
        <translation>&lt;b&gt;Nota:&lt;/b&gt; Los atajos de teclado globales pueden no funcionar en Wayland. En X11, el atajo funciona globalmente. En Windows y macOS, los atajos globales son totalmente compatibles.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="236"/>
        <source>Hotkeys</source>
        <translation>Atajos</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="245"/>
        <source>Menu Settings</source>
        <translation>Configuración del menú</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="251"/>
        <source>Maximum number of prompts to show in the menu</source>
        <translation>Número máximo de prompts para mostrar en el menú</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="252"/>
        <source>Max Prompts in Menu:</source>
        <translation>Máx. prompts en el menú:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Name</source>
        <translation>Nombre</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Description</source>
        <translation>Descripción</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Content Type</source>
        <translation>Tipo de contenido</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Model</source>
        <translation>Modelo</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Priority</source>
        <translation>Prioridad</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="275"/>
        <source>Add</source>
        <translation>Agregar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="279"/>
        <source>Edit</source>
        <translation>Editar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="284"/>
        <source>Delete</source>
        <translation>Eliminar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="299"/>
        <source>Import</source>
        <translation>Importar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="303"/>
        <source>Export</source>
        <translation>Exportar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="317"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="325"/>
        <source>History Settings</source>
        <translation>Configuración del historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="331"/>
        <source>Unlimited</source>
        <translation>Ilimitado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="334"/>
        <source>Maximum entries:</source>
        <translation>Entradas máximas:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="336"/>
        <source>Automatically clean up old entries</source>
        <translation>Limpiar automáticamente entradas antiguas</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="346"/>
        <source>Days to keep:</source>
        <translation>Días a mantener:</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="350"/>
        <source>Actions</source>
        <translation>Acciones</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="353"/>
        <source>Clear All History</source>
        <translation>Limpiar todo el historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="489"/>
        <source>English</source>
        <translation>Inglés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="490"/>
        <source>Russian</source>
        <translation>Ruso</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="491"/>
        <source>German</source>
        <translation>Alemán</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="492"/>
        <source>French</source>
        <translation>Francés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="493"/>
        <source>Spanish</source>
        <translation>Español</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="500"/>
        <source>OpenRouter</source>
        <translation>OpenRouter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="501"/>
        <source>OpenAI</source>
        <translation>OpenAI</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="502"/>
        <source>Anthropic</source>
        <translation>Anthropic</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="503"/>
        <source>Custom</source>
        <translation>Personalizado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="605"/>
        <source>Reset Settings</source>
        <translation>Restablecer configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="606"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>¿Estás seguro de que deseas restablecer toda la configuración a los valores predeterminados?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="631"/>
        <source>Language Changed</source>
        <translation>Idioma cambiado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="632"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>El idioma se cambiará después de reiniciar la aplicación.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="658"/>
        <source>API key set</source>
        <translation>Clave API configurada</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="658"/>
        <source>No API key</source>
        <translation>Sin clave API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="664"/>
        <source>Testing...</source>
        <translation>Probando...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="668"/>
        <source>Error: No API key</source>
        <translation>Error: Sin clave API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="673"/>
        <source>Connected</source>
        <translation>Conectado</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="696"/>
        <location filename="../src/ui/settingsdialog.cpp" line="732"/>
        <source>Error</source>
        <translation>Error</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="697"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation>Error al agregar prompt. El ID puede ya existir.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="733"/>
        <source>Failed to update prompt.</source>
        <translation>Error al actualizar prompt.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="757"/>
        <source>Delete Prompt</source>
        <translation>Eliminar prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="758"/>
        <source>Are you sure you want to delete this prompt?</source>
        <translation>¿Estás seguro de que deseas eliminar este prompt?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="772"/>
        <location filename="../src/ui/settingsdialog.cpp" line="787"/>
        <source>Import Prompts</source>
        <translation>Importar prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="774"/>
        <location filename="../src/ui/settingsdialog.cpp" line="797"/>
        <source>JSON Files (*.json)</source>
        <translation>Archivos JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="788"/>
        <source>Import will be implemented in a future version.</source>
        <translation>La importación se implementará en una versión futura.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="795"/>
        <location filename="../src/ui/settingsdialog.cpp" line="811"/>
        <source>Export Prompts</source>
        <translation>Exportar prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="812"/>
        <source>Prompts exported to %1</source>
        <translation>Prompts exportados a %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="819"/>
        <source>Reset Prompts</source>
        <translation>Restablecer prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="820"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation>¿Estás seguro de que deseas restablecer los prompts a los valores predeterminados? Se perderán todos los prompts personalizados.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="845"/>
        <source>Clear History</source>
        <translation>Limpiar historial</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="846"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>¿Estás seguro de que deseas eliminar todas las entradas del historial? Esto no se puede deshacer.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="902"/>
        <source>Fetch not supported for this provider</source>
        <translation>Obtener modelos no compatible con este proveedor</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="912"/>
        <source>Fetching models...</source>
        <translation>Obteniendo modelos...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="923"/>
        <source>Error: %1</source>
        <translation>Error: %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="933"/>
        <source>Error: Invalid response</source>
        <translation>Error: Respuesta no válida</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="968"/>
        <source>No models found</source>
        <translation>No se encontraron modelos</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="997"/>
        <source>Loaded %1 models</source>
        <translation>%1 modelos cargados</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="75"/>
        <source>OK</source>
        <translation>Aceptar</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="79"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="38"/>
        <location filename="../src/ui/trayicon.cpp" line="157"/>
        <location filename="../src/ui/trayicon.cpp" line="263"/>
        <source>ClipAI - LLM Clipboard Utility</source>
        <translation>ClipAI - Utilidad de portapapeles LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="69"/>
        <location filename="../src/ui/trayicon.cpp" line="267"/>
        <source>&amp;Settings</source>
        <translation>&amp;Configuración</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="73"/>
        <location filename="../src/ui/trayicon.cpp" line="270"/>
        <source>&amp;History</source>
        <translation>&amp;Historial</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="77"/>
        <location filename="../src/ui/trayicon.cpp" line="273"/>
        <source>&amp;About</source>
        <translation>&amp;Acerca de</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="87"/>
        <location filename="../src/ui/trayicon.cpp" line="276"/>
        <source>&amp;Quit</source>
        <translation>&amp;Salir</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="95"/>
        <location filename="../src/ui/trayicon.cpp" line="281"/>
        <source>&amp;Prompts</source>
        <translation>&amp;Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="117"/>
        <location filename="../src/ui/trayicon.cpp" line="125"/>
        <source>No prompts available</source>
        <translation>No hay prompts disponibles</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="159"/>
        <source>Hotkey: </source>
        <translation>Atajo de teclado: </translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="221"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipAI&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipAI&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipAI makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipAI&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Versión 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipAI&lt;/b&gt; es una utilidad de portapapeles multiplataforma que integra modelos de lenguaje grandes (LLM) directamente en tu flujo de trabajo. Funcionando como un servicio en la bandeja del sistema, te permite procesar contenido del portapapeles (tanto texto como imágenes) con prompts de IA personalizados usando atajos de teclado globales.&lt;/p&gt;&lt;p&gt;Ya sea que necesites resumir texto, traducir contenido, reescribir código, extraer información de imágenes o realizar cualquier otra transformación potenciada por IA, ClipAI lo hace instantáneamente accesible con una sola pulsación de tecla. Copia contenido, presiona tu atajo y obtén resultados generados por IA de vuelta en tu portapapeles.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="242"/>
        <source>About ClipAI</source>
        <translation>Acerca de ClipAI</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="71"/>
        <source>[Image: %1 bytes]</source>
        <translation>[Imagen: %1 bytes]</translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="75"/>
        <location filename="../src/core/historymanager.cpp" line="87"/>
        <source>[Empty]</source>
        <translation>[Vacío]</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="16"/>
        <source>ClipAI - Cross-platform LLM clipboard utility</source>
        <translation>ClipAI - Utilidad de portapapeles LLM multiplataforma</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="22"/>
        <source>Start minimized to system tray</source>
        <translation>Iniciar minimizado en la bandeja del sistema</translation>
    </message>
</context>
</TS>
