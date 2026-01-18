#include "core/app.h"
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{
    // High DPI scaling is enabled by default in Qt6

    ClipAI::App app(argc, argv);

    // Setup command line parser
    QCommandLineParser parser;
    parser.setApplicationDescription(QObject::tr("ClipAI - Cross-platform LLM clipboard utility"));
    parser.addHelpOption();
    parser.addVersionOption();

    // Optional: Start minimized option
    QCommandLineOption minimizedOption(QStringList() << "m" << "minimized",
                                       QObject::tr("Start minimized to system tray"));
    parser.addOption(minimizedOption);

    parser.process(app);

    // Check if another instance is running
    if (app.isSecondary()) {
        qDebug() << "Another instance of ClipAI is already running";
        return 0;
    }

    // Initialize application components
    if (!app.initialize(parser.isSet(minimizedOption))) {
        qCritical() << "Failed to initialize application";
        return 1;
    }

    return app.exec();
}
