#include "raylib.h"
#include "game.h"

#define WIDTH 800
#define HEIGHT 460
#define TITLE "Snake"

struct Game game;

int main() {
    SetTargetFPS(60);
    InitWindow(WIDTH, HEIGHT, TITLE);

    GameInit(&game, WIDTH, HEIGHT, 20, 20);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
            GameUpdate(&game, dt);
            GameDraw(&game);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}