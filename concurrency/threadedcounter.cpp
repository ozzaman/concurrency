#include "threadedcounter.h"

ThreadedCounter::ThreadedCounter(QThread *parent)
    : QThread{parent}
{

}

void ThreadedCounter::run()
{
    for (int i = 0; i < countLimit; ++i){
        if(countRestarted){
            countRestarted = false;
            i = 0;
            qDebug() << "i sıfırlandı" << i ;
        }
        emit currentCount(i);
        qDebug() << "güncel i : " <<i;
        QThread::msleep(500);
    }
}

bool ThreadedCounter::getCountRestarted() const
{
    return countRestarted;
}

void ThreadedCounter::setCountRestarted(bool newCountRestarted)
{
    countRestarted = newCountRestarted;
}

