//
// Created by svjat on 3/13/2024.
//
#ifndef CHAT_PLAYER_H
#define CHAT_PLAYER_H

#include "Game.h"

class Player {
public:
    Player(int x, int y, int speed);
    ~Player();

    void events(SDL_Event& e);
    void update();
    void render(SDL_Renderer* renderer);

private:
    int xPos;
    int yPos;
    int xVel = 0;
    int yVel = 0;
    int speed;

    static const int PLAYER_WIDTH = 32;
    static const int PLAYER_HEIGHT = 32;

};
#endif //CHAT_PLAYER_H
