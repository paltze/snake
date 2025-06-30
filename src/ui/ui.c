#include "button.h"
#include "raylib.h"
#include "ui.h"
#include "game.h"

void InitUI(struct Game *game) {
    /* Main Menu Start */
    NewButton(&game->ui.mainMenu.play, game->screenWidth / 2, game->screenHeight * 8 / 10, "PLAY", 20);
    /* Main Menu End */
}

/* Main Menu Start */

void UpdateMainMenu(struct Game *game) {
    UpdateButton(&game->ui.mainMenu.play);

    if(game->ui.mainMenu.play.clicked) {
        game->state = GAME;
    }
}

void DrawMainMenu(struct Game *game) {
    char text[6] = "SNAKE";
    int fontSize = 50;

    int textWidth = MeasureText(text, fontSize);

    DrawText(text, (game->screenWidth / 2) - (textWidth / 2), (game->screenHeight / 2) - (fontSize / 2), fontSize, BLACK);
    DrawButton(&game->ui.mainMenu.play);
}

/* Main Menu End */

/* Pause Start */

void UpdatePause(struct Game *game) {

}

void DrawPause(struct Game *game) {

}

/* Pause End */

/* Game Over Start */

void UpdateGameOver(struct Game *game) {

}

void DrawGameOver(struct Game *game) {

}

/* Game Over End */
