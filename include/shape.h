#pragma once

// Vec2 and Rect2 type definition.
typedef struct Vec2 {
    float x;
    float y;
} Vec2;

typedef struct Rect2 {
    Vec2 pos;
    Vec2 size;
} Rect2;
