#include "elevator.h"
#include "errors.h"
#include <stdio.h>
#include <QDebug>
#include <iostream>


elevator::elevator()
{
    setState(ElevatorStateFree);

    connect(&cab, SIGNAL(arrived()), this, SLOT(cabinArrived()));
    connect(this, SIGNAL(moveUp()), &cab, SLOT(moveUp()));
    connect(this, SIGNAL(moveDown()), &cab, SLOT(moveDown()));
    connect(this, SIGNAL(openDoors()), &cab, SLOT(openDoors()));
    connect(this, SIGNAL(checkState()), &cab, SLOT(floorButtonPressed(-1)));

    connect(&cab, SIGNAL(stateTextChanged(QString)), this, SIGNAL(cabinStateTextChanged(QString)));
    connect(&cab, SIGNAL(doorsStateTextChanged(QString)), this, SIGNAL(doorsStateTextChanged(QString)));
}

void elevator::updateState()
{
    setState(state);
    cab.updateState();
}

void elevator::setState(ElevatorState state)
{
    this->state = state;

    QString stateText;

    switch (state) {
    case ElevatorStateBusy:
        stateText = "Занят";
        break;
    case ElevatorStateFree:
        stateText = "Свободен";
        break;
    }

    qDebug() << "Лифт: " << stateText;

    emit stateTextChanged(stateText);
}

void elevator::floorButtonPressed(int floor)
{
    add_floor(floor);
    if (state == ElevatorStateFree) {
        setState(ElevatorStateBusy);

        if (cab.currentFloor() == floor) {
            emit openDoors();
            return;
        }

        bool movingUp = cab.currentFloor() < floor;

        if (movingUp) {
            emit moveUp();
        } else {
            emit moveDown();
        }
    }
}


void elevator::cabinArrived()
{
    if (state == ElevatorStateBusy) {
        emit floorChanged(cab.currentFloor());
        if (std::find(queue.begin(), queue.end(), cab.currentFloor()) != queue.end()) {
                emit openDoors();
                queue.erase(std::remove(queue.begin(), queue.end(), cab.currentFloor()), queue.end());
        }
        setState(ElevatorStateFree);
        emit(checkState());
    }
}
