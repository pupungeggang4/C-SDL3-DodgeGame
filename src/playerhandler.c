#include "playerhandler.h"
#include "includes.h"

// Handling frames of player.
void handleTickPlayer(Game* game, Player* player) {
    movePlayer(game, player);
}

// Moving player.
void movePlayer(Game* game, Player* player) {
    int pressH = 0, pressV = 0;
    float speed = player->speed;
    if (game->pressLeft == 1 || game->pressRight == 1) {
        pressH = 1;
    }
    if (game->pressUp == 1 || game->pressDown == 1) {
        pressV = 1;
    }
    if (pressH == 1 && pressV == 1) {
        speed = speed * 0.707;
    }
    if (game->pressLeft == 1) {
        player->rect.pos.x -= speed * game->delta;
    }
    if (game->pressRight == 1) {
        player->rect.pos.x += speed * game->delta;
    }
    if (game->pressUp == 1) {
        player->rect.pos.y -= speed * game->delta;
    }
    if (game->pressDown == 1) {
        player->rect.pos.y += speed * game->delta;
    }
}

// Rendering player.
void renderPlayer(Game* game, Player* player) {
    SDL_FRect rect = {player->rect.pos.x - player->rect.size.x / 2.f, player->rect.pos.y - player->rect.size.y / 2.f, player->rect.size.x, player->rect.size.y};
    SDL_RenderFillRect(game->renderer, &rect);
}
