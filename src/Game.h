#pragma once
#ifndef __Game__
#define __Game__

#include <raylib.h>
#include "Snake.h"
#include "Food.h"
#include "GameStateMachine.h"

// class GameStateMachine;

class Game
{
public:
    ~Game();
    static Game* Instance(void)
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

    Snake m_snake = Snake();
    Food m_food = Food();

    void draw();
    void update();
    // void checkSnakeFoodCollision();

    // void setRunning(bool running);
    int getHighScore();
    void updateHighScore(int score);

    // void gameOver();
    GameStateMachine* getGameStateMachine(void) { return m_pGameStateMachine; }

private:
    Game(void);
    static Game* s_pInstance;

    GameStateMachine* m_pGameStateMachine;
    int m_highScore = 0;
};

typedef Game TheGame;

#endif // __Game__