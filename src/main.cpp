#include <raylib.h>
#include <iostream>
#include "Game.h"
#include "Colors.h"
#include "Constants.h"

double lastUpdateTime = 0;
bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    std::cout << "Starting the game...\n";
    InitWindow(2 * Constants::offsetBorder + Constants::frameWidthHeight, 2 * Constants::offsetBorder + Constants::frameWidthHeight, "Snake");
    InitAudioDevice();
    Music music = LoadMusicStream("assets/kim-lightyear-leave-the-world-tonight-chiptune-edit-loop-132102.mp3");
    music.looping = true;
    PlayMusicStream(music);
    SetMusicVolume(music, 0.08);

    SetTargetFPS(60);
    // Game game = Game();

    // Rectangle frameRect = {(float) Constants::offsetBorder - rectThickness, (float) Constants::offsetBorder - rectThickness, (float) Constants::frameWidthHeight + 10, (float) Constants::frameWidthHeight + 10};

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(green);

        // DrawRectangleLinesEx(frameRect, rectThickness, darkGreen);
        // DrawText("Retro Snake", Constants::offsetBorder - 5, 20, 40, darkGreen);
        // DrawText(TextFormat("%i", game.m_snake.getFoodEaten()), Constants::offsetBorder + 45, Constants::offsetBorder + Constants::cellSize * Constants::cellCount + 17, 40, darkGreen);
        // DrawText(TextFormat("High score: %i", game.getHighScore()), frameWidthHeight - 3 * Constants::offsetBorder + 22, Constants::offsetBorder + Constants::cellSize * Constants::cellCount + 17, 40, darkGreen);

        // game.update();
        // game.draw();
        TheGame::Instance()->update();
        TheGame::Instance()->draw();
        // DrawFPS(GetScreenWidth() - 95, 10);
        EndDrawing();
    }
    
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}