#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <stddef.h>
#include "Body.h"

struct Window
{
    const std::string title;
    const size_t width, height;
};

class Simulation
{
public:
    Simulation( const Window window, const float timeStep );
    ~Simulation();

    bool IsRunning() const;
    void SetBGColor( const Color color );

    void AddBody( const Body& body );
    void ListBodies() const;
    Body& GetBodyByName( const std::string& name ) const;

    void Tick();
    void Update();
    void Draw();
private:
    Window m_window;
    float m_timeStep;
    Color m_bgColor = { 0, 0, 0, 255 };

    std::vector<Body> m_bodies;

    bool CheckIfNameExists( const std::string& name );
};