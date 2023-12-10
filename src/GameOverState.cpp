#include "GameOverState.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "Game.h"
// #include "TextureManager.h"
// #include "LoaderParams.h"
// #include "AnimatedGraphic.h"
// #include "MenuButton.h"
// #include "StateParser.h"
#include <iostream>
#include <string>

// GameState *GameOverState::s_pTransitionState = nullptr;
const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain()
{
    Game::Instance()->getGameStateMachine()->changeState(new MainMenuState());
    // s_pTransitionState = new MainMenuState();
}

void GameOverState::s_restartPlay()
{
    Game::Instance()->getGameStateMachine()->changeState(new PlayState());
    // s_pTransitionState = new PlayState();
}

void GameOverState::update()
{    
    if(IsKeyDown(KEY_ENTER))
    {
        TheGame::Instance()->getGameStateMachine()->changeState(new PlayState(m_score));
    }
    m_textCounter++;
    // if (m_bLoadingComplete && !m_gameObjects.empty())
    // {
    //     for (int i = 0; i < m_gameObjects.size(); i++)
    //     {
    //         m_gameObjects[i]->update();
    //     }
    // }
    // if (s_pTransitionState != nullptr)
    // {
    //     TheGame::Instance()->getGameStateMachine()->changeState(s_pTransitionState);
    // }
}

void GameOverState::render()
{
    if (m_textCounter % 15 == 0)
    {
        m_textCounter = 0;
        if (m_displ == 0)
        {
            m_displ = 5;
        }
        else
        {
            m_displ = 0;
        }
    }
    
    DrawText("Game Over!", m_textPosX + m_displ, m_textPosY, 80, darkGreen);
    std::string appleString = (m_score == 1) ? "apple" : "apples";
    DrawText(TextFormat("You have eaten\n     %i %s", m_score, appleString.c_str()), m_textPosX + 20, m_textPosY + 100, 50, darkGreen);
    DrawText("Press Enter to play again", m_textPosX , m_textPosY + 250, 35, darkGreen);
    // if (m_bLoadingComplete && !m_gameObjects.empty())
    // {
    //     for (int i = 0; i < m_gameObjects.size(); i++)
    //     {
    //         m_gameObjects[i]->draw();
    //     }
    // }
}

bool GameOverState::onEnter()
{
    // s_pTransitionState = nullptr;
    // StateParser stateParser;
    // stateParser.parseState("src/assets/attack.xml", s_gameOverID, &m_gameObjects, &m_textureIDs);
    // m_callbacks.push_back(0);
    // m_callbacks.push_back(s_gameOverToMain);
    // m_callbacks.push_back(s_restartPlay);
    // setCallbacks(m_callbacks);
    m_textPosX = (2*Constants::offsetBorder + Constants::frameWidthHeight)/4;
    m_textPosY = (2*Constants::offsetBorder + Constants::frameWidthHeight)/4;
    m_bLoadingComplete = true;
    std::cout << "Entering GameOverState\n";
    return true;
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
{
    // for (int i = 0; i < m_gameObjects.size(); i++)
    // {
    //     if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
    //     {
    //         MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
    //         pButton->setCallback(callbacks[pButton->getCallbackID()]);
    //     }
    // }
}

bool GameOverState::onExit()
{
    // if (m_bLoadingComplete && !m_gameObjects.empty())
    // {
    //     for (int i = 0; i < m_gameObjects.size(); i++)
    //     {
    //         m_gameObjects[i]->clean();
    //     }
    //     m_gameObjects.clear();
    // }
    // for (int i = 0; i < m_textureIDs.size(); i++)
    // {
    //     TextureManager::Instance()->unload(m_textureIDs[i]);
    // }

    std::cout << "exiting GameOverState\n";
    return true;
}