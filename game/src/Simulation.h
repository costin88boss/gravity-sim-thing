#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <stddef.h>
#include "Body.h"

class Simulation
{
public:
    Simulation( const std::string title, const size_t windowWidth, const size_t windowHeight, const float timeStep );
    ~Simulation();

    bool IsRunning() const;
    void SetBGColor( const Color color );

    void AddBody( const std::string name, Vec2 position, Vec2 velocity, float mass );
    void ListBodies() const;
    Body& GetBodyByName( const std::string& name ) const;

    void Tick();
    void Update();
    void Draw();
private:
    std::string m_title;
    size_t m_windowWidth, m_windowHeight;
    float m_timeStep;
    Color m_bgColor = { 0, 0, 0, 255 };

    std::vector<Body> m_bodies;

    bool CheckIfNameExists( const std::string& name );
};