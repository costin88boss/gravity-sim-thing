#include "Body.h"

Body::Body( const std::string name, const Vec2 position, const Vec2 velocity, const float mass )
    :
    name( name ),
    position( position ),
    velocity( velocity ),
    mass( mass )
{}

void Body::Move( const Vec2 displacement )
{
    position += displacement;
}

void Body::AddVelocity( const Vec2 velocityDelta )
{
    velocity += velocityDelta;
}

void Body::UpdateVelocity( const float timeDeltaSeconds, const std::vector<Body>& bodies )
{
    Vec2 force{ 0, 0 };
    for ( Body body : bodies )
    {
        if ( body == *this ) continue;
        Vec2 dist = body.position - position;
        force += Physics::GetGravForce( mass, body.mass, dist );
    }
    // Newton's Second Law of Motion\
    // F = ma ==> a = F / m
    Vec2 accelaration = force / mass;
    // v = at
    Vec2 velocityDelta = accelaration * timeDeltaSeconds;

    AddVelocity( velocityDelta );
}

void Body::UpdatePosition( const float timeDeltaSeconds )
{
    // x = vt
    Move( velocity * timeDeltaSeconds );
}

void Body::Draw()
{
    DrawCircleV( WorldToScreenPoint( position ).ToRaylibVector(), 25.0f, WHITE );
}

// Operator Overloads
bool Body::operator == ( const Body& rhs )
{
    return ( name     == rhs.name     && position == rhs.position &&
             velocity == rhs.velocity && mass     == rhs.mass );
}
bool Body::operator != ( const Body& rhs )
{
    return !( name     == rhs.name     && position == rhs.position &&
              velocity == rhs.velocity && mass     == rhs.mass );
}