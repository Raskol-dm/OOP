#ifndef FIGURE_H
#define FIGURE_H

#include "structures.h"

data_points& init_points();

data_connections& init_connections();

model& init_model();

void copy_points(data_points& obj, data_points& tmp);

void copy_links(data_connections& obj, data_connections& tmp);

void copy_model(model &obj, model &tmp);

int load_figure(model &obj, const char *filename);

int draw_figure(model obj, draw arg);

int move_figure(model &obj, move coeff);

int scale_figure(model &obj, scale coeff);

int turn_figure(model &obj, turn coeff);


#endif // FIGURE_H
