#include "running.h"
#include "ui_running.h"
#include "select.h"
#include "setting.h"
#include "running_1.h"
#include "bilang.h"
#include <QDebug>

Running *g_running=NULL;

Running::Running(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Running)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//去掉标题栏
}

Running::~Running()
{
    delete ui;
}

void Running::on_pushButton_6_clicked()//back
{
    //this->close();
    if(g_select==NULL)
    {
    g_select = new Select;
    g_select->show();
    g_select->exec();
    }
    else
    {
        delete g_select;
        g_select = new Select;
        g_select->show();
        g_select->exec();

    }
}

void Running::on_pushButton_7_clicked()//setting
{
    //this->close();
    if(g_setting==NULL)
    {
    g_setting = new Setting;
    g_setting->show();
    g_setting->exec();
    }
    else
    {
        delete g_setting;
        g_setting = new Setting;
        g_setting->show();
        g_setting->exec();
    }
}

void Running::on_pushButton_clicked()
{
    //this->close();
    if(g_running_1==NULL)
    {
    g_running_1 = new Running_1;
    g_running_1->show();
    g_running_1->exec();
    }
    else
    {
        delete g_running_1;
        g_running_1 = new Running_1;
        g_running_1->show();
        g_running_1->exec();
    }
}

void Running::on_pushButton_2_clicked()
{
    if(g_running_2==NULL)
    {
    g_running_2 = new Running_2;
    g_running_2->show();
    g_running_2->exec();
    }
    else
    {
        delete g_running_1;
        g_running_2 = new Running_2;
        g_running_2->show();
        g_running_2->exec();
    }

}

void Running::on_pushButton_3_clicked()
{
    if(g_running_3==NULL)
    {
    g_running_3 = new Running_3;
    g_running_3->show();
    g_running_3->exec();
    }
    else
    {
        delete g_running_1;
        g_running_3 = new Running_3;
        g_running_3->show();
        g_running_3->exec();
    }
}

void Running::on_pushButton_4_clicked()
{
    if(g_running_4==NULL)
    {
    g_running_4 = new Running_4;
    g_running_4->show();
    g_running_4->exec();
    }
    else
    {
        delete g_running_4;
        g_running_4 = new Running_4;
        g_running_4->show();
        g_running_4->exec();
    }
}

void Running::on_pushButton_5_clicked()
{
    if(g_running_5==NULL)
    {
    g_running_5 = new Running_5;
    g_running_5->show();
    g_running_5->exec();
    }
    else
    {
        delete g_running_5;
        g_running_5 = new Running_5;
        g_running_5->show();
        g_running_5->exec();
    }
}
