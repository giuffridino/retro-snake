#include <iostream>
#include "Food.h"
#include "Colors.h"
#include "raymath.h"
#include "Constants.h"

Food::Food()
{
    m_texture = LoadTexture("assets/apple-fruit.png");
    if (m_texture.id == 0) {
        std::cerr << "Error loading texture\n";
        return;
    }
    m_srcRect = {0.0f, 0.0f, (float) m_frameWidth, (float) m_frameHeight};
    m_origin = {0.0f, 0.0f};
}

Food::~Food()
{
    UnloadTexture(m_texture);
}

void Food::draw()
{
    m_destRect = {Constants::offsetBorder + m_position.x * m_cellSize, Constants::offsetBorder + m_position.y * m_cellSize, (float) m_cellSize, (float) m_cellSize};
    DrawTexturePro(m_texture, m_srcRect, m_destRect, m_origin, 0, darkGreen);
    m_destRect = {Constants::offsetBorder - 5, Constants::offsetBorder + Constants::cellSize * Constants::cellCount + 10, (float) 1.5 * m_cellSize, (float) 1.5 * m_cellSize};
    DrawTexturePro(m_texture, m_srcRect, m_destRect, m_origin, 0, darkGreen);
}

Vector2 Food::generateRandomPos()
{
    float x = GetRandomValue(0, m_cellCount - 1);
    float y = GetRandomValue(0, m_cellCount - 1);
    return Vector2{x, y};
}

void Food::placeFoodInRandomPos(std::deque<Vector2> snakeBody)
{
    m_position = generateRandomPos();
    while (isElementInDeque(m_position, snakeBody))
    {
        m_position = generateRandomPos();
    }
}

Vector2 Food::getFoodPos()
{
    return m_position;
}

