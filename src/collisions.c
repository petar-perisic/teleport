#include "../include/controls.h"
#include "../include/display.h"
#include "../include/robot.h"
#include "../include/map.h"

bool allowed_direction[] = {true, true, true, true};

/* TODO: change wall_collision function */
void wall_collision()
{
    /* side walls */
    if (doors_opened && robot_position[Z]  >= 50 && robot_position[Z]  <= 90)
        return;

    if (active_movement[LEFT])
        active_movement[LEFT] = robot_position[X] >= 142.0 ? false : true;

    if (active_movement[RIGHT])
        active_movement[RIGHT] = robot_position[X] <= 7.0 ? false : true;

    /* horizontal walls  */
    if (active_movement[UP])
        active_movement[UP] = robot_position[Z] >= 140.0 ? false : true;

    if (active_movement[DOWN])
        active_movement[DOWN] = robot_position[Z] <= 2.0 ? false : true;
}

bool box_collision()
{
    double diff_x = robot_position[X] - box[X];
    double diff_z = robot_position[Z] - box[Z];
    double diff = fabs(diff_x) + fabs(diff_z);

    if (diff < 17.0) {
        if (diff_x > 0 && fabs(diff_z) < 13.0)
            active_movement[RIGHT] = false;

        if (diff_x < 0 && fabs(diff_z) < 13.0)
            active_movement[LEFT] = false;

        if (diff_z > 0 && fabs(diff_x) < 12.0)
            active_movement[DOWN] = false;

        if (diff_z < 0 && fabs(diff_x) < 12.0)
            active_movement[UP] = false;

        return true;
    }
    return false;
}
