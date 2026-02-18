#pragma once
#include "shape.h"

// Bullet type definition.
typedef struct Bullet {
    Rect2 rect;
    Vec2 direction;
    float speed;
    int valid;
} Bullet;
