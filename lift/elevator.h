#ifndef elevator_H
#define elevator_H

#include <QObject>
#include <QTextEdit>
#include <QTimer>
#include <QQueue>
#include <QLabel>

#include "cabin.h"


using namespace std;

class elevator : public QObject
{
    Q_OBJECT
    enum ElevatorState
    {
        ElevatorStateBusy,
        ElevatorStateFree,
    };
public:
    elevator();
    void updateState();
    void add_floor(int floor)
    {
        if (floor > 0 && floor < 9 && std::find(queue.begin(), queue.end(), floor) == queue.end()) {
            queue.push_back(floor);
        }
    }

private:
    void setState(ElevatorState state);
    cabin cab;
    std::vector<int> queue;
    ElevatorState state;

public slots:
    void floorButtonPressed(int floor);
    void cabinArrived();
signals:
    void moveUp();
    void moveDown();
    void openDoors();
    void checkState();
    void stateTextChanged(QString stateText);
    void cabinStateTextChanged(QString stateText);
    void doorsStateTextChanged(QString stateText);
    void floorChanged(int floor);
};

#endif // elevator_H
