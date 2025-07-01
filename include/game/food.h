#ifndef FOOD_H
#define FOOD_H

#include "grid.h"

struct Game;

struct Food {
    struct Point point;
};

void generateFood(struct Game *game);
void FoodInit(struct Game *game);
void DrawFood(struct Game *game);

#endif