#include "doors.h"
#include "errors.h"
#include "waitTime.h"
#include "lift.h"
#include <QTimer>
#include <QTime>

doors::doors()
{
    this->st = CLOSED;
    connect(this, SIGNAL(opening()), this, SLOT(start_open())); // Поступил сигнал открытие дверей, то я запускаю слот opening
    connect(this, SIGNAL(closing()), this, SLOT(start_close()));

}

void doors::set_state(doors_state state) // Вывод
{
    this->st = state;
    if(state == OPENED)
        this->lab->setText("Открыты");
    else if(state == CLOSED)
        this->lab->setText("Закрыты");
    else if(state == CLOSING)
        this->lab->setText("Закрываются");
    else if(state == OPENING)
        this->lab->setText("Открываются");
}


void doors::open()
{
    if(this->st == OPENING)
    {
        this->set_state(OPENED);
    }
}

void doors::close()
{
    if(this->st == CLOSING)
    {
        this->set_state(CLOSED);
    }

}


void doors::start_open()
{
    if(this->st == CLOSED)
    {
        this->set_state(OPENING);
        QTimer::singleShot(200, this, SLOT(open()));
    }
}

void doors::start_close()
{
    if(this->st == OPENED)
    {
        this->set_state(CLOSING);
        QTimer::singleShot(200, this, SLOT(close()));
    }
}



void doors::set_label(QLabel* l)
{
    this->lab = l;
    this->set_state(CLOSED);
}


bool doors::is_open()
{
    return this->st == OPENED;
}
