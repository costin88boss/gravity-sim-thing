#include <stddef.h>
#include "raylib.h"
#include "Simulation.h"
#include "Physics.h"
#include "WorldScreen.h"

const std::string WINDOW_TITLE  = "Gravity Sim Thing 💫";
const size_t      WINDOW_WIDTH  = 960;
const size_t      WINDOW_HEIGHT = WINDOW_WIDTH / 16 * 9;  // 16 to 9 aspect ratio
const float       TIME_DELTA    = 0.01f;
const float       TIME_SPEED    = 1.0f;
const Color       BG_COLOR      = { 10, 20, 30 };

int main()
{
    // ------ Initialization ------
    Simulation sim( { WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT }, TIME_DELTA, TIME_SPEED );
    Physics::bigG = 1.0;
    sim.SetBGColor( BG_COLOR );

    sim.AddBody({ "body1", {  0.0f, 0.0f }, { 0.0f, -16.0f / 1000.0f }, 1000.0f, 30.0f, RED   });
    sim.AddBody({ "body2", {  4.0f, 0.0f }, { 0.0f,  16.0f           }, 1.0f,    20.0f, BLUE  });

    // ------ Main Loop ------
    while ( sim.IsRunning() )
    {
        sim.Tick();
    }
}