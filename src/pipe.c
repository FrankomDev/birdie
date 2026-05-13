#include <raylib.h>
#include <stdio.h>
#include "pipe.h"
#include "bird.h"

Pipe pipes[PIPES_ARRAY];

void init_pipes() {
    for (int i=0; i<PIPES_ARRAY; i++) {
        pipes[i].height = GetRandomValue(1, HEIGHT-250);
        pipes[i].pos_x = 500 + i*80 + i*GAP_BETWEEN_PIPES;
    }
}

void draw_pipes() {
    for (int i=0; i<PIPES_ARRAY; i++) {
        DrawRectangle(pipes[i].pos_x, 0, 80, pipes[i].height, GREEN);
        DrawRectangle(pipes[i].pos_x, pipes[i].height+GAP, 80, HEIGHT-pipes[i].height+GAP, GREEN);
    }
}

void move_pipes() {
    if (!bird.hit) {
        for (int i=0; i<PIPES_ARRAY; i++) {
            pipes[i].pos_x -= 2;
        }

        if (pipes[0].pos_x <= -80) {
            Pipe new_pipes[PIPES_ARRAY];
            for (int i=0; i<PIPES_ARRAY-1; i++) {
                new_pipes[i] = pipes[i+1];
            }
            new_pipes[PIPES_ARRAY-1].height = GetRandomValue(200, HEIGHT-200);
            new_pipes[PIPES_ARRAY-1].pos_x = new_pipes[PIPES_ARRAY-2].pos_x + 80 + GAP_BETWEEN_PIPES;

            for (int i=0; i<PIPES_ARRAY; i++) {
                pipes[i] = new_pipes[i];
            }
        }
    }
}
