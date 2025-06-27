#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "snake.h"
#include "collision.h"
#include "food.h"

struct Game {
    struct Grid grid;
    struct SnakeState snakeState;
    struct World world;
    struct Food food;
    int score;
    int border;
    int screenWidth;
    int screenHeight;
};

void GameInit(struct Game *game, int screenWidth, int screenHeight, int gridWidth, int border);
void GameUpdate(struct Game *game, float dt);
void GameDraw(struct Game *game);

#endif