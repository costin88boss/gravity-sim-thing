#pragma once

#include <string>
#include <vector>
#include "raylib.h"
#include "Vec2.h"
#include "Physics.h"
#include "WorldScreen.h"

class Body
{
public:
    std::string name;
    Vec2 position;
    Vec2 velocity;
    float mass;

    Body( const std::string name, const Vec2 position, const Vec2 velocity, const float mass );

    void Move( const Vec2 displacement );
    void AddVelocity( const Vec2 velocityDelta );
    
    void UpdateVelocity( const float timeDeltaSeconds, const std::vector<Body>& bodies );
    void UpdatePosition( const float timeDeltaSeconds );

    void Draw();

    // Operator Overloads
    bool operator == ( const Body& rhs );
    bool operator != ( const Body& rhs );
};