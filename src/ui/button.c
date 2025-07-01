#include "raylib.h"
#include "button.h"

void NewButton(struct Button *button, int centerX, int centerY, char *text, int fontSize) {
    button->color = DARKBROWN;
    button->fontSize = fontSize;
    button->textWidth = MeasureText(text, fontSize);
    button->padding = button->textWidth / 5;

    button->bounds.x = centerX - (button->textWidth / 2) - button->padding;
    button->bounds.y = centerY - (fontSize / 2) - button->padding;
    button->bounds.width = button->textWidth + (button->padding * 2);
    button->bounds.height = fontSize + (button->padding * 2);

    button->text = text;

    button->clicked = 0;
}

void UpdateButton(struct Button *button) {
    button->clicked = CheckCollisionPointRec(GetMousePosition(), button->bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void DrawButton(struct Button *button) {
    DrawRectangleRec(button->bounds, button->color);
    DrawText(button->text, button->bounds.x + button->padding, button->bounds.y + button->padding, button->fontSize, DARKGREEN);
}