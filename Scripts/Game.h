//
// Created by svjat on 3/13/2024.
//

#ifndef CHAT_GAME_H
#define CHAT_GAME_H
#include <SDL.h>
#include <iostream>

class Game {
public:
    Game(int width, int height);
    ~Game();

    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Event e;

    bool isRunning() {return running;};
    bool running = true;
};


#endif //CHAT_GAME_H
