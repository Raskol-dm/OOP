#include "structures.h"
#include "errors.h"
#include "io.h"
#include "draw.h"

int read_points(point *arr, int n, FILE *f)
{
    int rc = OK;
    for (int i = 0; i < n && rc == OK; i++){
        if (fscanf(f, "%f%f%f", &arr[i].x, &arr[i].y, &arr[i].z) != 3)
            rc = ERR_INPUT;
    }
    return rc;
}

int read_connections(connection *arr, int n, FILE *f)
{
    int rc = OK;
    for (int i = 0; i < n && rc == OK; i++){
        if (fscanf(f, "%d%d", &arr[i].p1, &arr[i].p2) != 2)
            rc = ERR_INPUT;
    }
    return rc;
}

int scan_number(int *n, FILE *f)
{
    if (fscanf(f, "%d", n) != 1)
        return ERR_INPUT;
    if (*n <= 0)
        return ERR_RANGE;
    return OK;
}

int points_alloc(data_points& tmp_p, int n)
{
    tmp_p.n = n;
    tmp_p.arr = (point*) calloc(n, sizeof(point));
    if (!tmp_p.arr)
        return ERR_ALLOC;
    return OK;
}

void destroy_points(data_points& tmp_p)
{
    tmp_p.n = 0;
    if (!tmp_p.arr)
        free(tmp_p.arr);
}

int connection_alloc(data_connections& tmp_c, int n)
{
    tmp_c.n = n;
    tmp_c.arr = (connection*) calloc(n, sizeof(connection));
    if (!tmp_c.arr)
        return ERR_ALLOC;
    return OK;
}

void destroy_connections(data_connections& tmp_c)
{
    tmp_c.n = 0;
    if (!tmp_c.arr)
        free(tmp_c.arr);
}

void destroy_model(model& obj)
{
    destroy_points(obj.points);
    destroy_connections(obj.links);
}

int load_points(data_points& tmp_p, FILE *f)
{
    int n;
    int rc = OK;

    rc = scan_number(&n, f);
    if (rc == OK)
    {
        rc = points_alloc(tmp_p, n);
        if (rc == OK)
        {
            rc = read_points(tmp_p.arr, tmp_p.n, f);
            if (rc != OK)
                destroy_points(tmp_p);
        }
    }
    return rc;
}

int load_connections(data_connections& tmp_c, FILE *f)
{
    int n;
    int rc = OK;

    rc = scan_number(&n, f);
    if (rc == OK)
    {
        rc = connection_alloc(tmp_c, n);
        if (rc == OK)
        {
            rc = read_connections(tmp_c.arr, tmp_c.n, f);
            if (rc != OK)
                destroy_connections(tmp_c);
        }
    }
    return rc;
}
