#pragma once
#ifndef __MainMenuState__
#define __MainMenuState__

#include "MenuState.h"

// class GameObject;

class MainMenuState : public MenuState
{
public:
	// MainMenuState() {};
	virtual ~MainMenuState() {};

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_mainMenuID; };

private:
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	static void s_menuToPlay();
	static void s_exitFromMenu();

    static const std::string s_mainMenuID;

	int m_textCounter = 0;
	int m_displ = 0;
	int m_textPosX;
	int m_textPosY;

};

#endif /* defined(__MainMenuState__) */