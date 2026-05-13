#ifndef _BIRD_H_
#define _BIRD_H_

#include <raylib.h>

typedef struct {
    Vector2 position;
    bool hit;
} Bird;
extern Bird bird;

void draw_bird();
void move_bird();

#endif // _BIRD_H_
