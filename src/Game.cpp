#include "Game.h"
#include "raymath.h"
#include <iostream>

Game::Game()
{
    m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
    // InitAudioDevice();
    // m_music = LoadMusicStream("assets/man-is-he-mega-glbml-22045.mp3");
    // m_music.looping = true;
}

Game::~Game()
{
    // UnloadMusicStream(m_music);
    // CloseAudioDevice();
}

void Game::draw()
{
    m_food.draw();
    m_snake.draw();
}

void Game::update()
{
    if (m_bRunning)
    {
        // UpdateMusicStream(m_music);
        // if (!IsMusicStreamPlaying(m_music))
        // {
        //     std::cout << "Playing music!!\n";
        //     PlayMusicStream(m_music);
        // }
        
        checkSnakeFoodCollision();
        m_snake.update();
        if (m_snake.dead())
        {
            gameOver();
        }
    }
    else
    {
        m_snake.handleInput();
        if (!m_snake.dead())
        {
            m_bRunning = true;
        }
    }    
}

void Game::checkSnakeFoodCollision()
{
    if (Vector2Equals(m_snake.getSnakeHead(), m_food.getFoodPos()))
    {
        m_snake.eatFood();
        m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
    }
}

void Game::setRunning(bool running)
{
    m_bRunning = running;
}

int Game::getHighScore()
{
    return m_highScore;
}

void Game::updateHighScore()
{
    if (m_snake.getFoodEaten() > m_highScore)
    {
        m_highScore = m_snake.getFoodEaten();
    }
}

void Game::gameOver()
{
    std::cout << "Game over!\n";
    updateHighScore();
    m_snake.reset();
    m_food.placeFoodInRandomPos(m_snake.getSnakeBody());
    m_bRunning = false;
}