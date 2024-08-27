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
    Simulation( const std::string& title, size_t windowWidth, size_t windowHeight, float timeStep );
    ~Simulation();

    bool IsRunning() const;
    void SetBGColor( Color color );

    void AddBody( Body& body );
    void ListBodies();

    void Tick();
    void Update();
    void Draw();
private:
    std::string m_title;
    size_t m_windowWidth, m_windowHeight;
    float m_timeStep;
    Color m_bgColor;

    std::vector<Body*> m_bodies;

    bool CheckIfNameExists( const std::string& name );
    int GetBodyIndex( Body& body );
};