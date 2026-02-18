#include "gamehandler.h"
#include "fieldhandler.h"

void initGame(Game* game) {
    printf("%d\n", 4 > 5);
    printf("%d\n", 4 < 5);
    srand(time(0));

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return;
    }

    if (!SDL_CreateWindowAndRenderer("SDL3 Bullet Dodge Game", 800, 600, 0, &game->window, &game->renderer)) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return;
    }

    if (!SDL_SetRenderVSync(game->renderer, 1)) {
        SDL_Log("Failed to set vsync: %s", SDL_GetError());
        SDL_Quit();
        return;
    }

    game->running = 1;
    game->gameOver = 0;
    game->frameCurrent = 0.f;
    game->framePrevious = 0.f;
    game->delta = 0.f;

    initField(&game->field);
    runGame(game);
}

void runGame(Game* game) {
    while (game->running == 1) {
        game->frameCurrent = SDL_GetTicks();
        game->delta = (game->frameCurrent - game->framePrevious) / 1000.f;
        game->framePrevious = game->frameCurrent;
        handleInputGame(game);
        updateGame(game);
        renderGame(game);
    }
}

void updateGame(Game* game) {
    if (game->gameOver == 0) {
        handleTickField(game, &game->field);
    }
}

void renderGame(Game* game) {
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);
    renderField(game, &game->field);
    SDL_RenderPresent(game->renderer);
}

void handleInputGame(Game* game) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            game->running = 0;
        }

        if (event.type == SDL_EVENT_KEY_DOWN) {
            if (event.key.key == SDLK_LEFT) {
                game->pressLeft = 1;
            }
            if (event.key.key == SDLK_RIGHT) {
                game->pressRight = 1;
            }
            if (event.key.key == SDLK_UP) {
                game->pressUp = 1;
            }
            if (event.key.key == SDLK_DOWN) {
                game->pressDown = 1;
            }
            if (game->gameOver == 1) {
                if (event.key.key == SDLK_RETURN) {
                    game->gameOver = 0;
                    initField(&game->field);
                }
            }
        }

        if (event.type == SDL_EVENT_KEY_UP) {
            if (event.key.key == SDLK_LEFT) {
                game->pressLeft = 0;
            }
            if (event.key.key == SDLK_RIGHT) {
                game->pressRight = 0;
            }
            if (event.key.key == SDLK_UP) {
                game->pressUp = 0;
            }
            if (event.key.key == SDLK_DOWN) {
                game->pressDown = 0;
            }
        }
    }
}

void quitGame(Game* game) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
