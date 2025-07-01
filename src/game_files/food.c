#include "food.h"
#include "raylib.h"
#include "game.h"
#include "collision.h"
#include "grid.h"

void generateFood(struct Game *game) {
    struct Point point;

    do {
        point.x = GetRandomValue(1, game->grid.width - 2);
        point.y = GetRandomValue(1, game->grid.height - 2);
    } while (LiesOnSnake(game, &point));

    game->food.point = point;
}

void FoodInit(struct Game *game) {
    generateFood(game);
}

void DrawFood(struct Game *game) {
    struct Point point = getReal(&(game->grid), &(game->food.point));
    DrawRectangle(point.x, point.y, game->grid.gridWidth, game->grid.gridWidth, ORANGE);
}

