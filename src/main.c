#include <stdbool.h>
#include <GL/glut.h>

#include "../include/controls.h"
#include "../include/display.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TelePort");

    /* register callbacks */
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_pressed);
    glutSpecialUpFunc(special_released);

    /* OpenGL initialization */
    glClearColor(0, 0, 0, 0);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* init lights */
    init_lighting();

    glutMainLoop();

    return 0;
}
