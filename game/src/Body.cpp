#include "Body.h"

Body::Body( const std::string name, Vec2 position, Vec2 velocity, float mass )
    :
    name( name ),
    position( position ),
    velocity( velocity ),
    mass( mass )
{}

void Body::Move( Vec2 displacement )
{
    position += displacement;
}

void Body::AddVelocity( Vec2 velocityDelta )
{
    velocity += velocityDelta;
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

void Body::UpdateVelocity( float timeDeltaSeconds, const std::vector<Body>& bodies )
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

void Body::UpdatePosition( float timeDeltaSeconds )
{
    // x = vt
    Move( velocity * timeDeltaSeconds );
}