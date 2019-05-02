#include "../include/materials.h"
#include "../include/controls.h"
#include "../include/display.h"
#include "../include/robot.h"
#include "../include/map.h"

#include <stdio.h>

/* robot position initialization */
GLdouble robot_position[] = {106.0, 0, 33.0};

/* robot moving speed */
double robot_moving_speed = 1.0;

/* init body and arm rotation angles */
double body_rotation_angle = 0.0;
double arm_rotation_angle = 0.0;

void draw_robot()
{
    glPushMatrix();
        glTranslated(robot_position[X], robot_position[Y], robot_position[Z]);
        glRotated(body_rotation_angle, 0, 1, 0);

        /* body */
        glPushMatrix();
            set_material(WHITE, 1.0f);

            glTranslated(0.0, 7.5, 0.0);
            glScaled(2.5, 5.0, 2.5);

            glutSolidSphere(1, 20, 20);
        glPopMatrix();

        /* head */
        glPushMatrix();
            glTranslated(0.0, 13.5, 0.0);
            glScaled(4.0, 2.0, 2.0);

            glutSolidSphere(1.0, 20, 20);
        glPopMatrix();

        glPushMatrix();
            set_material(SKY_BLUE, 1.0f);

            glTranslated(0.0, 13.5, 0.0);
            glScaled(1.7, 1.0, 1.0);
            glRotated(90, 1.0, 0.0, 0.0);

            double clip_plane[] = {0, -1, 0, 1};
            glClipPlane(GL_CLIP_PLANE0, clip_plane);
            glEnable(GL_CLIP_PLANE0);
                glutSolidTorus(0.3, 2.0, 20, 20);
            glDisable(GL_CLIP_PLANE0);
        glPopMatrix();

        /* portal guns */
        glPushMatrix();
            set_material(SKY_BLUE, 1.0f);

            glTranslated(-3.0, 7.5, -0.5);
            glRotated(arm_rotation_angle, 1, 0, 0);
            glScaled(1.0, 3.0, 1.3);

            glutSolidSphere(1, 20, 20);
        glPopMatrix();

        glPushMatrix();
            set_material(ORANGE, 1.0f);

            glTranslated(3.0, 7.5, -0.5);
            glRotated(arm_rotation_angle, 1, 0, 0);
            glScaled(1.0, 3.0, 1.3);

            glutSolidSphere(1, 20, 20);
        glPopMatrix();

    glPopMatrix();
}

void move_robot()
{
    /* check for collisions */
    //wall_collision();

    if (box_parameter)
        move_box();
    else
        box_collision();

    /* move player based on pressed key */
    if (active_movement[UP]) {
        robot_position[Z] += robot_moving_speed;
    }

    if (active_movement[DOWN]) {
        robot_position[Z] -= robot_moving_speed;
    }

    if (active_movement[LEFT]) {
        robot_position[X] += robot_moving_speed;
    }

    if (active_movement[RIGHT]) {
        robot_position[X] -= robot_moving_speed;
    }

    /*printf("x = %lf\nz = %lf\n", robot_position[X], robot_position[Z]);*/
}

void control_robot()
{
    move_robot();
    draw_robot();
    glutPostRedisplay();
}
