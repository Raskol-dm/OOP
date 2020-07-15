#ifndef MANAGER_H
#define MANAGER_H

#include "structures.h"
#include "errors.h"
#include "figure.h"
#include "io.h"

enum task{
    LOAD_FILE,
    FREE_MODEL,
    MOVE_MODEL,
    SCALE_MODEL,
    TURN_MODEL,
    DRAW_MODEL,
    UNKNOWN_COMMAND
};

typedef struct{
    task t;
    union
    {
        const char *filename;
        draw dr;
        move mo;
        scale sc;
        turn tu;
    };
}request;

int task_manager(request req);

#endif
