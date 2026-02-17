#include "bullethandler.h"

void handleTickBullet(Game* game, Bullet* bullet) {
    moveBullet(game, bullet);

    if (bullet->rect.pos.x > 840 && bullet->rect.pos.x < -40 && bullet->rect.pos.y > 640 && bullet->rect.pos.y < -40) {
        bullet->valid = 0;
    }
}

void moveBullet(Game* game, Bullet* bullet) {
    bullet->rect.pos.x += bullet->direction.x * bullet->speed * game->delta;
    bullet->rect.pos.y += bullet->direction.y * bullet->speed * game->delta;
}

void collideCheckBullet(Game* game, Bullet* bullet, Player* player) {

}

void renderBullet(Game* game, Bullet* bullet) {

}
