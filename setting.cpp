#include "setting.h"
#include "ui_setting.h"
#include "select.h"
#include "running.h"
#include "setting_1.h"
#include "setting_2.h"
#include <QDebug>
#include "bilang.h"

Setting *g_setting=NULL;

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//去掉标题栏
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_pushButton_6_clicked()//back
{
    //this->close();
    if(g_select==NULL)
    {
        //this->hide();
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
        //this->hide();
        qDebug()<<"This is the second time come into select!"<<endl;
    }
}

void Setting::on_pushButton_7_clicked()//running
{
    //this->close();
    if(g_running==NULL)
    {
    g_running = new Running;
    g_running->show();
    g_running->exec();
    }
    else
    {
        delete g_running;
        g_running = new Running;
        g_running->show();
        g_running->exec();
        qDebug()<<"This is the second time come into running!"<<endl;
    }
}

void Setting::on_pushButton_clicked()//the first experiment应该将cfg文件中的内容装载进去
{
    //this->close();//g_setting_1
    if(g_setting_1==NULL)
    {
    g_setting_1 = new Setting_1;
    g_setting_1->show();
    g_setting_1->exec();
    }
    else
    {
        delete g_setting_1;
        g_setting_1 = new Setting_1;
        g_setting_1->show();
        g_setting_1->exec();
        qDebug()<<"This is the second time come into setting_1!"<<endl;
    }

}

void Setting::on_pushButton_2_clicked()
{
    if(g_setting_2==NULL)
    {
    g_setting_2 = new Setting_2;
    g_setting_2->show();
    g_setting_2->exec();
    }
    else
    {
        delete g_setting_2;
        g_setting_2 = new Setting_2;
        g_setting_2->show();
        g_setting_2->exec();
        qDebug()<<"This is the second time come into setting_1!"<<endl;
    }


}

void Setting::on_pushButton_3_clicked()
{
    if(g_setting_3==NULL)
    {
    g_setting_3 = new Setting_3;
    g_setting_3->show();
    g_setting_3->exec();
    }
    else
    {
        delete g_setting_1;
        g_setting_3 = new Setting_3;
        g_setting_3->show();
        g_setting_3->exec();
        qDebug()<<"This is the second time come into setting_1!"<<endl;
    }

}

void Setting::on_pushButton_4_clicked()
{
    if(g_setting_4==NULL)
    {
    g_setting_4 = new Setting_4;
    g_setting_4->show();
    g_setting_4->exec();
    }
    else
    {
        delete g_setting_4;
        g_setting_4 = new Setting_4;
        g_setting_4->show();
        g_setting_4->exec();
        qDebug()<<"This is the second time come into setting_1!"<<endl;
    }

}

void Setting::on_pushButton_5_clicked()
{
    if(g_setting_4==NULL)
    {
    g_setting_4 = new Setting_4;
    g_setting_4->show();
    g_setting_4->exec();
    }
    else
    {
        delete g_setting_4;
        g_setting_4 = new Setting_4;
        g_setting_4->show();
        g_setting_4->exec();
        qDebug()<<"This is the second time come into setting_1!"<<endl;
    }

}
