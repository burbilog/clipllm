<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="fr_FR">
<context>
    <name>ClipLLM</name>
    <message>
        <source>Clipboard Empty</source>
        <translation type="obsolete">Presse-papiers vide</translation>
    </message>
    <message>
        <source>No content found in clipboard.</source>
        <translation type="obsolete">Aucun contenu trouvé dans le presse-papiers.</translation>
    </message>
    <message>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation type="obsolete">Impossible d&apos;exécuter le prompt : le presse-papiers est vide.

Copiez du texte ou une image d&apos;abord.</translation>
    </message>
    <message>
        <source>Error</source>
        <translation type="obsolete">Erreur</translation>
    </message>
    <message>
        <source>Prompt not found: %1</source>
        <translation type="obsolete">Prompt introuvable : %1</translation>
    </message>
    <message>
        <source>Provider Error</source>
        <translation type="obsolete">Erreur de fournisseur</translation>
    </message>
    <message>
        <source>No valid LLM provider configured.</source>
        <translation type="obsolete">Aucun fournisseur LLM valide configuré.</translation>
    </message>
    <message>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation type="obsolete">Aucun fournisseur LLM configuré. Veuillez en configurer un dans les paramètres.</translation>
    </message>
    <message>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation type="obsolete">Fournisseur LLM par défaut non trouvé. Veuillez en configurer un dans les paramètres.</translation>
    </message>
    <message>
        <source>Model Error</source>
        <translation type="obsolete">Erreur de modèle</translation>
    </message>
    <message>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation type="obsolete">Aucun modèle sélectionné. Veuillez sélectionner un modèle dans Paramètres → LLM → Profils de fournisseurs.</translation>
    </message>
    <message>
        <source>Incompatible Content</source>
        <translation type="obsolete">Contenu incompatible</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="obsolete">Ce prompt nécessite un contenu %1.</translation>
    </message>
    <message>
        <source>[Image content]</source>
        <translation type="obsolete">[Contenu image]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::App</name>
    <message>
        <location filename="../src/core/app.cpp" line="268"/>
        <source>System Tray</source>
        <translation>Zone de notification</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="269"/>
        <source>Couldn&apos;t detect any system tray on this system.</source>
        <translation>Impossible de détecter une zone de notification sur ce système.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="279"/>
        <source>Welcome to ClipLLM</source>
        <translation>Bienvenue dans ClipLLM</translation>
    </message>
    <message>
        <source>ClipLLM is running in the system tray. Press the global hotkey to start.</source>
        <translation type="vanished">ClipLLM fonctionne dans la zone de notification. Appuyez sur le raccourci global pour commencer.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="280"/>
        <source>ClipLLM is running in the system tray. Click the tray icon or configure a hotkey in settings.</source>
        <translation>ClipLLM s&apos;exécute dans la zone de notification. Cliquez sur l&apos;icône ou configurez un raccourci dans les paramètres.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="372"/>
        <source>Hotkey Not Supported</source>
        <translation>Raccourci non pris en charge</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="373"/>
        <source>Global hotkeys are not supported on this platform (Wayland?).</source>
        <translation>Les raccourcis globaux ne sont pas pris en charge sur cette plateforme (Wayland ?).</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="398"/>
        <source>Hotkey Registration Failed</source>
        <translation>Échec de l&apos;enregistrement du raccourci</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="399"/>
        <source>Could not register global hotkey: %1</source>
        <translation>Impossible d&apos;enregistrer le raccourci global : %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="603"/>
        <location filename="../src/core/app.cpp" line="655"/>
        <source>Clipboard Empty</source>
        <translation>Presse-papiers vide</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="604"/>
        <source>No content found in clipboard.</source>
        <translation>Aucun contenu trouvé dans le presse-papiers.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="627"/>
        <source>Chain Cycle Detected</source>
        <translation>Cycle de chaîne détecté</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="628"/>
        <source>The prompt chain would create a cycle. Execution stopped.

Prompt &apos;%1&apos; was already executed in this chain.</source>
        <translation>La chaîne de prompts créerait un cycle. Exécution arrêtée.

Le prompt &apos;%1&apos; a déjà été exécuté dans cette chaîne.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="636"/>
        <source>Chain Depth Limit</source>
        <translation>Limite de profondeur de chaîne</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="637"/>
        <source>Maximum chain depth (%1) reached. Execution stopped.

You can increase this limit in Settings → General → Prompt Chains.</source>
        <translation>Profondeur maximale de chaîne (%1) atteinte. Exécution arrêtée.

Vous pouvez augmenter cette limite dans Paramètres → Général → Chaînes de prompts.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="656"/>
        <source>Cannot execute prompt: clipboard is empty.

Copy some text or an image first.</source>
        <translation>Impossible d&apos;exécuter le prompt : le presse-papiers est vide.

Copiez du texte ou une image d&apos;abord.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="671"/>
        <source>Error</source>
        <translation>Erreur</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="672"/>
        <source>Prompt not found: %1</source>
        <translation>Prompt introuvable : %1</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="694"/>
        <location filename="../src/core/app.cpp" line="699"/>
        <location filename="../src/core/app.cpp" line="710"/>
        <location filename="../src/core/app.cpp" line="715"/>
        <source>Provider Error</source>
        <translation>Erreur de fournisseur</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="695"/>
        <source>No valid LLM provider configured.</source>
        <translation>Aucun fournisseur LLM valide configuré.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="700"/>
        <location filename="../src/core/app.cpp" line="716"/>
        <source>No LLM provider configured. Please configure one in Settings.</source>
        <translation>Aucun fournisseur LLM configuré. Veuillez en configurer un dans les paramètres.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="711"/>
        <source>Default LLM provider not found. Please configure one in Settings.</source>
        <translation>Fournisseur LLM par défaut non trouvé. Veuillez en configurer un dans les paramètres.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="753"/>
        <source>This prompt requires text content.</source>
        <translation>Ce prompt nécessite du contenu texte.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="207"/>
        <source>No LLM Provider Configured</source>
        <translation>Aucun fournisseur LLM configuré</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="208"/>
        <source>No LLM provider profile has been configured.

Please add at least one provider profile in Settings to use ClipLLM.</source>
        <translation>Aucun profil de fournisseur LLM n&apos;a été configuré.

Veuillez ajouter au moins un profil de fournisseur dans les paramètres pour utiliser ClipLLM.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="733"/>
        <source>Model Error</source>
        <translation>Erreur de modèle</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="734"/>
        <source>No model selected. Please select a model in Settings → LLM → Provider Profiles.</source>
        <translation>Aucun modèle sélectionné. Veuillez sélectionner un modèle dans Paramètres → LLM → Profils de fournisseurs.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="752"/>
        <source>Incompatible Content</source>
        <translation>Contenu incompatible</translation>
    </message>
    <message>
        <source>This prompt requires %1 content.</source>
        <translation type="vanished">Ce prompt nécessite un contenu %1.</translation>
    </message>
    <message>
        <location filename="../src/core/app.cpp" line="778"/>
        <source>[Image content]</source>
        <translation>[Contenu image]</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::App</name>
    <message>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation type="vanished">ClipLLM - Utilitaire de presse-papiers LLM multiplateforme</translation>
    </message>
    <message>
        <source>Another instance of ClipLLM is already running</source>
        <translation type="vanished">Une autre instance de ClipLLM est déjà en cours d&apos;exécution</translation>
    </message>
    <message>
        <source>Failed to initialize application</source>
        <translation type="vanished">Échec de l&apos;initialisation de l&apos;application</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::LLMClient</name>
    <message>
        <location filename="../src/core/llmclient.cpp" line="280"/>
        <source>API key is not set</source>
        <translation>Clé API non définie</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="352"/>
        <location filename="../src/core/llmclient.cpp" line="448"/>
        <source>Connection successful</source>
        <translation>Connexion réussie</translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="385"/>
        <source>HTTP %1: Authentication required. Please check your API key.</source>
        <translation>HTTP %1 : Authentification requise. Veuillez vérifier votre clé API.</translation>
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
        <translation>HTTP %1 : </translation>
    </message>
    <message>
        <location filename="../src/core/llmclient.cpp" line="531"/>
        <source>SSL error: %1</source>
        <translation>Erreur SSL: %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::Core::PromptManager</name>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="66"/>
        <source>Failed to load default prompts</source>
        <translation>Échec du chargement des prompts par défaut</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="125"/>
        <source>Failed to open prompts file</source>
        <translation>Échec de l&apos;ouverture du fichier de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="135"/>
        <source>Failed to parse prompts file</source>
        <translation>Échec de l&apos;analyse du fichier de prompts</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="354"/>
        <source>ID is required</source>
        <translation>ID requis</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="358"/>
        <source>Name is required</source>
        <translation>Nom requis</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="373"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Espace réservé invalide dans le modèle utilisateur : %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="383"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Espace réservé invalide dans le prompt système : %1</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="451"/>
        <source>Summary</source>
        <translation>Résumé</translation>
    </message>
    <message>
        <source>Generate a structured summary of the text</source>
        <translation type="vanished">Générer un résumé structuré du texte</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="453"/>
        <source>You are a professional analyst. Create a clear, structured summary.</source>
        <translation>Vous êtes un analyste professionnel. Créez un résumé clair et structuré.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="454"/>
        <source>Please provide a comprehensive summary of the following text:

