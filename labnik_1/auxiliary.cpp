#include "auxiliary.h"

int get_amount_links(figure fig)
{
    return fig.links.n;
}

int get_amount_vertix(figure fig)
{
    return fig.points.n;
}

point* get_arr_points(figure fig)
{
    return fig.points.arr;
}

connection* get_arr_links(figure fig)
{
    return fig.links.arr;
}
