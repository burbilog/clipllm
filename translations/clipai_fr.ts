<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="fr_FR">
<context>
    <name>ClipAI::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="225"/>
        <source>System Tray</source>
        <translation>Zone de notification</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="226"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation>Impossible de détecter une zone de notification sur ce système.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="236"/>
        <source>Welcome to ClipAI</source>
        <translation>Bienvenue dans ClipAI</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="237"/>
        <source>ClipAI is running in the system tray. Press the global hotkey to start.</source>
        <translation>ClipAI fonctionne dans la zone de notification. Appuyez sur le raccourci global pour commencer.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="329"/>
        <source>Hotkey Not Supported</source>
        <translation>Raccourci non pris en charge</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="330"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation>Les raccourcis globaux ne sont pas pris en charge sur cette plateforme (Wayland ?).</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="355"/>
        <source>Hotkey Registration Failed</source>
        <translation>Échec de l&apos;enregistrement du raccourci</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="356"/>
        <source>Could not register global hotkey: %1</source>
        <translation>Impossible d&apos;enregistrer le raccourci global : %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="464"/>
        <location filename="../src/core/app.cpp" line="494"/>
        <source>Clipboard Empty</source>
        <translation>Presse-papiers vide</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="465"/>
        <location filename="../src/core/app.cpp" line="495"/>
        <source>No content found in clipboard.</source>
        <translation>Aucun contenu trouvé dans le presse-papiers.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="484"/>
        <source>Error</source>
        <translation>Erreur</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="485"/>
        <source>Prompt not found: %1</source>
        <translation>Prompt introuvable : %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="512"/>
        <source>Incompatible Content</source>
        <translation>Contenu incompatible</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="513"/>
        <source>This prompt requires %1 content.</source>
        <translation>Ce prompt nécessite un contenu %1.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="546"/>
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
        <location filename="../src/core/llmclient.cpp" line="154"/>
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
        <location filename="../src/core/promptmanager.cpp" line="336"/>
        <source>Summary</source>
        <translation>Résumé</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="337"/>
        <source>Generate a structured summary of the text</source>
        <translation>Générer un résumé structuré du texte</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="339"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Vous êtes un analyste professionnel. Créez un résumé clair et structuré.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="340"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation>Veuillez fournir un résumé complet du texte suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="351"/>
        <source>Translate to Russian</source>
        <translation>Traduire en russe</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="352"/>
        <source>Translate the text to Russian</source>
        <translation>Traduire le texte en russe</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="354"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Vous êtes un traducteur professionnel. Traduisez le texte en russe en conservant le style et le sens.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="355"/>
        <location filename="../src/core/promptmanager.cpp" line="370"/>
        <source>{clipboard}</source>
        <translation>{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="366"/>
        <source>Translate to English</source>
        <translation>Traduire en anglais</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="367"/>
        <source>Translate the text to English</source>
        <translation>Traduire le texte en anglais</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="369"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Vous êtes un traducteur professionnel. Traduisez le texte en anglais en conservant le style et le sens.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="381"/>
        <source>Explain Code</source>
        <translation>Expliquer le code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="382"/>
        <source>Explain what the code does</source>
        <translation>Expliquer ce que fait le code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="384"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Vous êtes un programmeur expert. Expliquez le code clairement et concisément.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="385"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation>Expliquez le code suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="396"/>
        <source>Code Review</source>
        <translation>Revue de code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="397"/>
        <source>Review code and suggest improvements</source>
        <translation>Examiner le code et suggérer des améliorations</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="399"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Vous êtes un réviseur de code. Analysez le code pour les bugs, problèmes de sécurité et suggérez des améliorations.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="400"/>
        <source>Review the following code:

{clipboard}</source>
        <translation>Examinez le code suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="411"/>
        <source>Refactor Code</source>
        <translation>Refactoriser le code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="412"/>
        <source>Suggest refactoring improvements</source>
        <translation>Suggérer des améliorations de refactoring</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="414"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Vous êtes un expert en optimisation de code. Suggérez un refactoring pour améliorer la lisibilité, la maintenabilité et les performances.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="415"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation>Refactorisez le code suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="426"/>
        <source>Describe Image</source>
        <translation>Décrire l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="427"/>
        <source>Generate a detailed description of the image</source>
        <translation>Générer une description détaillée de l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="429"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Vous êtes un analyste visuel. Fournissez une description détaillée de l&apos;image.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="430"/>
        <source>Describe this image in detail.</source>
        <translation>Décrivez cette image en détail.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="441"/>
        <source>Extract Text</source>
        <translation>Extraire le texte</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="442"/>
        <source>Extract all text from the image</source>
        <translation>Extraire tout le texte de l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="444"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Extrayez tout le texte de l&apos;image en préservant la mise en forme si possible.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="445"/>
        <source>Extract all text from this image.</source>
        <translation>Extrayez tout le texte de cette image.</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::GroupsDialog</name>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="37"/>
        <source>Manage Groups</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="43"/>
        <source>Right-click to add, rename, or delete groups. Drag and drop to move groups.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="51"/>
        <source>Group Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="74"/>
        <source>Close</source>
        <translation type="unfinished">Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="88"/>
        <source>Root</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="182"/>
        <source>New Group...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="186"/>
        <source>New Subgroup...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="189"/>
        <source>Rename...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="194"/>
        <source>Delete...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="205"/>
        <source>New Group</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="206"/>
        <source>Enter group name:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="216"/>
        <location filename="../src/ui/groupsdialog.cpp" line="251"/>
        <source>Duplicate Group</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="217"/>
        <source>A group with this name already exists.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="240"/>
        <source>New Subgroup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="241"/>
        <source>Enter subgroup name:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="252"/>
        <source>A subgroup with this name already exists.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="289"/>
        <source>(root)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="301"/>
        <source>Delete group &apos;%1&apos;?

%2 prompt(s) in this group will be moved to root.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="304"/>
        <source>Delete group &apos;%1&apos;?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="308"/>
        <source>Delete Group</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="352"/>
        <source>Invalid Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="353"/>
        <source>Group name cannot be empty.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="373"/>
        <source>Duplicate Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="374"/>
        <source>A group with this name already exists in this location.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="37"/>
        <source>ClipAI - History</source>
        <translation>ClipAI - Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="43"/>
        <source>Filters</source>
        <translation>Filtres</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="47"/>
        <source>Search...</source>
        <translation>Rechercher...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="51"/>
        <location filename="../src/ui/historydialog.cpp" line="241"/>
        <source>All Models</source>
        <translation>Tous les modèles</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="56"/>
        <location filename="../src/ui/historydialog.cpp" line="248"/>
        <source>All Prompts</source>
        <translation>Tous les prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="60"/>
        <source>Favorites only</source>
        <translation>Favoris seulement</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="78"/>
        <source>Search:</source>
        <translation>Rechercher :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="80"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="82"/>
        <source>Prompt:</source>
        <translation>Prompt :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="85"/>
        <source>From:</source>
        <translation>De :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="87"/>
        <source>To:</source>
        <translation>À :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="110"/>
        <source>Preview</source>
        <translation>Aperçu</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="113"/>
        <location filename="../src/ui/historydialog.cpp" line="117"/>
        <location filename="../src/ui/historydialog.cpp" line="555"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="117"/>
        <location filename="../src/ui/historydialog.cpp" line="555"/>
        <source>Raw</source>
        <translation>Brut</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="137"/>
        <source>View Details</source>
        <translation>Voir les détails</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="142"/>
        <source>Copy Output</source>
        <translation>Copier la sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="147"/>
        <location filename="../src/ui/historydialog.cpp" line="382"/>
        <source>Favorite</source>
        <translation>Favori</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="152"/>
        <source>Delete</source>
        <translation>Supprimer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="157"/>
        <source>Export</source>
        <translation>Exporter</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="161"/>
        <source>Clear All</source>
        <translation>Tout effacer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="165"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="185"/>
        <source>Date</source>
        <translation>Date</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="186"/>
        <source>Prompt</source>
        <translation>Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="187"/>
        <source>Model</source>
        <translation>Modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="188"/>
        <source>Input Preview</source>
        <translation>Aperçu de l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="189"/>
        <source>Output Preview</source>
        <translation>Aperçu de la sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="190"/>
        <source>Duration</source>
        <translation>Durée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="191"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="266"/>
        <source>Total entries: %1</source>
        <translation>Total des entrées : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="322"/>
        <source>Showing %1 entries</source>
        <translation>Affichage de %1 entrées</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="535"/>
        <source>Prompt: %1
</source>
        <translation>Prompt : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="536"/>
        <source>Model: %1
</source>
        <translation>Modèle : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="537"/>
        <source>Date: %1
</source>
        <translation>Date : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="538"/>
        <source>Duration: %1
</source>
        <translation>Durée : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="539"/>
        <source>Tokens: %1 input / %2 output
</source>
        <translation>Jetons : %1 entrée / %2 sortie
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="543"/>
        <source>Input:
</source>
        <translation>Entrée :
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="545"/>
        <source>Output:
</source>
        <translation>Sortie :
</translation>
    </message>
    <message>
        <source>&lt;b&gt;Prompt:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Prompt :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Model:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Modèle :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Date:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Date :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Duration:&lt;/b&gt; %1&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Durée :&lt;/b&gt; %1&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Tokens:&lt;/b&gt; %1 input / %2 output&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Jetons :&lt;/b&gt; %1 entrée / %2 sortie&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Input:&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</source>
        <translation type="vanished">&lt;b&gt;Entrée :&lt;/b&gt;&lt;br&gt;%1&lt;br&gt;&lt;br&gt;</translation>
    </message>
    <message>
        <source>&lt;b&gt;Output:&lt;/b&gt;&lt;br&gt;%1</source>
        <translation type="vanished">&lt;b&gt;Sortie :&lt;/b&gt;&lt;br&gt;%1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="382"/>
        <source>Unfavorite</source>
        <translation>Retirer des favoris</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="399"/>
        <source>Copied to clipboard</source>
        <translation>Copié dans le presse-papiers</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="411"/>
        <source>Delete Entry</source>
        <translation>Supprimer l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="412"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>Voulez-vous vraiment supprimer cette entrée ?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="440"/>
        <source>Export History</source>
        <translation>Exporter l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="442"/>
        <source>JSON Files (*.json)</source>
        <translation>Fichiers JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="463"/>
        <source>Exported to %1</source>
        <translation>Exporté vers %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="465"/>
        <source>Export Failed</source>
        <translation>Échec de l&apos;export</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="466"/>
        <source>Failed to write to file: %1</source>
        <translation>Échec de l&apos;écriture dans le fichier : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="474"/>
        <source>Clear All History</source>
        <translation>Effacer tout l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="475"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Voulez-vous vraiment supprimer toutes les entrées de l&apos;historique ? Cela ne peut pas être annulé.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="506"/>
        <source>%1 ms</source>
        <translation>%1 ms</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="508"/>
        <source>%1 s</source>
        <translation>%1 s</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="512"/>
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
        <location filename="../src/ui/imageviewdialog.cpp" line="29"/>
        <source>Clipboard Image</source>
        <translation>Image du presse-papiers</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="46"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Taille : %1 x %2 pixels</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="56"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptEditorDialog</name>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="29"/>
        <source>Add Prompt</source>
        <translation>Ajouter un prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="64"/>
        <source>Edit Prompt</source>
        <translation>Modifier le prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="94"/>
        <source>Basic Information</source>
        <translation>Informations de base</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="98"/>
        <source>e.g., custom_prompt</source>
        <translation>ex., custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="100"/>
        <source>ID:</source>
        <translation>ID :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="103"/>
        <source>e.g., My Custom Prompt</source>
        <translation>ex., Mon prompt personnalisé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="105"/>
        <source>Name:</source>
        <translation>Nom :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="108"/>
        <source>e.g., Does something useful</source>
        <translation>ex., Fait quelque chose d&apos;utile</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="109"/>
        <source>Description:</source>
        <translation>Description :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="112"/>
        <source>(root)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="129"/>
        <source>Group:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="134"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="137"/>
        <source>System Prompt:</source>
        <translation>Prompt système :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="140"/>
        <source>You are a helpful assistant...</source>
        <translation>Vous êtes un assistant utile...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="145"/>
        <source>User Prompt Template:</source>
        <translation>Modèle de prompt utilisateur :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="148"/>
        <source>Process the following text:

{clipboard}</source>
        <translation>Traitez le texte suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="155"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation>Utilisez {clipboard} pour insérer le contenu du presse-papiers, {clipboard:1000} pour le contenu tronqué, {language} pour la langue de l&apos;utilisateur.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="163"/>
        <source>Settings</source>
        <translation>Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="167"/>
        <source>Text</source>
        <translation>Texte</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="168"/>
        <source>Image</source>
        <translation>Image</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="169"/>
        <source>Any</source>
        <translation>Tout</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="170"/>
        <source>Content Type:</source>
        <translation>Type de contenu :</translation>
    </message>
    <message>
        <source>None</source>
        <translation type="vanished">Aucun</translation>
    </message>
    <message>
        <source>Text Summary</source>
        <translation type="vanished">Résumé</translation>
    </message>
    <message>
        <source>Translate</source>
        <translation type="vanished">Traduire</translation>
    </message>
    <message>
        <source>Code Review</source>
        <translation type="vanished">Revue de code</translation>
    </message>
    <message>
        <source>Refactor</source>
        <translation type="vanished">Refactoriser</translation>
    </message>
    <message>
        <source>Explain</source>
        <translation type="vanished">Expliquer</translation>
    </message>
    <message>
        <source>Custom</source>
        <translation type="vanished">Personnalisé</translation>
    </message>
    <message>
        <source>Icon:</source>
        <translation type="vanished">Icône :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="173"/>
        <source>Use default model from settings</source>
        <translation>Utiliser le modèle par défaut des paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="179"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="340"/>
        <source>e.g., openai/gpt-4, anthropic/claude-3-opus</source>
        <translation>ex., openai/gpt-4, anthropic/claude-3-opus</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="180"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="183"/>
        <source>Use default temperature from settings</source>
        <translation>Utiliser la température par défaut des paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="191"/>
        <source>Temperature:</source>
        <translation>Température :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="196"/>
        <source>Max Tokens:</source>
        <translation>Jetons max :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="198"/>
        <source>Enabled</source>
        <translation>Activé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="206"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation>Les prompts de priorité plus élevée apparaissent en premier dans le menu</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="207"/>
        <source>Priority (higher = first):</source>
        <translation>Priorité (plus élevé = premier) :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="221"/>
        <source>Prompt Preview</source>
        <translation>Aperçu du prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="225"/>
        <source>OK</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="230"/>
        <source>Cancel</source>
        <translation>Annuler</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="337"/>
        <source>Uses global default model</source>
        <translation>Utilise le modèle global par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="392"/>
        <source>Name is required</source>
        <translation>Nom requis</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="396"/>
        <source>ID is required</source>
        <translation>ID requis</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="411"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Espace réservé invalide dans le modèle utilisateur : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="421"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Espace réservé invalide dans le prompt système : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="431"/>
        <source>ID already exists: %1</source>
        <translation>L&apos;ID existe déjà : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="453"/>
        <source>Validation Error</source>
        <translation>Erreur de validation</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="454"/>
        <source>The prompt has validation errors:

%1</source>
        <translation>Le prompt contient des erreurs de validation :

%1</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptMenu</name>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="37"/>
        <source>Search prompts...</source>
        <translation>Rechercher des prompts...</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="102"/>
        <source>No prompts available</source>
        <translation>Aucun prompt disponible</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="120"/>
        <source>No prompts available for this content type</source>
        <translation>Aucun prompt disponible pour ce type de contenu</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::PromptPreviewDialog</name>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="59"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation>⚠ Ce prompt est configuré pour le contenu Texte uniquement, mais il y a une image dans le presse-papiers. L&apos;image sera ignorée.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="68"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation>⚠ Ce prompt est configuré pour le contenu Image uniquement, mais il y a du texte dans le presse-papiers. Seule l&apos;image sera envoyée au modèle.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="71"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation>⚠ Ce prompt est configuré pour le contenu Image uniquement, mais le presse-papiers est vide ou ne contient pas d&apos;image.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="165"/>
        <source>%1x%2</source>
        <translation>%1x%2</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="205"/>
        <source>Prompt Preview</source>
        <translation>Aperçu du prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="217"/>
        <source>Request that will be sent to the API</source>
        <translation>Requête qui sera envoyée à l&apos;API</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="230"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation>Ceci est le JSON exact qui sera envoyé à l&apos;API LLM. Le contenu du presse-papiers est substitué à l&apos;espace réservé {clipboard}. Cliquez sur le lien de l&apos;image pour voir l&apos;image complète.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="242"/>
        <source>Refresh</source>
        <translation>Actualiser</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="246"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="26"/>
        <source>ClipAI - Result</source>
        <translation>ClipAI - Résultat</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="63"/>
        <source>Model: -</source>
        <translation>Modèle : -</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="65"/>
        <source>Tokens: 0 / 0</source>
        <translation>Jetons : 0 / 0</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="66"/>
        <location filename="../src/ui/resultdialog.cpp" line="188"/>
        <source>Traffic: 0 B</source>
        <translation>Trafic : 0 o</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="83"/>
        <source>Ready</source>
        <translation>Prêt</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="88"/>
        <location filename="../src/ui/resultdialog.cpp" line="92"/>
        <location filename="../src/ui/resultdialog.cpp" line="182"/>
        <location filename="../src/ui/resultdialog.cpp" line="440"/>
        <source>Markdown</source>
        <translation>Markdown</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="92"/>
        <location filename="../src/ui/resultdialog.cpp" line="182"/>
        <location filename="../src/ui/resultdialog.cpp" line="440"/>
        <source>Raw</source>
        <translation>Brut</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="99"/>
        <source>Input</source>
        <translation>Entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="108"/>
        <source>Output</source>
        <translation>Sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="122"/>
        <source>Copy &amp;&amp; close</source>
        <translation>Copier et fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="127"/>
        <source>Save to History</source>
        <translation>Enregistrer dans l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="132"/>
        <source>Retry</source>
        <translation>Réessayer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="137"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="156"/>
        <source>ClipAI - %1</source>
        <translation>ClipAI - %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="168"/>
        <location filename="../src/ui/resultdialog.cpp" line="233"/>
        <source>Model: %1</source>
        <translation>Modèle : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="189"/>
        <source>Connecting...</source>
        <translation>Connexion...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="217"/>
        <source>Tokens: ~%1</source>
        <translation>Jetons : ~%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="230"/>
        <source>Completed in %1 seconds</source>
        <translation>Terminé en %1 secondes</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="235"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation>Jetons : %1 entrée / %2 sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="248"/>
        <location filename="../src/ui/resultdialog.cpp" line="263"/>
        <source>Error: %1</source>
        <translation>Erreur : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="294"/>
        <source>Saved</source>
        <translation>Enregistré</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="353"/>
        <source>Close During Generation</source>
        <translation>Fermer pendant la génération</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="354"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation>Une réponse est encore en cours de génération. Fermer et annuler la requête ?</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="362"/>
        <source>Cancelling...</source>
        <translation>Annulation...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="403"/>
        <source>Model is thinking...</source>
        <translation>Le modèle réfléchit...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="406"/>
        <source>Generating response...</source>
        <translation>Génération de la réponse...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="415"/>
        <source>Traffic: %1</source>
        <translation>Trafic : %1</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="65"/>
        <source>ClipAI - Settings</source>
        <translation>ClipAI - Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="91"/>
        <location filename="../src/ui/settingsdialog.cpp" line="327"/>
        <source>Reset to Defaults</source>
        <translation>Réinitialiser par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="109"/>
        <source>Language</source>
        <translation>Langue</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="112"/>
        <source>Interface Language:</source>
        <translation>Langue de l&apos;interface :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="123"/>
        <location filename="../src/ui/settingsdialog.cpp" line="385"/>
        <source>History</source>
        <translation>Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="126"/>
        <source>Automatically save to history after generation</source>
        <translation>Enregistrer automatiquement dans l&apos;historique après génération</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="133"/>
        <source>General</source>
        <translation>Général</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="141"/>
        <source>LLM Provider</source>
        <translation>Fournisseur LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="147"/>
        <source>Provider:</source>
        <translation>Fournisseur :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="153"/>
        <location filename="../src/ui/settingsdialog.cpp" line="469"/>
        <source>Select or enter model name...</source>
        <translation>Sélectionner ou entrer le nom du modèle...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="154"/>
        <source>Refresh</source>
        <translation>Actualiser</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="160"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="165"/>
        <source>API Key:</source>
        <translation>Clé API :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="168"/>
        <source>http://localhost:11434/v1/chat/completions</source>
        <translation>http://localhost:11434/v1/chat/completions</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="169"/>
        <source>Used only when Provider is set to Custom.

Examples:
• Ollama: http://localhost:11434/v1/chat/completions
• LM Studio: http://localhost:1234/v1/chat/completions
• LocalAI: http://localhost:8080/v1/chat/completions</source>
        <translation>Utilisé uniquement lorsque le fournisseur est défini sur Personnalisé.

Exemples :
• Ollama : http://localhost:11434/v1/chat/completions
• LM Studio : http://localhost:1234/v1/chat/completions
• LocalAI : http://localhost:8080/v1/chat/completions</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="174"/>
        <source>Custom API URL:</source>
        <translation>URL API personnalisée :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="177"/>
        <source>http://host:port or socks5://host:port</source>
        <translation>http://host:port or socks5://host:port</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="178"/>
        <source>Proxy (optional):</source>
        <translation>Proxy (facultatif) :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="182"/>
        <source>Options</source>
        <translation>Options</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="190"/>
        <source>Temperature:</source>
        <translation>Température :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="192"/>
        <source>Override temperature</source>
        <translation>Remplacer la température</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="203"/>
        <source>Max Tokens:</source>
        <translation>Jetons max :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="205"/>
        <source>Enable streaming responses</source>
        <translation>Activer les réponses en streaming</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="213"/>
        <source>Test Connection</source>
        <translation>Tester la connexion</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="224"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="232"/>
        <source>Global Hotkey</source>
        <translation>Raccourci global</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="239"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Activer le traitement du presse-papiers :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="242"/>
        <source>&lt;b&gt;Note:&lt;/b&gt; Global hotkeys may not work on Wayland. On X11, the hotkey works globally. On Windows and macOS, global hotkeys are fully supported.</source>
        <translation>&lt;b&gt;Note :&lt;/b&gt; Les raccourcis globaux peuvent ne pas fonctionner sur Wayland. Sur X11, le raccourci fonctionne globalement. Sur Windows et macOS, les raccourcis globaux sont entièrement pris en charge.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="252"/>
        <source>Hotkeys</source>
        <translation>Raccourcis</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="261"/>
        <source>Menu Settings</source>
        <translation>Paramètres du menu</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="267"/>
        <source>Maximum number of prompts to show in the menu</source>
        <translation>Nombre maximum de prompts à afficher dans le menu</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="268"/>
        <source>Max Prompts in Menu:</source>
        <translation>Max prompts dans le menu :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>Name</source>
        <translation>Nom</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>Description</source>
        <translation>Description</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>Content Type</source>
        <translation>Type de contenu</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>Model</source>
        <translation>Modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>Priority</source>
        <translation>Priorité</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="291"/>
        <source>Add</source>
        <translation>Ajouter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="295"/>
        <source>Edit</source>
        <translation>Modifier</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="300"/>
        <source>Delete</source>
        <translation>Supprimer</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="305"/>
        <source>Manage Groups...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="319"/>
        <source>Import</source>
        <translation>Importer</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="323"/>
        <source>Export</source>
        <translation>Exporter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="337"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="345"/>
        <source>History Settings</source>
        <translation>Paramètres de l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="351"/>
        <source>Unlimited</source>
        <translation>Illimité</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="354"/>
        <source>Maximum entries:</source>
        <translation>Entrées maximum :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="356"/>
        <source>Automatically clean up old entries</source>
        <translation>Nettoyer automatiquement les anciennes entrées</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="366"/>
        <source>Days to keep:</source>
        <translation>Jours à conserver :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="370"/>
        <source>Actions</source>
        <translation>Actions</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="373"/>
        <source>Clear All History</source>
        <translation>Effacer tout l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="510"/>
        <source>English</source>
        <translation>Anglais</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="511"/>
        <source>Russian</source>
        <translation>Russe</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="512"/>
        <source>German</source>
        <translation>Allemand</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="513"/>
        <source>French</source>
        <translation>Français</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="514"/>
        <source>Spanish</source>
        <translation>Espagnol</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="521"/>
        <source>OpenRouter</source>
        <translation>OpenRouter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="522"/>
        <source>OpenAI</source>
        <translation>OpenAI</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="523"/>
        <source>Anthropic</source>
        <translation>Anthropic</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="524"/>
        <source>Custom</source>
        <translation>Personnalisé</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="626"/>
        <source>Reset Settings</source>
        <translation>Réinitialiser les paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="627"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>Voulez-vous vraiment réinitialiser tous les paramètres par défaut ?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="652"/>
        <source>Language Changed</source>
        <translation>Langue modifiée</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="653"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>La langue sera modifiée après le redémarrage de l&apos;application.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="679"/>
        <source>API key set</source>
        <translation>Clé API définie</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="679"/>
        <source>No API key</source>
        <translation>Pas de clé API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="685"/>
        <source>Testing...</source>
        <translation>Test en cours...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="689"/>
        <source>Error: No API key</source>
        <translation>Erreur : Pas de clé API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="694"/>
        <source>Connected</source>
        <translation>Connecté</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="717"/>
        <location filename="../src/ui/settingsdialog.cpp" line="753"/>
        <source>Error</source>
        <translation>Erreur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="718"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation>Échec de l&apos;ajout du prompt. L&apos;ID existe peut-être déjà.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="754"/>
        <source>Failed to update prompt.</source>
        <translation>Échec de la mise à jour du prompt.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="778"/>
        <source>Delete Prompt</source>
        <translation>Supprimer le prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="779"/>
        <source>Are you sure you want to delete this prompt?</source>
        <translation>Voulez-vous vraiment supprimer ce prompt ?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="807"/>
        <location filename="../src/ui/settingsdialog.cpp" line="822"/>
        <source>Import Prompts</source>
        <translation>Importer des prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="809"/>
        <location filename="../src/ui/settingsdialog.cpp" line="832"/>
        <source>JSON Files (*.json)</source>
        <translation>Fichiers JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="823"/>
        <source>Import will be implemented in a future version.</source>
        <translation>L&apos;importation sera implémentée dans une future version.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="830"/>
        <location filename="../src/ui/settingsdialog.cpp" line="846"/>
        <source>Export Prompts</source>
        <translation>Exporter des prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="847"/>
        <source>Prompts exported to %1</source>
        <translation>Prompts exportés vers %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="854"/>
        <source>Reset Prompts</source>
        <translation>Réinitialiser les prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="855"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation>Voulez-vous vraiment réinitialiser les prompts par défaut ? Tous les prompts personnalisés seront perdus.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="880"/>
        <source>Clear History</source>
        <translation>Effacer l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="881"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Voulez-vous vraiment supprimer toutes les entrées de l&apos;historique ? Cela ne peut pas être annulé.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="937"/>
        <source>Fetch not supported for this provider</source>
        <translation>Récupération non prise en charge pour ce fournisseur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="947"/>
        <source>Fetching models...</source>
        <translation>Récupération des modèles...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="958"/>
        <source>Error: %1</source>
        <translation>Erreur : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="968"/>
        <source>Error: Invalid response</source>
        <translation>Erreur : Réponse invalide</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1003"/>
        <source>No models found</source>
        <translation>Aucun modèle trouvé</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1032"/>
        <source>Loaded %1 models</source>
        <translation>%1 modèles chargés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="84"/>
        <source>OK</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="88"/>
        <source>Cancel</source>
        <translation>Annuler</translation>
    </message>
</context>
<context>
    <name>ClipAI::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="39"/>
        <location filename="../src/ui/trayicon.cpp" line="234"/>
        <location filename="../src/ui/trayicon.cpp" line="339"/>
        <source>ClipAI - LLM Clipboard Utility</source>
        <translation>ClipAI - Utilitaire de presse-papiers LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="70"/>
        <location filename="../src/ui/trayicon.cpp" line="343"/>
        <source>&amp;Settings</source>
        <translation>&amp;Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="74"/>
        <location filename="../src/ui/trayicon.cpp" line="346"/>
        <source>&amp;History</source>
        <translation>&amp;Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="78"/>
        <location filename="../src/ui/trayicon.cpp" line="349"/>
        <source>&amp;About</source>
        <translation>&amp;À propos</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="88"/>
        <location filename="../src/ui/trayicon.cpp" line="352"/>
        <source>&amp;Quit</source>
        <translation>&amp;Quitter</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="96"/>
        <location filename="../src/ui/trayicon.cpp" line="357"/>
        <source>&amp;Prompts</source>
        <translation>&amp;Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="118"/>
        <location filename="../src/ui/trayicon.cpp" line="126"/>
        <source>No prompts available</source>
        <translation>Aucun prompt disponible</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="236"/>
        <source>Hotkey: </source>
        <translation>Raccourci : </translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="297"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipAI&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipAI&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipAI makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipAI&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipAI&lt;/b&gt; est un utilitaire de presse-papiers multiplateforme qui intègre les grands modèles de langage (LLM) directement dans votre flux de travail. Fonctionnant comme un service de zone de notification, il vous permet de traiter le contenu du presse-papiers (texte et images) avec des prompts IA personnalisables à l&apos;aide de raccourcis globaux.&lt;/p&gt;&lt;p&gt;Que vous ayez besoin de résumer du texte, de traduire du contenu, de réécrire du code, d&apos;extraire des informations d&apos;images ou d&apos;effectuer toute autre transformation alimentée par l&apos;IA, ClipAI rend cela instantanément accessible avec une seule pression de touche. Copiez le contenu, appuyez sur votre raccourci et obtenez des résultats générés par l&apos;IA dans votre presse-papiers.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="318"/>
        <source>About ClipAI</source>
        <translation>À propos de ClipAI</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="71"/>
        <source>[Image: %1 bytes]</source>
        <translation>[Image : %1 octets]</translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="75"/>
        <location filename="../src/core/historymanager.cpp" line="87"/>
        <source>[Empty]</source>
        <translation>[Vide]</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="16"/>
        <source>ClipAI - Cross-platform LLM clipboard utility</source>
        <translation>ClipAI - Utilitaire de presse-papiers LLM multiplateforme</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="22"/>
        <source>Start minimized to system tray</source>
        <translation>Démarrer minimisé dans la zone de notification</translation>
    </message>
</context>
</TS>
