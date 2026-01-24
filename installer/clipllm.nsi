; ClipLLM Installer Script for NSIS
; Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>

!define APP_NAME "ClipLLM"
; APP_VERSION can be set with -DAPP_VERSION=x.y.z
!ifdef PRODUCT_VERSION
  !define APP_VERSION "${PRODUCT_VERSION}"
!else
  !define APP_VERSION "1.0.0"
!endif
!define APP_PUBLISHER "Roman V. Isaev"
!define APP_URL "https://github.com/rm-isaeff/clipllm"
!define APP_DESCRIPTION "Cross-platform LLM clipboard utility"

; Modern UI
!include "MUI2.nsh"

; General
Name "${APP_NAME}"
OutFile "dist\${APP_NAME}-${APP_VERSION}-windows-x86_64-setup.exe"
InstallDir "$PROGRAMFILES64\${APP_NAME}"
InstallDirRegKey HKCU "Software\${APP_NAME}" ""
RequestExecutionLevel admin
ShowInstDetails show
ShowUnInstDetails show

; Variables for language selection
Var dlg_Language
Var cmb_Language
Var hCtl_Language

; Set compression
SetCompressor /SOLID lzma

; Interface Settings
!define MUI_ABORTWARNING
!define MUI_ICON "resources/icons/tray-icon.ico"
!define MUI_UNICON "resources/icons/tray-icon.ico"

; Pages
Page custom fnc_Language_Show fnc_Language_Leave
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "LICENSE.md"
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

; Languages
!insertmacro MUI_LANGUAGE "English"

; Installer Section
Section "MainSection" SEC01
  SetOutPath $INSTDIR

  ; Main executable
  File "deploy-windows\ClipLLM.exe"

  ; All DLLs (Qt6, ICU, PCRE, OpenSSL, etc. - copied by windeployqt)
  ; /nonfatal for static builds where no DLLs are needed
  File /nonfatal "deploy-windows\*.dll"

  ; Qt config (only for shared builds)
  File /nonfatal "deploy-windows\qt.conf"

  ; Plugins (only for shared builds)
  SetOutPath $INSTDIR\platforms
  File /nonfatal "deploy-windows\platforms\*.dll"

  SetOutPath $INSTDIR\imageformats
  File /nonfatal "deploy-windows\imageformats\*.dll"

  SetOutPath $INSTDIR\tls
  File /nonfatal "deploy-windows\tls\*.dll"

  SetOutPath $INSTDIR\iconengines
  ; May be empty, but create directory anyway

  SetOutPath $INSTDIR\styles
  ; May be empty, but create directory anyway

  ; Translations
  SetOutPath $INSTDIR\translations
  File "deploy-windows\translations\*.qm"

  ; Config
  SetOutPath $INSTDIR\config
  File "deploy-windows\config\prompts-default.json"

  ; Set back to root for uninstaller
  SetOutPath $INSTDIR

  ; Write registry keys
  WriteRegStr HKCU "Software\${APP_NAME}" "" $INSTDIR
  WriteRegStr HKCU "Software\${APP_NAME}" "Version" "${APP_VERSION}"
  WriteRegStr HKCU "Software\${APP_NAME}" "language" $hCtl_Language

  ; Create uninstaller
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "DisplayName" "${APP_NAME}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "DisplayVersion" "${APP_VERSION}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "Publisher" "${APP_PUBLISHER}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "URLInfoAbout" "${APP_URL}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "DisplayIcon" "$INSTDIR\ClipLLM.exe"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "UninstallString" "$INSTDIR\uninstall.exe"
  WriteRegDWORD HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "NoModify" 1
  WriteRegDWORD HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "NoRepair" 1

  ; Create uninstaller
  WriteUninstaller "$INSTDIR\uninstall.exe"

  ; Start Menu shortcut
  CreateDirectory "$SMPROGRAMS\${APP_NAME}"
  CreateShortCut "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk" "$INSTDIR\ClipLLM.exe"
  CreateShortCut "$SMPROGRAMS\${APP_NAME}\Uninstall.lnk" "$INSTDIR\uninstall.exe"

  ; Desktop shortcut
  CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\ClipLLM.exe"
