#include "doors.h"
#include "errors.h"
#include <iostream>
#include <QDebug>


doors::doors()
{
    setState(DoorStateClosed);
    QObject::connect(&TimerOpening, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&TimerClosing, SIGNAL(timeout()), this, SLOT(closed()));
}

bool doors::isOpen()
{
    return st == DoorStateOpen;
}

void doors::updateState()
{
    setState(st);
}

int doors::get_time_opening()
{
    return TIME_OPENING;
}

int doors::get_time_closing()
{
    return TIME_CLOSING;
}

void doors::setState(DoorState state)
{
    st = state;

    QString stateText;

    switch (state) {
    case DoorStateOpen:
        stateText = "Открыты";
        break;
    case DoorStateClosed:
        stateText = "Закрыты";
        break;
    case DoorStateOpening:
        stateText = "Открываются";
        break;
    case DoorStateClosing:
        stateText = "Закрываются";
        break;
    }

    qDebug() << "Двери: " << stateText;

    emit stateTextChanged(stateText);
}

void doors::opening()
{
    if (st == DoorStateClosed) {
        setState(DoorStateOpening);
        TimerOpening.start(get_time_opening());
    }

}

void doors::closing()
{
    if (st == DoorStateOpen) {
        setState(DoorStateClosing);
        TimerClosing.start(get_time_closing());
    }
}

void doors::opened()
{
    if (st == DoorStateOpening) {
        setState(DoorStateOpen);
        emit alreadyOpened();
    }
}

void doors::closed()
{
    if (st == DoorStateClosing) {
        setState(DoorStateClosed);
        emit alreadyClosed();
    }
}
