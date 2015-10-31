#include "bilang.h"
#include <QFile>
#include <QDebug>

void Save_config_file(QString file_name);
void Save_config_file(QString file_name)
{
    system("rm bilang.cfg");//文件名为 a.txt 可以用“C:/a.txt”之类
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
