#include "Debug.h"

static int INF = std::numeric_limits<int>::max();

template<typename T>
void Debug::Log( const T& message )
{
    std::cout << message << '\n';
}

void Debug::HandleTargetFPS()
{
    static int targetFPS = GetMonitorRefreshRate( GetCurrentMonitor() );
    KeyboardKey keyPressed = static_cast<KeyboardKey>( GetKeyPressed() );

    // TO-DO some "Input handling manager"
    switch ( keyPressed )
    {
    case KEY_HOME:
    {
        bool vSync = IsWindowState( FLAG_VSYNC_HINT );

        ClearWindowState( FLAG_VSYNC_HINT *  vSync );
        SetWindowState  ( FLAG_VSYNC_HINT * !vSync );

        SetTargetFPS( targetFPS * !IsWindowState( FLAG_VSYNC_HINT ) );
        break;
    }
    case KEY_DELETE:
    {
        targetFPS = INF;
        SetTargetFPS( 0 );
        break;
    }
    case KEY_UP:
    {
        if ( targetFPS == INF ) targetFPS = GetMonitorRefreshRate( GetCurrentMonitor() ) + 1;
        ClearWindowState( FLAG_VSYNC_HINT );
        SetTargetFPS( targetFPS++ );
        break;
    }
    case KEY_DOWN:
    {
        if ( targetFPS == INF ) targetFPS = GetMonitorRefreshRate( GetCurrentMonitor() );
        ClearWindowState( FLAG_VSYNC_HINT );
        SetTargetFPS( targetFPS-- );
        break;
    }
    }

    // Drawing
    if ( IsWindowState( FLAG_VSYNC_HINT ) ) 
    {
        DrawText( "VSync", 0, 20, 20, WHITE );
    }
    else if ( targetFPS == INF ) 
    {
        DrawText( "Unlimited", 0, 20, 20, WHITE );
    }
    else 
    {
        DrawText( TextFormat( "%i Target", targetFPS ), 0, 20, 20, WHITE );
    }
}