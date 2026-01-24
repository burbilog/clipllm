// ClipAI - Qt Installer Framework installation script
// Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>

function Component()
{
}

Component.prototype.createOperations = function()
{
    component.createOperations();

    // Create desktop shortcut (optional, on Windows only)
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut",
                               "@TargetDir@/ClipAI.exe",
                               "@StartMenuDir@/ClipAI.lnk",
                               "workingDirectory=@TargetDir@");
    }
}

// Check if ClipAI is already installed
Component.prototype.isInstalled = function()
{
    return installer.value("InstalledVersion", "") !== "";
}

// Perform operations after installation
Component.prototype.installationFinished = function()
{
    // Mark as installed with version
    installer.setValue("InstalledVersion", "@Version@");

    // Ask to launch application after installation
    var result = QMessageBox.question("Installation Completed",
        "ClipAI has been installed successfully.\n\n" +
        "Would you like to start ClipAI now?",
        QMessageBox.Yes | QMessageBox.No);

    if (result === QMessageBox.Yes) {
        installer.executeDetached("@TargetDir@/ClipAI.exe", []);
    }
}

// Perform operations before uninstallation
Component.prototype.uninstallationStarted = function()
{
    var result = QMessageBox.question("Uninstall ClipAI",
        "Are you sure you want to uninstall ClipAI?\n\n" +
        "Your configuration and history will be preserved.",
        QMessageBox.Yes | QMessageBox.No);

    if (result === QMessageBox.No) {
        installer.cancelInstallerTask("Uninstallation cancelled by user");
    }
}

// Perform operations after uninstallation
Component.prototype.uninstallationFinished = function()
{
    // Remove version marker
    installer.setValue("InstalledVersion", "");
}
