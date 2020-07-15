#include "manager.h"

int task_manager(request req){  // Голова бизнес - программы ( техническая часть )
    int  err = OK;
    static model obj = init_model();
    switch (req.t){
    case LOAD_FILE:  // Все компоненты программы
        err = load_figure(obj, req.filename);
        break;
    case FREE_MODEL:
        destroy_model(obj);
        break;
    case DRAW_MODEL:
        err = draw_figure(obj, req.dr);
        break;
    case MOVE_MODEL:
        err = move_figure(obj, req.mo);
        break;
    case SCALE_MODEL:
        err = scale_figure(obj, req.sc);
        break;
    case TURN_MODEL:
        err = turn_figure(obj, req.tu);
        break;
    default:
        err = UNKNOWN_COMMAND;
    }

    return err;
}
