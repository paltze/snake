#include "collision.h"
#include "game.h"

void InitWorld(struct Game *game) {
    struct World *world = &(game->world);

    world->bodies[0].point = &(game->snakeState.snake.elem[0].point);
    world->bodies[0].entity = SNAKE_HEAD;
    world->worldSize = 1;

    for (int i = 1; i < game->snakeState.snake.length; i++) {
        world->bodies[world->worldSize].point = &(game->snakeState.snake.elem[i].point);
        world->bodies[world->worldSize].entity = SNAKE_BODY;
        world->worldSize++;
    }

    world->bodies[world->worldSize].point = &(game->food.point);
    world->bodies[world->worldSize].entity = FOOD;
    world->worldSize++;

    world->borderSize = 0;

    for (int i = 1; i < game->grid.width - 1; i++) {
        world->border[world->borderSize].x = i;
        world->border[world->borderSize].y = 0;
        world->bodies[world->worldSize].point = &(world->border[world->borderSize]);
        world->bodies[world->worldSize].entity = BOX;

        world->borderSize++;
        world->worldSize++;

        world->border[world->borderSize].x = i;
        world->border[world->borderSize].y = game->grid.height - 1;
        world->bodies[world->worldSize].point = &(world->border[world->borderSize]);
        world->bodies[world->worldSize].entity = BOX;

        world->borderSize++;
        world->worldSize++;
    }

    for (int i = 1; i < game->grid.height - 1; i++) {
        world->border[world->borderSize].x = 0;
        world->border[world->borderSize].y = i;
        world->bodies[world->worldSize].point = &(world->border[world->borderSize]);
        world->bodies[world->worldSize].entity = BOX;

        world->borderSize++;
        world->worldSize++;

        world->border[world->borderSize].x = game->grid.width - 1;
        world->border[world->borderSize].y = i;
        world->bodies[world->worldSize].point = &(world->border[world->borderSize]);
        world->bodies[world->worldSize].entity = BOX;

        world->borderSize++;
        world->worldSize++;
    }
}

void AddToWorld(struct Game *game, struct Body body) {
    game->world.bodies[game->world.worldSize] = body;
    game->world.worldSize++;
}

void CollisionTick(struct Game *game) {
    for (int i = 1; i < game->world.worldSize; i++) { // i = 0 is SNAKE_HEAD
        if (game->world.bodies[i].point->x == game->world.bodies[0].point->x && game->world.bodies[i].point->y == game->world.bodies[0].point->y) {
            game->world.currentSnakeHeadCollision = game->world.bodies[i].entity;
            return;
        }
    }

    game->world.currentSnakeHeadCollision = NULL_ENITITY;
}

int LiesOnSnake(struct Game *game, struct Point *point) {
    struct World *world = &(game->world);

    for (int i = 0; i < world->worldSize; i++) {
        if (world->bodies[i].entity == SNAKE_HEAD || world->bodies[i].entity == SNAKE_BODY) {
            if (world->bodies[i].point->x == point->x && world->bodies[i].point->y == point->y) {
                return 1;
            }
        }
    }

    return 0;
}
