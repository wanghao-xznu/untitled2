#include "setting_3.h"
#include "ui_setting_3.h"
#include "numkeyboard.h"
#include "setting.h"
#include <QFile>

#include <QDebug>
#include "bilang.h"

Setting_3 *g_setting_3=NULL;

extern QString arr_setting[5][6];

void Setting_3::load_cfg()
{
    QFile file("bilang_3.cfg");
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text)) {
            qDebug()<<"Can't open the file!"<<endl;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            QByteArray line = file.readLine();//每次都把换行符读了进来，烦人
            //QByteArray line = file.read(10);
            QString str(line);
            str=str.left(str.length() - 1);
            arr_setting[i][j]=str;
            qDebug()<< str;
        }
    }
    file.close();
     ui->pushButton_2->setText(arr_setting[0][0]);
     ui->pushButton_7->setText(arr_setting[0][1]);
     ui->pushButton_8->setText(arr_setting[0][2]);
     ui->pushButton_17->setText(arr_setting[0][3]);
     ui->pushButton_18->setText(arr_setting[0][4]);
     ui->pushButton_19->setText(arr_setting[0][5]);
     ui->pushButton_3->setText(arr_setting[1][0]);
     ui->pushButton_9->setText(arr_setting[1][1]);
     ui->pushButton_10->setText(arr_setting[1][2]);
     ui->pushButton_20->setText(arr_setting[1][3]);
     ui->pushButton_24->setText(arr_setting[1][4]);
     ui->pushButton_25->setText(arr_setting[1][5]);
     ui->pushButton_4->setText(arr_setting[2][0]);
     ui->pushButton_11->setText(arr_setting[2][1]);
     ui->pushButton_12->setText(arr_setting[2][2]);
     ui->pushButton_21->setText(arr_setting[2][3]);
     ui->pushButton_26->setText(arr_setting[2][4]);
     ui->pushButton_27->setText(arr_setting[2][5]);
     ui->pushButton_5->setText(arr_setting[3][0]);
     ui->pushButton_13->setText(arr_setting[3][1]);
     ui->pushButton_14->setText(arr_setting[3][2]);
     ui->pushButton_22->setText(arr_setting[3][3]);
     ui->pushButton_28->setText(arr_setting[3][4]);
     ui->pushButton_29->setText(arr_setting[3][5]);
     ui->pushButton_6->setText(arr_setting[4][0]);
     ui->pushButton_15->setText(arr_setting[4][1]);
     ui->pushButton_16->setText(arr_setting[4][2]);
     ui->pushButton_23->setText(arr_setting[4][3]);
     ui->pushButton_30->setText(arr_setting[4][4]);
     ui->pushButton_31->setText(arr_setting[4][5]);


}

Setting_3::Setting_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting_3)
{
    ui->setupUi(this);//在这里应该装载文件cfg文件内容
    load_cfg();
    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//去掉标题栏
}

Setting_3::~Setting_3()
{
    delete ui;
}

void Setting_3::on_pushButton_clicked()//only save
{
    system("rm bilang_3.cfg");//文件名为 a.txt 可以用“C:/a.txt”之类
    QFile file("bilang_3.cfg");
    file.open(QIODevice::WriteOnly);
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
        QTextStream txtOutput(&file);
        QString n1(arr_setting[i][j]);
        //n1=n1.toInt();
        txtOutput << n1<<endl;
        }
    }
    file.close();
    //this->close();

}

void Setting_3::on_pushButton_2_clicked()//1
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=500){
        ret = "500";
        ui->pushButton_2->setText("500");
    }
    else{
        ui->pushButton_2->setText(ret);
    }
    arr_setting[0][0]=ret;//下表弄错了，明天注意修改

}


void Setting_3::on_pushButton_7_clicked()//2
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=999){
        ret = "999";
        ui->pushButton_7->setText("999");
    }
    else{
        ui->pushButton_7->setText(ret);
    }
    ui->pushButton_7->setText(ret);
    arr_setting[0][1]=ret;

}

void Setting_3::on_pushButton_8_clicked()//3
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=59){
        ret = "59";
        ui->pushButton_8->setText("59");
    }
    else{
        ui->pushButton_8->setText(ret);
    }
    ui->pushButton_8->setText(ret);
    arr_setting[0][2]=ret;
}

void Setting_3::on_pushButton_17_clicked()//4
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=9999){
        ret = "9999";
        ui->pushButton_17->setText("9999");
    }
    else{
        ui->pushButton_17->setText(ret);
    }
    ui->pushButton_17->setText(ret);
    arr_setting[0][3]=ret;
}

void Setting_3::on_pushButton_18_clicked()//5
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_18->setText(ret);
    arr_setting[0][4]=ret;
}

void Setting_3::on_pushButton_19_clicked()//6
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_19->setText(ret);
    arr_setting[0][5]=ret;
}

void Setting_3::on_pushButton_3_clicked()//7
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=500){
        ret = "500";
        ui->pushButton_3->setText("500");
    }
    else{
        ui->pushButton_3->setText(ret);
    }
    ui->pushButton_3->setText(ret);
    arr_setting[1][0]=ret;
}

void Setting_3::on_pushButton_9_clicked()//8
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=999){
        ret = "999";
        ui->pushButton_9->setText("999");
    }
    else{
        ui->pushButton_9->setText(ret);
    }
    ui->pushButton_9->setText(ret);
    arr_setting[1][1]=ret;
}

