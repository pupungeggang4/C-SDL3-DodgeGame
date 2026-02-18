#pragma once
#include "bullet.h"
#include "player.h"

typedef struct Field {
    Bullet bullets[50];
    Player player;
    float spawnInterval;
    float spawnTimeLeft;
} Field;
