#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>
#include <QTimer>

class doors : public QObject
{
    Q_OBJECT
    enum DoorState
    {
        DoorStateOpen,
        DoorStateClosed,
        DoorStateOpening,
        DoorStateClosing
    };

public:
    doors();
    bool isOpen();
    void updateState();
    int get_time_opening();
    int get_time_closing();

private:
    void setState(DoorState state);

    DoorState st;
    static constexpr int TIME_OPENING = 1000;
    static constexpr int TIME_CLOSING = 1000;
    QTimer TimerOpening;
    QTimer TimerClosing;

public slots:
  void opening();
  void closing();
  void opened();
  void closed();

signals:
  void open();
  void close();
  void alreadyOpened();
  void alreadyClosed();
  void stateTextChanged(QString stateText);
};

#endif // DOORS_H
