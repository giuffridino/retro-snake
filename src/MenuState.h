#pragma once
#ifndef __MenuState__
#define __MenuState__

#include "GameState.h"
// #include "MenuButton.h"

class MenuState : public GameState
{
public:
	virtual ~MenuState(){};

protected:
	typedef void (*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
	std::vector<Callback> m_callbacks;
};

#endif /* defined(__MenuState__) */