#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>

#define WINDOW_WIDTH  1024
#define WINDOW_HEIGHT 768

/* on_timer parameters and timer IDs */
#define TIME_INTERVAL 30

#define ROTATE_ROBOT  0
#define ARMED_MODE    1
#define LIFT_BOX      2
#define OPEN_DOORS    3
#define CLOSE_DOORS   4

/* axis */
#define X 0
#define Y 1
#define Z 2

void display(void);
void reshape(int width, int height);
void on_timer(int value);

void init_lighting(void);

#endif /* DISPLAY_H */
