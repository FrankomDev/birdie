#include <raylib.h>
#include <stdbool.h>
#include "bird.h"
#include "pipe.h"
#include "state.h"

Bird bird = {
    .position = {10, 200},
    .hit = false
};

void draw_bird() {
    DrawCircle(bird.position.x, bird.position.y, 28, RED);
}

bool check_collision_with_pipes() {
    for (int i=0; i<PIPES_ARRAY; i++) {
        if (CheckCollisionCircleRec(bird.position, 30, (Rectangle){pipes[i].pos_x, 0, 80, pipes[i].height}) ||
            CheckCollisionCircleRec(bird.position, 30, (Rectangle){pipes[i].pos_x, pipes[i].height+GAP, 80, HEIGHT-pipes[i].height+GAP})) {
                return true;
            }
    }

    return false;
}

bool check_bird_offscreen() {
    return bird.position.y > HEIGHT+28 || bird.position.y < -28;
}

void move_bird() {
    static bool clicked = false;
    static float click_delay = 0.0f;

    if (!bird.hit) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) )
            clicked = true;

        if (clicked) {
            click_delay += GetFrameTime();
            if (click_delay >= 0.25f) {
                clicked = false;
                click_delay = 0.0f;
            }
            else if (click_delay <= 0.2f) {
                bird.position.y -= 7;
            }
        } else
            bird.position.y += 4.5f;

        if (check_collision_with_pipes()) {
            bird.hit = true;
        }
    } else
        bird.position.y += 8;

    if (check_bird_offscreen())
        end = true;
}
