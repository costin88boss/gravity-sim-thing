#include "Simulation.h"

Simulation::Simulation( const std::string& title, size_t windowWidth, size_t windowHeight, float timeStep )
    :
    m_title{ title },
    m_windowWidth( windowWidth ),
    m_windowHeight( windowHeight ),
    m_timeStep( timeStep )
{
    if ( GetWindowHandle() )
        throw std::runtime_error("Error initializing simulation: Window already initialized!");

    InitWindow( m_windowWidth, m_windowHeight, m_title.c_str() );
    InitAudioDevice();
}

Simulation::~Simulation()
{
    if ( !GetWindowHandle() )
        throw std::runtime_error("Error closing simulation: Window already closed!");
    
    CloseAudioDevice();
    CloseWindow();
}

bool Simulation::IsRunning() const
{
    return !WindowShouldClose();
}

void Simulation::SetBGColor( Color color )
{
    m_bgColor = color;
}

void Simulation::AddBody( Body& body )
{
    if ( CheckIfNameExists( body.name ) )
    {
        throw std::runtime_error("Error adding body: A body with this name already exists!");
    }
    else
    {
        m_bodies.push_back( &body );
    }
}

void Simulation::ListBodies()
{
    for ( auto body : m_bodies )
    {
        std::cout <<  body->name.c_str() << " at pos: ";
        body->position.Print();
        std::cout << " \n";
    }
    std::cout << "------\n";
}

void Simulation::Tick()
{
    Update();

    BeginDrawing();
    Draw();
    EndDrawing();
}


void Simulation::Update()
{

}

void Simulation::Draw()
{
    ClearBackground( m_bgColor );
}

bool Simulation::CheckIfNameExists( const std::string& name )
{
    for ( auto other : m_bodies )
    {
        if ( other->name != name ) continue;
        return true;
    }

    return false;
}