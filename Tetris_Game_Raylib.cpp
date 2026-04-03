#include <iostream>
#include "raylib.h"
using namespace std;

int main()
{
    const int width = 500;
    const int height = 500;

    SetTargetFPS(60);
    InitWindow(width, height, "Tetris Game");

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(YELLOW);
        DrawCircle(width / 2, height / 2, 15.0, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
