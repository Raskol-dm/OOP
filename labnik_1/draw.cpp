#include "draw.h"
#include "structures.h"
#include "errors.h"
#include "init_scene.h"


void my_addLine(graphics a, float x1, float y1, float x2, float y2){
    a.scene->addLine(x1, y1, x2, y2);
}

connection get_link(connection *arr, int i){
    connection cur;
    cur.p1 = arr[i].p1;
    cur.p2 = arr[i].p2;
    return cur;
}

point get_dot(point *arr, int i){
    point cur;
    cur.x = arr[i].x;
    cur.y = arr[i].y;
    return cur;
}

void draw_obj(model obj, graphics a){
    int p1, p2;
    data_points points = obj.points;
    data_connections links = obj.links;

    for (int i = 0; i < links.n; i++){
        connection cur;
        point tmp_1, tmp_2;

        cur = get_link(links.arr, i);
        p1 = cur.p1;
        p2 = cur.p2;

        tmp_1 = get_dot(points.arr, p1);
        tmp_2 = get_dot(points.arr, p2);

        my_addLine(a, tmp_1.x, tmp_1.y, tmp_2.x, tmp_2.y);
    }
}