{clipboard}</source>
        <translation>Veuillez fournir un résumé complet du texte suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="465"/>
        <source>Translate to Russian</source>
        <translation>Traduire en russe</translation>
    </message>
    <message>
        <source>Translate the text to Russian</source>
        <translation type="vanished">Traduire le texte en russe</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="467"/>
        <source>Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл.</source>
        <translation>Vous êtes un traducteur professionnel. Traduisez le texte en russe en conservant le style et le sens.</translation>
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
        <translation>Traduire en anglais</translation>
    </message>
    <message>
        <source>Translate the text to English</source>
        <translation type="vanished">Traduire le texte en anglais</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="481"/>
        <source>You are a professional translator. Translate the text to English, preserving style and meaning.</source>
        <translation>Vous êtes un traducteur professionnel. Traduisez le texte en anglais en conservant le style et le sens.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="493"/>
        <source>Explain Code</source>
        <translation>Expliquer le code</translation>
    </message>
    <message>
        <source>Explain what the code does</source>
        <translation type="vanished">Expliquer ce que fait le code</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="495"/>
        <source>You are an expert programmer. Explain the code clearly and concisely.</source>
        <translation>Vous êtes un programmeur expert. Expliquez le code clairement et concisément.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="496"/>
        <source>Explain the following code:

{clipboard}</source>
        <translation>Expliquez le code suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="507"/>
        <source>Code Review</source>
        <translation>Revue de code</translation>
    </message>
    <message>
        <source>Review code and suggest improvements</source>
        <translation type="vanished">Examiner le code et suggérer des améliorations</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="509"/>
        <source>You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements.</source>
        <translation>Vous êtes un réviseur de code. Analysez le code pour les bugs, problèmes de sécurité et suggérez des améliorations.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="510"/>
        <source>Review the following code:

{clipboard}</source>
        <translation>Examinez le code suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="521"/>
        <source>Refactor Code</source>
        <translation>Refactoriser le code</translation>
    </message>
    <message>
        <source>Suggest refactoring improvements</source>
        <translation type="vanished">Suggérer des améliorations de refactoring</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="523"/>
        <source>You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance.</source>
        <translation>Vous êtes un expert en optimisation de code. Suggérez un refactoring pour améliorer la lisibilité, la maintenabilité et les performances.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="524"/>
        <source>Refactor the following code:

{clipboard}</source>
        <translation>Refactorisez le code suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="535"/>
        <source>Describe Image</source>
        <translation>Décrire l&apos;image</translation>
    </message>
    <message>
        <source>Generate a detailed description of the image</source>
        <translation type="vanished">Générer une description détaillée de l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="537"/>
        <source>You are a visual analyst. Provide a detailed description of the image.</source>
        <translation>Vous êtes un analyste visuel. Fournissez une description détaillée de l&apos;image.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="538"/>
        <source>Describe this image in detail.</source>
        <translation>Décrivez cette image en détail.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="549"/>
        <source>Extract Text</source>
        <translation>Extraire le texte</translation>
    </message>
    <message>
        <source>Extract all text from the image</source>
        <translation type="vanished">Extraire tout le texte de l&apos;image</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="551"/>
        <source>Extract all text from the image, preserving formatting where possible.</source>
        <translation>Extrayez tout le texte de l&apos;image en préservant la mise en forme si possible.</translation>
    </message>
    <message>
        <location filename="../src/core/promptmanager.cpp" line="552"/>
        <source>Extract all text from this image.</source>
        <translation>Extrayez tout le texte de cette image.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::GroupsDialog</name>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="53"/>
        <source>Manage Groups</source>
        <translation>Gérer les groupes</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="59"/>
        <source>Right-click to add, rename, or delete groups. Drag and drop to move groups.</source>
        <translation>Clic droit pour ajouter, renommer ou supprimer des groupes. Glisser-déposer pour déplacer des groupes.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="67"/>
        <source>Group Name</source>
        <translation>Nom du groupe</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="90"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="104"/>
        <source>Root</source>
        <translation>Racine</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="198"/>
        <source>New Group...</source>
        <translation>Nouveau groupe...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="202"/>
        <source>New Subgroup...</source>
        <translation>Nouveau sous-groupe...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="205"/>
        <source>Rename...</source>
        <translation>Renommer...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="210"/>
        <source>Delete...</source>
        <translation>Supprimer...</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="221"/>
        <source>New Group</source>
        <translation>Nouveau groupe</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="222"/>
        <source>Enter group name:</source>
        <translation>Entrez le nom du groupe :</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="232"/>
        <location filename="../src/ui/groupsdialog.cpp" line="269"/>
        <source>Duplicate Group</source>
        <translation>Groupe en double</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="233"/>
        <source>A group with this name already exists.</source>
        <translation>Un groupe avec ce nom existe déjà.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="258"/>
        <source>New Subgroup</source>
        <translation>Nouveau sous-groupe</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="259"/>
        <source>Enter subgroup name:</source>
        <translation>Entrez le nom du sous-groupe :</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="270"/>
        <source>A subgroup with this name already exists.</source>
        <translation>Un sous-groupe avec ce nom existe déjà.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="309"/>
        <source>(root)</source>
        <translation>(racine)</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="321"/>
        <source>Delete group &apos;%1&apos;?

%2 prompt(s) in this group will be moved to root.</source>
        <translation>Supprimer le groupe &apos;%1&apos; ?

