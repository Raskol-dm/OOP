#include "errors.h"
#include "io.h"
#include "init_scene.h"
#include "draw.h"
#include "operations.h"
#include "figure.h"

data_points& init_points()
{
    static data_points tmp;
    tmp.n = 0;
    tmp.arr = NULL;
    return tmp;
}

data_connections& init_connections()
{
    static data_connections tmp;
    tmp.n = 0;
    tmp.arr = NULL;
    return tmp;
}

model& init_model()
{
    static model obj;

    obj.points = init_points();
    obj.links = init_connections();

    return obj;
}

void copy_points(data_points& obj, data_points& tmp)
{
    obj.n = tmp.n;
    obj.arr = tmp.arr;
}

void copy_links(data_connections& obj, data_connections& tmp)
{
    obj.n = tmp.n;
    obj.arr = tmp.arr;
}

void copy_model(model &obj, model &tmp)
{
    copy_points(obj.points, tmp.points);
    copy_links(obj.links, tmp.links);
}

int load_figure(model &obj, const char *filename) // создаётся дубликат основной структуры obj - obj_tmp,
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERR_READ;

    int rc = OK;
    model obj_tmp = init_model();

    rc = load_points(obj_tmp.points, f);
    if (rc == OK){
        rc = load_connections(obj_tmp.links, f);
        if (rc != OK)
            destroy_points(obj_tmp.points);
    }
    fclose(f);
    if (rc == OK)
    {
        destroy_model(obj);
        copy_model(obj, obj_tmp);
    }
    return rc;
}

int draw_figure(model obj, draw arg)
{
    graphics a;

    int err = init(a, arg.gV);
    if (err)
        return err;
    clear(a);
    draw_obj(obj, a);
    set(arg.gV, a);
    return err;
}

int move_figure(model &obj, move coeff)
{
    return move_points_array(obj, coeff);
}

int scale_figure(model &obj, scale coeff)
{
    return scale_points_array(obj, coeff);
}

int turn_figure(model &obj, turn coeff)
{
    return turn_points_array(obj, coeff);
}