void Setting_3::on_pushButton_10_clicked()//9
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=59){
        ret = "59";
        ui->pushButton_10->setText("59");
    }
    else{
        ui->pushButton_10->setText(ret);
    }
    ui->pushButton_10->setText(ret);
    arr_setting[1][2]=ret;
}

void Setting_3::on_pushButton_20_clicked()//10
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=9999){
        ret = "9999";
        ui->pushButton_20->setText("9999");
    }
    else{
        ui->pushButton_20->setText(ret);
    }
    ui->pushButton_20->setText(ret);
    arr_setting[1][3]=ret;
}

void Setting_3::on_pushButton_24_clicked()//11
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_24->setText(ret);
    arr_setting[1][4]=ret;
}

void Setting_3::on_pushButton_25_clicked()//12
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_25->setText(ret);
    arr_setting[1][5]=ret;
}

void Setting_3::on_pushButton_4_clicked()//13
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=500){
        ret = "500";
        ui->pushButton_4->setText("500");
    }
    else{
        ui->pushButton_4->setText(ret);
    }
    ui->pushButton_4->setText(ret);
    arr_setting[2][0]=ret;
}

void Setting_3::on_pushButton_11_clicked()//14
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=999){
        ret = "999";
        ui->pushButton_11->setText("999");
    }
    else{
        ui->pushButton_11->setText(ret);
    }
    ui->pushButton_11->setText(ret);
    arr_setting[2][1]=ret;
}

void Setting_3::on_pushButton_12_clicked()//15
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=59){
        ret = "59";
        ui->pushButton_12->setText("59");
    }
    else{
        ui->pushButton_12->setText(ret);
    }
    ui->pushButton_12->setText(ret);
    arr_setting[2][2]=ret;
}

void Setting_3::on_pushButton_21_clicked()//16
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=9999){
        ret = "9999";
        ui->pushButton_21->setText("9999");
    }
    else{
        ui->pushButton_21->setText(ret);
    }
    ui->pushButton_21->setText(ret);
    arr_setting[2][3]=ret;
}

void Setting_3::on_pushButton_26_clicked()//17
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_26->setText(ret);
    arr_setting[2][4]=ret;
}

void Setting_3::on_pushButton_27_clicked()//18
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_27->setText(ret);
    arr_setting[2][5]=ret;
}

void Setting_3::on_pushButton_5_clicked()//19
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=500){
        ret = "500";
        ui->pushButton_5->setText("500");
    }
    else{
        ui->pushButton_5->setText(ret);
    }
    ui->pushButton_5->setText(ret);
    arr_setting[3][0]=ret;
}

void Setting_3::on_pushButton_13_clicked()//20
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=999){
        ret = "999";
        ui->pushButton_13->setText("999");
    }
    else{
        ui->pushButton_13->setText(ret);
    }
    ui->pushButton_13->setText(ret);
    arr_setting[3][1]=ret;
}

void Setting_3::on_pushButton_14_clicked()//21
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=59){
        ret = "59";
        ui->pushButton_14->setText("59");
    }
    else{
        ui->pushButton_14->setText(ret);
    }
    ui->pushButton_14->setText(ret);
    arr_setting[3][2]=ret;
}

void Setting_3::on_pushButton_22_clicked()//22
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=9999){
        ret = "9999";
        ui->pushButton_22->setText("9999");
    }
    else{
        ui->pushButton_22->setText(ret);
    }
    ui->pushButton_22->setText(ret);
    arr_setting[3][3]=ret;
}

void Setting_3::on_pushButton_28_clicked()//23
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_28->setText(ret);
    arr_setting[3][4]=ret;
}

void Setting_3::on_pushButton_29_clicked()//24
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_29->setText(ret);
    arr_setting[3][5]=ret;
}

void Setting_3::on_pushButton_6_clicked()//25
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=500){
        ret = "500";
        ui->pushButton_6->setText("500");
    }
    else{
        ui->pushButton_6->setText(ret);
    }
    ui->pushButton_6->setText(ret);
    arr_setting[4][0]=ret;
}

void Setting_3::on_pushButton_15_clicked()//26
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=999){
        ret = "999";
        ui->pushButton_15->setText("999");
    }
    else{
        ui->pushButton_15->setText(ret);
    }
    ui->pushButton_15->setText(ret);
    arr_setting[4][1]=ret;
}

void Setting_3::on_pushButton_16_clicked()//27
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=59){
        ret = "59";
        ui->pushButton_16->setText("59");
    }
    else{
        ui->pushButton_16->setText(ret);
    }
    ui->pushButton_16->setText(ret);
    arr_setting[4][2]=ret;
}

void Setting_3::on_pushButton_23_clicked()//28
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    if(ret.toInt()>=999){
        ret = "999";
        ui->pushButton_23->setText("999");
    }
    else{
        ui->pushButton_23->setText(ret);
    }
    ui->pushButton_23->setText(ret);
    arr_setting[4][3]=ret;
}

void Setting_3::on_pushButton_30_clicked()
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_30->setText(ret);
    arr_setting[4][4]=ret;
}

void Setting_3::on_pushButton_31_clicked()
{
    NumKeyBoard numkeyboard;
    //numkeyboard.show();
    //numkeyboard.exec();
    ret=numkeyboard.returnValue();
    ui->pushButton_31->setText(ret);
    arr_setting[4][5]=ret;
}

void Setting_3::on_pushButton_33_clicked() //back
{
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
