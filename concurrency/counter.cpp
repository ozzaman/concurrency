#include "counter.h"

Counter::Counter(QObject *parent)
{

}

void Counter::countMyNumber()
{

    for (int i = 0; i < countLimit; ++i) {
        if(countRestarted){
            countRestarted = false;
            i = 0;
            qDebug() << "i sıfırlandı" << i;
        }
        emit currentCount(i);
        qDebug() << "güncel i" << i;
        QThread::msleep(500);
    }

    emit countCompleted();
}


bool Counter::getCountRestarted() const
{
    return countRestarted;
}

void Counter::setCountRestarted(bool newCountRestarted)
{
    countRestarted = newCountRestarted;
}
