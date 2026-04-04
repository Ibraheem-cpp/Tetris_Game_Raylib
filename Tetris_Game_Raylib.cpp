#include <iostream>
#include "raylib.h"
#include "grid.h"
using namespace std;

int main()
{
    Grid grid;
    const int Height = grid.getCellSize() * grid.getRows();
    const int Width = grid.getCellSize() * grid.getCols();

    SetTargetFPS(60);
    InitWindow(Width, Height, "Tetris Game");

    grid.printGrid();

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(DARKBLUE);
       
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