%2 prompt(s) de ce groupe seront déplacés vers la racine.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="324"/>
        <source>Delete group &apos;%1&apos;?</source>
        <translation>Supprimer le groupe &apos;%1&apos; ?</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="328"/>
        <source>Delete Group</source>
        <translation>Supprimer le groupe</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="372"/>
        <source>Invalid Name</source>
        <translation>Nom invalide</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="373"/>
        <source>Group name cannot be empty.</source>
        <translation>Le nom du groupe ne peut pas être vide.</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="393"/>
        <source>Duplicate Name</source>
        <translation>Nom en double</translation>
    </message>
    <message>
        <location filename="../src/ui/groupsdialog.cpp" line="394"/>
        <source>A group with this name already exists in this location.</source>
        <translation>Un groupe avec ce nom existe déjà à cet emplacement.</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::HistoryDialog</name>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="54"/>
        <source>ClipLLM - History</source>
        <translation>ClipLLM - Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="63"/>
        <source>Search in history...</source>
        <translation>Rechercher dans l&apos;historique...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="69"/>
        <source>Filters</source>
        <translation>Filtres</translation>
    </message>
    <message>
        <source>Search...</source>
        <translation type="vanished">Rechercher...</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="73"/>
        <location filename="../src/ui/historydialog.cpp" line="294"/>
        <source>All Models</source>
        <translation>Tous les modèles</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="78"/>
        <location filename="../src/ui/historydialog.cpp" line="301"/>
        <source>All Prompts</source>
        <translation>Tous les prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="82"/>
        <source>Favorites only</source>
        <translation>Favoris seulement</translation>
    </message>
    <message>
        <source>Search:</source>
        <translation type="vanished">Rechercher :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="100"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="102"/>
        <source>Prompt:</source>
        <translation>Prompt :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="105"/>
        <source>From:</source>
        <translation>De :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="107"/>
        <source>To:</source>
        <translation>À :</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="130"/>
        <source>Preview</source>
        <translation>Aperçu</translation>
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
        <translation>Brut</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="158"/>
        <source>View Details</source>
        <translation>Voir les détails</translation>
    </message>
    <message>
        <source>Copy Output</source>
        <translation type="vanished">Copier la sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="163"/>
        <location filename="../src/ui/historydialog.cpp" line="427"/>
        <source>Favorite</source>
        <translation>Favori</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="168"/>
        <source>Delete</source>
        <translation>Supprimer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="173"/>
        <source>Export</source>
        <translation>Exporter</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="177"/>
        <source>Clear All</source>
        <translation>Tout effacer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="181"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="197"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="198"/>
        <source>Zoom out</source>
        <translation>Zoom arrière</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="202"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="203"/>
        <source>Zoom in</source>
        <translation>Zoom avant</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="228"/>
        <source>Date</source>
        <translation>Date</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="229"/>
        <source>Prompt</source>
        <translation>Prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="230"/>
        <source>Model</source>
        <translation>Modèle</translation>
    </message>
    <message>
        <source>Input Preview</source>
        <translation type="vanished">Aperçu de l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="231"/>
        <source>Output Preview</source>
        <translation>Aperçu de la sortie</translation>
    </message>
    <message>
        <source>Duration</source>
        <translation type="vanished">Durée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="232"/>
        <source>ID</source>
        <translation>ID</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="319"/>
        <source>Total entries: %1</source>
        <translation>Total des entrées : %1</translation>
    </message>
    <message>
        <source>No history entries.\nEnable &apos;Automatically save to history&apos; in Settings\nor save prompts manually to populate this list.</source>
        <translation type="vanished">Aucune entrée d&apos;historique.\nActivez &apos;Sauvegarder automatiquement dans l&apos;historique&apos; dans les Paramètres\nou enregistrez manuellement des prompts pour remplir cette liste.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="551"/>
        <location filename="../src/ui/historydialog.cpp" line="560"/>
        <source>Unknown</source>
        <translation>Inconnu</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="369"/>
        <source>Showing %1 entries</source>
        <translation>Affichage de %1 entrées</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="264"/>
        <source>No history entries.
Enable &apos;Automatically save to history&apos; in Settings
or save prompts manually to populate this list.</source>
        <translation>Aucune entrée d&apos;historique.
Activez &apos;Enregistrer automatiquement dans l&apos;historique&apos; dans Paramètres
ou enregistrez les prompts manuellement pour remplir cette liste.</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="270"/>
        <source>Total entries: 0</source>
        <translation>Total des entrées : 0</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="580"/>
        <source>Prompt: %1
</source>
        <translation>Prompt : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="581"/>
        <source>Model: %1
</source>
        <translation>Modèle : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="582"/>
        <source>Date: %1
</source>
        <translation>Date : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="583"/>
        <source>Duration: %1
</source>
        <translation>Durée : %1
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="584"/>
        <source>Tokens: %1 input / %2 output
</source>
        <translation>Jetons : %1 entrée / %2 sortie
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="588"/>
        <source>Input:
</source>
        <translation>Entrée :
</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="590"/>
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
        <location filename="../src/ui/historydialog.cpp" line="427"/>
        <source>Unfavorite</source>
        <translation>Retirer des favoris</translation>
    </message>
    <message>
        <source>Copied to clipboard</source>
        <translation type="vanished">Copié dans le presse-papiers</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="443"/>
        <source>Delete Entry</source>
        <translation>Supprimer l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="444"/>
        <source>Are you sure you want to delete this entry?</source>
        <translation>Voulez-vous vraiment supprimer cette entrée ?</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="472"/>
        <source>Export History</source>
        <translation>Exporter l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="474"/>
        <source>JSON Files (*.json)</source>
        <translation>Fichiers JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="495"/>
        <source>Exported to %1</source>
        <translation>Exporté vers %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="497"/>
        <source>Export Failed</source>
        <translation>Échec de l&apos;export</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="498"/>
        <source>Failed to write to file: %1</source>
        <translation>Échec de l&apos;écriture dans le fichier : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="506"/>
        <source>Clear All History</source>
        <translation>Effacer tout l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/historydialog.cpp" line="507"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Voulez-vous vraiment supprimer toutes les entrées de l&apos;historique ? Cela ne peut pas être annulé.</translation>
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
        <translation>Appuyer sur le raccourci...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="41"/>
        <location filename="../src/ui/hotkeyedit.cpp" line="196"/>
        <source>Record</source>
        <translation>Enregistrer</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="48"/>
        <source>Clear</source>
        <translation>Effacer</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="175"/>
        <source>Stop</source>
        <translation>Arrêter</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="176"/>
        <source>Press key combination...</source>
        <translation>Appuyer sur la combinaison de touches...</translation>
    </message>
    <message>
        <location filename="../src/ui/hotkeyedit.cpp" line="208"/>
        <source>None</source>
        <translation>Aucun</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ImageViewDialog</name>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="45"/>
        <source>Clipboard Image</source>
        <translation>Image du presse-papiers</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="62"/>
        <source>Size: %1 x %2 pixels</source>
        <translation>Taille : %1 x %2 pixels</translation>
    </message>
    <message>
        <location filename="../src/ui/imageviewdialog.cpp" line="72"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptConflictDialog</name>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="32"/>
        <source>Prompt Conflict</source>
        <translation>Conflit de prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="39"/>
        <source>A prompt named &quot;%1&quot; already exists.</source>
        <translation>Un prompt nommé &quot;%1&quot; existe déjà.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="47"/>
        <source>&lt;b&gt;Existing:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Existant :&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="53"/>
        <source>&lt;b&gt;New:&lt;/b&gt; %1</source>
        <translation>&lt;b&gt;Nouveau :&lt;/b&gt; %1</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="60"/>
        <source>Do you want to replace it?</source>
        <translation>Voulez-vous le remplacer ?</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="69"/>
        <source>Yes</source>
        <translation>Oui</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="70"/>
        <source>Yes for all</source>
        <translation>Oui pour tous</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="71"/>
        <source>No</source>
        <translation>Non</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="72"/>
        <source>No for all</source>
        <translation>Non pour tous</translation>
    </message>
    <message>
        <location filename="../src/ui/promptconfirmdialog.cpp" line="73"/>
        <source>Cancel</source>
        <translation>Annuler</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptEditorDialog</name>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="71"/>
        <source>Add Prompt</source>
        <translation>Ajouter un prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="119"/>
        <source>Edit Prompt</source>
        <translation>Modifier le prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="224"/>
        <source>Basic Information</source>
        <translation>Informations de base</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="228"/>
        <source>e.g., custom_prompt</source>
        <translation>ex., custom_prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="241"/>
        <source>ID:</source>
        <translation>ID :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="244"/>
        <source>e.g., My Custom Prompt</source>
        <translation>ex., Mon prompt personnalisé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="246"/>
        <source>Name:</source>
        <translation>Nom :</translation>
    </message>
    <message>
        <source>e.g., Does something useful</source>
        <translation type="vanished">ex., Fait quelque chose d&apos;utile</translation>
    </message>
    <message>
        <source>Description:</source>
        <translation type="vanished">Description :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="250"/>
        <source>(root)</source>
        <translation>(racine)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="271"/>
        <source>Group:</source>
        <translation>Groupe :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="215"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="194"/>
        <source>System Prompt:</source>
        <translation>Prompt système :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="197"/>
        <source>You are a helpful assistant...</source>
        <translation>Vous êtes un assistant utile...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="201"/>
        <source>User Prompt Template:</source>
        <translation>Modèle de prompt utilisateur :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="204"/>
        <source>Process the following text:

{clipboard}</source>
        <translation>Traitez le texte suivant :

