#ifndef MATERIALS_H
#define MATERIALS_H

#include <GL/glut.h>

#define WHITE    0
#define SKY_BLUE 1
#define RED      2
#define ORANGE   3
#define GREEN    4
#define GREY     5
#define TEAL     6

void set_material(int material_id, float alpha);

#endif /* MATERIALS_H */
