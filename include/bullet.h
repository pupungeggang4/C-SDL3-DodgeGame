#pragma once
#include "shape.h"

typedef struct Bullet {
    Rect2 rect;
    Vec2 direction;
    float speed;
    int valid;
} Bullet;
