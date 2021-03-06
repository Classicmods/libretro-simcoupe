// Part of SimCoupe - A SAM Coupe emulator
//
// Main.cpp: Main entry point
//
//  Copyright (c) 1999-2012 Simon Owen
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "SimCoupe.h"
#include "Main.h"

#include "CPU.h"
#include "Frame.h"
#include "Input.h"
#include "Options.h"
#include "Sound.h"
#include "UI.h"
#include "Util.h"
#include "Video.h"


// Use default main unless the platform requires something special
#ifndef CUSTOM_MAIN

int main (int argc_, char* argv_[])
{
    if (Main::Init(argc_, argv_))
        CPU::Run();

    Main::Exit();

    return 0;
}

#endif


bool Main::Init (int argc_, char* argv_[])
{

    // Load settings and check command-line options
    if (!Util::Init() || !Options::Load(argc_, argv_))
        return 0;

    // Initialise all modules
    return Frame::Init(true) && OSD::Init(true) && Sound::Init(true) && Video::Init(true) && Input::Init(true) && CPU::Init(true);
}

void Main::Exit ()
{
    CPU::Exit();
    Input::Exit();
    Video::Exit();
    Sound::Exit();
    OSD::Exit();
    Frame::Exit();

    Options::Save();

    Util::Exit();
}
