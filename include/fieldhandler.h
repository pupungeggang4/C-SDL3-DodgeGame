#pragma once
#include "field.h"

void initField(Field*);
void handleTickField(Game*, Field*);
void renderField(Game*, Field*);
void spawnBullet(Field*);

