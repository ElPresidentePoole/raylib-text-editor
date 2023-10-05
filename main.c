#include <stdio.h>
#include "raylib/include/raylib.h"

struct Cursor {
  int col;
  int row;
};

int main() {
  InitWindow(640, 480, "Window");
  SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);

  struct Cursor cursor = {0, 0};

  while(!WindowShouldClose()) {
    if(IsKeyPressed(KEY_J)) {
      cursor.row++;
    }
    if(IsKeyPressed(KEY_K)) {
      cursor.row--;
    }
    if(IsKeyPressed(KEY_H)) {
      cursor.col--;
    }
    if(IsKeyPressed(KEY_L)) {
      cursor.col++;
    }

    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(cursor.col * 20, cursor.row * 20, 10, 20, GREEN);
    for(int row = 0; row < 100; row++) {
      DrawText(TextFormat("%d BEEP BOOP", row), 0, 20*row, 20, GREEN);
    }
    DrawFPS(0, 0);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
