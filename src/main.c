#include "includes.h"
#include "game.h"
#include "gamehandler.h"

// Main function.
int main(int argc, char** argv) {
    Game game = {0};
    initGame(&game);
    quitGame(&game);
    return 0;
}