SectionEnd

; Uninstaller Section
Section "Uninstall"
  DeleteRegKey HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}"
  DeleteRegKey HKCU "Software\${APP_NAME}"

  ; Delete shortcuts
  Delete "$DESKTOP\${APP_NAME}.lnk"
  Delete "$SMPROGRAMS\${APP_NAME}\*.*"
  RMDir "$SMPROGRAMS\${APP_NAME}"

  ; Delete files and directories
  Delete "$INSTDIR\uninstall.exe"
  RMDir /r "$INSTDIR"
SectionEnd

; Functions
Function .onInit
  ; Initialize language selection (default: English)
  StrCpy $hCtl_Language "en"

  ; Check if already installed
  ReadRegStr $R0 HKCU "Software\${APP_NAME}" ""
  StrCmp $R0 "" done

  MessageBox MB_YESNO|MB_ICONQUESTION \
    "${APP_NAME} is already installed. $\n$\nWould you like to uninstall the previous version before installing the new one?" \
    IDYES uninst IDNO done

uninst:
  ClearErrors
  ExecWait '$R0\uninstall.exe _?=$INSTDIR'
  IfErrors done
  done:
FunctionEnd

Function fnc_Language_Show
  !insertmacro MUI_HEADER_TEXT "Select Language" "Choose the interface language for ClipLLM"

  nsDialogs::Create 1018
  Pop $dlg_Language

  ${If} $dlg_Language == error
    Abort
  ${EndIf}

  ; Create label
  ${NSD_CreateLabel} 0 0 100% 40u "Please select the language you want to use:"
  Pop $0

  ; Create dropdown
  ${NSD_CreateDropList} 0 50u 100% 15u ""
  Pop $cmb_Language

  ; Add languages to dropdown (native names)
  SendMessage $cmb_Language ${CB_ADDSTRING} 0 "STR:English"
  SendMessage $cmb_Language ${CB_ADDSTRING} 0 "STR:Русский"
  SendMessage $cmb_Language ${CB_ADDSTRING} 0 "STR:Deutsch"
  SendMessage $cmb_Language ${CB_ADDSTRING} 0 "STR:Français"
  SendMessage $cmb_Language ${CB_ADDSTRING} 0 "STR:Español"

  ; Auto-select based on system locale
  System::Call "kernel32::GetUserDefaultLangID() i .r0"
  ${Switch} $0
    ${Case} 0x0419  ; Russian (0419)
      SendMessage $cmb_Language ${CB_SETCURSEL} 1 0
    ${Case} 0x0407  ; German (0407)
      SendMessage $cmb_Language ${CB_SETCURSEL} 2 0
    ${Case} 0x040c  ; French (040c)
      SendMessage $cmb_Language ${CB_SETCURSEL} 3 0
    ${Case} 0x0c0a  ; Spanish (0c0a)
      SendMessage $cmb_Language ${CB_SETCURSEL} 4 0
    ${Default}
      SendMessage $cmb_Language ${CB_SETCURSEL} 0 0  ; English default
  ${EndSwitch}

  nsDialogs::Show
FunctionEnd

Function fnc_Language_Leave
  ; Get selected language index
  SendMessage $cmb_Language ${CB_GETCURSEL} 0 0 $hCtl_Language

  ; Map index to language code
  ${Switch} $hCtl_Language
    ${Case} 0
      StrCpy $hCtl_Language "en"
    ${Case} 1
      StrCpy $hCtl_Language "ru"
    ${Case} 2
      StrCpy $hCtl_Language "de"
    ${Case} 3
      StrCpy $hCtl_Language "fr"
    ${Case} 4
      StrCpy $hCtl_Language "es"
  ${EndSwitch}
FunctionEnd
