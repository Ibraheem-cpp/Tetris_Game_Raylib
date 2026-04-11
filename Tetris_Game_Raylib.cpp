#include <iostream>
#include <vector>
#include "raylib.h"
#include "game.h"
using namespace std;

int main()
{
    Game game;
    const int Height = game.getGridCellSize() * game.getGridRows();
    const int Width = game.getGridCellSize() * game.getGridCols();
    
    SetTargetFPS(60);
    InitWindow(Width, Height, "Tetris Game");

    while (!WindowShouldClose()) {

        game.checkInput();
        if (game.eventTriggered(0.3)) {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
