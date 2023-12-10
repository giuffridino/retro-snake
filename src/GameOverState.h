#pragma once
#ifndef __GameOverState__
#define __GameOverState__

#include "MenuState.h"
// #include "GameObject.h"
#include <string>
#include <vector>

class GameOverState : public MenuState
{
public:
	GameOverState(int score) { m_score = score; };

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; };

	virtual void setCallbacks(const std::vector<Callback>& callbacks);

private:
    static void s_gameOverToMain();
    static void s_restartPlay();

    static const std::string s_gameOverID;

	int m_score = 0;
	int m_textCounter = 0;
	int m_displ = 0;
	int m_textPosX;
	int m_textPosY;
};

#endif /* defined(__GameOverState__) */