#include <math.h>
#include "operations.h"
#include "errors.h"


void move_point(point& dot, move coeff)
{
    dot.x += coeff.dx;
    dot.y += coeff.dy;
    dot.z += coeff.dz;
}

int move_points_array(model& obj, move coeff)
{
    data_points points = obj.points;
    if(!points.arr)
        return NO_DOTS;
    for(int i = 0; i < points.n; i++)
        move_point(points.arr[i], coeff);
    return OK;
}

void scale_point(point& dot, scale coeff)
{
    dot.x *= coeff.kx;
    dot.y *= coeff.ky;
    dot.z *= coeff.kz;
}

int scale_points_array(model& obj, scale coeff)
{
    data_points points = obj.points;
    if(!points.arr)
        return NO_DOTS;
    for(int i = 0; i < points.n; i++)
        scale_point(points.arr[i], coeff);
    return OK;
}

double d_cos(double angle)
{
    return cos(angle * 3.1415 / 180);
}

double d_sin(double angle)
{
    return sin(angle * 3.1415 / 180);
}

void x_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    dot.y = dot.y + cos_ang + dot.z * sin_ang;
    dot.z = -dot.y * sin_ang + dot.z * cos_ang;
}

void y_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    dot.x = dot.x * cos_ang + dot.z * sin_ang;
    dot.z = -dot.x * sin_ang + dot.z * cos_ang;
}

void z_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    dot.x = dot.x * cos_ang + dot.y * sin_ang;
    dot.y = -dot.x * sin_ang + dot.y * cos_ang;
}


int turn_points_array(model& obj, turn coeff)
{
    data_points points = obj.points;
    if(!points.arr)
        return NO_DOTS;
    for(int i = 0; i < points.n; i++)
    {
        x_turn_point(points.arr[i], coeff.ox);
        y_turn_point(points.arr[i], coeff.oy);
        z_turn_point(points.arr[i], coeff.oz);
    }
    return OK;
}
