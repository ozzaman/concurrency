#ifndef THREADEDCOUNTER_H
#define THREADEDCOUNTER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class ThreadedCounter : public QThread
{
    Q_OBJECT
public:
    explicit ThreadedCounter(QThread *parent = nullptr);

public:
    int countLimit = 25;
    bool countRestarted = false;

    bool getCountRestarted() const;
    void setCountRestarted(bool newCountRestarted);

signals:
    void currentCount(int);

    // QThread interface
protected:
    void run();
};

#endif // THREADEDCOUNTER_H
