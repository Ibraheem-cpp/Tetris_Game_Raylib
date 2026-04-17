#include <iostream>
#include "raylib.h"
#include "game.h"
using namespace std;

int main()
{
    Game game;
    const int Height = game.getGridCellSize() * game.getGridRows();
    const int Width = game.getGridCellSize() * game.getGridCols();
    
    SetTargetFPS(60);
    InitWindow(Width + 200, Height + 20, "Tetris Game");

    while (!WindowShouldClose()) {

        UpdateMusicStream(game.bgMusic);

        game.checkInput();
        if (game.eventTriggered(0.2)) {
            game.MoveBlockDown();
            
        }

        game.checkCompletedRows();

        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
