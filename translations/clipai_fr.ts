<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="fr_FR">
<context>
    <name>ClipAI::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="211"/>
        <source>System Tray</source>
        <translation>Zone de notification</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="212"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="222"/>
        <source>Welcome to ClipAI</source>
        <translation>Bienvenue dans ClipAI</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="223"/>
        <source>ClipAI is running in the system tray. Press the global hotkey to start.</source>
        <translation>ClipAI fonctionne dans la zone de notification. Appuyez sur le raccourci global pour commencer.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="315"/>
        <source>Hotkey Not Supported</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="316"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="341"/>
        <source>Hotkey Registration Failed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="342"/>
        <source>Could not register global hotkey: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="439"/>
        <location filename="../src/core/app.cpp" line="469"/>
        <source>Clipboard Empty</source>
        <translation>Presse-papiers vide</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="440"/>
        <location filename="../src/core/app.cpp" line="470"/>
        <source>No content found in clipboard.</source>
        <translation>Aucun contenu trouvé dans le presse-papiers.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="459"/>
        <source>Error</source>
        <translation>Erreur</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="460"/>
        <source>Prompt not found: %1</source>
        <translation>Prompt introuvable : %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="487"/>
        <source>Incompatible Content</source>
        <translation>Contenu incompatible</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="488"/>
        <source>This prompt requires %1 content.</source>
        <translation>Ce prompt nécessite un contenu %1.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="521"/>
        <source>[Image content]</source>
        <translation>[Contenu image]</translation>
    </message>
</context>
<context>
    <name>ClipAI::Core::App</name>
    <message>
        <source>ClipAI - Cross-platform LLM clipboard utility</source>
        <translation type="vanished">ClipAI - Utilitaire de presse-papiers LLM multiplateforme</translation>
    </message>
    <message>
        <source>Another instance of ClipAI is already running</source>
        <translation type="vanished">Une autre instance de ClipAI est déjà en cours d&apos;exécution</translation>
    </message>
    <message>
        <source>Failed to initialize application</source>
        <translation type="vanished">Échec de l&apos;initialisation de l&apos;application</translation>
    </message>
</context>
<context>
    <name>ClipAI::Core::LLMClient</name>
    <message>
        <location filename="../src/core/llmclient.cpp" line="143"/>
        <source>API key is not set</source>
        <translation>Clé API non définie</translation>
    </message>
</context>
<context>
    <name>ClipAI::Core::PromptManager</name>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="48"/>
        <source>Failed to open prompts file</source>
        <translation>Échec de l&apos;ouverture du fichier de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="58"/>
        <source>Failed to parse prompts file</source>
        <translation>Échec de l&apos;analyse du fichier de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="241"/>
        <source>ID is required</source>
        <translation>ID requis</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="245"/>
        <source>Name is required</source>
        <translation>Nom requis</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="260"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Espace réservé invalide dans le modèle utilisateur : %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="270"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Espace réservé invalide dans le prompt système : %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="308"/>
        <source>Summary</source>
        <translation>Résumé</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="309"/>
        <source>Generate a structured summary of the text</source>
        <translation>Générer un résumé structuré du texte</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="311"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Vous êtes un analyste professionnel. Créez un résumé clair et structuré.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="312"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="323"/>
        <source>Translate to Russian</source>
        <translation>Traduire en russe</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="324"/>
        <source>Translate the text to Russian</source>
        <translation>Traduire le texte en russe</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="326"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Vous êtes un traducteur professionnel. Traduisez le texte en russe en conservant le style et le sens.</translation>
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
        <translation>Traduire en anglais</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="339"/>
        <source>Translate the text to English</source>
        <translation>Traduire le texte en anglais</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="341"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Vous êtes un traducteur professionnel. Traduisez le texte en anglais en conservant le style et le sens.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="353"/>
        <source>Explain Code</source>
        <translation>Expliquer le code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="354"/>
        <source>Explain what the code does</source>
        <translation>Expliquer ce que fait le code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="356"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Vous êtes un programmeur expert. Expliquez le code clairement et concisément.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="357"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="368"/>
        <source>Code Review</source>
        <translation>Revue de code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="369"/>
        <source>Review code and suggest improvements</source>
        <translation>Examiner le code et suggérer des améliorations</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="371"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Vous êtes un réviseur de code. Analysez le code pour les bugs, problèmes de sécurité et suggérez des améliorations.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="372"/>
        <source>Review the following code:

{clipboard}</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="383"/>
        <source>Refactor Code</source>
        <translation>Refactoriser le code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="384"/>
        <source>Suggest refactoring improvements</source>
        <translation>Suggérer des améliorations de refactoring</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="386"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Vous êtes un expert en optimisation de code. Suggérez un refactoring pour améliorer la lisibilité, la maintenabilité et les performances.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="387"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="398"/>
        <source>Describe Image</source>
        <translation>Décrire l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="399"/>
        <source>Generate a detailed description of the image</source>
        <translation>Générer une description détaillée de l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="401"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Vous êtes un analyste visuel. Fournissez une description détaillée de l&apos;image.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="402"/>
        <source>Describe this image in detail.</source>
        <translation>Décrivez cette image en détail.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="413"/>
        <source>Extract Text</source>
        <translation>Extraire le texte</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="414"/>
        <source>Extract all text from the image</source>
        <translation>Extraire tout le texte de l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="416"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Extrayez tout le texte de l&apos;image en préservant la mise en forme si possible.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="417"/>
        <source>Extract all text from this image.</source>
        <translation>Extrayez tout le texte de cette image.</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="30"/>
        <source>ClipAI - History</source>
        <translation>ClipAI - Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="36"/>
        <source>Filters</source>
        <translation>Filtres</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="40"/>
        <source>Search...</source>
        <translation>Rechercher...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="44"/>
        <location filename="../src/ui/historydialog.cpp" line="227"/>
        <source>All Models</source>
        <translation>Tous les modèles</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="49"/>
        <location filename="../src/ui/historydialog.cpp" line="234"/>
        <source>All Prompts</source>
        <translation>Tous les prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="53"/>
        <source>Favorites only</source>
        <translation>Favoris seulement</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="71"/>
        <source>Search:</source>
        <translation>Rechercher :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="73"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="75"/>
        <source>Prompt:</source>
        <translation>Prompt :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="78"/>
        <source>From:</source>
        <translation>De :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="80"/>
        <source>To:</source>
        <translation>À :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="103"/>
        <source>Preview</source>
        <translation>Aperçu</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="123"/>
        <source>View Details</source>
        <translation>Voir les détails</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="128"/>
        <source>Copy Output</source>
        <translation>Copier la sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="133"/>
        <location filename="../src/ui/historydialog.cpp" line="376"/>
        <source>Favorite</source>
        <translation>Favori</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="138"/>
        <source>Delete</source>
        <translation>Supprimer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="143"/>
        <source>Export</source>
        <translation>Exporter</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="147"/>
        <source>Clear All</source>
        <translation>Tout effacer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="151"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="171"/>
        <source>Date</source>
        <translation>Date</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="172"/>
        <source>Prompt</source>
        <translation>Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="173"/>
        <source>Model</source>
        <translation>Modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="174"/>
        <source>Input Preview</source>
        <translation>Aperçu de l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="175"/>
        <source>Output Preview</source>
        <translation>Aperçu de la sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="176"/>
        <source>Duration</source>
        <translation>Durée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="177"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="252"/>
        <source>Total entries: %1</source>
        <translation>Total des entrées : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="308"/>
        <source>Showing %1 entries</source>
        <translation>Affichage de %1 entrées</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="363"/>
        <source>&lt;b&gt;Prompt:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation>&lt;b&gt;Prompt :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="364"/>
        <source>&lt;b&gt;Model:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation>&lt;b&gt;Modèle :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="365"/>
        <source>&lt;b&gt;Date:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation>&lt;b&gt;Date :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="366"/>
        <source>&lt;b&gt;Duration:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation>&lt;b&gt;Durée :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="367"/>
        <source>&lt;b&gt;Tokens:&lt;/b&gt; %1 input / %2 output&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;Jetons :&lt;/b&gt; %1 entrée / %2 sortie&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="370"/>
        <source>&lt;b&gt;Input:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</source>
        <translation>&lt;b&gt;Entrée :&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="371"/>
        <source>&lt;b&gt;Output:&lt;/b&gt;&lt;br&gt;%1</source>
        <translation>&lt;b&gt;Sortie :&lt;/b&gt;&lt;br&gt;%1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="376"/>
        <source>Unfavorite</source>
        <translation>Retirer des favoris</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="393"/>
        <source>Copied to clipboard</source>
        <translation>Copié dans le presse-papiers</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="405"/>
        <source>Delete Entry</source>
        <translation>Supprimer l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="406"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>Voulez-vous vraiment supprimer cette entrée ?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="434"/>
        <source>Export History</source>
        <translation>Exporter l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="436"/>
        <source>JSON Files (*.json)</source>
        <translation>Fichiers JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="457"/>
        <source>Exported to %1</source>
        <translation>Exporté vers %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="459"/>
        <source>Export Failed</source>
        <translation>Échec de l&apos;export</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="460"/>
        <source>Failed to write to file: %1</source>
        <translation>Échec de l&apos;écriture dans le fichier : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="468"/>
        <source>Clear All History</source>
        <translation>Effacer tout l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="469"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Voulez-vous vraiment supprimer toutes les entrées de l&apos;historique ? Cela ne peut pas être annulé.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="500"/>
        <source>%1 ms</source>
        <translation>%1 ms</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="502"/>
        <source>%1 s</source>
        <translation>%1 s</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="506"/>
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
        <translation>Appuyer sur le raccourci...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="22"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="177"/>
        <source>Record</source>
        <translation>Enregistrer</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="29"/>
        <source>Clear</source>
        <translation>Effacer</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="156"/>
        <source>Stop</source>
        <translation>Arrêter</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="157"/>
        <source>Press key combination...</source>
        <translation>Appuyer sur la combinaison de touches...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="189"/>
        <source>None</source>
        <translation>Aucun</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::ImageViewDialog</name>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="22"/>
        <source>Clipboard Image</source>
        <translation>Image du presse-papiers</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="39"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Taille : %1 x %2 pixels</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="49"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptEditorDialog</name>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="24"/>
        <source>Add Prompt</source>
        <translation>Ajouter un prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="52"/>
        <source>Edit Prompt</source>
        <translation>Modifier le prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="76"/>
        <source>Basic Information</source>
        <translation>Informations de base</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="80"/>
        <source>e.g., custom_prompt</source>
        <translation>ex., custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="82"/>
        <source>ID:</source>
        <translation>ID :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="85"/>
        <source>e.g., My Custom Prompt</source>
        <translation>ex., Mon prompt personnalisé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="87"/>
        <source>Name:</source>
        <translation>Nom :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="90"/>
        <source>e.g., Does something useful</source>
        <translation>ex., Fait quelque chose d&apos;utile</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="91"/>
        <source>Description:</source>
        <translation>Description :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="96"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="99"/>
        <source>System Prompt:</source>
        <translation>Prompt système :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="102"/>
        <source>You are a helpful assistant...</source>
        <translation>Vous êtes un assistant utile...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="107"/>
        <source>User Prompt Template:</source>
        <translation>Modèle de prompt utilisateur :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="110"/>
        <source>Process the following text:

{clipboard}</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="117"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="125"/>
        <source>Settings</source>
        <translation>Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="129"/>
        <source>Text</source>
        <translation>Texte</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="130"/>
        <source>Image</source>
        <translation>Image</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="131"/>
        <source>Any</source>
        <translation>Tout</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="132"/>
        <source>Content Type:</source>
        <translation>Type de contenu :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="135"/>
        <source>None</source>
        <translation>Aucun</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="136"/>
        <source>Text Summary</source>
        <translation>Résumé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="137"/>
        <source>Translate</source>
        <translation>Traduire</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="138"/>
        <source>Code Review</source>
        <translation>Revue de code</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="139"/>
        <source>Refactor</source>
        <translation>Refactoriser</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="140"/>
        <source>Explain</source>
        <translation>Expliquer</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="141"/>
        <source>Custom</source>
        <translation>Personnalisé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="142"/>
        <source>Icon:</source>
        <translation>Icône :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="145"/>
        <source>Use default model from settings</source>
        <translation>Utiliser le modèle par défaut des paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="151"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="294"/>
        <source>e.g., openai/gpt-4, anthropic/claude-3-opus</source>
        <translation>ex., openai/gpt-4, anthropic/claude-3-opus</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="152"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="155"/>
        <source>Use default temperature from settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="163"/>
        <source>Temperature:</source>
        <translation>Température :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="168"/>
        <source>Max Tokens:</source>
        <translation>Jetons max :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="170"/>
        <source>Enabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="178"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="179"/>
        <source>Priority (higher = first):</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="193"/>
        <source>Prompt Preview</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="197"/>
        <source>OK</source>
        <translation type="unfinished">OK</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="202"/>
        <source>Cancel</source>
        <translation type="unfinished">Annuler</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="291"/>
        <source>Uses global default model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="346"/>
        <source>Name is required</source>
        <translation>Nom requis</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="350"/>
        <source>ID is required</source>
        <translation>ID requis</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="365"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Espace réservé invalide dans le modèle utilisateur : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="375"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Espace réservé invalide dans le prompt système : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="385"/>
        <source>ID already exists: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="407"/>
        <source>Validation Error</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="408"/>
        <source>The prompt has validation errors:

%1</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptMenu</name>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="36"/>
        <source>Search prompts...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="101"/>
        <source>No prompts available</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="119"/>
        <source>No prompts available for this content type</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptPreviewDialog</name>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="51"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="60"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="63"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="157"/>
        <source>%1x%2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="197"/>
        <source>Prompt Preview</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="209"/>
        <source>Request that will be sent to the API</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="222"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="234"/>
        <source>Refresh</source>
        <translation>Actualiser</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="238"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="25"/>
        <source>ClipAI - Result</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="56"/>
        <source>Model: -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="58"/>
        <source>Tokens: 0 / 0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="59"/>
        <location filename="../src/ui/resultdialog.cpp" line="170"/>
        <source>Traffic: 0 B</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="76"/>
        <source>Ready</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="84"/>
        <source>Input</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="93"/>
        <source>Output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="107"/>
        <source>Copy &amp;&amp; close</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="112"/>
        <source>Save to History</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="117"/>
        <source>Retry</source>
        <translation>Réessayer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="122"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="141"/>
        <source>ClipAI - %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="153"/>
        <location filename="../src/ui/resultdialog.cpp" line="207"/>
        <source>Model: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="171"/>
        <source>Connecting...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="191"/>
        <source>Tokens: ~%1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="204"/>
        <source>Completed in %1 seconds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="209"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="222"/>
        <location filename="../src/ui/resultdialog.cpp" line="237"/>
        <source>Error: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="268"/>
        <source>Saved</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="320"/>
        <source>Close During Generation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="321"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="329"/>
        <source>Cancelling...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="370"/>
        <source>Model is thinking...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="373"/>
        <source>Generating response...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="382"/>
        <source>Traffic: %1</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="56"/>
        <source>ClipAI - Settings</source>
        <translation>ClipAI - Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="82"/>
        <location filename="../src/ui/settingsdialog.cpp" line="307"/>
        <source>Reset to Defaults</source>
        <translation>Réinitialiser par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="100"/>
        <source>Language</source>
        <translation>Langue</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="103"/>
        <source>Interface Language:</source>
        <translation>Langue de l&apos;interface :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="114"/>
        <location filename="../src/ui/settingsdialog.cpp" line="365"/>
        <source>History</source>
        <translation>Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="117"/>
        <source>Automatically save to history after generation</source>
        <translation>Enregistrer automatiquement dans l&apos;historique après génération</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="124"/>
        <source>General</source>
        <translation>Général</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="132"/>
        <source>LLM Provider</source>
        <translation>Fournisseur LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="138"/>
        <source>Provider:</source>
        <translation>Fournisseur :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="144"/>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Select or enter model name...</source>
        <translation>Sélectionner ou entrer le nom du modèle...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="145"/>
        <source>Refresh</source>
        <translation>Actualiser</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="151"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="156"/>
        <source>API Key:</source>
        <translation>Clé API :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="159"/>
        <source>Custom API URL:</source>
        <translation>URL API personnalisée :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="162"/>
        <source>Proxy (optional):</source>
        <translation>Proxy (facultatif) :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="166"/>
        <source>Options</source>
        <translation>Options</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="174"/>
        <source>Temperature:</source>
        <translation>Température :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="176"/>
        <source>Override temperature</source>
        <translation>Remplacer la température</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="187"/>
        <source>Max Tokens:</source>
        <translation>Jetons max :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="189"/>
        <source>Enable streaming responses</source>
        <translation>Activer les réponses en streaming</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="197"/>
        <source>Test Connection</source>
        <translation>Tester la connexion</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="208"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="216"/>
        <source>Global Hotkey</source>
        <translation>Raccourci global</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="223"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Activer le traitement du presse-papiers :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="226"/>
        <source>&lt;b&gt;Note:&lt;/b&gt; Global hotkeys may not work on Wayland. On X11, the hotkey works globally. On Windows and macOS, global hotkeys are fully supported.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="236"/>
        <source>Hotkeys</source>
        <translation>Raccourcis</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="245"/>
        <source>Menu Settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="251"/>
        <source>Maximum number of prompts to show in the menu</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="252"/>
        <source>Max Prompts in Menu:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Name</source>
        <translation>Nom</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Description</source>
        <translation>Description</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Content Type</source>
        <translation>Type de contenu</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Model</source>
        <translation>Modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="260"/>
        <source>Priority</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="275"/>
        <source>Add</source>
        <translation>Ajouter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="279"/>
        <source>Edit</source>
        <translation>Modifier</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="284"/>
        <source>Delete</source>
        <translation>Supprimer</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="299"/>
        <source>Import</source>
        <translation>Importer</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="303"/>
        <source>Export</source>
        <translation>Exporter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="317"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="325"/>
        <source>History Settings</source>
        <translation>Paramètres de l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="331"/>
        <source>Unlimited</source>
        <translation>Illimité</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="334"/>
        <source>Maximum entries:</source>
        <translation>Entrées maximum :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="336"/>
        <source>Automatically clean up old entries</source>
        <translation>Nettoyer automatiquement les anciennes entrées</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="346"/>
        <source>Days to keep:</source>
        <translation>Jours à conserver :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="350"/>
        <source>Actions</source>
        <translation>Actions</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="353"/>
        <source>Clear All History</source>
        <translation>Effacer tout l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="489"/>
        <source>English</source>
        <translation>Anglais</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="490"/>
        <source>Russian</source>
        <translation>Russe</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="491"/>
        <source>German</source>
        <translation>Allemand</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="492"/>
        <source>French</source>
        <translation>Français</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="493"/>
        <source>Spanish</source>
        <translation>Espagnol</translation>
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
        <translation>Personnalisé</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="605"/>
        <source>Reset Settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="606"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>Voulez-vous vraiment réinitialiser tous les paramètres par défaut ?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="631"/>
        <source>Language Changed</source>
        <translation>Langue modifiée</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="632"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>La langue sera modifiée après le redémarrage de l&apos;application.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="658"/>
        <source>API key set</source>
        <translation>Clé API définie</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="658"/>
        <source>No API key</source>
        <translation>Pas de clé API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="664"/>
        <source>Testing...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="668"/>
        <source>Error: No API key</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="673"/>
        <source>Connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="696"/>
        <location filename="../src/ui/settingsdialog.cpp" line="732"/>
        <source>Error</source>
        <translation>Erreur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="697"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="733"/>
        <source>Failed to update prompt.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="757"/>
        <source>Delete Prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="758"/>
        <source>Are you sure you want to delete this prompt?</source>
        <translation>Voulez-vous vraiment supprimer ce prompt ?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="772"/>
        <location filename="../src/ui/settingsdialog.cpp" line="787"/>
        <source>Import Prompts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="774"/>
        <location filename="../src/ui/settingsdialog.cpp" line="797"/>
        <source>JSON Files (*.json)</source>
        <translation>Fichiers JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="788"/>
        <source>Import will be implemented in a future version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="795"/>
        <location filename="../src/ui/settingsdialog.cpp" line="811"/>
        <source>Export Prompts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="812"/>
        <source>Prompts exported to %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="819"/>
        <source>Reset Prompts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="820"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="845"/>
        <source>Clear History</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="846"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Voulez-vous vraiment supprimer toutes les entrées de l&apos;historique ? Cela ne peut pas être annulé.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="902"/>
        <source>Fetch not supported for this provider</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="912"/>
        <source>Fetching models...</source>
        <translation>Récupération des modèles...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="923"/>
        <source>Error: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="933"/>
        <source>Error: Invalid response</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="968"/>
        <source>No models found</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="997"/>
        <source>Loaded %1 models</source>
        <translation>%1 modèles chargés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="75"/>
        <source>OK</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="79"/>
        <source>Cancel</source>
        <translation>Annuler</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="38"/>
        <location filename="../src/ui/trayicon.cpp" line="157"/>
        <location filename="../src/ui/trayicon.cpp" line="263"/>
        <source>ClipAI - LLM Clipboard Utility</source>
        <translation>ClipAI - Utilitaire de presse-papiers LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="69"/>
        <location filename="../src/ui/trayicon.cpp" line="267"/>
        <source>&amp;Settings</source>
        <translation>&amp;Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="73"/>
        <location filename="../src/ui/trayicon.cpp" line="270"/>
        <source>&amp;History</source>
        <translation>&amp;Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="77"/>
        <location filename="../src/ui/trayicon.cpp" line="273"/>
        <source>&amp;About</source>
        <translation>&amp;À propos</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="87"/>
        <location filename="../src/ui/trayicon.cpp" line="276"/>
        <source>&amp;Quit</source>
        <translation>&amp;Quitter</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="95"/>
        <location filename="../src/ui/trayicon.cpp" line="281"/>
        <source>&amp;Prompts</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="117"/>
        <location filename="../src/ui/trayicon.cpp" line="125"/>
        <source>No prompts available</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="159"/>
        <source>Hotkey: </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="221"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipAI&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipAI&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipAI makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="242"/>
        <source>About ClipAI</source>
        <translation>À propos de ClipAI</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="71"/>
        <source>[Image: %1 bytes]</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="75"/>
        <location filename="../src/core/historymanager.cpp" line="87"/>
        <source>[Empty]</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="16"/>
        <source>ClipAI - Cross-platform LLM clipboard utility</source>
        <translation type="unfinished">ClipAI - Utilitaire de presse-papiers LLM multiplateforme</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="22"/>
        <source>Start minimized to system tray</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
