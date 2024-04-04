//
// Created by Mats on 04.04.2024.
//
#include "Control.h"

void Control::KeyboardControl(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                m_position.y -= m_velocity;
                break;
            case SDLK_s:
                m_position.y += m_velocity;
                break;
            case SDLK_a:
                m_position.x -= m_velocity;
                break;
            case SDLK_d:
                m_position.x += m_velocity;
                break;
            default:
                break;
        }
    }
}