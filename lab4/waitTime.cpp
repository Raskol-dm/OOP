#include "waitTime.h"

void wait_time(int sec)
{
    QTime dieTime= QTime::currentTime().addMSecs(sec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1200);


}
