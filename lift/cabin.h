#ifndef cabin_H
#define cabin_H

#include <QObject>
#include <QTextEdit>
#include <QTimer>
#include <QQueue>
#include <QLabel>

#include "doors.h"


class cabin : public QObject
{
    Q_OBJECT
    enum CabinState
    {
        CabinStateGoingUp,
        CabinStateGoingDown,
        CabinStateWaiting,
        CabinStateOpening,
        CabinStateClosing
    };
public:
    cabin();
    int currentFloor();
    void updateState();
    int get_time_moving_up();
    int get_time_moving_dawn();
    int get_time_floor_waiting();

private:
    void setState(CabinState state);
    doors door;
    CabinState st;
    int floor;
    static constexpr int TIME_MOVING_UP = 1000;
    static constexpr int TIME_MOVING_DAWN = 1000;
    static constexpr int TIME_FLOOR_WAITING = 1000;
    QTimer TimeMoving;
    QTimer TimeFloorWaiting;

public slots:
    void moveUp();
    void moveDown();
    void openDoors();
    void closeDoors();
    void arrive();

signals:
    void startOpening();
    void startClosing();
    void opened();
    void closed();
    void arrived();
    void arriving();
    void stateTextChanged(QString stateText);
    void doorsStateTextChanged(QString stateText);
};

#endif // cabin_H
