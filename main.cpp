#define SDL_MAIN_HANDLED // insert this
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>

#include "RenderWindow.h"
#include "Player.h"
#include "Game.h"

int main() {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->init("QuickThrow", WINDOW_WIDTH, WINDOW_HEIGHT, false);
    game->initPlayers();
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        //game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

   /* if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
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
    //Player player2("Player2", window.GetRenderer());

    // GameLoop
    bool isRunning = true;
    Uint32 prevTime = SDL_GetTicks();
    while (isRunning) {
        // Aktuelle Zeit erfassen und Delta-Zeit berechnen
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - prevTime) / 1000.0f; // in Sekunden umwandeln
        // Ereignisse verarbeiten
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            player.handleInput(event);
            //player2.handleInput(event);
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        // Inhalte zeichnen
        window.Clear();
        //Draw the player
        player.draw();
        //player2.draw();

        //Move player
        player.move(deltaTime);
        //player2.move(deltaTime);

        window.Present();
    }*/

    return 0;
}