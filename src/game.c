#include "raylib.h"
#include "game.h"
#include "grid.h"
#include "snake.h"
#include "collision.h"
#include "food.h"

void GameInit(struct Game *game, int screenWidth, int screenHeight, int gridWidth, int border) {
    game->screenWidth = screenWidth;
    game->screenHeight = screenHeight;
    game->border = border;

    game->grid = NewGrid(game->screenWidth, game->screenHeight, gridWidth);
    game->snakeState = SnakeInit();
    InitWorld(game);
    FoodInit(game);

    game->score = 0;
}

void GameUpdate(struct Game *game, float dt) {
    CollisionTick(game);

    if (game->world.currentSnakeHeadCollision == FOOD) {
        AddSnake(game);
        generateFood(game);
        game->score++;
    }

    UpdateSnake(game, dt);
}

void GameDraw(struct Game *game) {
    ClearBackground(DARKBROWN);
    DrawRectangle(game->border, game->border, 
                  game->screenWidth - 2 * game->border, 
                  game->screenHeight - 2 * game->border, DARKGREEN);
    
    DrawSnake(game);
    DrawFood(game);
    DrawText(TextFormat("Score: %d", game->score), 10, 10, 20, RAYWHITE);
}