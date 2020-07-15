#ifndef IO_H
#define IO_H

#include "structures.h"

int read_points(point *arr, int n, FILE *f);

int read_connections(connection *arr, int n, FILE *f);

int scan_number(int *n, FILE *f);

int points_alloc(data_points& tmp_p, int n);

void destroy_points(data_points& tmp_p);

int connection_alloc(data_connections& tmp_c, int n);

void destroy_connections(data_connections& tmp_c);

void destroy_model(model& obj);

int load_points(data_points& tmp_p, FILE *f);

int load_connections(data_connections& tmp_c, FILE *f);

#endif // IO_H
