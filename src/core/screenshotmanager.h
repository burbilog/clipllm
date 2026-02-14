// ClipLLM - Cross-platform LLM clipboard utility
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

#ifndef CLIPLLM_CORE_SCREENSHOTMANAGER_H
#define CLIPLLM_CORE_SCREENSHOTMANAGER_H

#include <QObject>
#include <QImage>

namespace ClipLLM {
namespace Core {

class ScreenshotManager : public QObject
{
    Q_OBJECT
public:
    explicit ScreenshotManager(QObject* parent = nullptr);
    ~ScreenshotManager();

    // Capture all screens as a single combined image (virtual desktop)
    QImage captureScreen() const;

    // Check if the platform supports global hotkeys (required for screenshot hotkeys)
    static bool isPlatformSupported();
};

} // namespace Core
} // namespace ClipLLM

#endif // CLIPLLM_CORE_SCREENSHOTMANAGER_H
