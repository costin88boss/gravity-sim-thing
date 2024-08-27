#include "Vec2.h"

Vec2 Vec2::Zero()
{ return { 0.0f, 0.0f }; }

Vec2 Vec2::One()
{ return { 1.0f, 1.0f }; }

Vec2 Vec2::Right()
{ return { 1.0f, 0.0f }; }

Vec2 Vec2::Up()
{ return { 0.0f, 1.0f }; }


Vec2::Vec2( float x, float y )
    :
    x( x ),
    y( y )
{}


float Vec2::Distance( Vec2& v1, Vec2& v2 )
{ return ( v1 - v2 ).Magnitude(); }

Vec2 Vec2::Normalized()
{ return { x / Magnitude(), y / Magnitude() }; }

float Vec2::SqrMagnitude()
{ return pow( x, 2 ) + pow( y, 2 ); }

float Vec2::Magnitude()
{ return sqrt( pow( x, 2 ) + pow( y, 2  ) ); }

Vector2 Vec2::ToRaylibVector()
{ return { x, y }; }

void Vec2::Print()
{
    std::cout << "(x: " << x <<
                 " y: " << y <<
                 ")";
}

//---------- Operation Overloads ----------
// Unary Arithmetic
Vec2 Vec2::operator+()
{ return *this; }
Vec2 Vec2::operator-()
{ return { -x, -y }; }
// Binary Arithmetic
Vec2 Vec2::operator+( const Vec2& rhs )
{ return { x + rhs.x, y + rhs.y }; }
Vec2 Vec2::operator-( const Vec2& rhs )
{ return { x - rhs.x, y - rhs.y }; }
Vec2 Vec2::operator*( const Vec2& rhs )
{ return { x * rhs.x, y * rhs.y }; }
Vec2 Vec2::operator/( const Vec2& rhs )
{ return { x / rhs.x, y / rhs.y }; }

Vec2 Vec2::operator*( const float& rhs )
{ return { x * rhs, y * rhs }; }
Vec2 Vec2::operator/( const float& rhs )
{ return { x / rhs, y / rhs }; }

Vec2& Vec2::operator+=( const Vec2& rhs )
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}
Vec2& Vec2::operator-=( const Vec2& rhs )
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}
Vec2& Vec2::operator*=( const Vec2& rhs )
{ 
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}
Vec2& Vec2::operator/=( const Vec2& rhs )
{
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

Vec2& Vec2::operator*=( const float& rhs )
{
    x *= rhs;
    y *= rhs;
    return *this;
}
Vec2& Vec2::operator/=( const float& rhs )
{
    x /= rhs;
    y /= rhs;
    return *this;
}

// Comparison
bool Vec2::operator==( const Vec2& rhs )
{ return ( x == rhs.x && y == rhs.y ); }
bool Vec2::operator!=( const Vec2& rhs )
{ return !( x == rhs.x && y == rhs.y ); }