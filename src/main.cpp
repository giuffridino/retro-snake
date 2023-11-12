#include <raylib.h>
#include <iostream>
#include "Game.h"
#include "Colors.h"
#include "Constants.h"

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

const int frameWidthHeight = Constants::cellSize * Constants::cellCount;
const int rectThickness = 5;

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
    InitWindow(2* Constants::offsetBorder + frameWidthHeight, 2* Constants::offsetBorder + frameWidthHeight, "Snake");
    InitAudioDevice();
    Music music = LoadMusicStream("assets/kim-lightyear-leave-the-world-tonight-chiptune-edit-loop-132102.mp3");
    music.looping = true;
    PlayMusicStream(music);
    SetMusicVolume(music, 0.08);

    SetTargetFPS(60);
    Game game = Game();

    Rectangle frameRect = {(float) Constants::offsetBorder - rectThickness, (float) Constants::offsetBorder - rectThickness, (float) frameWidthHeight + 10, (float) frameWidthHeight + 10};

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(green);

        DrawRectangleLinesEx(frameRect, rectThickness, darkGreen);
        DrawText("Retro Snake", Constants::offsetBorder - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", game.m_snake.getFoodEaten()), Constants::offsetBorder + 45, Constants::offsetBorder + Constants::cellSize * Constants::cellCount + 17, 40, darkGreen);
        DrawText(TextFormat("High score: %i", game.getHighScore()), frameWidthHeight - 3 * Constants::offsetBorder + 22, Constants::offsetBorder + Constants::cellSize * Constants::cellCount + 17, 40, darkGreen);

        game.update();
        game.draw();

        EndDrawing();
    }
    
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}