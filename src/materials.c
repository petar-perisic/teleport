#include <GL/glut.h>

#include "../include/materials.h"

GLfloat ambient[4];
GLfloat diffuse[4];
GLfloat specular[4];
GLfloat shininess;

void set_material(int material_id, float alpha)
{
    switch (material_id) {
        case WHITE:
            ambient[0]  = 0.7; ambient[1]  = 0.7; ambient[2]  = 0.7;
            diffuse[0]  = 0.8; diffuse[1]  = 0.8; diffuse[2]  = 0.8;
            specular[0] = 0.9; specular[1] = 0.9; specular[2] = 0.9;
        break;

        case SKY_BLUE:
            ambient[0]  = 0.118; ambient[1]  = 0.565; ambient[2]  = 1.0;
            diffuse[0]  = 0.118; diffuse[1]  = 0.565; diffuse[2]  = 1.0;
            specular[0] = 0.118; specular[1] = 0.565; specular[2] = 1.0;
        break;

        case RED:
            ambient[0]  = 0.863; ambient[1]  = 0.078; ambient[2]  = 0.0235;
            diffuse[0]  = 0.863; diffuse[1]  = 0.078; diffuse[2]  = 0.0235;
            specular[0] = 0.863; specular[1] = 0.078; specular[2] = 0.0235;
        break;

        case ORANGE:
            ambient[0]  = 1.0; ambient[1]  = 0.549; ambient[2]  = 0.0;
            diffuse[0]  = 1.0; diffuse[1]  = 0.549; diffuse[2]  = 0.0;
            specular[0] = 1.0; specular[1] = 0.549; specular[2] = 0.0;
        break;

        case GREEN:
            ambient[0]  = 0.0; ambient[1]  = 1.0; ambient[2]  = 0.498;
            diffuse[0]  = 0.0; diffuse[1]  = 1.0; diffuse[2]  = 0.498;
            specular[0] = 0.0; specular[1] = 1.0; specular[2] = 0.498;
        break;

        case GREY:
            ambient[0]  = 0.2; ambient[1]  = 0.2; ambient[2]  = 0.2;
            diffuse[0]  = 0.4; diffuse[1]  = 0.4; diffuse[2]  = 0.4;
            specular[0] = 0.7; specular[1] = 0.7; specular[2] = 0.7;
        break;

        case TEAL:
            ambient[0]  = 0.0; ambient[1]  = 0.502; ambient[2]  = 0.502;
            diffuse[0]  = 0.0; diffuse[1]  = 0.502; diffuse[2]  = 0.502;
            specular[0] = 0.0; specular[1] = 0.502; specular[2] = 0.502;
        break;
    }

    /* set transparency */
    ambient[3] = alpha;
    diffuse[3] = alpha;
    specular[3] = alpha;

    shininess = 30.0;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, shininess);
}
