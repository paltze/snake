#include "button.h"
#include "raylib.h"
#include "ui.h"
#include "game.h"

/* Game Start */

void initGameUI(struct Game *game) {
    
}

void updateGameUI(struct Game *game) {
    if (IsKeyPressed(KEY_SPACE)) {
        game->state = PAUSE;
    }
}

void drawGameUI(struct Game *game) {
    DrawText(TextFormat("Score: %d", game->score), game->grid.gridWidth * 2, 0, game->grid.gridWidth, DARKGREEN);
}

/* Game End */

/* Main Menu Start */

void initMainMenu(struct Game *game) {
    NewButton(&game->ui.mainMenu.playButton, game->screenWidth / 2, game->screenHeight * 8 / 10, "PLAY", 20);
}

void updateMainMenu(struct Game *game) {
    UpdateButton(&game->ui.mainMenu.playButton);

    if(game->ui.mainMenu.playButton.clicked) {
        game->state = GAME;
    }
}

void drawMainMenu(struct Game *game) {
    char text[6] = "SNAKE";
    int fontSize = 50;

    int textWidth = MeasureText(text, fontSize);

    DrawText(text, (game->screenWidth / 2) - (textWidth / 2), (game->screenHeight / 2) - (fontSize / 2), fontSize, DARKBROWN);
    DrawButton(&game->ui.mainMenu.playButton);
}

/* Main Menu End */

/* Pause Start */

void initPause(struct Game *game) {
    NewButton(&game->ui.pause.resumeButton, game->screenWidth / 2, game->screenHeight * 8 / 10, "RESUME", 20);
}

void updatePause(struct Game *game) {
    UpdateButton(&game->ui.pause.resumeButton);

    if(game->ui.pause.resumeButton.clicked || IsKeyPressed(KEY_SPACE)) {
        game->state = GAME;
    }
}

void drawPause(struct Game *game) {
    char text[10] = "PAUSED";
    int fontSize = 50;

    int textWidth = MeasureText(text, fontSize);

    DrawText(text, (game->screenWidth / 2) - (textWidth / 2), (game->screenHeight / 2) - (fontSize / 2), fontSize, DARKBROWN);
    DrawButton(&game->ui.pause.resumeButton);

    DrawText(TextFormat("Score: %d", game->score), game->grid.gridWidth * 2, 0, game->grid.gridWidth, DARKGREEN);
}

/* Pause End */

/* Game Over Start */

void initGameOver(struct Game *game) {
    NewButton(&game->ui.gameOver.replayButton, game->screenWidth / 2, game->screenHeight * 8 / 10, "REPLAY", 20);
}

void updateGameOver(struct Game *game) {
    UpdateButton(&game->ui.gameOver.replayButton);

    if(game->ui.gameOver.replayButton.clicked) {
        CleanGame(game);
        game->state = GAME;
    }
}

void drawGameOver(struct Game *game) {
    char text[10] = "GAME OVER";
    int fontSize = 50;

    int textWidth = MeasureText(text, fontSize);

    DrawText(text, (game->screenWidth / 2) - (textWidth / 2), (game->screenHeight / 2) - (fontSize / 2), fontSize, DARKBROWN);
    DrawButton(&game->ui.gameOver.replayButton);

    DrawText(TextFormat("Score: %d", game->score), game->grid.gridWidth * 2, 0, game->grid.gridWidth, DARKGREEN);
}

/* Game Over End */

void InitUI(struct Game *game) {
    initGameUI(game);
    initMainMenu(game);
    initPause(game);
    initGameOver(game);
}

void UpdateUI(struct Game *game) {
    switch (game->state) {
        case GAME:
            updateGameUI(game);
            break;
        case MAIN_MENU:
            updateMainMenu(game);
            break;
        case PAUSE:
            updatePause(game);
            break;
        case GAME_OVER:
            updateGameOver(game);
            break;
    }
}

void DrawUI(struct Game *game) {
    switch (game->state) {
        case GAME:
            drawGameUI(game);
            break;
        case MAIN_MENU:
            drawMainMenu(game);
            break;
        case PAUSE:
            drawPause(game);
            break;
        case GAME_OVER:
            drawGameOver(game);
            break;
    }
}
