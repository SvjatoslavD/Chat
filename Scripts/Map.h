//
// Created by svjat on 3/14/2024.
//

#ifndef CHAT_MAP_H
#define CHAT_MAP_H
#include <vector>
#include "Game.h"

class Map {
public:
    Map(int tileWidth, int tileHeight, int mapWidth, int mapHeight, SDL_Renderer* renderer);

    void render(SDL_Renderer* renderer);

private:
    std::vector<std::vector<int>> tiles;
    int tileWidth;
    int tileHeight;

    SDL_Texture* grass;
};

#endif //CHAT_MAP_H
