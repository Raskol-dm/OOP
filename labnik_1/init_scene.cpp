#include "init_scene.h"
#include "errors.h"
#include "draw.h"

int init(graphics &a, QGraphicsView *gv){
    a.scene = new QGraphicsScene(gv);
    if (!a.scene)
        return ERR_ALLOC;
    return OK;
}
void clear(graphics &a){
    a.scene->clear();
}

void set(QGraphicsView *gv, graphics &a){
    gv->setScene(a.scene);
}
