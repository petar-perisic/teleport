#ifndef ROBOT_H
#define ROBOT_H

#include <GL/glut.h>
#include <stdbool.h>
#include <math.h>

/* robot position parameters */
extern GLdouble robot_position[3];
extern double robot_moving_speed;

/* animation parameters for robot rotation */
extern bool body_rotation_parameter;
extern double body_rotation_angle;
extern double body_rotation_goal;

/* portal gun parameters */
extern bool arm_animation_parameter;
extern double arm_rotation_angle;
extern int armed_mode;

/* robot drawing and controling functions */
void draw_robot(void);
void move_robot(void);
void control_robot(void);

/* robot collision functions */
void wall_collision(void);
bool box_collision(void);

#endif /* ROBOT_H */
