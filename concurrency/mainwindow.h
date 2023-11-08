#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "dialog.h"
#include "counter.h"
#include "threadedcounter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showdialogBtn_clicked();

    void onMainTask1BtnClicked();
    void litLCD1(int);
    void litLCD4(int);

    void onshowMsg1BtnClicked();
    void onshowMsg2BtnClicked();

    void onMainTask2BtnClicked();

signals:
    void restartMyCounter(bool);
    void restartMyThreadedCounter(bool);


private:
    Ui::MainWindow *ui;
    Dialog *myDialog;
    Counter *myCounter;
    QThread *myCountThread;
    ThreadedCounter *mythreadedCounter;
};
#endif // MAINWINDOW_H
