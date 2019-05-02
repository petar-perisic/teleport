#include "../include/materials.h"
#include "../include/controls.h"
#include "../include/display.h"
#include "../include/robot.h"
#include "../include/map.h"

#include <math.h>

#define M_PI 3.14159265358979323846

/* blue box parameters initialization */
double box[] = {80.0, 6.5, 30.0};

/* if box is lifted - parameter = true */
bool box_parameter = false;

/* init door parameters */
double right_door_side = 85.0;
double left_door_side = 55.0;
bool doors_opened = false;

void draw_world()
{
    draw_box();
    draw_door_panel();

    draw_doors();
    open_doors();

    draw_misc_objects();

    draw_floor();
    draw_walls();
}

void draw_floor()
{
    set_material(GREY, 1.0f);

    /* main room */
    glPushMatrix();
        glBegin(GL_QUADS);
          glVertex3f(0.0, 0.0, 0.0);
          glVertex3f(150.0, 0.0, 0.0);
          glVertex3f(150.0, 0.0, 150.0);
          glVertex3f(0.0, 0.0,  150.0);
        glEnd();
    glPopMatrix();

    /* side room */
    glPushMatrix();
        glBegin(GL_QUADS);
          glVertex3f(150.0, 0.0, 0.0);
          glVertex3f(150.0, 0.0, 190.0);
          glVertex3f(240.0, 0.0, 190.0);
          glVertex3f(240.0, 0.0, 0.0);
        glEnd();
    glPopMatrix();
}

void draw_walls()
{
    set_material(WHITE, 1.0f);

    /* main room right wall */
    glPushMatrix();
        glTranslated(0.0, 22.5, 75.2);
        glScaled(5.0, 45.0, 150.5);
        glutSolidCube(1);
    glPopMatrix();

    /* main room left wall / left part */
    glPushMatrix();
        glTranslated(152.0, 22.5, 18.75);
        glScaled(5.0, 45.0, 37.5);
        glutSolidCube(1);

    glPopMatrix();

    /* main room left wall / right part / side room right wall */
    glPushMatrix();
        glTranslated(152.0, 22.5, 152.0);
        glScaled(5.0, 45.0, 85.0);
        glutSolidCube(1);
    glPopMatrix();

    /* main room top wall */
    glPushMatrix();
        glTranslated(77.0, 22.5, 148.0);
        glScaled(154.0, 45.0, 5.0);
        glutSolidCube(1);
    glPopMatrix();

    /* side room left wall */
    set_material(WHITE, 1.0f);
    glPushMatrix();
        glTranslated(242.0, 22.5, 95.0);
        glScaled(5.0, 45.0, 190.0);
        glutSolidCube(1);
    glPopMatrix();

    /* side room top wall */
    glPushMatrix();
        glTranslated(199.0, 22.5, 192.0);
        glScaled(91.0, 45.0, 5.0);
        glutSolidCube(1);
    glPopMatrix();

    /* bottom wall */
    set_material(WHITE, 0.4f);
    glPushMatrix();
        glTranslated(121.0, 22.5, -2.5);
        glScaled(247.0, 45.0, 5.0);
        glutSolidCube(1);
    glPopMatrix();

}

void draw_door_panel()
{
    set_material(ORANGE, 1.0f);

    glPushMatrix();
        glTranslated(60.0, 1.0, 105.0);
        glScaled(1.0, 0.01, 1.0);

        glutSolidCube(13);
    glPopMatrix();
}

void draw_box()
{
    set_material(GREEN, 1.0f);

    glPushMatrix();
        /* rotate box when robot is carrying it */
        if (box_parameter) {
            box[X] = robot_position[X] - sin(body_rotation_angle * M_PI/180) * 13;
            box[Z] = robot_position[Z] - cos(body_rotation_angle * M_PI/180) * 13;
        }

        glTranslated(box[X], box[Y], box[Z]);

        glutSolidCube(15);
    glPopMatrix();
}

void draw_doors()
{
    set_material(SKY_BLUE, 1.0f);

    /* left blue block */
    glPushMatrix();
        glTranslated(152.0, 23.5, 106.00);
        glScaled(10, 47.0, 11);
        glutSolidCube(1);
    glPopMatrix();

    /* right blue block */
    glPushMatrix();
        glTranslated(152.0, 23.5, 40.00);
        glScaled(10, 47.0, 11);
        glutSolidCube(1);
    glPopMatrix();

    set_material(ORANGE, 1.0f);

    /* left door side */
    glPushMatrix();
        glTranslated(152.0, 22.0, left_door_side);
        glScaled(4, 44.0, 32);
        glutSolidCube(1);
    glPopMatrix();

    /* right door side */
    glPushMatrix();
        glTranslated(152.0, 22.0, right_door_side);
        glScaled(4, 44.0, 30);
        glutSolidCube(1);
    glPopMatrix();
}

void draw_misc_objects()
{
    /* main room red boxes */
    set_material(RED, 1.0f);

    glPushMatrix();
        glTranslated(15, 12.5, 132.5);
        glutSolidCube(25);
    glPopMatrix();

    glPushMatrix();
        glTranslated(11.5, 9.0, 110.5);
        glutSolidCube(18);
    glPopMatrix();

    glPushMatrix();
        glTranslated(140.5, 5.0, 6.0);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glTranslated(130.5, 2.5, 3.5);
        glutSolidCube(5);
    glPopMatrix();

    /* side room teal box*/
    set_material(TEAL, 1.0f);

    glPushMatrix();
        glTranslated(217, 10.0, 175.5);
        glScaled(45, 20, 30);
        glutSolidCube(1);
    glPopMatrix();

    /* side room red boxes */
    set_material(RED, 1.0f);

    glPushMatrix();
        glTranslated(234.2, 10.0, 21.0);
        glScaled(10, 20, 40);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(159.5, 2.5, 4);
        glutSolidCube(5);
    glPopMatrix();
}

void lift_box()
{
    double diff_x = robot_position[X] - box[X];
    double diff_z = robot_position[Z] - box[Z];
    double diff = fabs(diff_x) + fabs(diff_z);

    if (diff < 18 && (box_state % 2)) {
        glutTimerFunc(TIME_INTERVAL, on_timer, LIFT_BOX);
        box_parameter = true;
    }

    if (diff < 18 && !(box_state % 2)) {
        glutTimerFunc(TIME_INTERVAL, on_timer, LIFT_BOX);
        box_parameter = false;
    }
}

void move_box()
{
    if (active_movement[UP]) {
        box[Z] += robot_moving_speed;
    }

    if (active_movement[DOWN]) {
        box[Z] -= robot_moving_speed;
    }

    if (active_movement[LEFT]) {
        box[X] += robot_moving_speed;
    }

    if (active_movement[RIGHT]) {
        box[X] -= robot_moving_speed;
    }
}

void open_doors(void)
{
    /* check if box is on panel */
    double diff = fabs(box[X] + box[Z] - 165.0);

    /* open doors */
    if (diff < 7 && box[Y] <= 6.5)
        glutTimerFunc(TIME_INTERVAL, on_timer, OPEN_DOORS);

    /* close doors */
    if (doors_opened && diff > 7)
        glutTimerFunc(TIME_INTERVAL, on_timer, CLOSE_DOORS);
}
