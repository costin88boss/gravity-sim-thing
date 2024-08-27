#pragma once

#include <cmath>
#include "raylib.h"

class Vec2
{
public:
    static Vec2 Zero();
    static Vec2 One();
    static Vec2 Right();
    static Vec2 Up();

    static float Distance( Vec2& v1, Vec2& v2 );
public:
    float x, y;

    Vec2( float x, float y );

    Vec2 Normalized();
    float SqrMagnitude();
    float Magnitude();
    Vector2 ToRaylibVector();

    //---------- Operation Overloads ----------
    // Unary Arithmetic
    Vec2 operator+();
    Vec2 operator-();
    // Binary Arithmetic
    Vec2 operator+( const Vec2& rhs );
    Vec2 operator-( const Vec2& rhs );
    Vec2 operator*( const Vec2& rhs );
    Vec2 operator/( const Vec2& rhs );

    Vec2 operator*( const float& rhs );
    Vec2 operator/( const float& rhs );

    Vec2& operator+=( const Vec2& rhs );
    Vec2& operator-=( const Vec2& rhs );
    Vec2& operator*=( const Vec2& rhs );
    Vec2& operator/=( const Vec2& rhs );

    Vec2& operator*=( const float& rhs );
    Vec2& operator/=( const float& rhs );

    // Comparison
    bool operator==( const Vec2& rhs );
    bool operator!=( const Vec2& rhs );
};