#include "errors.h"
#include "manager.h"
#include "QMessageBox"
#include <QObject>

void error_message(int err){
    if (err == ERR_READ || err == ERR_RANGE || err == ERR_INPUT)
    {
        QMessageBox::critical(NULL, "ERROR", "File format error");
    }
    else if (err == NO_DOTS)
    {
        QMessageBox::critical(NULL, "ERROR", "File is empty, or array is empty!");
    }
    else if (err == ERR_ALLOC)
    {
        QMessageBox::critical(NULL, "ERROR", "Memory allocation!");
    }
    else if (err == UNKNOWN_COMMAND)
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown command in enter point!");
    }
    else
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown error");
    }
}
