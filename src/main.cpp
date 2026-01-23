// ClipAI - Cross-platform LLM clipboard utility
// Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

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
