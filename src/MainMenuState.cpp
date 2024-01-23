    #include "MainMenuState.h"
    #include "PlayState.h"
    #include "Game.h"
    #include <iostream>

    const std::string MainMenuState::s_mainMenuID = "MENU";

    void MainMenuState::update()
    {
        if(IsKeyDown(KEY_ENTER))
        {
            TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
        }
        m_textCounter++;
    }

    void MainMenuState::render()
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
        
        DrawText("RETRO-SNAKE!", m_textPosX + m_displ, m_textPosY, 80, darkGreen);
        DrawText("Press Enter to play", m_textPosX + 50, m_textPosY + 100, 50, darkGreen);
        DrawText("Toggle fullscreen and sound (resume)", m_textPosX + 25, m_textPosY + 200, 30, darkGreen);
        DrawText("for optimal experience", m_textPosX + 155, m_textPosY + 250, 30, darkGreen);
    }

    bool MainMenuState::onEnter()
    {
        m_textPosX = (2*Constants::offsetBorder + Constants::frameWidthHeight)/5 - 40;
        m_textPosY = (2*Constants::offsetBorder + Constants::frameWidthHeight)/4;
        m_bLoadingComplete = true;
        return true;
    }

    bool MainMenuState::onExit()
    {
        // m_bExiting = true;
        // if (m_bLoadingComplete && !m_gameObjects.empty())
        // {
        //     for (int i = 0; i < m_gameObjects.size(); i++)
        //     {
        //         m_gameObjects[i]->clean();
        //         m_gameObjects.pop_back();
        //     }
        //     m_gameObjects.clear();
        // }
        // for (int i = 0; i < m_textureIDs.size(); i++)
        // {
        //     TextureManager::Instance()->unload(m_textureIDs[i]);
        // }
        std::cout << "exiting MainMenuState\n";
        return true;
    }

    void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
    {
        // if (!m_gameObjects.empty())
        // {
        //     for (int i = 0; i < m_gameObjects.size(); i++)
        //     {
        //         if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
        //         {
        //             MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
        //             pButton->setCallback(callbacks[pButton->getCallbackID()]);
        //             std::cout << "Setting callback for MenuButton for which pButton->getCallbackID() = " << pButton->getCallbackID() << "\n";
        //             std::cout << "Setting callback for MenuButton for which callbacks[pButton->getCallbackID()] = " << callbacks[pButton->getCallbackID()] << "\n";
        //         }
        //     }
        // }
    }

    void MainMenuState::s_menuToPlay()
    {
        std::cout << "Play button clicked\n";
        Game::Instance()->getGameStateMachine()->changeState(new PlayState());
    }

    void MainMenuState::s_exitFromMenu()
    {
        std::cout << "Exit button clicked\n";
        // Game::Instance()->quit();
    }
