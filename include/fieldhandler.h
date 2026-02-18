#pragma once
#include "field.h"

// Field function declaration.
void initField(Field*);
void handleTickField(Game*, Field*);
void renderField(Game*, Field*);
void spawnBullet(Field*);

