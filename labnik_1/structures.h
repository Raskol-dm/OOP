#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <QGraphicsView>

typedef struct{
    QGraphicsView *gV;
}draw;

typedef struct{
    QGraphicsScene *scene;
}graphics;

typedef struct{
    float x;
    float y;
    float z;
}point;

typedef struct{
    int p1;
    int p2;
}connection;

typedef struct{
    int dx;
    int dy;
    int dz;
}move;

typedef struct{
    float kx;
    float ky;
    float kz;
}scale;

typedef struct{
    float ox;
    float oy;
    float oz;
}turn;

typedef struct{
    int n;
    point *arr;
}data_points;

typedef struct{
    int n;
    connection *arr;
}data_connections;

typedef struct{
    data_points points;
    data_connections links;
}model;

#endif // STRUCTURES_H
