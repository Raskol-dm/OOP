#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "structures.h"
#include "io.h"
#include "manager.h"
#include "draw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

int draw_action(Ui::MainWindow* ui){
    draw dr;
    request req;

    dr.gV = ui->graphicsView;
    req.t = DRAW_MODEL;
    req.dr = dr;

    int err = (int) task_manager(req);
    return err;
}

int change(request req, Ui::MainWindow* ui){
    int err = (int) task_manager(req);
    if (err)
        return err;
    else
        err = draw_action(ui);
    return err;
}

void MainWindow::on_pushButton_4_clicked(){
    request req;

    req.t = LOAD_FILE;
    req.filename = "E:/OOP/lab_1/labnik_1/cube.txt";

    int err = change(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_pushButton_clicked(){
    request req;
    req.t = MOVE_MODEL;

    req.mo.dx = ui->line_dx->text().toInt();
    req.mo.dy = ui->line_dy->text().toInt();
    req.mo.dz = ui->line_dz->text().toInt();
    puts("MOVE");

    int err = change(req, ui);
    if (err)
        error_message(err);

}

void MainWindow::on_pushButton_2_clicked(){
    request req;
    req.t = TURN_MODEL;

    req.tu.ox = ui->line_ox->text().toFloat();
    req.tu.oy = ui->line_oy->text().toFloat();
    req.tu.oz = ui->line_oz->text().toFloat();
    puts("TURN");
    int err = change(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_pushButton_3_clicked(){
    request req;
    req.t = SCALE_MODEL;

    req.sc.kx = ui->line_kx->text().toFloat();
    req.sc.ky = ui->line_ky->text().toFloat();
    req.sc.kz = ui->line_kz->text().toFloat();
    puts("MASHTab");
    int err = change(req, ui);
    if (err)
        error_message(err);
}
