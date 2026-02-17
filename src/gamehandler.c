#include "gamehandler.h"

void initGame(Game* game) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return;
    }

    if (!SDL_CreateWindowAndRenderer("SDL3 Hello World", 800, 600, 0, &game->window, &game->renderer)) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return;
    }
    game->running = 1;
    runGame(game);
}

void runGame(Game* game) {
    while (game->running == 1) {
        handleInputGame(game);
        updateGame(game);
        renderGame(game);
    }
}

void updateGame(Game* game) {

}

void renderGame(Game* game) {
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);
    SDL_RenderPresent(game->renderer);
}

void handleInputGame(Game* game) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            game->running = 0;
        }
    }
}

void quitGame(Game* game) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