{clipboard}</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="210"/>
        <source>Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user&apos;s language.</source>
        <translation>Utilisez {clipboard} pour insérer le contenu du presse-papiers, {clipboard:1000} pour le contenu tronqué, {language} pour la langue de l&apos;utilisateur.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="392"/>
        <source>Settings</source>
        <translation>Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="274"/>
        <source>Text</source>
        <translation>Texte</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="275"/>
        <source>Image</source>
        <translation>Image</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="276"/>
        <source>Any</source>
        <translation>Tout</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="277"/>
        <source>Content Type:</source>
        <translation>Type de contenu :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="313"/>
        <source>Override provider and model</source>
        <translation>Remplacer le fournisseur et le modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="314"/>
        <source>When checked, use specific provider and model instead of defaults</source>
        <translation>Lorsque coché, utilise un fournisseur et un modèle spécifiques au lieu des valeurs par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="320"/>
        <source>Select provider for this prompt</source>
        <translation>Sélectionner le fournisseur pour ce prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="329"/>
        <source>Select or enter model name</source>
        <translation>Sélectionner ou entrer le nom du modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="332"/>
        <source>Refresh</source>
        <translation>Actualiser</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="292"/>
        <source>Optional global hotkey to directly execute this prompt</source>
        <translation>Raccourci clavier global optionnel pour exécuter directement ce prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="304"/>
        <source>Hotkey:</source>
        <translation>Raccourci :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="368"/>
        <source>Select next prompt in the chain (only text prompts available)</source>
        <translation>Sélectionner le prompt suivant dans la chaîne (prompts texte uniquement)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="371"/>
        <source>Next Prompt:</source>
        <translation>Prompt suivant :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="373"/>
        <source>Auto-continue to next prompt</source>
        <translation>Continuer automatiquement vers le prompt suivant</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="374"/>
        <source>Automatically run the next prompt after this one completes</source>
        <translation>Exécuter automatiquement le prompt suivant après celui-ci</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="169"/>
        <source>Export</source>
        <translation>Exporter</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="232"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="876"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="884"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="926"/>
        <source>Rename ID</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="233"/>
        <source>Change the prompt ID</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="309"/>
        <source>LLM Settings</source>
        <translation>Paramètres LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="364"/>
        <source>Chain Settings</source>
        <translation>Paramètres de chaîne</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="575"/>
        <source>(Select provider first)</source>
        <translation>(Sélectionner d&apos;abord le fournisseur)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="582"/>
        <source>(Provider not found)</source>
        <translation>(Fournisseur non trouvé)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="600"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="611"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1077"/>
        <source>(Custom model...)</source>
        <translation>(Modèle personnalisé...)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="768"/>
        <source>Chain Cycle Detected</source>
        <translation>Cycle de chaîne détecté</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="769"/>
        <source>This prompt would create a cycle in the chain.

Please select a different &apos;Next Prompt&apos; or set it to &apos;(None)&apos;.</source>
        <translation>Ce prompt créerait un cycle dans la chaîne.

Veuillez sélectionner un &apos;Prompt suivant&apos; différent ou le définir sur &apos;(Aucun)&apos;.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="804"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="816"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="838"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="846"/>
        <source>Export Prompt</source>
        <translation>Exporter le prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="805"/>
        <source>Cannot export: prompt is not valid.</source>
        <translation>Impossible d&apos;exporter : le prompt n&apos;est pas valide.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="818"/>
        <source>JSON Files (*.json)</source>
        <translation>Fichiers JSON (*.json)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="839"/>
        <source>Failed to open file for writing: %1</source>
        <translation>Impossible d&apos;ouvrir le fichier en écriture : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="847"/>
        <source>Prompt exported to %1</source>
        <translation>Prompt exporté vers %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="861"/>
        <source>Rename Prompt ID</source>
        <translation>Renommer l&apos;ID du prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="862"/>
        <source>Enter new ID for this prompt:</source>
        <translation>Entrez le nouvel ID pour ce prompt :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="877"/>
        <source>New ID is the same as the current ID.</source>
        <translation>Le nouvel ID est identique à l&apos;ID actuel.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="892"/>
        <source>Rename ID - Historical Records</source>
        <translation>Renommer l&apos;ID — Enregistrements historiques</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="893"/>
        <source>Historical records of this prompt will remain with the old ID &quot;%1&quot;.

When re-running prompts from history, they will use the old ID.

Continue with renaming?</source>
        <translation>Les enregistrements historiques de ce prompt conserveront l&apos;ancien ID &quot;%1&quot;.

Lors de la réexécution de prompts depuis l&apos;historique, l&apos;ancien ID sera utilisé.

Continuer le renommage ?</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="927"/>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.

Click OK to save the changes.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>Prompt ID has been renamed from &quot;%1&quot; to &quot;%2&quot;.

All chain references have been updated.</source>
        <translation type="vanished">L&apos;ID du prompt a été renommé de &quot;%1&quot; à &quot;%2&quot;.

Toutes les références de chaîne ont été mises à jour.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="955"/>
        <source>No provider selected</source>
        <translation>Aucun fournisseur sélectionné</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="962"/>
        <source>Provider not found</source>
        <translation>Fournisseur non trouvé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="970"/>
        <source>Model fetching not supported for this provider</source>
        <translation>Récupération des modèles non prise en charge pour ce fournisseur</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1025"/>
        <source>Fetching models...</source>
        <translation>Récupération des modèles...</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1041"/>
        <source>Error: %1</source>
        <translation>Erreur : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1054"/>
        <source>Error: Invalid response</source>
        <translation>Erreur : réponse invalide</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1066"/>
        <source>No models found</source>
        <translation>Aucun modèle trouvé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1103"/>
        <source>Loaded %1 models</source>
        <translation>%1 modèles chargés</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1141"/>
        <source>Hotkey Conflict</source>
        <translation>Conflit de raccourcis</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1142"/>
        <source>This hotkey is already in use by another prompt or the global hotkey.

Please choose a different hotkey.</source>
        <translation>Ce raccourci est déjà utilisé par un autre prompt ou le raccourci global.

Veuillez choisir un autre raccourci.</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1186"/>
        <source>(None)</source>
        <translation>(Aucun)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1216"/>
        <source> (disabled)</source>
        <translation> (désactivé)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1289"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="1307"/>
        <source>Warning: This would create a cycle in the chain!</source>
        <translation>Attention : Cela créerait un cycle dans la chaîne !</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="1301"/>
        <source>Warning: Target prompt is part of an existing cycle!</source>
        <translation>Attention : Le prompt cible fait partie d&apos;un cycle existant !</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="323"/>
        <source>Provider:</source>
        <translation>Fournisseur :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="291"/>
        <source>None</source>
        <translation>Aucun</translation>
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
        <source>Use default model from settings</source>
        <translation type="vanished">Utiliser le modèle par défaut des paramètres</translation>
    </message>
    <message>
        <source>e.g., openai/gpt-4, anthropic/claude-3-opus</source>
        <translation type="vanished">ex., openai/gpt-4, anthropic/claude-3-opus</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="343"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="346"/>
        <source>Use default temperature from settings</source>
        <translation>Utiliser la température par défaut des paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="354"/>
        <source>Temperature:</source>
        <translation>Température :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="359"/>
        <source>Max Tokens:</source>
        <translation>Jetons max :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="279"/>
        <source>Enabled</source>
        <translation>Activé</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="287"/>
        <source>Higher priority prompts appear first in the menu</source>
        <translation>Les prompts de priorité plus élevée apparaissent en premier dans le menu</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="288"/>
        <source>Priority (higher = first):</source>
        <translation>Priorité (plus élevé = premier) :</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="173"/>
        <source>Prompt Preview</source>
        <translation>Aperçu du prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="177"/>
        <source>OK</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="182"/>
        <source>Cancel</source>
        <translation>Annuler</translation>
    </message>
    <message>
        <source>Uses global default model</source>
        <translation type="vanished">Utilise le modèle global par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="629"/>
        <source>(No providers available)</source>
        <translation>(Aucun fournisseur disponible)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="638"/>
        <source>(No providers configured)</source>
        <translation>(Aucun fournisseur configuré)</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="705"/>
        <source>Name is required</source>
        <translation>Nom requis</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="709"/>
        <source>ID is required</source>
        <translation>ID requis</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="724"/>
        <source>Invalid placeholder in user template: %1</source>
        <translation>Espace réservé invalide dans le modèle utilisateur : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="734"/>
        <source>Invalid placeholder in system prompt: %1</source>
        <translation>Espace réservé invalide dans le prompt système : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="744"/>
        <location filename="../src/ui/prompteditordialog.cpp" line="885"/>
        <source>ID already exists: %1</source>
        <translation>L&apos;ID existe déjà : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="778"/>
        <source>Validation Error</source>
        <translation>Erreur de validation</translation>
    </message>
    <message>
        <location filename="../src/ui/prompteditordialog.cpp" line="779"/>
        <source>The prompt has validation errors:

