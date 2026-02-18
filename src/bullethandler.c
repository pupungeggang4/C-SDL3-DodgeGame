#include "physics.h"
#include "bullethandler.h"

// Handling frames of bullet.
void handleTickBullet(Game* game, Bullet* bullet) {
    moveBullet(game, bullet);

    if (bullet->rect.pos.x > 840 || bullet->rect.pos.x < -40 || bullet->rect.pos.y > 640 || bullet->rect.pos.y < -40) {
        bullet->valid = 0;
    }

    collideCheckBullet(game, bullet, &game->field.player);
}

// Moving bullet.
void moveBullet(Game* game, Bullet* bullet) {
    bullet->rect.pos.x += bullet->direction.x * bullet->speed * game->delta;
    bullet->rect.pos.y += bullet->direction.y * bullet->speed * game->delta;
}

// Player collision check and game over check.
void collideCheckBullet(Game* game, Bullet* bullet, Player* player) {
    if (collideCheckRect(&bullet->rect, &player->rect) == 1) {
        game->gameOver = 1;
    }
}

// Rendering bullet.
void renderBullet(Game* game, Bullet* bullet) {
    SDL_FRect rect = {bullet->rect.pos.x - bullet->rect.size.x / 2.f, bullet->rect.pos.y - bullet->rect.size.y / 2.f, bullet->rect.size.x, bullet->rect.size.y};
    SDL_RenderFillRect(game->renderer, &rect);
}
