#include "shape.h"
#include "bullethandler.h"
#include "playerhandler.h"
#include "fieldhandler.h"
#include "includes.h"

void initField(Field* field) {
    field->spawnInterval = 0.8f;
    field->spawnTimeLeft = 0.8f;

    for (int i = 0; i < 50; i++) {
        field->bullets[i].rect = (Rect2){{0.f, 0.f}, {40.f, 40.f}};
        field->bullets[i].direction = (Vec2){1.f, 0.f};
        field->bullets[i].speed = 200.f;
        field->bullets[i].valid = 0;
    }

    field->player.rect = (Rect2){{400.f, 300.f}, {80.f, 80.f}};
    field->player.speed = 320.f;
}

void handleTickField(Game* game, Field* field) {
    handleTickPlayer(game, &field->player);
    for (int i = 0; i < 50; i++) {
        if (field->bullets[i].valid == 1) {
            handleTickBullet(game, &field->bullets[i]);
        }
    }
    field->spawnTimeLeft -= game->delta;
    if (field->spawnTimeLeft < 0) {
        field->spawnTimeLeft = field->spawnInterval;
        spawnBullet(field);
    }
}

void spawnBullet(Field* field) {
    for (int i = 0; i < 50; i++) {
        Bullet* bullet = &field->bullets[i];
        if (bullet->valid == 0) {
            int pos = rand() % 4;
            if (pos == 0 || pos == 2) {
                bullet->rect.pos.y = 20.f + rand() % 560;
                bullet->direction.y = 0.f;
                if (pos == 0) {
                    bullet->rect.pos.x = -20.f;
                    bullet->direction.x = 1.f;
                } else {
                    bullet->rect.pos.x = 820.f;
                    bullet->direction.x = -1.f;
                }
            } else {
                bullet->rect.pos.x = 20.f + rand() % 760;
                bullet->direction.x = 0.f;
                if (pos == 1) {
                    bullet->rect.pos.y = -20.f;
                    bullet->direction.y = 1.f;
                } else {
                    bullet->rect.pos.y = 620.f;
                    bullet->direction.y = -1.f;
                }
            }
            bullet->valid = 1;
            break;
        }
    }
}

void renderField(Game* game, Field* field) {
    SDL_SetRenderDrawColor(game->renderer, 0, 255, 255, 255);
    renderPlayer(game, &field->player);
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    for (int i = 0; i < 50; i++) {
        if (field->bullets[i].valid == 1) {
            renderBullet(game, &field->bullets[i]);
        }
    }
}
