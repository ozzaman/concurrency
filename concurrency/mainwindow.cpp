#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myDialog = new Dialog(this);
    myCounter = new Counter(nullptr);
    myCountThread = new QThread(this);
    mythreadedCounter = new ThreadedCounter(nullptr);

    QObject::connect(ui->MainTask1Btn, &QPushButton::clicked, this, &MainWindow::onMainTask1BtnClicked);
    QObject::connect(ui->MainTask2Btn, &QPushButton::clicked, this, &MainWindow::onMainTask2BtnClicked);
    QObject::connect(myDialog->ui->subtask1Btn, &QPushButton::clicked, [=](){ui->lcdNumber->display(29);});
//    QObject::connect(myCounter, &Counter::currentCount, [=](int num){ui->lcdNumber->display(num);} );
    QObject::connect(myCounter, &Counter::currentCount, this, &MainWindow::litLCD1);
    QObject::connect(mythreadedCounter, &ThreadedCounter::currentCount, this, &MainWindow::litLCD4);
    QObject::connect(ui->showMsg1Btn, &QPushButton::clicked, this, &MainWindow::onshowMsg1BtnClicked);
    QObject::connect(ui->showMsg2Btn, &QPushButton::clicked, this, &MainWindow::onshowMsg2BtnClicked);
    QObject::connect(myCountThread, &QThread::started, myCounter, &Counter::countMyNumber, Qt::QueuedConnection);
//    QObject::connect(myCounter, &Counter::countCompleted, myCountThread, &QThread::finished);
    QObject::connect(this, &MainWindow::restartMyCounter, myCounter, &Counter::setCountRestarted);
    QObject::connect(this, &MainWindow::restartMyThreadedCounter, mythreadedCounter, &ThreadedCounter::setCountRestarted);

    myCounter->moveToThread(myCountThread);
    myCountThread->start();
    mythreadedCounter->start();

}

MainWindow::~MainWindow()
{
    delete ui;
    myCountThread->terminate();
}

void MainWindow::on_showdialogBtn_clicked()
{
    myDialog->show();
}


void MainWindow::onMainTask1BtnClicked()
{
    if(myCountThread->isRunning()){
        myCountThread->terminate();
        emit restartMyCounter(true);
        myCountThread->start();
    }
}

void MainWindow::litLCD1(int num)
{
    ui->lcdNumber->display(num);

}

void MainWindow::litLCD4(int num)
{
    ui->lcdNumber4->display(num);
}


void MainWindow::onshowMsg1BtnClicked()
{
    ui->lcdNumber2->display(18);
}

void MainWindow::onshowMsg2BtnClicked()
{
    ui->lcdNumber2->display(81);
}

void MainWindow::onMainTask2BtnClicked()
{
    if(mythreadedCounter->isRunning()){
        mythreadedCounter->terminate();
        emit restartMyThreadedCounter(true);
        mythreadedCounter->start();
    }
}

