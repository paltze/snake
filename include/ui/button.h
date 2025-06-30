#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

struct Button {
    Rectangle bounds;
    char *text;

    Color color;
    int fontSize;
    int textWidth;
    int padding;

    int clicked;
};

void NewButton(struct Button *button, int centerX, int centerY, char *text, int fontSize);
void UpdateButton(struct Button *button);
void DrawButton(struct Button *button);

#endif