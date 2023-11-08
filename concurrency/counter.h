#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);


public slots:
    void countMyNumber();

public:
    bool countRestarted = false;
    int countLimit = 25;

    bool getCountRestarted() const;
    void setCountRestarted(bool newCountRestarted);

signals:
    void currentCount(int);
    void countCompleted();


};

#endif // COUNTER_H
