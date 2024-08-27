#include <stddef.h>
#include "raylib.h"

const size_t WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;

int main()
{
    // ------ Initialization ------
    InitWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "" );
    InitAudioDevice();
    
    // ------ Main Loop ------
    while ( !WindowShouldClose() )
    {
        BeginDrawing();

        ClearBackground( { r: 0, g: 60, b: 120, a: 255 } );

        EndDrawing();
    }

    // ------ Deinitialization ------
    CloseAudioDevice();
    CloseWindow();
}