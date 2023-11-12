#pragma once
#ifndef __Snake__
#define __Snake__

#include <raylib.h>
#include <deque>

class Snake
{
public:
    Snake();
    ~Snake();
    void draw();
    void drawEyes();
    void update();
    void handleInput();
    Vector2 getSnakeHead();
    std::deque<Vector2> getSnakeBody();
    void eatFood();
    int getFoodEaten();
    bool dead();
    bool checkCollision();

    void reset();

private:
    std::deque<Vector2> m_body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    Vector2 m_direction = {1, 0};
    Vector2 m_eyeDirection = {1, 0};
    int m_frameCounter = 0;
    const int m_frameDelay = 10;
    bool m_bCanChangeDirection = true;
    bool m_bDead = false;
    int m_foodEaten = 0;
    bool m_bAddSegment = false;
    Sound m_eatSound;
    Sound m_wallSound;
};

#endif // __Snake__