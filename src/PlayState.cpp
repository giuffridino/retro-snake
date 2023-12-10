#include "PlayState.h"
#include "GameOverState.h"
#include "Game.h"
#include "raymath.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState(void)
{
    m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
}

PlayState::PlayState(int highScore)
{
    m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
    m_highScore = highScore;
}

PlayState::~PlayState(void)
{
    
}

void PlayState::update(void)
{
    TheGame::Instance()->updateHighScore(m_highScore);
    checkSnakeFoodCollision();
    m_snake.update();
    if (m_snake.dead())
    {
        // gameOver();
        TheGame::Instance()->getGameStateMachine()->pushState(new GameOverState(m_snake.getFoodEaten()));
    }
}

void PlayState::render(void)
{
    DrawRectangleLinesEx(m_frameRect, rectThickness, darkGreen);
    DrawText("Retro Snake", Constants::offsetBorder - 5, 20, 40, darkGreen);
    m_food.draw();
    m_snake.draw();
    DrawText(TextFormat("%i", m_snake.getFoodEaten()), Constants::offsetBorder + 45, Constants::offsetBorder + Constants::cellSize * Constants::cellCount + 17, 40, darkGreen);
    DrawText(TextFormat("High score: %i", TheGame::Instance()->getHighScore()), Constants::frameWidthHeight - 3 * Constants::offsetBorder + 22, Constants::offsetBorder + Constants::cellSize * Constants::cellCount + 17, 40, darkGreen);
}

void PlayState::checkSnakeFoodCollision()
{
    if (Vector2Equals(m_snake.getSnakeHead(), m_food.getFoodPos()))
    {
        m_snake.eatFood();
        m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
    }
}

// void PlayState::updateHighScore(void)
// {
//     if (m_snake.getFoodEaten() > m_highScore)
//     {
//         m_highScore = m_snake.getFoodEaten();
//     }
// }

bool PlayState::onEnter(void)
{
    std::cout << "Trying to enter playstate\n";
    m_snake.reset();
    m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
    std::cout << "Entering playstate\n";
    return true;
}

bool PlayState::onExit(void)
{
    // m_bExiting = true;
    std::cout << "exiting PlayState\n";
    return true;
}
