//
// Created by svjat on 3/14/2024.
//
#include "Map.h"

Map::Map(int tWidth, int tHeight, int mWidth, int mHeight, SDL_Renderer* renderer) {
    tileWidth = tWidth;
    tileHeight = tHeight;
    tiles = {static_cast<size_t>(mHeight), std::vector<int>(static_cast<size_t>(mWidth), 0)};
    tiles.back().assign(tiles.back().size(), 1);

    grass = SDL_CreateTextureFromSurface(renderer, IMG_Load("Assets/Images/Grass.png"));
}

void Map::render(SDL_Renderer* renderer) {
    for (int y = 0; y < tiles.size(); ++y) {
        for (int x = 0; x < tiles[y].size(); ++x) {
            SDL_Rect destRect = { static_cast<int>(x * tileWidth), static_cast<int>(y * tileHeight), tileWidth, tileHeight };
            switch (tiles[y][x]) {
                case 0: // Empty tile
                    SDL_SetRenderDrawColor(renderer, 30, 59, 130, 0xFF);
                    SDL_RenderFillRect(renderer, &destRect);

                    break;
                case 1: // Wall tile
                    SDL_RenderCopy(renderer, grass, NULL, &destRect);
                    break;
                    // Add more cases for different tile types
            }
        }
    }
}
