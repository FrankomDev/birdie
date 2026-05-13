#ifndef _PIPE_H_
#define _PIPE_H_

#define HEIGHT 600
#define GAP 200
#define GAP_BETWEEN_PIPES 180
#define PIPES_ARRAY 4

typedef struct {
    int height;
    int pos_x;
    bool touched;
} Pipe;
extern Pipe pipes[PIPES_ARRAY];

void init_pipes();
void draw_pipes();
void move_pipes();

#endif // _PIPE_H_
