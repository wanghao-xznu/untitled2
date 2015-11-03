#include "numkeyboard.h"
#include "ui_numkeyboard.h"
#include "bilang.h"

NumKeyBoard::NumKeyBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumKeyBoard)
{

    ui->setupUi(this);
    ui->lineEdit->setText("0");
    //this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit->setAlignment(Qt::AlignRight);
    ui->lineEdit->setMaxLength(15);

    if(flag_num == 'T')
        ui->label->setText("TestTest");

    switch (flag_num)
    {
        case 'T':
            ui->label->setText("0~500");
            break;
        case 'M':
            ui->label->setText("0~999");
            break;
        case 'S':
            ui->label->setText("0~59");
            break;
        case 'P':
            ui->label->setText("50~999");
            break;
        default:
            break;
    }

    QFont font = ui->lineEdit->font();
    font.setPointSize(font.pointSize() + 8);
    ui->lineEdit->setFont(font);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);//OnTopHint

}

NumKeyBoard::~NumKeyBoard()
{
    delete ui;
}

void NumKeyBoard::on_pushButton_clicked()//num1
{
    int digitValue = ui->pushButton->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));
}

void NumKeyBoard::on_pushButton_2_clicked()//num2
{
    int digitValue = ui->pushButton_2->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_3_clicked()//num3
{
    int digitValue = ui->pushButton_3->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_6_clicked()//num4
{
    int digitValue = ui->pushButton_6->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_5_clicked()//num5
{
    int digitValue = ui->pushButton_5->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_8_clicked()//num6
{
    int digitValue = ui->pushButton_8->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_10_clicked()//num7
{
    int digitValue = ui->pushButton_10->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_9_clicked()//num8
{
    int digitValue = ui->pushButton_9->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_12_clicked()//num9
{
    int digitValue = ui->pushButton_12->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_13_clicked()//num0
{
    int digitValue = ui->pushButton_13->text().toInt();
    if (ui->lineEdit->text() == "0"){
        ui->lineEdit->setText(QString::number(digitValue));
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));

}

void NumKeyBoard::on_pushButton_11_clicked()//num ENTER//发送edit的结果到setting
                                            //全局变量传递消息，如何更新上一层
{
     //ui->lineEdit->setText("####");
     //setting_11.pushButton_2->setText("####");
    this->close();
}
QString NumKeyBoard::returnValue()

{
    exec();
    //return inputBuf;
    return ui->lineEdit->text();
}//keyboard.cpp返回输入值

void NumKeyBoard::on_pushButton_4_clicked()//clear == CLR
{
    ui->lineEdit->setText("0");
}

void NumKeyBoard::on_pushButton_7_clicked()//delete ==DEL
{
    QString text = ui->lineEdit->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
    }
    ui->lineEdit->setText(text);
}
