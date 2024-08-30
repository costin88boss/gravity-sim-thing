#include <stddef.h>
#include "raylib.h"
#include "Simulation.h"
#include "Physics.h"

const size_t WINDOW_WIDTH = 800, WINDOW_HEIGHT = 480;
const Color BG_COLOR = { 40, 80, 80, 255 };

int main()
{
    // ------ Initialization ------
    Simulation sim( "", WINDOW_WIDTH, WINDOW_HEIGHT, 0.01f );
    Physics::bigG = 1.0;
    sim.SetBGColor( BG_COLOR );

    sim.AddBody( "body1", { -5.0f, 0.0f }, Vec2::Zero(), 1.0f );
    sim.AddBody( "body2", {  5.0f, 0.0f }, Vec2::Zero(), 1.0f );
    
    // ------ Main Loop ------
    while ( sim.IsRunning() )
    {
        sim.Tick();
        sim.ListBodies();
    }
}