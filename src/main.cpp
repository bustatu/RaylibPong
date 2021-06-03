// Small game for now, can manage with just a header
#include "game/game.h"

int main() {
    
    // Initialization
    Init();

    // Main game loop
    while(!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        Update(GetFrameTime());

        // Draw
        BeginDrawing();

        Draw();
    
        EndDrawing();
    }

    End();

    return 0;
}