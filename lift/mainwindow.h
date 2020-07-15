#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "elevator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_bt1_clicked();

    void on_bt2_clicked();

    void on_bt3_clicked();

    void on_bt4_clicked();

    void on_bt5_clicked();

    void on_bt6_clicked();

    void on_bt7_clicked();

    void on_bt8_clicked();

    void on_bt9_clicked();

    void on_bt11_clicked();

    void on_bt12_clicked();

    void on_bt13_clicked();

    void on_bt14_clicked();

    void on_bt15_clicked();

    void on_bt16_clicked();

    void on_bt17_clicked();

    void on_bt18_clicked();

    void on_bt19_clicked();

signals:
    void floorButtonPressed(int floor);

public slots:
    void elevatorStateChanged(QString stateText);
    void cabinFloorChanged(int floor);
    void cabinStateChanged(QString stateText);
    void doorsStateChanged(QString stateText);

private:
    Ui::MainWindow *elevate;
    elevator el;
};

#endif // MAINWINDOW_H
