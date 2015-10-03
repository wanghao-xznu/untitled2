#include "setting.h"
#include "ui_setting.h"
#include "select.h"
#include "running.h"
//#include "setting_11.h"
#include "setting_1.h"

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_pushButton_6_clicked()//back
{
    this->close();
    Select select;
    select.show();
    select.exec();
}

void Setting::on_pushButton_7_clicked()//running
{
    this->close();
    Running running;
    running.show();
    running.exec();
}

void Setting::on_pushButton_clicked()//the first experiment应该将cfg文件中的内容装载进去
{
    this->close();
    Setting_1 setting_1;
    setting_1.show();
    setting_1.exec();

}

void Setting::on_pushButton_2_clicked()
{

}
