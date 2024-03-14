#define SCREEN_WIDTH (32*30)
#define SCREEN_HEIGHT (32*22)

#include "Scripts/Game.h"
#include "Scripts/Player.h"
#include "Scripts/Map.h"

int main(int argc, char* args []) {
    Game game(SCREEN_WIDTH,SCREEN_HEIGHT);
    // Create a player
    Player player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 5);
    //Creates map object
    Map map(32, 32, 30, 22, game.renderer);

    Uint32 currentTime = SDL_GetTicks();
    //Denominator is the fps, numerator is to convert fps to be measured in miliseconds
    double fpsTime = 1000/60;

    // While application is running
    while (game.isRunning()) {
        //Makes the game run at deltatime
        Uint32 newTime = SDL_GetTicks();
        double frameTime = newTime - currentTime;
        currentTime = newTime;

        if (frameTime < fpsTime) {
            SDL_Delay(fpsTime - frameTime);
        }

        // Handle Events
        while (SDL_PollEvent(&game.e) != 0) {
            // User requests quit
            if (game.e.type == SDL_QUIT) {
                game.running = false;
            }
            // Handle player input
            player.events(game.e);
        }
        // Updates
        player.update();

        // Render items
        SDL_SetRenderDrawColor(game.renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(game.renderer);
        // Items to render
        map.render(game.renderer);
        player.render(game.renderer);
        SDL_RenderPresent(game.renderer);
    }

    return 0;
}