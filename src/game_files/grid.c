#include "grid.h"

struct Grid NewGrid(int screenWidth, int screenHeight, int gridWidth) {
    struct Grid grid;

    grid.width = screenWidth/gridWidth;
    grid.height = screenHeight/gridWidth;
    grid.gridWidth = gridWidth;

    return grid;
}

struct Point getReal(struct Grid *grid, struct Point *box) {
    struct Point point;
    
    point.x = box->x * grid->gridWidth;
    point.y = box->y * grid->gridWidth;

    return point;
}

struct Point moveLeft(struct Point box) {
    box.x--;
    return box;
}

struct Point moveRight(struct Point box) {
    box.x++;
    return box;
}

struct Point moveUp(struct Point box) {
    box.y--;
    return box;
}

struct Point moveDown(struct Point box) {
    box.y++;
    return box;
}
