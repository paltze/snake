#ifndef UI_H
#define UI_H

#include "button.h"

struct Game;

struct MainMenu {
    struct Button playButton;
};

struct Pause {
    struct Button resumeButton;
};

struct GameOver {
    struct Button replayButton;
};

struct UI {
    struct MainMenu mainMenu;
    struct Pause pause;
    struct GameOver gameOver;
};

void InitUI(struct Game *game);
void UpdateUI(struct Game *game);
void DrawUI(struct Game *game);

#endif