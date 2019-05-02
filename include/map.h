#ifndef MAP_H
#define MAP_H

#include <GL/glut.h>
#include "../include/display.h"

/* drawing functions */
void draw_world(void);
void draw_floor(void);
void draw_walls(void);
void draw_door_panel(void);
void draw_box(void);
void draw_doors(void);
void draw_misc_objects(void);

/* object functions */
void lift_box(void);
void move_box(void);
void open_doors(void);

/* box parameters */
extern double box[3];
extern int box_state;
extern bool box_parameter;

/* door parameters */
extern double left_door_side;
extern double right_door_side;
extern bool doors_opened;

#endif /* MAP_H */
