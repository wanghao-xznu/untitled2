#include "setting_11.h"
#include "ui_setting_11.h"
#include "numkeyboard.h"
#include "setting.h"
#include "calculator.h"

Setting_11::Setting_11(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_11)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

Setting_11::~Setting_11()
{
    delete ui;
}

void Setting_11::on_pushButton_2_clicked()
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_2->setText(ret);

}

void Setting_11::on_pushButton_clicked()//保存按钮
{
    this->close();
    Setting setting;
    setting.show();
    setting.exec();
}
