#include "lift.h"
#include "errors.h"
#include <QString>
#include <stdio.h>
#include "waitTime.h"
#include <QTime>
#include <QTimer>

lift::lift()
{
    this->log = nullptr;
    this->min_floor = 1;
    this->max_floor = 5;
    this->floor = 1;
    this->door = new doors;
    this->st = WAIT;
    this->is_empty = true;
    this->customs = new QSet<int>;
    this->queue = new QQueue<int>;
    connect(this, SIGNAL(arrived()), this->door, SLOT(open())); // Если поступил сигнал приехал, то для двирей сигнал открытие
    connect(this, SIGNAL(opening_doors()), this, SLOT(open_doors()));
    connect(this, SIGNAL(closing_doors()), this, SLOT(close_doors()));
    connect(this, SIGNAL(up()), this, SLOT(go_up()));
    connect(this, SIGNAL(down()), this, SLOT(go_down()));
    connect(this, SIGNAL(up()), this->door, SLOT(close()));
    connect(this, SIGNAL(down()), this->door, SLOT(close()));

}

void lift::get_order(int o) // Получение заказа
{
    this->customs->insert(o);
    this->reorder(); // перерасчёт порядка
}


void lift::set_state(lift_state state)
{
    this->log->append("Лифт ");
    this->st = state;
    QString s;

    switch (state) {
    case UP:
        s = "поднимается вверх...";
        this->lab->setText("Поднимается наверх");
        break;
    case DOWN:
        s = "опускается вниз....";
        this->lab->setText("Опускается вниз");
        break;
    case OPENING:
        s = "открывает двери...";
        this->lab->setText("Открывает двери");
        break;
    case CLOSING:
        s = "закрывает двери...";
        this->lab->setText("Закрывает двери");
        break;
    case WAIT:
        s = "перешел на ждущий режим...";
        this->lab->setText("Ждущий режим");
        break;
    default:
        s = "изменил свое сотояние на неизвестное!..";
        this->lab->setText("Неизвестное");
        break;
    }

    this->log->insertPlainText(s);
}


void lift::wait_here()
{

    emit this->opening_doors();
    this->set_state(WAIT);
}



void lift::go_up()
{
    if(this->door->is_open())
        emit this->closing_doors();

    this->set_state(UP);
    wait_time(500);
    this->floor++;
    this->table->display(this->floor);

    if(this->floor > this->max_floor)
        throw rangeError();
    if (this->queue->head() == this->floor)
    {
        emit this->arrived();
        this->queue->dequeue();
        this->customs->remove(this->floor);


        if(this->customs->isEmpty())
        {
            this->wait_here();
        }
        else
        {
            this->go_to(this->queue->head());
        }

    }
    else
    {
        if(this->floor <= this->max_floor)
            emit this->up();
        else
            emit this->down();
    }

}

void lift::go_down()
{
    if(this->door->is_open())
        emit this->closing_doors();

    this->set_state(DOWN);
    wait_time(500);
    this->floor--;
    this->table->display(this->floor);
    if(this->floor < this->min_floor)
        throw rangeError();
    if (this->queue->head() == this->floor)
    {
        emit this->arrived();

        this->queue->dequeue();
        this->customs->remove(this->floor);


        if(this->customs->isEmpty())
        {
            this->wait_here();
        }
        else
        {
            this->go_to(this->queue->head());
        }
    }
    else
    {
        if(this->floor >= this->min_floor)
            emit this->down();
        else
            emit this->up();
    }
}


void lift::open_doors()
{
    this->set_state(OPENING);
    emit this->door->opening();
}


void lift::close_doors()
{
    this->set_state(CLOSING);
    emit this->door->closing();
}

void lift::reorder()
{
    QSet<int>* new_set = new QSet<int>;
    for(QSet<int>::iterator it = this->customs->begin(); it != this->customs->end(); it++)
    {
        new_set->insert(*it);
    }

    while(!this->customs->isEmpty())
    {
        int opt = this->optional_queue();
        this->customs->remove(opt);
        this->queue->enqueue(opt);
    }

    this->customs = new_set;
    this->go_to(this->queue->head());


}


void lift::set_log(QTextEdit* log)
{
    this->log =log;
}


int lift::optional_queue()  // Выбор ближайшего этажа, относительно исходного
{
    int diff = this->max_floor;
    int optional = this->floor;

    for(QSet<int>::iterator it = this->customs->begin(); it != this->customs->end(); it++)
    {
        if (abs(*it - this->floor) < diff)
        {
            diff = *it - this->floor;
            optional = *it;
        }

    }

    return optional;
}


void lift::go_to(int o)
{
    if (!(this->min_floor <= o && o <= this->max_floor))
        throw rangeError();

    if (o < this->floor)
        emit this->down(); // Сигнал down - Слот go_down
    else if (o > this->floor)
        emit this->up(); // Сигнал UP - Слот go_up
    else
        this->wait_here();

}

void lift::set_labels(QLabel* doors_l, QLabel* cabin_l, QLCDNumber* table)
{
    this->door->set_label(doors_l);
    this->lab = cabin_l;
    this->set_state(WAIT);
    this->table = table;

}