%1</source>
        <translation>Le prompt contient des erreurs de validation :

%1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptMenu</name>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="59"/>
        <source>Search prompts...</source>
        <translation>Rechercher des prompts...</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="69"/>
        <source>History</source>
        <translation>Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="77"/>
        <source>Settings</source>
        <translation>Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="143"/>
        <source>No prompts available</source>
        <translation>Aucun prompt disponible</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="172"/>
        <source>No prompts available for this content type</source>
        <translation>Aucun prompt disponible pour ce type de contenu</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="194"/>
        <source>No prompts found</source>
        <translation>Aucun prompt trouvé</translation>
    </message>
    <message>
        <location filename="../src/ui/promptmenu.cpp" line="213"/>
        <source>Add priority to prompts to see them here</source>
        <translation>Ajoutez une priorité aux prompts pour les voir ici</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::PromptPreviewDialog</name>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="75"/>
        <source>⚠ This prompt is configured for Text content only, but there is an image in the clipboard. The image will be ignored.</source>
        <translation>⚠ Ce prompt est configuré pour le contenu Texte uniquement, mais il y a une image dans le presse-papiers. L&apos;image sera ignorée.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="84"/>
        <source>⚠ This prompt is configured for Image content only, but there is text in the clipboard. Only the image will be sent to the model.</source>
        <translation>⚠ Ce prompt est configuré pour le contenu Image uniquement, mais il y a du texte dans le presse-papiers. Seule l&apos;image sera envoyée au modèle.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="87"/>
        <source>⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn&apos;t contain an image.</source>
        <translation>⚠ Ce prompt est configuré pour le contenu Image uniquement, mais le presse-papiers est vide ou ne contient pas d&apos;image.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="181"/>
        <source>%1x%2</source>
        <translation>%1x%2</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="221"/>
        <source>Prompt Preview</source>
        <translation>Aperçu du prompt</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="233"/>
        <source>Request that will be sent to the API</source>
        <translation>Requête qui sera envoyée à l&apos;API</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="246"/>
        <source>This is the exact JSON that will be sent to the LLM API. Clipboard content is substituted for {clipboard} placeholder. Click the image link to view the full image.</source>
        <translation>Ceci est le JSON exact qui sera envoyé à l&apos;API LLM. Le contenu du presse-papiers est substitué à l&apos;espace réservé {clipboard}. Cliquez sur le lien de l&apos;image pour voir l&apos;image complète.</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="258"/>
        <source>Refresh</source>
        <translation>Actualiser</translation>
    </message>
    <message>
        <location filename="../src/ui/promptpreviewdialog.cpp" line="262"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::ResultDialog</name>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="49"/>
        <source>ClipLLM - Result</source>
        <translation>ClipLLM - Résultat</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="90"/>
        <location filename="../src/ui/resultdialog.cpp" line="274"/>
        <source>Model: -</source>
        <translation>Modèle : -</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="92"/>
        <source>Tokens: 0 / 0</source>
        <translation>Jetons : 0 / 0</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="93"/>
        <location filename="../src/ui/resultdialog.cpp" line="301"/>
        <source>Traffic: 0 B</source>
        <translation>Trafic : 0 o</translation>
    </message>
    <message>
        <source>Settings</source>
        <translation type="obsolete">Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="110"/>
        <source>Ready</source>
        <translation>Prêt</translation>
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
        <translation>Brut</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="129"/>
        <location filename="../src/ui/resultdialog.cpp" line="692"/>
        <source>Show Input</source>
        <translation>Afficher l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="144"/>
        <source>Input</source>
        <translation>Entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="154"/>
        <source>Output</source>
        <translation>Sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="171"/>
        <source>Copy &amp;&amp; close</source>
        <translation>Copier et fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="176"/>
        <source>Save to History</source>
        <translation>Enregistrer dans l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="181"/>
        <source>Save as...</source>
        <translation>Enregistrer sous...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="184"/>
        <source>Save output to a file</source>
        <translation>Enregistrer la sortie dans un fichier</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="187"/>
        <source>Retry</source>
        <translation>Réessayer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="192"/>
        <source>Continue</source>
        <translation>Continuer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="198"/>
        <source>Close</source>
        <translation>Fermer</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="203"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="204"/>
        <source>Zoom out</source>
        <translation>Zoom arrière</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="208"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="209"/>
        <source>Zoom in</source>
        <translation>Zoom avant</translation>
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
        <translation>Modèle : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="280"/>
        <source>Model: %1 / %2</source>
        <translation>Modèle : %1 / %2</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="302"/>
        <source>Connecting...</source>
        <translation>Connexion...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="333"/>
        <source>Tokens: ~%1</source>
        <translation>Jetons : ~%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="346"/>
        <source>Completed in %1 seconds</source>
        <translation>Terminé en %1 secondes</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="351"/>
        <source>Tokens: %1 input / %2 output</source>
        <translation>Jetons : %1 entrée / %2 sortie</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="389"/>
        <location filename="../src/ui/resultdialog.cpp" line="417"/>
        <source>API Error</source>
        <translation>Erreur API</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="390"/>
        <location filename="../src/ui/resultdialog.cpp" line="418"/>
        <source>An error occurred while communicating with the API:

%1</source>
        <translation>Une erreur s&apos;est produite lors de la communication avec l&apos;API :

%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="393"/>
        <location filename="../src/ui/resultdialog.cpp" line="426"/>
        <source>Error: %1</source>
        <translation>Erreur : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="459"/>
        <source>Saved</source>
        <translation>Enregistré</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="483"/>
        <source>Save Output As</source>
        <translation>Enregistrer la sortie sous</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="485"/>
        <source>Text Files (*.txt);;All Files (*)</source>
        <translation>Fichiers texte (*.txt);;Tous les fichiers (*)</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="512"/>
        <source>Saved to %1</source>
        <translation>Enregistré sous %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="518"/>
        <source>Save Failed</source>
        <translation>Échec de l&apos;enregistrement</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="519"/>
        <source>Could not write to file:
%1</source>
        <translation>Impossible d&apos;écrire dans le fichier :
