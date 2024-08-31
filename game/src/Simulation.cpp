#include "Simulation.h"

Simulation::Simulation( const Window window, const float timeStep, float timeSpeed )
    :
    m_window( window ),
    m_timeStep( timeStep ),
    m_timeSpeed( timeSpeed )
{
    // Window already initialized
    assert( !GetWindowHandle() );
    InitWindow( m_window.width, m_window.height, m_window.title.c_str() );
    InitAudioDevice();

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
}

Simulation::~Simulation()
{
    // Window already closed
    assert( GetWindowHandle() );
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
    // Name already exists
    assert( !CheckIfNameExists( body.name ));
    m_bodies.push_back( body );
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
    static float accumulator = 0.0f;
    accumulator += GetFrameTime() * m_timeSpeed;

    while ( accumulator >= m_timeStep )
    {
        Update();
        accumulator -= m_timeStep;
    }

    BeginDrawing();
    Draw();
    Debug::HandleTargetFPS();
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
    ClearBackground(m_bgColor);
    DrawFPS(0.0f, 0.0f);

    for ( auto& body : m_bodies )
    {
        body.Draw();
    }
}

bool Simulation::CheckIfNameExists( const std::string& name )
{
    for ( auto& other : m_bodies )
    {
        if ( other.name != name ) continue;
        return true;
    }

    return false;
}