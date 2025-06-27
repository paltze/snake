#ifndef GRID_H
#define GRID_H

struct Grid {
    int width;
    int height;
    int gridWidth;
    int offsetX;
    int offsetY;
};

struct Point {
    int x;
    int y;
};

struct Grid NewGrid(int screenWidth, int screenHeight, int gridWidth);
struct Point getReal(struct Grid *grid, struct Point *box);

struct Point moveLeft(struct Point box);
struct Point moveRight(struct Point box);
struct Point moveUp(struct Point box);
struct Point moveDown(struct Point box);

#endif
