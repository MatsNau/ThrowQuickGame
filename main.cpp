#define SDL_MAIN_HANDLED // insert this
#include <iostream>
#include <SDL2/SDL.h>

#include "RenderWindow.h"
#include "Player.h"

int main() {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
        std::cerr << "Fehler beim Initialisieren von SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Überprüfe, wie viele Controller angeschlossen sind
    int numControllers = SDL_NumJoysticks();
    if (numControllers < 1) {
        std::cout << "Keine Controller gefunden." << std::endl;
    } else {
        std::cout << "Gefundene Controller:" << std::endl;
        for (int i = 0; i < numControllers; ++i) {
            if (SDL_IsGameController(i)) {
                std::cout << "Controller " << i << ": " << SDL_GameControllerNameForIndex(i) << std::endl;
            } else {
                std::cout << "Joystick " << i << ": " << SDL_JoystickNameForIndex(i) << std::endl;
            }
        }
    }
    SDL_Joystick* joystick = SDL_JoystickOpen(0);

    // Erstelle ein RenderWindow-Objekt
    RenderWindow window("Catch Throw", WINDOW_WIDTH, WINDOW_HEIGHT);
    //Erstelle einen Player
    Player player("Player1", window.GetRenderer());
    Player player2("Player2", window.GetRenderer());

    // Hauptschleife: Warte auf Benutzerinteraktion
    bool isRunning = true;
    while (isRunning) {
        // Ereignisse verarbeiten
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            player.handleInput(event);
            player2.handleInput(event);
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        // Inhalte zeichnen
        window.Clear();
       //Draw the player
       player.draw();
       player2.draw();
       //Move player
       player.move();
       player2.move();
        window.Present();
    }

    return 0;
}