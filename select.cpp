#include "select.h"
#include "ui_select.h"
#include "setting.h"
#include "running.h"

Select::Select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

Select::~Select()
{
    delete ui;
}

void Select::on_pushButton_clicked()
{
    this->close();
    Setting setting;
    setting.show();
    setting.exec();

}

void Select::on_pushButton_2_clicked()
{
    this->close();
    Running running;
    running.show();
    running.exec();
}
