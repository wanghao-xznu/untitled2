#include "bilang.h"
#include <QFile>
#include <QDebug>

void Save_config_file(QString file_name);
void Save_config_file(QString file_name)
{
    QString str_cfg1 = "bilang.cfg";
    QString str_cfg2 = "bilang_2.cfg";
    QString str_cfg3 = "bilang_3.cfg";
    QString str_cfg4 = "bilang_4.cfg";
    QString str_cfg5 = "bilang_5.cfg";
    if(file_name == str_cfg1)
    {
        system("rm bilang.cfg");//文件名为 a.txt 可以用“C:/a.txt”之类
    }
    if(file_name == str_cfg2)
    {
        system("rm bilang_2.cfg");//文件名为 a.txt 可以用“C:/a.txt”之类
    }
    if(file_name == str_cfg3)
    {
        system("rm bilang_3.cfg");//文件名为 a.txt 可以用“C:/a.txt”之类
    }
    if(file_name == str_cfg4)
    {
        system("rm bilang_4.cfg");//文件名为 a.txt 可以用“C:/a.txt”之类
    }
    if(file_name == str_cfg5)
    {
        system("rm bilang_5.cfg");//文件名为 a.txt 可以用“C:/a.txt”之类
    }



    QFile file(file_name);
    file.open(QIODevice::WriteOnly);
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
        QTextStream txtOutput(&file);
        QString n1(arr_setting[i][j]);//arr_setting[][] is global
        //n1=n1.toInt();
        txtOutput << n1<<endl;
        }
    }
    file.close();
    //this->close();
}
