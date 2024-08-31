#pragma once

#include <iostream>
#include <string>
#include <limits>
#include "raylib.h"

class Debug
{
public:
    template<typename T>
    static void Log( const T& message );
    static void HandleTargetFPS();
};