#pragma once
#include "bullet.h"
#include "player.h"
#include "game.h"

// Declaring bullet functions.
void handleTickBullet(Game*, Bullet*);
void moveBullet(Game*, Bullet*);
void collideCheckBullet(Game*, Bullet*, Player*);
void renderBullet(Game*, Bullet*);
