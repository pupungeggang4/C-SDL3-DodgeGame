#pragma once
#include "shape.h"

typedef struct Bullet {
    Rect2 rect;
    float speed;
    int valid;
} Bullet;
