#include "Snake.h"
#include "Constants.h"
#include "Colors.h"
#include "raymath.h"
#include "Food.h"

Snake::Snake()
{
    // InitAudioDevice();
    m_eatSound = LoadSound("assets/monster-crunch.mp3");
    SetSoundVolume(m_eatSound, 0.2); 
    SetSoundPitch(m_eatSound, 0.85);
    m_wallSound = LoadSound("assets/thump.mp3");
    SetSoundVolume(m_wallSound, 0.4); 
}

Snake::~Snake()
{
    UnloadSound(m_eatSound);
    UnloadSound(m_wallSound);
    // CloseAudioDevice();
}

void Snake::draw()
{
    for (unsigned int i = 0; i < m_body.size(); i++)
    {
        float x = m_body[i].x;
        float y = m_body[i].y;
        Rectangle segment = Rectangle{Constants::offsetBorder + x * Constants::cellSize, Constants::offsetBorder + y * Constants::cellSize, (float) Constants::cellSize, (float) Constants::cellSize};
        DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
    drawEyes();
}

void Snake::drawEyes()
{
    if (Vector2Equals(m_eyeDirection, (Vector2) {1, 0}))
    {
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 20, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 10, 2.0f, green);
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 20, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 20, 2.0f, green);
    }
    else if (Vector2Equals(m_eyeDirection, (Vector2) {-1, 0}))
    {
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 10, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 10, 2.0f, green);
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 10, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 20, 2.0f, green);
    }
    else if (Vector2Equals(m_eyeDirection, (Vector2) {0, 1}))
    {
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 10, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 20, 2.0f, green);
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 20, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 20, 2.0f, green);
    }
    else if (Vector2Equals(m_eyeDirection, (Vector2) {0, -1}))
    {
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 10, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 10, 2.0f, green);
        DrawCircle(Constants::offsetBorder + m_body[0].x * Constants::cellSize + 20, Constants::offsetBorder + m_body[0].y * Constants::cellSize + 10, 2.0f, green);
    }
}

void Snake::update()
{
    handleInput();
    m_frameCounter++;    
    if (m_frameCounter >= m_frameDelay && !checkCollision() && !m_bDead)
    {
        m_frameCounter = 0;
        m_body.push_front(Vector2Add(m_body[0], m_direction));
        if (m_bAddSegment)
        {
            m_bAddSegment = false;
        }
        else
        {
            m_body.pop_back();
        }
        m_bCanChangeDirection = true;
        m_eyeDirection = m_direction;
    }
}

void Snake::handleInput()
{
    if (IsKeyPressed(KEY_RIGHT) && m_direction.x != - 1 && m_bCanChangeDirection)
    {
        m_direction = {1, 0};
        m_bCanChangeDirection = false;
        m_bDead = false;
    }
    else if (IsKeyPressed(KEY_LEFT) && m_direction.x != 1 && m_bCanChangeDirection)
    {
        m_direction = {-1, 0};
        m_bCanChangeDirection = false;
        m_bDead = false;
    }
    else if (IsKeyPressed(KEY_UP) && m_direction.y != 1 && m_bCanChangeDirection)
    {
        m_direction = {0, -1};
        m_bCanChangeDirection = false;
        m_bDead = false;
    }
    else if (IsKeyPressed(KEY_DOWN) && m_direction.y != - 1 && m_bCanChangeDirection)
    {
        m_direction = {0, 1};
        m_bCanChangeDirection = false;
        m_bDead = false;
    }
}

Vector2 Snake::getSnakeHead()
{
    return m_body[0];
}

std::deque<Vector2> Snake::getSnakeBody()
{
    return m_body;
}

void Snake::eatFood()
{
    PlaySound(m_eatSound);
    m_bAddSegment = true;
    m_foodEaten++;
}   

int Snake::getFoodEaten()
{
    return m_foodEaten;
}

bool Snake::dead()
{
    return m_bDead;
}

bool Snake::checkCollision()
{
    Vector2 collisionHead = Vector2Add(m_body[0], m_direction);
    for (unsigned int i = 1; i < m_body.size(); i++)
    {
        if (Vector2Equals(collisionHead, m_body[i]) | (collisionHead.x < 0) | (collisionHead.x >= Constants::cellCount) | (collisionHead.y < 0) | (collisionHead.y >= Constants::cellCount))
        {
            PlaySound(m_wallSound);
            m_bDead = true;
            return true;
        }
    }
    return false;
}

void Snake::reset()
{
    m_body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    m_direction = {1, 0};
    m_eyeDirection = m_direction;
    m_frameCounter = 0;
    m_bCanChangeDirection = true;
    m_foodEaten = 0;
    m_bAddSegment = false;
}