%1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="582"/>
        <source>Close During Generation</source>
        <translation>Fermer pendant la génération</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="583"/>
        <source>A response is still being generated. Close and cancel the request?</source>
        <translation>Une réponse est encore en cours de génération. Fermer et annuler la requête ?</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="591"/>
        <source>Cancelling...</source>
        <translation>Annulation...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="632"/>
        <source>Model is thinking...</source>
        <translation>Le modèle réfléchit...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="635"/>
        <source>Generating response...</source>
        <translation>Génération de la réponse...</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="644"/>
        <source>Traffic: %1</source>
        <translation>Trafic : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="688"/>
        <source>Hide Input</source>
        <translation>Masquer l&apos;entrée</translation>
    </message>
    <message>
        <location filename="../src/ui/resultdialog.cpp" line="795"/>
        <source>Chain: %1</source>
        <translation>Chaîne : %1</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::SettingsDialog</name>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="92"/>
        <source>ClipLLM - Settings</source>
        <translation>ClipLLM - Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="125"/>
        <location filename="../src/ui/settingsdialog.cpp" line="517"/>
        <source>Reset to Defaults</source>
        <translation>Réinitialiser par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="143"/>
        <source>Language</source>
        <translation>Langue</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="150"/>
        <source>Interface Language:</source>
        <translation>Langue de l&apos;interface :</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the tray menu (disabled by default for cleaner menu)</source>
        <translation type="vanished">Afficher les descriptions des prompts dans le menu de la zone de notification (désactivé par défaut pour un menu plus épuré)</translation>
    </message>
    <message>
        <source>Show prompt descriptions in the popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Afficher les descriptions des prompts dans le menu contextuel (désactivé par défaut pour un menu plus épuré)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="188"/>
        <source>Prompt Chains</source>
        <translation>Chaînes de prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="194"/>
        <source>Maximum number of prompts in a chain to prevent infinite loops</source>
        <translation>Nombre maximum de prompts dans une chaîne pour éviter les boucles infinies</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="195"/>
        <source>Maximum Chain Depth:</source>
        <translation>Profondeur maximale de chaîne :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="200"/>
        <source>Debug</source>
        <translation>Débogage</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="203"/>
        <source>Record debug messages</source>
        <translation>Enregistrer les messages de débogage</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="204"/>
        <source>Write debug information to debug.log file in the configuration directory</source>
        <translation>Écrire les informations de débogage dans le fichier debug.log dans le répertoire de configuration</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="212"/>
        <source>Normal</source>
        <translation>Normal</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="213"/>
        <source>Basic debug information</source>
        <translation>Informations de débogage de base</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="214"/>
        <source>Trace</source>
        <translation>Trace</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="215"/>
        <source>Full request/response logging for LLM</source>
        <translation>Journalisation complète des requêtes/réponses pour LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="224"/>
        <source>Debug Level:</source>
        <translation>Niveau de débogage :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="235"/>
        <source>Log file:</source>
        <translation>Fichier journal :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="238"/>
        <source>Copy</source>
        <translation>Copier</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="588"/>
        <source>History</source>
        <translation>Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="536"/>
        <source>Automatically save to history after generation</source>
        <translation>Enregistrer automatiquement dans l&apos;historique après génération</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="258"/>
        <source>General</source>
        <translation>Général</translation>
    </message>
    <message>
        <source>LLM Provider</source>
        <translation type="vanished">Fournisseur LLM</translation>
    </message>
    <message>
        <source>Provider:</source>
        <translation type="vanished">Fournisseur :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="337"/>
        <source>Select or enter model name...</source>
        <translation>Sélectionner ou entrer le nom du modèle...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="342"/>
        <source>Refresh</source>
        <translation>Actualiser</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="348"/>
        <source>Model:</source>
        <translation>Modèle :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="354"/>
        <source>API Key:</source>
        <translation>Clé API :</translation>
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
        <translation type="vanished">Utilisé uniquement lorsque le fournisseur est défini sur Personnalisé.

Exemples :
• Ollama : http://localhost:11434/v1/chat/completions
• LM Studio : http://localhost:1234/v1/chat/completions
• LocalAI : http://localhost:8080/v1/chat/completions</translation>
    </message>
    <message>
        <source>Custom API URL:</source>
        <translation type="vanished">URL API personnalisée :</translation>
    </message>
    <message>
        <source>http://host:port or socks5://host:port</source>
        <translation type="vanished">http://host:port or socks5://host:port</translation>
    </message>
    <message>
        <source>Proxy (optional):</source>
        <translation type="vanished">Proxy (facultatif) :</translation>
    </message>
    <message>
        <source>Options</source>
        <translation type="vanished">Options</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="377"/>
        <location filename="../src/ui/settingsdialog.cpp" line="410"/>
        <source>Temperature:</source>
        <translation>Température :</translation>
    </message>
    <message>
        <source>Override temperature</source>
        <translation type="vanished">Remplacer la température</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="384"/>
        <location filename="../src/ui/settingsdialog.cpp" line="420"/>
        <source>Max Tokens:</source>
        <translation>Jetons max :</translation>
    </message>
    <message>
        <source>Enable streaming responses</source>
        <translation type="vanished">Activer les réponses en streaming</translation>
    </message>
    <message>
        <source>Test Connection</source>
        <translation type="vanished">Tester la connexion</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="437"/>
        <source>LLM</source>
        <translation>LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="155"/>
        <source>Global Hotkey</source>
        <translation>Raccourci global</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="172"/>
        <source>Activate Clipboard Processing:</source>
        <translation>Activer le traitement du presse-papiers :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="175"/>
        <source>&lt;b&gt;Note:&lt;/b&gt; Global hotkeys may not work on Wayland. On X11, the hotkey works globally. On Windows and macOS, global hotkeys are fully supported.</source>
        <translation>&lt;b&gt;Note :&lt;/b&gt; Les raccourcis globaux peuvent ne pas fonctionner sur Wayland. Sur X11, le raccourci fonctionne globalement. Sur Windows et macOS, les raccourcis globaux sont entièrement pris en charge.</translation>
    </message>
    <message>
        <source>Hotkeys</source>
        <translation type="vanished">Raccourcis</translation>
    </message>
    <message>
        <source>Menu Settings</source>
        <translation type="vanished">Paramètres du menu</translation>
    </message>
    <message>
        <source>Maximum number of prompts to show in the menu</source>
        <translation type="vanished">Nombre maximum de prompts à afficher dans le menu</translation>
    </message>
    <message>
        <source>Max Prompts in Menu:</source>
        <translation type="vanished">Max prompts dans le menu :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Name</source>
        <translation>Nom</translation>
    </message>
    <message>
        <source>Description</source>
        <translation type="vanished">Description</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Content Type</source>
        <translation>Type de contenu</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Model</source>
        <translation>Modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Priority</source>
        <translation>Priorité</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Group</source>
        <translation>Groupe</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="466"/>
        <source>Add</source>
        <translation>Ajouter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="470"/>
        <source>Edit</source>
        <translation>Modifier</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="475"/>
        <source>Delete</source>
        <translation>Supprimer</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="488"/>
        <source>Manage Groups...</source>
        <translation>Gérer les groupes...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="509"/>
        <source>Import</source>
        <translation>Importer</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="513"/>
        <source>Export</source>
        <translation>Exporter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="527"/>
        <source>Prompts</source>
        <translation>Prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="539"/>
        <source>History Settings</source>
        <translation>Paramètres de l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="551"/>
        <source>Unlimited</source>
        <translation>Illimité</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="555"/>
        <source>Maximum entries:</source>
        <translation>Entrées maximum :</translation>
    </message>
    <message>
        <source>Automatically clean up old entries</source>
        <translation type="vanished">Nettoyer automatiquement les anciennes entrées</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="542"/>
        <source>Auto-cleanup by max entries</source>
        <translation>Nettoyage auto par max entrées</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="543"/>
        <source>Automatically remove oldest entries when limit is exceeded</source>
        <translation>Supprimer automatiquement les entrées les plus anciennes lorsque la limite est dépassée</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="557"/>
        <source>Auto-cleanup by date</source>
        <translation>Nettoyage auto par date</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="558"/>
        <source>Automatically remove entries older than the specified number of days</source>
        <translation>Supprimer automatiquement les entrées plus anciennes que le nombre de jours spécifié</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="569"/>
        <source>Days to keep:</source>
        <translation>Jours à conserver :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="573"/>
        <source>Actions</source>
        <translation>Actions</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="576"/>
        <source>Clear All History</source>
        <translation>Effacer tout l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="720"/>
        <source>English</source>
        <translation>Anglais</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="721"/>
        <source>Russian</source>
        <translation>Russe</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="722"/>
        <source>German</source>
        <translation>Allemand</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="723"/>
        <source>French</source>
        <translation>Français</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="724"/>
        <source>Spanish</source>
        <translation>Espagnol</translation>
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
        <translation type="vanished">Personnalisé</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="773"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1141"/>
        <source>(root)</source>
        <translation>(racine)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="811"/>
        <source>Reset Settings</source>
        <translation>Réinitialiser les paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="812"/>
        <source>Are you sure you want to reset all settings to defaults?</source>
        <translation>Voulez-vous vraiment réinitialiser tous les paramètres par défaut ?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="837"/>
        <source>Language Changed</source>
        <translation>Langue modifiée</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="838"/>
        <source>The language will be changed after you restart the application.</source>
        <translation>La langue sera modifiée après le redémarrage de l&apos;application.</translation>
    </message>
    <message>
        <source>Configuration valid</source>
        <translation type="vanished">Configuration valide</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1265"/>
        <source>Failed to open file: %1</source>
        <translation>Impossible d&apos;ouvrir le fichier : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1275"/>
        <source>Failed to parse JSON file: %1</source>
        <translation>Impossible d&apos;analyser le fichier JSON : %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1289"/>
        <source>Prompts imported successfully.</source>
        <translation>Prompts importés avec succès.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1486"/>
        <source>No API URL set</source>
        <translation>URL de l&apos;API non définie</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1678"/>
        <source>No provider profiles configured.
