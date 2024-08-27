#pragma once

#include "raylib.h"
#include "Vec2.h"

class Body
{
public:
    Vec2 position;
    Vec2 velocity;
    float mass;

    Body( Vec2 position, Vec2 velocity, float mass );

    void Move( Vec2 displacement );
    void AddVelocity( Vec2 velocity );
    void UpdateVelocity( float timeDeltaSeconds );
    void UpdatePosition( float timeDeltaSeconds );
};