#include "running.h"
#include "ui_running.h"
#include "select.h"
#include "setting.h"
#include "running_1.h"

Running::Running(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Running)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

Running::~Running()
{
    delete ui;
}

void Running::on_pushButton_6_clicked()//back
{
    this->close();
    Select select;
    select.show();
    select.exec();
}

void Running::on_pushButton_7_clicked()//setting
{
    this->close();
    Setting setting;
    setting.show();
    setting.exec();
}

void Running::on_pushButton_clicked()
{
    this->close();
    Running_1 running_1;
    running_1.show();
    running_1.exec();
}
