#ifndef SNAKE_H
#define SNAKE_H

#include "grid.h"

struct Game;

enum Dir {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Vector {
    struct Point point;
    enum Dir dir;
};

struct VectorArray {
    struct Vector elem[64];
    int length;
};

struct SnakeState {
    struct VectorArray snake;
    struct VectorArray keys;
};

struct SnakeState SnakeInit();
void AddSnake(struct Game *game);
void UpdateSnake(struct Game *game, float dt);
void DrawSnake(struct Game *game);

#endif
