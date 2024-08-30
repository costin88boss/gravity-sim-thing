#include "WorldScreen.h"

static float WORLD_TO_SCREEN_MULT = 50.0f;

Vec2 WorldToScreenPoint( Vec2 point )
{
    Vec2 center{ static_cast<float>( GetScreenWidth()  ) / 2.0f,
                 static_cast<float>( GetScreenHeight() ) / 2.0f };
    point *= WORLD_TO_SCREEN_MULT;
    return center + point;
}

Vec2 ScreenToWorldPoint( Vec2 point )
{
    Vec2 center{ static_cast<float>( GetScreenWidth()  ) / 2.0f,
                 static_cast<float>( GetScreenHeight() ) / 2.0f };
    point.x -= center.x;
    point.y = center.y - point.y;
    point /= WORLD_TO_SCREEN_MULT;
    return point;
}