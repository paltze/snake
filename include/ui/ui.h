#ifndef UI_H
#define UI_H

#include "button.h"

struct Game;

struct MainMenu {
    struct Button play;
};

struct UI {
    struct MainMenu mainMenu;
};

void InitUI(struct Game *game);

void UpdateMainMenu(struct Game *game);
void DrawMainMenu(struct Game *game);


void UpdatePause(struct Game *game);
void DrawPause(struct Game *game);

void UpdateGameOver(struct Game *game);
void DrawGameOver(struct Game *game);

#endif