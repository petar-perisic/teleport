#include <GL/glut.h>

#include "../include/display.h"
#include "../include/robot.h"
#include "../include/map.h"

/* animation parameters*/
static double lift_parameter;
static double body_angle;
static double arm_angle;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(robot_position[X], 80, robot_position[Z] - 60,
              robot_position[X],  0, robot_position[Z],
              0, 1, 0);

    control_robot();
    draw_world();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    /* set projection */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) width / height, 0.1, 500);
}

void on_timer(int value)
{
    switch (value) {
        /* rotate robot on keypress */
        case ROTATE_ROBOT:
            if (fabs(body_rotation_angle - body_rotation_goal) <= 0.01)
                break;

              body_angle = body_rotation_goal > body_rotation_angle ? 10.0 : -10.0;

              body_rotation_angle += body_angle;

              glutPostRedisplay();

              if (fabs(body_rotation_goal - body_rotation_angle) <= 0.01) {
                  body_rotation_parameter = false;
              }

              if (body_rotation_parameter)
                  glutTimerFunc(TIME_INTERVAL, on_timer, ROTATE_ROBOT);
        break;

        /* activate armed mode */
        case ARMED_MODE:
            /* check if armed angle is activated */
            arm_angle = armed_mode % 2 ? 10.0 : -10.0;
            arm_rotation_angle += arm_angle;

            glutPostRedisplay();

            /* check if animation is finished */
            if (arm_rotation_angle == 90.0 && (armed_mode % 2))
                arm_animation_parameter = false;

            if (arm_rotation_angle == 0.0 && !(armed_mode % 2))
                arm_animation_parameter = false;

            if (arm_animation_parameter)
                glutTimerFunc(TIME_INTERVAL, on_timer, ARMED_MODE);
        break;

        case LIFT_BOX:
            if (box[Y] >= 12.0 && box_state % 2)
                break;

            if (box[Y] <= 6.5 && (!(box_state % 2) || box_state == 0))
                break;

            lift_parameter = box_state % 2 ? 2.0 : -2.0;

            box[Y] += lift_parameter;

            glutPostRedisplay();

            glutTimerFunc(TIME_INTERVAL, on_timer, LIFT_BOX);
        break;

        case OPEN_DOORS:
            if (right_door_side >= 115 && left_door_side <= 27.0) {
                doors_opened = true;
                break;
            }

            right_door_side += 0.2;
            left_door_side -= 0.2;

            glutPostRedisplay();
        break;

        case CLOSE_DOORS:
            if (right_door_side <= 85.5 && left_door_side >= 30.0) {
                doors_opened = true;
                break;
            }

            right_door_side -= 0.2;
            left_door_side += 0.2;

            glutPostRedisplay();
        break;
    }
}

/* main light settings */
void init_lighting()
{
    GLfloat light_position[] = {155, 60, 75, 1};
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1};
    GLfloat light_diffuse[]  = {0.8, 0.8, 0.8, 1};
    GLfloat light_specular[] = {0.9, 0.9, 0.9, 1};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}
