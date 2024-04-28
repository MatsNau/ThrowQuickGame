//
// Created by Mats on 04.04.2024.
//

#ifndef THROWQUICK_PLAYER_H
#define THROWQUICK_PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>

class Player {
private:
    std::string m_name;
    SDL_Rect m_position; // Position des Spielers auf dem Bildschirm
    SDL_Texture* m_sprite; // Sprite des Spielers
    SDL_Renderer* m_renderer; // Renderer
    float m_velocity; // Geschwindigkeit des Spielers
    bool m_isMovingUp;
    bool m_isMovingDown;
    bool m_isMovingLeft;
    bool m_isMovingRight;

public:
    Player();
    ~Player();

    // Methode um die Position und die Größe des Spieler zu definieren
    void initPlayer(const std::string playerName, SDL_Renderer* renderer, int* posx, int* posy);

    // Methode zur Bewegung des Spielers
    void move();
    void handleInput(SDL_Event& event);

    // Methode zum Zeichnen des Spielers auf dem Bildschirm
    void draw();

    // Methode zur Bereitstellung der Textur
    SDL_Texture* getTexture();

    //Getter für die position
    SDL_Rect* getPosition();

    // Getter und Setter für den Namen des Spielers
    std::string getName() const;
    void setName(const std::string& newName);
};

#endif // PLAYER_H


#endif //THROWQUICK_PLAYER_H
