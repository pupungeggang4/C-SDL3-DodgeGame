#pragma once
#include "includes.h"
#include "field.h"

typedef struct Game {
    SDL_Window* window;
    SDL_Renderer* renderer;
    Field field;
} Game;
