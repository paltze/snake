#ifndef COLLISION_H
#define COLLISION_H

#include "grid.h"

struct Game;

enum Entity {
    NULL_ENITITY,
    SNAKE_HEAD,
    SNAKE_BODY,
    FOOD,
    BOX
};

struct Body {
    struct Point *point;
    enum Entity entity;
};

struct World {
    struct Body bodies[256];
    struct Point border[128];
    int borderSize;
    int worldSize;
    enum Entity currentSnakeHeadCollision;
};

void InitWorld(struct Game *game);
void AddToWorld(struct Game *game, struct Body body);
void CollisionTick(struct Game *game);
int LiesOnSnake(struct Game *game, struct Point *point);

#endif