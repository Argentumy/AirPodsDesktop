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


namespace Core::GlobalMedia::Details
{
    template <class Derived>
    class ControllerAbstract
    {
    public:
        inline static auto& GetInstance() {
            static Derived i;
            return i;
        }

        virtual ~ControllerAbstract() = 0;

        virtual void Play() = 0;
        virtual void Pause() = 0;

    protected:
        ControllerAbstract() = default;
    };

    template <class Derived>
    inline ControllerAbstract<Derived>::~ControllerAbstract() {};

} // namespace Core::GlobalMedia::Details
