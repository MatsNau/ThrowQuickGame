//
// Created by Mats on 27.04.2024.
//

#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
    clean();
}

void Game::init(const std::string& title, int width, int height, bool fullscreen)
{
    int flags = 0;

    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem Initialized!" << std::endl;
        m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);


        if(m_window) {
            SDL_DisplayMode displayMode;
            if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) {
                SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
            } else {
                m_screenWidth = &displayMode.w;
                m_screenHeight = &displayMode.h;
            }
            std::cout << "Window Created!" << std::endl;
        }else{
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, 0);
        if(m_renderer)
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created!" << std::endl;

        m_isRunning = true;
    }
    else
    {
        m_isRunning  = false;
    }
}

bool Game::running()
{
    return m_isRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            m_isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    // Ereignisse verarbeiten
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        m_playerOne->handleInput(event);
        //player2.handleInput(event);
        if (event.type == SDL_QUIT) {
            m_isRunning = false;
        }
    }

    m_playerOne->move();

}


void Game::initPlayers()
{
    m_playerOne->initPlayer("PlayerOne", m_renderer, m_screenWidth, m_screenHeight);
    m_playerTwo->initPlayer("PlayerTwo", m_renderer, m_screenWidth, m_screenHeight);
}

void Game::render()
{
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_playerOne->getTexture(), nullptr, m_playerOne->getPosition());
    SDL_RenderPresent(m_renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}