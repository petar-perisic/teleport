#ifndef CONTROLS_H
#define CONTROLS_H

#include <GL/glut.h>
#include <stdbool.h>

#define ESC   27
#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

extern bool active_movement[4];

void keyboard(unsigned char key, int x, int y);
void special_pressed(int key, int x, int y);
void special_released(int key, int x, int y);

#endif /* CONTROLS_H */
