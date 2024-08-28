#include <stddef.h>
#include "raylib.h"
#include "Simulation.h"

const size_t WINDOW_WIDTH = 800, WINDOW_HEIGHT = 480;
const Color BG_COLOR = { r: 40, g: 80, b: 80, a: 255 };

int main()
{
    // ------ Initialization ------
    Simulation sim( "", WINDOW_WIDTH, WINDOW_HEIGHT, 1 );
    sim.SetBGColor( BG_COLOR );

    sim.AddBody( "body1", Vec2::Zero(), Vec2::Zero(), 1 );
    sim.AddBody( "body2", Vec2::Zero(), Vec2::Zero(), 1 );
    
    sim.GetBodyByName( "body1" ).Move({ 1, 0 }); // Test for changing body values inside sim
    
    // ------ Main Loop ------
    while ( sim.IsRunning() )
    {
        sim.Tick();
        sim.ListBodies();
    }
}