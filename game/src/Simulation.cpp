#include "Simulation.h"

Simulation::Simulation( const Window window, const float timeStep )
    :
    m_window( window ),
    m_timeStep( timeStep )
{
    if ( GetWindowHandle() )
        throw std::runtime_error("Error initializing simulation: Window already initialized!");

    SetConfigFlags( FLAG_VSYNC_HINT );
    InitWindow( m_window.width, m_window.height, m_window.title.c_str() );
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

void Simulation::SetBGColor( const Color color )
{
    m_bgColor = color;
}

void Simulation::AddBody( const Body& body )
{
    if ( CheckIfNameExists( body.name ) )
    {
        throw std::runtime_error("Error adding body: A body with this name already exists!");
    }
    else
    {
        m_bodies.push_back( body );
    }
}


void Simulation::ListBodies() const
{
    for ( auto body : m_bodies )
    {
        std::cout <<  body.name.c_str() << " at pos: ";
        body.position.Print();
        std::cout << " \n";
    }
    std::cout << "------\n";
}

Body& Simulation::GetBodyByName( const std::string& name ) const
{
    for ( auto& body : m_bodies )
    {
        if ( body.name != name ) continue;
        return ( Body& ) body;
    }
    
    throw std::runtime_error("Error finding body: No body exists with this name!");
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
    for ( auto& body : m_bodies )
    {
        body.UpdateVelocity( m_timeStep, m_bodies );
        body.UpdatePosition( m_timeStep );
    }
}

void Simulation::Draw()
{
    ClearBackground( m_bgColor );
    DrawFPS( 0.0f, 0.0f );
}

bool Simulation::CheckIfNameExists( const std::string& name )
{
    for ( auto other : m_bodies )
    {
        if ( other.name != name ) continue;
        return true;
    }

    return false;
}