//
// Created by svjat on 3/13/2024.
//
#include "Player.h"

Player::Player(int x, int y, int z)
{
    xPos = x; yPos = y; speed = z;
}

Player::~Player() {}

void Player::events(SDL_Event& e)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
            case SDLK_UP: yVel -= speed; break;
            case SDLK_DOWN: yVel += speed; break;
            case SDLK_LEFT: xVel -= speed; break;
            case SDLK_RIGHT: xVel += speed; break;
        }
    }
        // If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
            case SDLK_UP: yVel += speed; break;
            case SDLK_DOWN: yVel -= speed; break;
            case SDLK_LEFT: xVel += speed; break;
            case SDLK_RIGHT: xVel -= speed; break;
        }
    }
}

void Player::update()
{
    // Move the player left or right
    xPos += xVel;

    // Move the player up or down
    yPos += yVel;

}

void Player::render(SDL_Renderer* renderer)
{
    // Render the player
    SDL_Rect playerRect = { xPos, yPos, PLAYER_WIDTH, PLAYER_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x9C, 0xFF);
    SDL_RenderFillRect(renderer, &playerRect);
}



