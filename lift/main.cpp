#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication elevator(argc, argv);
    MainWindow elevatorWindow;
    elevatorWindow.show();

    return elevator.exec();
}
