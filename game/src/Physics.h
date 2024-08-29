#pragma once

#include <cmath>
#include "Vec2.h"

class Physics
{
public:
    static double bigG;

    static Vec2 GetGravForce( float m1, float m2,  Vec2 dist );
};