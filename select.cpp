#include "select.h"
#include "ui_select.h"
#include "setting.h"
#include "running.h"
#include "bilang.h"
#include <QDebug>

Select *g_select=NULL;






Select::Select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//去掉标题栏
    ui->label->setStyleSheet("QLabel {background: transparent;}");
}

Select::~Select()
{
    delete ui;
}

void Select::on_pushButton_clicked()
{
    //this->close(); DELETE ALL BUT THIS
    if(g_setting==NULL)
    {
        g_setting = new Setting;
        g_setting->show();
        g_setting->exec();
        qDebug()<<"===This is the first time come into setting!==="<<endl;
    }
    else
    {
//        g_setting->hide();
//        g_setting->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
//        g_setting->show();
//         qDebug()<<"This is the second time come into setting!"<<endl;
        delete g_setting;
        g_setting = new Setting;
        g_setting->show();
        g_setting->exec();
    }

}

void Select::on_pushButton_2_clicked()
{
    //this->close();
    if(g_running==NULL)
    {
        qDebug()<<"===before This is the first time come into running!==="<<endl;
        g_running = new Running;
        g_running->show();
        g_running->exec();
          qDebug()<<"===This is the first time come into running!==="<<endl;
    }
    else
    {
//        g_running->hide();
//        g_running->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
//        g_running->show();
//         qDebug()<<"This is the second time come into running!"<<endl;
        delete g_running;
        g_running = new Running;
        g_running->show();
        g_running->exec();
    }
}
