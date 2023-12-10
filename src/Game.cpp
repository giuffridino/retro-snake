#include "Game.h"
#include "raymath.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include <iostream>

Game *Game::s_pInstance = nullptr;

Game::Game()
{
    // m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
    m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new PlayState());
}

Game::~Game()
{
}

void Game::draw()
{
    m_pGameStateMachine->render();
    // m_food.draw();
    // m_snake.draw();
}

void Game::update()
{
    m_pGameStateMachine->update();
    // if (m_bRunning)
    // {
    //     checkSnakeFoodCollision();
    //     m_snake.update();
    //     if (m_snake.dead())
    //     {
    //         gameOver();
    //     }
    // }
    // else
    // {
    //     m_snake.handleInput();
    //     if (!m_snake.dead())
    //     {
    //         m_bRunning = true;
    //     }
    // }   
}

// void Game::checkSnakeFoodCollision()
// {
//     if (Vector2Equals(m_snake.getSnakeHead(), m_food.getFoodPos()))
//     {
//         m_snake.eatFood();
//         m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
//     }
// }

// void Game::setRunning(bool running)
// {
//     m_bRunning = running;
// }

int Game::getHighScore()
{
    return m_highScore;
}

void Game::updateHighScore(int score)
{
    if (score > m_highScore)
    {
        m_highScore = score;
    }
}

// void Game::gameOver()
// {
//     std::cout << "Game over!\n";
//     updateHighScore();
//     m_snake.reset();
//     m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
//     m_bRunning = false;
// }