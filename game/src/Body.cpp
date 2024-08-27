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

void Body::AddVelocity( Vec2 velocity )
{
    velocity += velocity;
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

// TODO: Update Body Based on Physics
//void Body::UpdateVelocity( float timeDeltaSeconds )
//{
//
//}
//
//void Body::UpdatePosition( float timeDeltaSeconds )
//{
//    
//}