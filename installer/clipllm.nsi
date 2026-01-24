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

; Set compression
SetCompressor /SOLID lzma

; Interface Settings
!define MUI_ABORTWARNING
!define MUI_ICON "resources/icons/tray-icon.ico"
!define MUI_UNICON "resources/icons/tray-icon.ico"

; Pages
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

  ; Qt6 DLLs
  File "deploy-windows\Qt6Core.dll"
  File "deploy-windows\Qt6Gui.dll"
  File "deploy-windows\Qt6Network.dll"
  File "deploy-windows\Qt6Widgets.dll"

  ; Runtime DLLs
  File "deploy-windows\libgcc_s_seh-1.dll"
  File "deploy-windows\libstdc++-6.dll"
  File "deploy-windows\libwinpthread-1.dll"
  File "deploy-windows\zlib1.dll"

  ; OpenSSL DLLs
  File "deploy-windows\libcrypto-3-x64.dll"
  File "deploy-windows\libssl-3-x64.dll"

  ; Qt config
  File "deploy-windows\qt.conf"

  ; Plugins
  SetOutPath $INSTDIR\platforms
  File "deploy-windows\platforms\qwindows.dll"

  SetOutPath $INSTDIR\imageformats
  File "deploy-windows\imageformats\qico.dll"
  File "deploy-windows\imageformats\qjpeg.dll"
  File "deploy-windows\imageformats\qsvg.dll"

  SetOutPath $INSTDIR\tls
  File "deploy-windows\tls\qcertonlybackend.dll"
  File "deploy-windows\tls\qopensslbackend.dll"

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
