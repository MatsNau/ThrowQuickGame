//
// Created by Mats on 27.04.2024.
//

#ifndef THROWQUICK_GAME_H
#define THROWQUICK_GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#include "Player.h"

class Game {

private:
    bool m_isRunning;
    int* m_screenHeight;
    int* m_screenWidth;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    std::shared_ptr<Player> m_playerOne = std::make_shared<Player>();
    std::shared_ptr<Player> m_playerTwo = std::make_shared<Player>();

public:
    Game();
    ~Game();

    void init(const std::string& title, int width, int height, bool fullscreen);

    void initPlayers();
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();



};


#endif //THROWQUICK_GAME_H
