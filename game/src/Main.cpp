#include <stddef.h>
#include "raylib.h"
#include "Simulation.h"
#include "Physics.h"
#include "WorldScreen.h"

const std::string WINDOW_TITLE  = "Title";
const size_t      WINDOW_WIDTH  = 960;
const size_t      WINDOW_HEIGHT = WINDOW_WIDTH / 16 * 9;  // 16 to 9 aspect ratio
const float       TIME_DELTA    = 0.01f;
const float       TIME_SPEED    = 20.0f;
const Color       BG_COLOR      = { 40, 80, 80, 255 };

int main()
{
    // ------ Initialization ------
    Simulation sim( { WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT }, TIME_DELTA, TIME_SPEED );
    Physics::bigG = 1.0;
    sim.SetBGColor( BG_COLOR );

    sim.AddBody({ "body1", { -2.0f, 0.0f }, { 0.0f, -0.35f }, 1.0f });
    sim.AddBody({ "body2", {  2.0f, 0.0f }, { 0.0f,  0.35f }, 1.0f });

    // ------ Main Loop ------
    while ( sim.IsRunning() )
    {
        sim.Tick();
    }
}