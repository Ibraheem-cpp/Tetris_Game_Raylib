#include <iostream>
#include <vector>
#include "raylib.h"
#include "grid.h"
#include "tetrominos.h"
using namespace std;

int main()
{
    Grid grid = Grid();
    const int Height = grid.getCellSize() * grid.getRows();
    const int Width = grid.getCellSize() * grid.getCols();

    SetTargetFPS(60);
    InitWindow(Width, Height, "Tetris Game");

    S_Tetromino block;

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.DrawGrid();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
