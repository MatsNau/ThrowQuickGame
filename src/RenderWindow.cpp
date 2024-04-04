//
// Created by Mats on 29.03.2024.
//

#include "RenderWindow.h"
#include <iostream>

RenderWindow::RenderWindow(const std::string& title, int width, int height) {

    // Erstelle das Fenster
    m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (m_Window == nullptr) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    // Erstelle den Renderer
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (m_Renderer == nullptr) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        return;
    }
}

RenderWindow::~RenderWindow() {
    // Zerstöre den Renderer und das Fenster
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    // Beende SDL
    SDL_Quit();
}

SDL_Renderer* RenderWindow::GetRenderer(){
    return m_Renderer;
}

void RenderWindow::Clear() {
    // Setze die Hintergrundfarbe auf weiß
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    // Lösche den Bildschirm
    SDL_RenderClear(m_Renderer);
}

void RenderWindow::Present() {
    // Aktualisiere den Bildschirm
    SDL_RenderPresent(m_Renderer);
}
