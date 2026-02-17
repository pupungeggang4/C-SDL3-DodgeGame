#include "includes.h"
#include "shape.h"

int main(int argc, char** argv) {
    Rect2 rect = {{10.f, 10.f}, {20.f, 20.f}};
    printf("%.1f", rect.pos.x);

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    bool quit = false;
    SDL_Event event;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer("SDL3 Hello World", 800, 600, 0, &window, &renderer)) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
