#include <string.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include "bird.h"
#include "pipe.h"

int score = 0;
int end = false;

int main() {
    InitWindow(800, HEIGHT, "Birdie");
    SetTargetFPS(60);

    init_pipes();

    while (!WindowShouldClose()) {
        if (!end) {
            move_pipes();
            move_bird();
        } else {
            if (IsKeyPressed(KEY_ENTER)) {}
        }

        BeginDrawing();
        ClearBackground((Color){135, 206, 250});

        if (!end) {
            draw_pipes();
            draw_bird();
        } else {
            const char* text = "Game Over!";
            int width = MeasureText(text, 40);
            DrawText(text, GetScreenWidth()/2-width/2, 150, 40, RED);

            char score_text[10] = "Score: ";
            char score_str[3];
            sprintf(score_str, "%d", score);
            strcat(score_text, score_str);
            width = MeasureText(score_text, 40);
            DrawText(score_text, GetScreenWidth()/2-width/2, 200, 40, RED);

            text = "Press ENTER to restart";
            width = MeasureText(text, 40);
            DrawText(text, GetScreenWidth()/2-width/2, 500, 40, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
