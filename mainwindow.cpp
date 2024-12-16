#include "mainwindow.h"
#include "ui_mainwindow.h"
#define Motor_PIN 1
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiSetup () ;;
    pinMode (Motor_PIN, PWM_OUTPUT);
    pwmWrite (Motor_PIN, 0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(Start()));  //Read & Incubator Block Temp Display

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     timer->start(1000);
}

void MainWindow::Start()
{
    int Val = ui->lineEdit->text().toInt();
    pwmWrite (Motor_PIN, Val);
    digitalWrite(Motor_PIN ,HIGH);
    delay(1000);
    digitalWrite(Motor_PIN ,LOW);
    delay(1000);
}

void MainWindow::on_pushButton_2_clicked()
{
    pwmWrite (Motor_PIN, 0);
    digitalWrite(Motor_PIN ,LOW);
    timer->stop();
}
