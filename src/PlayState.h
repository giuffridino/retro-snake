#pragma once
#ifndef __PlayState__
#define __PlayState__

#include <string>
#include "Snake.h"
#include "Food.h"
#include "Constants.h"
#include "GameState.h"

class PlayState : public GameState
{
public:
	PlayState(void);
	PlayState(int highScore);
	virtual ~PlayState(void);

	virtual void update(void);
	virtual void render(void);

	virtual bool onEnter(void);
	virtual bool onExit(void);

	virtual std::string getStateID(void) const { return s_playID; };

	void checkSnakeFoodCollision(void);
	int getHighScore(void) const {return m_highScore;}
	void updateHighScore(void);

private:
    static const std::string s_playID;

    Snake m_snake = Snake();
    Food m_food = Food();
	int m_highScore = 0;
	const Rectangle m_frameRect = {(float) Constants::offsetBorder - rectThickness, (float) Constants::offsetBorder - rectThickness, (float) Constants::frameWidthHeight + 10, (float) Constants::frameWidthHeight + 10};
};

#endif /* defined(__PlayState__) */