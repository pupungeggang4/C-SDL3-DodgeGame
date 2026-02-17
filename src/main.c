#include "includes.h"
#include "game.h"
#include "gamehandler.h"

int main(int argc, char** argv) {
    Game game;
    game.delta = 0.02;
    initGame(&game);
    quitGame(&game);
    return 0;
}
