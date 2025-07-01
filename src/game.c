#include "raylib.h"
#include "game.h"
#include "grid.h"
#include "snake.h"
#include "collision.h"
#include "food.h"
#include "ui.h"
#include <stdbool.h>

void GameInit(struct Game *game, int screenWidth, int screenHeight, int gridWidth, int border) {
    game->screenWidth = screenWidth;
    game->screenHeight = screenHeight;
    game->border = border;

    game->grid = NewGrid(game->screenWidth, game->screenHeight, gridWidth);
    game->snakeState = SnakeInit();
    InitWorld(game);
    FoodInit(game);
    InitUI(game);

    game->score = 0;
    game->state = MAIN_MENU;
}

void CleanGame(struct Game *game) {
    game->snakeState = SnakeInit();
    InitWorld(game);
    FoodInit(game);

    game->score = 0;
}

void GameUpdate(struct Game *game, float dt) {
    if (game->state == GAME) {
        CollisionTick(game);

        if (game->world.currentSnakeHeadCollision == FOOD) {
            AddSnake(game);
            generateFood(game);
            game->score++;
        }

        if (game->world.currentSnakeHeadCollision == SNAKE_BODY || game->world.currentSnakeHeadCollision == BOX) {
            game->state = GAME_OVER;
        }

        UpdateSnake(game, dt);
    }

    UpdateUI(game);
}

void GameDraw(struct Game *game) {
    ClearBackground(DARKBROWN);
    DrawRectangle(game->border, game->border, 
                  game->screenWidth - 2 * game->border, 
                  game->screenHeight - 2 * game->border, DARKGREEN);

    if (game->state == GAME) {
        DrawSnake(game);
        DrawFood(game);
    }

    DrawUI(game);
}
