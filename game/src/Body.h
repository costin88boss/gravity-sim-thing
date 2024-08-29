#pragma once

#include <string>
#include <vector>
#include "raylib.h"
#include "Vec2.h"
#include "Physics.h"

class Body
{
public:
    std::string name;
    Vec2 position;
    Vec2 velocity;
    float mass;

    Body( const std::string name, Vec2 position, Vec2 velocity, float mass );
    constexpr Body& operator=( const Body& ) = default;

    void Move( Vec2 displacement );
    void AddVelocity( Vec2 velocityDelta );
    
    void UpdateVelocity( float timeDeltaSeconds, const std::vector<Body>& bodies );
    void UpdatePosition( float timeDeltaSeconds );

    // Operator Overloads
    bool operator == ( const Body& rhs );
    bool operator != ( const Body& rhs );
};