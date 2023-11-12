#pragma once
#ifndef __Game__
#define __Game__

#include <raylib.h>
#include "Snake.h"
#include "Food.h"

class Game
{
public:
    Game();
    ~Game();

    Snake m_snake = Snake();
    Food m_food = Food();

    void draw();
    void update();
    void checkSnakeFoodCollision();

    void setRunning(bool running);
    int getHighScore();
    void updateHighScore();

    void gameOver();

private:
    bool m_bRunning = true;
    int m_highScore = 0;
    Music m_music;
};

#endif // __Game__