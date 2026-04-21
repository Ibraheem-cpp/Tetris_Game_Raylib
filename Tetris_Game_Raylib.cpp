#include <iostream>
#include <string>
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

        DrawText("SCORE", Width + 35, 30, 40, WHITE);
        DrawRectangleRounded({ float(Width) + 25, 80, 160, 60 }, 0.4, 4, SKYBLUE);
        std::string scoreStr = std::to_string(game.getScore());
        int scoreWidth = MeasureText(scoreStr.c_str(), 40);
        int scoreX = Width + 25 + (160 / 2) - (scoreWidth / 2);
        int scoreY = 80 + (60 / 2) - (40 / 2);
        DrawText(TextFormat("%d", game.getScore()), scoreX, scoreY, 40, WHITE);

        DrawText("Next Block", Width + 25, (Height / 2)-100, 30, WHITE);
        DrawRectangleRounded({ float(Width) + 25, float(Height)/2-50, 160, 160 }, 0.4, 4, SKYBLUE);

        if (game.isGameOver()) {
            DrawText("Game Over", Width + 30, Height - 120, 30, MAROON);
            PauseMusicStream(game.bgMusic);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
