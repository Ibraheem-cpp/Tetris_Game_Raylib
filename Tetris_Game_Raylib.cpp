#include <iostream>
#include <vector>
#include "raylib.h"
#include "grid.h"
using namespace std;

int main()
{
    Grid grid = Grid();
    const int Height = grid.getCellSize() * grid.getRows();
    const int Width = grid.getCellSize() * grid.getCols();

    SetTargetFPS(60);
    InitWindow(Width, Height, "Tetris Game");

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);
        grid.DrawGrid();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
