#ifndef DRAW_H
#define DRAW_H
#include "init_scene.h"
#include "structures.h"
#include <QGraphicsView>



void my_addLine(graphics a, float x1, float y1, float x2, float y2);

connection get_link(connection *arr, int i);

point get_dot(point *arr, int i);

void draw_obj(model obj, graphics a);

#endif // DRAW_H
