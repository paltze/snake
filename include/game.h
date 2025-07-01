#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "snake.h"
#include "collision.h"
#include "food.h"
#include "ui.h"

enum State {
    GAME,
    MAIN_MENU,
    PAUSE,
    GAME_OVER
};

struct Game {
    struct Grid grid;
    struct SnakeState snakeState;
    struct World world;
    struct Food food;
    struct UI ui;
    enum State state;
    int score;
    int border;
    int screenWidth;
    int screenHeight;
};

void GameInit(struct Game *game, int screenWidth, int screenHeight, int gridWidth, int border);
void CleanGame(struct Game *game);
void GameUpdate(struct Game *game, float dt);
void GameDraw(struct Game *game);

#endif