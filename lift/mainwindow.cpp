#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "elevator.h"
#include "cabin.h"
#include "doors.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    elevate(new Ui::MainWindow)
{
    elevate->setupUi(this);
    connect(this, SIGNAL(floorButtonPressed(int)), &el, SLOT(floorButtonPressed(int)));
    connect(&el, SIGNAL(stateTextChanged(QString)), this, SLOT(elevatorStateChanged(QString)));
    connect(&el, SIGNAL(cabinStateTextChanged(QString)), this, SLOT(cabinStateChanged(QString)));
    connect(&el, SIGNAL(doorsStateTextChanged(QString)), this, SLOT(doorsStateChanged(QString)));
    connect(&el, SIGNAL(floorChanged(int)), this, SLOT(cabinFloorChanged(int)));

    el.updateState();
}

MainWindow::~MainWindow()
{
    delete elevate;
}

void MainWindow::on_bt1_clicked()
{
    emit floorButtonPressed(1);
}

void MainWindow::on_bt2_clicked()
{
    emit floorButtonPressed(2);
}

void MainWindow::on_bt3_clicked()
{
    emit floorButtonPressed(3);
}

void MainWindow::on_bt4_clicked()
{
    emit floorButtonPressed(4);
}

void MainWindow::on_bt5_clicked()
{
    emit floorButtonPressed(5);
}

void MainWindow::on_bt6_clicked()
{
    emit floorButtonPressed(6);
}

void MainWindow::on_bt7_clicked()
{
    emit floorButtonPressed(7);
}

void MainWindow::on_bt8_clicked()
{
    emit floorButtonPressed(8);
}

void MainWindow::on_bt9_clicked()
{
    emit floorButtonPressed(9);
}

void MainWindow::on_bt11_clicked()
{
    emit floorButtonPressed(9);
}

void MainWindow::on_bt12_clicked()
{
    emit floorButtonPressed(8);
}

void MainWindow::on_bt13_clicked()
{
    emit floorButtonPressed(7);
}

void MainWindow::on_bt14_clicked()
{
    emit floorButtonPressed(6);
}

void MainWindow::on_bt15_clicked()
{
    emit floorButtonPressed(5);
}

void MainWindow::on_bt16_clicked()
{
    emit floorButtonPressed(4);
}

void MainWindow::on_bt17_clicked()
{
    emit floorButtonPressed(3);
}

void MainWindow::on_bt18_clicked()
{
    emit floorButtonPressed(2);
}

void MainWindow::on_bt19_clicked()
{
    emit floorButtonPressed(1);
}

void MainWindow::elevatorStateChanged(QString stateText)
{
    elevate->stage_lift_2->setText(stateText);
    update();
}

void MainWindow::cabinFloorChanged(int floor)
{
    elevate->floors->setText(QString("%1").arg(floor));
    elevate->floors_2->setText(QString("%1").arg(floor));
    update();
}

void MainWindow::cabinStateChanged(QString stateText)
{
    elevate->stage_lift->setText(stateText);
    update();
}

void MainWindow::doorsStateChanged(QString stateText)
{
    elevate->stage_doors->setText(stateText);
    update();
}
