#include "Physics.h"

double Physics::bigG = 0.0000000000667;

Vec2 Physics::GetGravForce( float m1, float m2,  Vec2 dist )
{
    Vec2 dir = dist.Normalized();
    // Newton's Law of Gravitation
    // F = ( G * m1 * m2 ) / d^2
    return dir * ( bigG * m1 * m2 / dist.SqrMagnitude() );
}