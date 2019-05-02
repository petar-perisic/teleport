#include "../include/controls.h"
#include "../include/display.h"
#include "../include/robot.h"
#include "../include/map.h"

/* init moving state */
bool active_movement[] = {false, false, false, false};

/* init body rotation parameters */
bool body_rotation_parameter = false;
double body_rotation_goal = 0.0;

/* init portal gun parameters */
bool arm_animation_parameter = false;
int armed_mode = 0;

/* init box animation parameters         *
 * odd number = lift, even number = drop */
int box_state = 0;

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case ESC:
            exit(EXIT_SUCCESS);
        break;

        /* activate armed mode */
        case 'z':
        case 'Z':
            armed_mode++;
            arm_animation_parameter = true;
            glutTimerFunc(TIME_INTERVAL, on_timer, ARMED_MODE);
        break;

        /* shoot portal entrances */
        case 'x':
        case 'X':
        break;

        case 'v':
        case 'V':
            box_state++;
            lift_box();
        break;
    }
}

/* move and rotate tobot based on moving direction */
void special_pressed(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            active_movement[UP]    = true;
            active_movement[DOWN]  = false;
            active_movement[LEFT]  = false;
            active_movement[RIGHT] = false;

            body_rotation_goal = 180;
            body_rotation_parameter = true;
            glutTimerFunc(TIME_INTERVAL, on_timer, ROTATE_ROBOT);
        break;

        case GLUT_KEY_DOWN:
            active_movement[DOWN]  = true;
            active_movement[UP]    = false;
            active_movement[LEFT]  = false;
            active_movement[RIGHT] = false;

            body_rotation_goal = 0;
            body_rotation_parameter = true;
            glutTimerFunc(TIME_INTERVAL, on_timer, ROTATE_ROBOT);
        break;

        case GLUT_KEY_LEFT:
            active_movement[LEFT]  = true;
            active_movement[UP]    = false;
            active_movement[DOWN]  = false;
            active_movement[RIGHT] = false;

            body_rotation_goal = -90.0;
            body_rotation_parameter = true;
            glutTimerFunc(TIME_INTERVAL, on_timer, ROTATE_ROBOT);
        break;

        case GLUT_KEY_RIGHT:
            active_movement[RIGHT] = true;
            active_movement[UP]    = false;
            active_movement[DOWN]  = false;
            active_movement[LEFT]  = false;

            body_rotation_goal = 90.0;
            body_rotation_parameter = true;
            glutTimerFunc(TIME_INTERVAL, on_timer, ROTATE_ROBOT);
        break;
    }
}

void special_released(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            active_movement[UP] = false;
        break;

        case GLUT_KEY_DOWN:
            active_movement[DOWN] = false;
        break;

        case GLUT_KEY_LEFT:
            active_movement[LEFT] = false;
        break;

        case GLUT_KEY_RIGHT:
            active_movement[RIGHT] = false;
        break;
    }
}
