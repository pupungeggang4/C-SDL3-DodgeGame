#pragma once
#include "includes.h"
#include "field.h"

typedef struct Game {
    SDL_Window* window;
    SDL_Renderer* renderer;
    Field field;
    float frameCurrent, framePrevious, delta;
    int gameOver;
    int running;
    int pressLeft, pressRight, pressUp, pressDown;
} Game;