Click &apos;+ Add&apos; to create one.</source>
        <translation>Aucun profil de fournisseur configuré.
Cliquez sur &apos;+ Ajouter&apos; pour en créer un.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1693"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1798"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1872"/>
        <source> [Default]</source>
        <translation> [Par défaut]</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1699"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1798"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1875"/>
        <source> (disabled)</source>
        <translation> (désactivé)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1736"/>
        <source>Add Provider Profile</source>
        <translation>Ajouter un profil de fournisseur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1737"/>
        <source>Select a template or create custom:</source>
        <translation>Sélectionner un modèle ou créer un personnalisé :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1802"/>
        <source>Remove Profile</source>
        <translation>Supprimer le profil</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1803"/>
        <source>Are you sure you want to remove the profile &quot;%1&quot;?</source>
        <translation>Êtes-vous sûr de vouloir supprimer le profil &quot;%1&quot; ?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1946"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2023"/>
        <source>API key set</source>
        <translation>Clé API définie</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1946"/>
        <location filename="../src/ui/settingsdialog.cpp" line="2023"/>
        <source>No API key</source>
        <translation>Pas de clé API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="844"/>
        <source>Testing...</source>
        <translation>Test en cours...</translation>
    </message>
    <message>
        <source>Miscellaneous</source>
        <translation type="vanished">Divers</translation>
    </message>
    <message>
        <source>Show prompt descriptions in menu</source>
        <translation type="vanished">Afficher les descriptions de prompt dans le menu</translation>
    </message>
    <message>
        <source>Show prompt descriptions in tray menu (disabled by default for cleaner menu)</source>
        <translation type="vanished">Afficher les descriptions de prompt dans le menu de la barre d&apos;état (désactivé par défaut pour un menu plus épuré)</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup</source>
        <translation type="vanished">Afficher les descriptions de prompt dans la fenêtre contextuelle</translation>
    </message>
    <message>
        <source>Show prompt descriptions in popup menu (disabled by default for cleaner popup)</source>
        <translation type="vanished">Afficher les descriptions de prompt dans la fenêtre contextuelle (désactivé par défaut pour une fenêtre plus épurée)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="267"/>
        <source>Provider Profiles</source>
        <translation>Profils de fournisseur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="272"/>
        <source>Available Profiles:</source>
        <translation>Profils disponibles :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="276"/>
        <source>+ Add</source>
        <translation>+ Ajouter</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="277"/>
        <source>Add a new provider profile</source>
        <translation>Ajouter un nouveau profil de fournisseur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="281"/>
        <source>- Remove</source>
        <translation>- Supprimer</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="282"/>
        <source>Remove selected profile</source>
        <translation>Supprimer le profil sélectionné</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="286"/>
        <source>Set as Default</source>
        <translation>Définir par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="287"/>
        <source>Set selected profile as default</source>
        <translation>Définir le profil sélectionné par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="302"/>
        <source>Profile Configuration</source>
        <translation>Configuration du profil</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="306"/>
        <source>e.g., OpenRouter (Main)</source>
        <translation>ex., OpenRouter (Principal)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="308"/>
        <source>Profile Name:</source>
        <translation>Nom du profil :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="313"/>
        <source>Select template or enter custom URL (e.g., http://.../v1/chat/completions)</source>
        <translation>Sélectionner un modèle ou entrer une URL personnalisée (ex., http://.../v1/chat/completions)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="325"/>
        <source>Template...</source>
        <translation>Modèle...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="331"/>
        <source>API URL:</source>
        <translation>URL de l&apos;API :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="352"/>
        <source>Leave empty for local providers (e.g., Ollama)</source>
        <translation>Laisser vide pour les fournisseurs locaux (ex., Ollama)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="357"/>
        <source>http://host:port or socks5://host:port (optional)</source>
        <translation>http://host:port ou socks5://host:port (optionnel)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="366"/>
        <source>Proxy:</source>
        <translation>Proxy :</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="369"/>
        <source>Override Global Defaults (optional, leave empty for default)</source>
        <translation>Remplacer les valeurs globales par défaut (optionnel, laisser vide pour les valeurs par défaut)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="375"/>
        <location filename="../src/ui/settingsdialog.cpp" line="382"/>
        <source>(use global)</source>
        <translation>(utiliser global)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="389"/>
        <source>Enabled</source>
        <translation>Activé</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="399"/>
        <source>Global Defaults (optional, leave empty for provider defaults)</source>
        <translation>Valeurs globales par défaut (optionnel, laisser vide pour les valeurs par défaut du fournisseur)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="405"/>
        <location filename="../src/ui/settingsdialog.cpp" line="415"/>
        <source>(provider default)</source>
        <translation>(valeur par défaut du fournisseur)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="407"/>
        <location filename="../src/ui/settingsdialog.cpp" line="417"/>
        <source>Recommended: Leave empty to let provider use its defaults</source>
        <translation>Recommandé : laisser vide pour permettre au fournisseur d&apos;utiliser ses valeurs par défaut</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="426"/>
        <source>Test Model Connection</source>
        <translation>Tester la connexion au modèle</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="449"/>
        <source>Hotkey</source>
        <translation>Raccourci</translation>
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
        <translation>(personnalisé)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="769"/>
        <source>(default)</source>
        <translation>(par défaut)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="779"/>
        <source>(none)</source>
        <translation>(aucun)</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="850"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1472"/>
        <source>No profile selected</source>
        <translation>Aucun profil sélectionné</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="859"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1478"/>
        <source>Profile not found</source>
        <translation>Profil non trouvé</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="867"/>
        <source>Invalid API URL</source>
        <translation>URL de l&apos;API invalide</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="880"/>
        <source>Error: No API key</source>
        <translation>Erreur : Pas de clé API</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="887"/>
        <source>Error: No model selected</source>
        <translation>Erreur : Aucun modèle sélectionné</translation>
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
        <translation type="unfinished">Impossible d&apos;ouvrir le fichier en écriture : %1</translation>
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
        <translation>Conflit de raccourcis</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="2149"/>
        <source>This hotkey is already in use by a prompt.

Please choose a different hotkey.</source>
        <translation>Ce raccourci est déjà utilisé par un prompt.

Veuillez choisir un autre raccourci.</translation>
    </message>
    <message>
        <source>Connected</source>
        <translation type="vanished">Connecté</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="962"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1000"/>
        <source>Error</source>
        <translation>Erreur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="963"/>
        <source>Failed to add prompt. ID may already exist.</source>
        <translation>Échec de l&apos;ajout du prompt. L&apos;ID existe peut-être déjà.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1001"/>
        <source>Failed to update prompt.</source>
        <translation>Échec de la mise à jour du prompt.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1066"/>
        <source>Delete Prompt</source>
        <translation>Supprimer le prompt</translation>
    </message>
    <message>
        <source>Are you sure you want to delete this prompt?</source>
        <translation type="vanished">Voulez-vous vraiment supprimer ce prompt ?</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1247"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1264"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1274"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1288"/>
        <source>Import Prompts</source>
        <translation>Importer des prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1249"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1340"/>
        <source>JSON Files (*.json)</source>
        <translation>Fichiers JSON (*.json)</translation>
    </message>
    <message>
        <source>Import will be implemented in a future version.</source>
        <translation type="vanished">L&apos;importation sera implémentée dans une future version.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1366"/>
        <source>Export Prompts</source>
        <translation>Exporter des prompts</translation>
    </message>
    <message>
        <source>Prompts exported to %1</source>
        <translation type="vanished">Prompts exportés vers %1</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1388"/>
        <source>Reset Prompts</source>
        <translation>Réinitialiser les prompts</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1389"/>
        <source>Are you sure you want to reset prompts to defaults? All custom prompts will be lost.</source>
        <translation>Voulez-vous vraiment réinitialiser les prompts par défaut ? Tous les prompts personnalisés seront perdus.</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1435"/>
        <source>Clear History</source>
        <translation>Effacer l&apos;historique</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1436"/>
        <source>Are you sure you want to delete all history entries? This cannot be undone.</source>
        <translation>Voulez-vous vraiment supprimer toutes les entrées de l&apos;historique ? Cela ne peut pas être annulé.</translation>
    </message>
    <message>
        <source>Model fetching not supported for this provider</source>
        <translation type="vanished">Récupération des modèles non prise en charge pour ce fournisseur</translation>
    </message>
    <message>
        <source>Fetch not supported for this provider</source>
        <translation type="vanished">Récupération non prise en charge pour ce fournisseur</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1561"/>
        <source>Fetching models...</source>
        <translation>Récupération des modèles...</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="927"/>
        <location filename="../src/ui/settingsdialog.cpp" line="1572"/>
        <source>Error: %1</source>
        <translation>Erreur : %1</translation>
    </message>
    <message>
        <source>Error: LLM client not available</source>
        <translation type="vanished">Erreur : Client LLM non disponible</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="924"/>
        <source>Connection successful</source>
        <translation>Connexion réussie</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1582"/>
        <source>Error: Invalid response</source>
        <translation>Erreur : Réponse invalide</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1623"/>
        <source>No models found</source>
        <translation>Aucun modèle trouvé</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="1655"/>
        <source>Loaded %1 models</source>
        <translation>%1 modèles chargés</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="110"/>
        <source>OK</source>
        <translation>OK</translation>
    </message>
    <message>
        <location filename="../src/ui/settingsdialog.cpp" line="114"/>
        <source>Cancel</source>
        <translation>Annuler</translation>
    </message>
</context>
<context>
    <name>ClipLLM::UI::TrayIcon</name>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="59"/>
        <location filename="../src/ui/trayicon.cpp" line="257"/>
        <location filename="../src/ui/trayicon.cpp" line="368"/>
        <source>ClipLLM - LLM Clipboard Utility</source>
        <translation>ClipLLM - Utilitaire de presse-papiers LLM</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="92"/>
        <location filename="../src/ui/trayicon.cpp" line="372"/>
        <source>&amp;Settings</source>
        <translation>&amp;Paramètres</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="96"/>
        <location filename="../src/ui/trayicon.cpp" line="375"/>
        <source>&amp;History</source>
        <translation>&amp;Historique</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="100"/>
        <location filename="../src/ui/trayicon.cpp" line="378"/>
        <source>&amp;About</source>
        <translation>&amp;À propos</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="110"/>
        <location filename="../src/ui/trayicon.cpp" line="381"/>
        <source>&amp;Quit</source>
        <translation>&amp;Quitter</translation>
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
        <translation>Aucun prompt disponible</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="259"/>
        <source>Hotkey: </source>
        <translation>Raccourci : </translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="321"/>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Project website:&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; est un utilitaire de presse-papiers multiplateforme qui intègre les grands modèles de langage (LLM) directement dans votre flux de travail. Fonctionnant comme un service de zone de notification, il vous permet de traiter le contenu du presse-papiers (texte et images) avec des prompts IA personnalisables à l&apos;aide de raccourcis globaux.&lt;/p&gt;&lt;p&gt;Que vous ayez besoin de résumer du texte, de traduire du contenu, de réécrire du code, d&apos;extraire des informations d&apos;images ou d&apos;effectuer toute autre transformation alimentée par l&apos;IA, ClipLLM rend cela instantanément accessible avec une seule pression de touche. Copiez le contenu, appuyez sur votre raccourci et obtenez des résultats générés par l&apos;IA dans votre presse-papiers.&lt;/p&gt;&lt;p&gt;&lt;b&gt;Site web du projet :&lt;/b&gt; &lt;a href=&apos;https://burbilog.github.io/clipllm/&apos;&gt;https://burbilog.github.io/clipllm/&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version %1&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; est un utilitaire de presse-papiers multiplateforme qui intègre les grands modèles de langage (LLM) directement dans votre flux de travail. Fonctionnant comme un service de zone de notification, il vous permet de traiter le contenu du presse-papiers (texte et images) avec des prompts IA personnalisables à l&apos;aide de raccourcis globaux.&lt;/p&gt;&lt;p&gt;Que vous ayez besoin de résumer du texte, de traduire du contenu, de réécrire du code, d&apos;extraire des informations d&apos;images ou d&apos;effectuer toute autre transformation alimentée par l&apos;IA, ClipLLM rend cela instantanément accessible avec une seule pression de touche. Copiez le contenu, appuyez sur votre raccourci et obtenez des résultats générés par l&apos;IA dans votre presse-papiers.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <source>&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; is a cross-platform clipboard utility that integrates Large Language Models (LLMs) directly into your workflow. Running as a system tray service, it allows you to process clipboard content (both text and images) with customizable AI prompts using global hotkeys.&lt;/p&gt;&lt;p&gt;Whether you need to summarize text, translate content, rewrite code, extract information from images, or perform any other AI-powered transformation, ClipLLM makes it instantly accessible with a single keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</source>
        <translation type="vanished">&lt;table border=&apos;0&apos; cellpadding=&apos;8&apos; cellspacing=&apos;0&apos;&gt;&lt;tr&gt;&lt;td align=&apos;center&apos; width=&apos;150&apos;&gt;&lt;img src=&apos;:/icons/tray-icon-128.png&apos; width=&apos;128&apos; height=&apos;128&apos;/&gt;&lt;/td&gt;&lt;td&gt;&lt;h2 style=&apos;margin-top:0;&apos;&gt;ClipLLM&lt;/h2&gt;&lt;p&gt;&lt;b&gt;Version 1.0.0&lt;/b&gt;&lt;/p&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;p&gt;&lt;b&gt;ClipLLM&lt;/b&gt; est un utilitaire de presse-papiers multiplateforme qui intègre les grands modèles de langage (LLM) directement dans votre flux de travail. Fonctionnant comme un service de zone de notification, il vous permet de traiter le contenu du presse-papiers (texte et images) avec des prompts IA personnalisables à l&apos;aide de raccourcis globaux.&lt;/p&gt;&lt;p&gt;Que vous ayez besoin de résumer du texte, de traduire du contenu, de réécrire du code, d&apos;extraire des informations d&apos;images ou d&apos;effectuer toute autre transformation alimentée par l&apos;IA, ClipLLM rend cela instantanément accessible avec une seule pression de touche. Copiez le contenu, appuyez sur votre raccourci et obtenez des résultats générés par l&apos;IA dans votre presse-papiers.&lt;/p&gt;&lt;p&gt;&lt;small&gt;Copyright © 2026 Roman V. Isaev &amp;lt;&lt;a href=&apos;mailto:rm@isaeff.net&apos;&gt;rm@isaeff.net&lt;/a&gt;&amp;gt;&lt;/small&gt;&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/ui/trayicon.cpp" line="343"/>
        <source>About ClipLLM</source>
        <translation>À propos de ClipLLM</translation>
    </message>
</context>
<context>
    <name>HistoryEntry</name>
    <message>
        <location filename="../src/core/historymanager.cpp" line="92"/>
        <source>[Image: %1 bytes]</source>
        <translation>[Image : %1 octets]</translation>
    </message>
    <message>
        <location filename="../src/core/historymanager.cpp" line="96"/>
        <location filename="../src/core/historymanager.cpp" line="108"/>
        <source>[Empty]</source>
        <translation>[Vide]</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/main.cpp" line="32"/>
        <source>ClipLLM - Cross-platform LLM clipboard utility</source>
        <translation>ClipLLM - Utilitaire de presse-papiers LLM multiplateforme</translation>
    </message>
    <message>
        <location filename="../src/main.cpp" line="38"/>
        <source>Start minimized to system tray</source>
        <translation>Démarrer minimisé dans la zone de notification</translation>
    </message>
</context>
</TS>
