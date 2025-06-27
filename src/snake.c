#include "snake.h"
#include "raylib.h"
#include "grid.h"
#include "game.h"
#include "collision.h"

struct SnakeState SnakeInit() {
    struct SnakeState snakeState;

    snakeState.snake.length = 3;

    snakeState.snake.elem[0].point.x = 3;
    snakeState.snake.elem[0].point.y = 1;
    snakeState.snake.elem[0].dir = RIGHT;

    snakeState.snake.elem[1].point.x = 2;
    snakeState.snake.elem[1].point.y = 1;
    snakeState.snake.elem[1].dir = RIGHT;

    snakeState.snake.elem[2].point.x = 1;
    snakeState.snake.elem[2].point.y = 1;
    snakeState.snake.elem[2].dir = RIGHT;

    snakeState.keys.length = 0;

    return snakeState;
}

void AddSnake(struct Game *game) {
    struct Body body;
    struct VectorArray *snake = &(game->snakeState.snake);
    struct Point point = snake->elem[snake->length - 1].point;

    if (snake->elem[snake->length - 1].dir == UP) {
        snake->elem[snake->length].point = moveDown(point);
        snake->elem[snake->length].dir = UP;
    }
    else if (snake->elem[snake->length - 1].dir == DOWN) {
        snake->elem[snake->length].point = moveUp(point);
        snake->elem[snake->length].dir = DOWN;
    }
    else if (snake->elem[snake->length - 1].dir == LEFT) {
        snake->elem[snake->length].point = moveRight(point);
        snake->elem[snake->length].dir = LEFT;
    }
    else if (snake->elem[snake->length - 1].dir == RIGHT) {
        snake->elem[snake->length].point = moveLeft(point);
        snake->elem[snake->length].dir = RIGHT;
    }

    body.point = &(snake->elem[snake->length].point);
    body.entity = SNAKE_BODY;

    AddToWorld(game, body);

    snake->length++;
}

void moveSnake(struct Game *game) {
    for (int i = 0; i < game->snakeState.snake.length; i++) {

        for (int j = 0; j < game->snakeState.keys.length; j++) {
            if (game->snakeState.keys.elem[j].point.x == game->snakeState.snake.elem[i].point.x && game->snakeState.keys.elem[j].point.y == game->snakeState.snake.elem[i].point.y) {
                game->snakeState.snake.elem[i] = game->snakeState.keys.elem[j];
                
                if (i == game->snakeState.snake.length - 1) {
                    for (int k = 1; k < game->snakeState.keys.length; k++) {
                        game->snakeState.keys.elem[k - 1] = game->snakeState.keys.elem[k];
                    }

                    game->snakeState.keys.length--;
                }
            }
        }

        if (game->snakeState.snake.elem[i].dir == UP) {
            game->snakeState.snake.elem[i].point = moveUp(game->snakeState.snake.elem[i].point);
        }

        if (game->snakeState.snake.elem[i].dir == DOWN) {
            game->snakeState.snake.elem[i].point = moveDown(game->snakeState.snake.elem[i].point);
        }

        if (game->snakeState.snake.elem[i].dir == LEFT) {
            game->snakeState.snake.elem[i].point = moveLeft(game->snakeState.snake.elem[i].point);
        }

        if (game->snakeState.snake.elem[i].dir == RIGHT) {
            game->snakeState.snake.elem[i].point = moveRight(game->snakeState.snake.elem[i].point);
        }

    }
}

int isVertical(struct Game *game) {
    enum Dir dir = game->snakeState.snake.elem[0].dir;

    if (dir == UP || dir == DOWN) {
        return 1;
    }
    else {
        return 0;
    }
}

float moveDelay = 0.2;
float moveTimer = 0;

void UpdateSnake(struct Game *game, float dt) {
    if (!isVertical(game) && IsKeyPressed(KEY_UP)) {
        game->snakeState.keys.elem[game->snakeState.keys.length].dir = UP;
        game->snakeState.keys.elem[game->snakeState.keys.length].point = game->snakeState.snake.elem[0].point;
        game->snakeState.keys.length++;
    }

    if (!isVertical(game) && IsKeyPressed(KEY_DOWN)) {
        game->snakeState.keys.elem[game->snakeState.keys.length].dir = DOWN;
        game->snakeState.keys.elem[game->snakeState.keys.length].point = game->snakeState.snake.elem[0].point;
        game->snakeState.keys.length++;
    }

    if (isVertical(game) && IsKeyPressed(KEY_LEFT)) {
        game->snakeState.keys.elem[game->snakeState.keys.length].dir = LEFT;
        game->snakeState.keys.elem[game->snakeState.keys.length].point = game->snakeState.snake.elem[0].point;
        game->snakeState.keys.length++;
    }

    if (isVertical(game) && IsKeyPressed(KEY_RIGHT)) {
        game->snakeState.keys.elem[game->snakeState.keys.length].dir = RIGHT;
        game->snakeState.keys.elem[game->snakeState.keys.length].point = game->snakeState.snake.elem[0].point;
        game->snakeState.keys.length++;
    }

    moveTimer += dt;

    if (moveTimer > moveDelay) {
        moveSnake(game);
        moveTimer = 0;
    }
}

void DrawSnake(struct Game *game) {
    struct Point realPoint;

    realPoint = getReal(&(game->grid), &(game->snakeState.snake.elem[0].point));
    DrawRectangle(realPoint.x, realPoint.y, game->grid.gridWidth, game->grid.gridWidth, RED);

    for (int i = 1; i < game->snakeState.snake.length; i++) {
        realPoint = getReal(&(game->grid), &(game->snakeState.snake.elem[i].point));
        DrawRectangle(realPoint.x, realPoint.y, game->grid.gridWidth, game->grid.gridWidth, DARKBLUE);
    }
}
