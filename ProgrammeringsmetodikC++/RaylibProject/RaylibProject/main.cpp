#include "engine.h"


int main()
{
    Engine game;

    while (!WindowShouldClose())
    {
        // uppdatera game logik
        game.updateGame();
        BeginDrawing();
        ClearBackground(SKYBLUE);
        EndDrawing();
    }

    return 0;
}