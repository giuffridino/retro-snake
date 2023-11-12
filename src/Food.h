#pragma once
#ifndef __Food__
#define __Food__

#include <raylib.h>
#include <deque>

class Food
{
public:
    Food();
    ~Food();
    void draw();
    Vector2 generateRandomPos();
    void placeFoodInRandomPos(std::deque<Vector2> snakeBody);
    Vector2 getFoodPos();

private:
    Texture2D m_texture;
    Rectangle m_srcRect;
    Rectangle m_destRect;
    Vector2 m_origin;
    float m_frameWidth = 128;
    float m_frameHeight = 128;

    Vector2 m_position;
    int m_cellSize = 30;
    int m_cellCount = 25;
};

#endif // __Food__