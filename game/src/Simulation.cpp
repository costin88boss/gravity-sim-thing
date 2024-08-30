#include "Simulation.h"

Simulation::Simulation( const Window window, const float timeStep, float timeSpeed )
    :
    m_window( window ),
    m_timeStep( timeStep ),
    m_timeSpeed( timeSpeed )
{
    if ( GetWindowHandle() )
        throw std::runtime_error("Error initializing simulation: Window already initialized!");

    InitWindow( m_window.width, m_window.height, m_window.title.c_str() );
    InitAudioDevice();

    m_targetFPS = GetMonitorRefreshRate(GetCurrentMonitor());
    SetTargetFPS(m_targetFPS);
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
    static float accumulator = 0.0f;
    accumulator += GetFrameTime() * m_timeSpeed;

    while ( accumulator >= m_timeStep )
    {
        Update();
        accumulator -= m_timeStep;
    }

    // TO-DO some "Input handling manager"
    if (IsKeyPressed(KEY_HOME)) {
        if (IsWindowState(FLAG_VSYNC_HINT)) {
            ClearWindowState(FLAG_VSYNC_HINT);
            SetTargetFPS(m_targetFPS);
        }
        else {
            SetWindowState(FLAG_VSYNC_HINT);
            SetTargetFPS(0);
        }
    }
    if (IsKeyPressed(KEY_DELETE)) {
        m_targetFPS = -1;
        SetTargetFPS(0);
    }
    if (IsKeyPressed(KEY_UP) || IsKeyPressedRepeat(KEY_UP)) {
        if (m_targetFPS == -1) m_targetFPS = GetMonitorRefreshRate(GetCurrentMonitor());
        ClearWindowState(FLAG_VSYNC_HINT);
        SetTargetFPS(++m_targetFPS);
    }
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressedRepeat(KEY_DOWN)) {
        if (m_targetFPS == -1) m_targetFPS = GetMonitorRefreshRate(GetCurrentMonitor());
        ClearWindowState(FLAG_VSYNC_HINT);
        SetTargetFPS(--m_targetFPS);
    }

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
    ClearBackground(m_bgColor);


    DrawFPS(0.0f, 0.0f);
    if (IsWindowState(FLAG_VSYNC_HINT)) {
        DrawText("VSync", 0, 21, 20, WHITE);
    }
    else if (_debugFPS == -1) {
        DrawText("Unlimited", 0, 21, 20, WHITE);
    }
    else {
        DrawText(TextFormat("%2i Target", _debugFPS), 0, 21, 20, WHITE);
    }

    for ( auto& body : m_bodies )
    {
        body.Draw();
    }
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