//
// Created by Mats on 04.04.2024.
//
#include "Player.h"
#include <iostream>

Player::Player(const std::string& playerName, SDL_Renderer* renderer)
    : m_name(playerName)
{
    m_velocity = 1.0f;
    m_renderer = renderer;
    // Initialisiere die Position des Spielers
    m_position.x = 100;
    m_position.y = 100;
    m_position.w = 50;
    m_position.h = 50;

    // Initialisierung der Bewegungsstatus
    m_isMovingUp = false;
    m_isMovingDown = false;
    m_isMovingLeft = false;
    m_isMovingRight = false;

    // Lade den Sprite des Spielers
    SDL_Surface* surface = SDL_LoadBMP("megaman.bmp");
    if (!surface) {
        std::cerr << "Failed to load player sprite: " << SDL_GetError() << std::endl;
    }
    m_sprite = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

Player::~Player() {
    SDL_DestroyTexture(m_sprite);
}

void Player::handleInput(SDL_Event& event)
{
    if (m_name == "Player1")
    {
        // Tasten für Bewegung nach oben/unten
        if (event.key.keysym.sym == SDLK_w) {
            m_isMovingUp = event.type == SDL_KEYDOWN;
        } else if (event.key.keysym.sym == SDLK_s) {
            m_isMovingDown = event.type == SDL_KEYDOWN;
        }

        // Tasten für Bewegung nach links/rechts
        if (event.key.keysym.sym == SDLK_a) {
            m_isMovingLeft = event.type == SDL_KEYDOWN;
        } else if (event.key.keysym.sym == SDLK_d) {
            m_isMovingRight = event.type == SDL_KEYDOWN;
        }
    }
    else if(m_name == "Player2") {
        if (event.type == SDL_JOYAXISMOTION) {
            // X-Achsenbewegung
            if (event.jaxis.axis == 0) {
                if (event.jaxis.value < -8000) {
                    // Joystick nach links bewegt
                    m_isMovingLeft = true;
                    m_isMovingRight = false;
                } else if (event.jaxis.value > 8000) {
                    // Joystick nach rechts bewegt
                    m_isMovingRight = true;
                    m_isMovingLeft = false;
                } else {
                    // Joystick in X-Richtung losgelassen
                    m_isMovingLeft = false;
                    m_isMovingRight = false;
                }
            }
                // Y-Achsenbewegung
            else if (event.jaxis.axis == 1) {
                if (event.jaxis.value < -8000) {
                    // Joystick unten oben bewegt
                    m_isMovingUp = true;
                    m_isMovingDown = false;
                } else if (event.jaxis.value > 8000) {
                    // Joystick nach oben bewegt
                    m_isMovingDown = true;
                    m_isMovingUp = false;
                } else {
                    // Joystick in Y-Richtung losgelassen
                    m_isMovingUp = false;
                    m_isMovingDown = false;
                }
            }
        }
    }
}

void Player::move()
{
    // Bewegung basierend auf den aktuellen Bewegungsstatus durchführen
    if (m_isMovingUp) {
        m_position.y -= m_velocity;
    }
    if (m_isMovingDown) {
        m_position.y += m_velocity;
    }
    if (m_isMovingLeft) {
        m_position.x -= m_velocity;
    }
    if (m_isMovingRight) {
        m_position.x += m_velocity;
    }
}

void Player::draw() {
    SDL_RenderCopy(m_renderer, m_sprite, nullptr, &m_position);
}

std::string Player::getName() const {
    return m_name;
}

void Player::setName(const std::string& newName) {
    m_name = newName;
}