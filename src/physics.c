#include "shape.h"

// Checking whether two rect overlap.
int collideCheckRect(Rect2* r1, Rect2* r2) {
    return r2->pos.x - r2->size.x / 2.f < r1->pos.x && r1->pos.x < r2->pos.x + r2->size.x / 2.f && r2->pos.y - r2->size.y / 2.f < r1->pos.y && r1->pos.y < r2->pos.y + r2->size.y / 2.f;
}
