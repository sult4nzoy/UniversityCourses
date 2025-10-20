#include "engine.h"
int main()
{
    Engine game;

    while (!WindowShouldClose())
    {
        // uppdatera game logik
        game.updateGame();
        
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();

    }

    return 0;
}