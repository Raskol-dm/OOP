#include "cabin.h"
#include "errors.h"
#include <stdio.h>
#include <QDebug>
#include <iostream>

cabin::cabin()
{
    st = CabinStateWaiting;
    floor = 1;

    connect(&door, SIGNAL(alreadyOpened()), this, SLOT(closeDoors()));
    connect(&TimeMoving, SIGNAL(timeout()), this, SLOT(arrive()));
    connect(&TimeFloorWaiting, SIGNAL(timeout()), &door, SLOT(closing()));
    connect(&door, SIGNAL(alreadyClosed()), this, SLOT(arrive()));
    connect(this, SIGNAL(closed()), this, SLOT(arrive()));

    connect(&door, SIGNAL(stateTextChanged(QString)), this, SIGNAL(doorsStateTextChanged(QString)));

    connect(this, SIGNAL(startOpening()), &door, SLOT(opening()));
    connect(this, SIGNAL(startClosing()), &door, SLOT(closing()));
}

void cabin::setState(CabinState state)
{
    st = state;

    QString stateText;

    switch (state) {
    case CabinStateGoingUp:
        stateText = "Едет вверх";
        break;
    case CabinStateGoingDown:
        stateText = "Едет вниз";
        break;
    case CabinStateWaiting:
        stateText = "Ожидает";
        break;
    case CabinStateOpening:
        stateText = "Открывается";
        break;
    case CabinStateClosing:
        stateText = "Закрывается";
        break;
    }

    qDebug() << "Кабина: " << stateText;

    emit stateTextChanged(stateText);
}

int cabin::currentFloor()
{
    return floor;
}

void cabin::updateState()
{
    setState(st);
    door.updateState();
}

int cabin::get_time_moving_up()
{
    return TIME_MOVING_UP;
}

int cabin::get_time_moving_dawn()
{
    return TIME_MOVING_DAWN;
}

int cabin::get_time_floor_waiting()
{
    return TIME_FLOOR_WAITING;
}


void cabin::closeDoors()
{
    if (st == CabinStateOpening)
    {
        setState(CabinStateClosing);
        TimeFloorWaiting.start(get_time_floor_waiting());
    }
}

void cabin::openDoors()
{
    if (st == CabinStateWaiting)
    {
        setState(CabinStateOpening);
        emit startOpening();
    }
}

void cabin::arrive()
{
    if (st == CabinStateGoingUp || st == CabinStateGoingDown || st == CabinStateClosing)
    {
        setState(CabinStateWaiting);
        emit arrived();
    }
}

void cabin::moveUp()
{
    if (st == CabinStateWaiting) {
        setState(CabinStateGoingUp);
        floor++;
        TimeMoving.start(get_time_moving_up());
    }
}

void cabin::moveDown()
{
    if (st == CabinStateWaiting) {
        setState(CabinStateGoingDown);
        floor--;
        TimeMoving.start(get_time_moving_dawn());
    }
}
