//
// AirPodsDesktop - AirPods Desktop User Experience Enhancement Program.
// Copyright (C) 2021 SpriteOvO
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#include <memory>
#include <QApplication>
#include <cxxopts.hpp>

#include "Config.h"
#include "Gui/SysTray.h"
#include "Gui/InfoWindow.h"
#include "Gui/DownloadWindow.h"
#include "Core/AirPods.h"


class Application : public QApplication
{
public:
    template <class ...Args>
    inline static void Initialize(Args &&...args) {
        App = std::make_unique<Application>(std::forward<Args>(args)...);
    }

    Application(int argc, char *argv[]);

    int Run();

    inline auto& GetSysTray()               { return _sysTray; }
    inline auto& GetInfoWindow()            { return _infoWindow; }

    inline static bool IsFirstTimeUse()     { return _isFirstTimeUse; }

    static void PopupAboutWindow(QWidget *parent);
    static void QuitSafety();

private:
    static inline cxxopts::Options _options{Config::ProgramName,Config::Description};
    static inline bool _isFirstTimeUse{false};

    bool _preInit{false};
    Gui::SysTray _sysTray;
    Gui::InfoWindow _infoWindow;
    std::unique_ptr<Gui::DownloadWindow> _downloadWindow;
    std::unique_ptr<Core::AirPods::AsyncScanner> _scanner;

    static bool PreMemberInit(int argc, char *argv[]);
    static void InitSettings();
    static void FirstTimeUse();

    // Returns false if the program will quit
    //
    bool CheckUpdate();

    void QuitHandler();
};

inline std::unique_ptr<Application> App;
