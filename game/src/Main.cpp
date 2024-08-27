#include <stddef.h>
#include "raylib.h"
#include "Simulation.h"

const size_t WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;
const Color BG_COLOR = { r: 0, g: 60, b: 120, a: 255 };

int main()
{
    // ------ Initialization ------
    Simulation sim( "", WINDOW_WIDTH, WINDOW_HEIGHT, 1 );
    sim.SetBGColor( BG_COLOR );

    Body body1( "body1", Vec2::Zero(), Vec2::Zero(), 1 );
    Body body2( "body2", Vec2::Zero(), Vec2::Zero(), 1 );

    sim.AddBody( body1 );
    sim.AddBody( body2 );
    
    body1.Move({1,0});
    
    // ------ Main Loop ------
    while ( sim.IsRunning() )
    {
        sim.Tick();
        sim.ListBodies();
    }
}