#include "Body.h"

Body::Body( Vec2 position, Vec2 velocity, float mass )
    :
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