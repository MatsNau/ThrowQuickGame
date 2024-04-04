//
// Created by Mats on 29.03.2024.
//

#ifndef THROWQUICK_RENDERWINDOW_H
#define THROWQUICK_RENDERWINDOW_H

#include <SDL.h>
#include <string>

class RenderWindow {
public:
    RenderWindow(const std::string& title, int width, int height);
    ~RenderWindow();
    SDL_Renderer* GetRenderer();

    void Clear();
    void Present();

private:
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
};

#endif //THROWQUICK_RENDERWINDOW_H
