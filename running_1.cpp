#include "running_1.h"
#include "ui_running_1.h"
#include "running.h"
#include <QTimer>
#include <QFile>
#include <QDebug>
#include "bilang.h"
//###############
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <QMessageBox>

#include <termio.h>//serial add just now
//###############

Running_1 *g_running_1=NULL;

int gobal=100;
int temp11;
int temp12;
int temp21;
int temp22;
int temp31;
int temp32;
int temp41;
int temp42;
int temp51;
int temp52;
int duanwei=1;//尽量不要使用全局变量
extern QString arr_setting[5][6];
void Running_1::Page_init()
{
    temp11=arr_setting[0][1].toInt();
    temp12=arr_setting[0][2].toInt();
    temp21=arr_setting[1][1].toInt();
    temp22=arr_setting[1][2].toInt();
    temp31=arr_setting[2][1].toInt();
    temp32=arr_setting[2][2].toInt();
    temp41=arr_setting[3][1].toInt();
    temp42=arr_setting[3][2].toInt();
    temp51=arr_setting[4][1].toInt();
    temp52=arr_setting[4][2].toInt();
    duanwei=1;
    receive_count=10;
    ui->lcdNumber->display(temp11);
    ui->lcdNumber_6->display(temp12);
    ui->lcdNumber_3->display(duanwei);
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    ui->lcdNumber_6->setMode(QLCDNumber::Dec);


}

Running_1::Running_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Running_1)
{
    QFile file("bilang.cfg");
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

    ui->setupUi(this);
#if 0
    ui->lcdNumber->display(100);
    //设置晶体管控件QLCDNumber能显示的位数
    //ui->lcdNumber->setDigitCount(10);
    //设置显示的模式为十进制
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    //新建一个QTimer对象
    timer = new QTimer();
    //设置定时器每个多少毫秒发送一个timeout()信号
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
#endif
    //    temp11=arr_setting[0][1].toInt();
    //    temp12=arr_setting[0][2].toInt();
    //    temp21=arr_setting[1][1].toInt();
    //    temp22=arr_setting[1][2].toInt();
    //    temp31=arr_setting[2][1].toInt();
    //    temp32=arr_setting[2][2].toInt();
    //    temp41=arr_setting[3][1].toInt();
    //    temp42=arr_setting[3][2].toInt();
    //    temp51=arr_setting[4][1].toInt();
    //    temp52=arr_setting[4][2].toInt();
    //    ui->lcdNumber->display(temp11);
    //    ui->lcdNumber_6->display(temp12);
    //    ui->lcdNumber->setMode(QLCDNumber::Dec);
    //    ui->lcdNumber_6->setMode(QLCDNumber::Dec);
        Page_init();
            open_serial();


    //新建一个QTimer对象
    timer = new QTimer();
    //设置定时器每个多少毫秒发送一个timeout()信号
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//去掉标题栏
}
int Running_1::open_serial()
{
    const char *devName = "/dev/ttySAC3";
    m_fd = ::open(devName, O_RDWR|O_NONBLOCK);
    if (m_fd < 0) {
        qDebug()<<"can't open ttySAC3"<<endl;
        return -1;
    }
    termios serialAttr;
    memset(&serialAttr, 0, sizeof serialAttr);
    serialAttr.c_iflag = IGNPAR;
    serialAttr.c_cflag = B9600 | HUPCL | CS8 | CREAD | CLOCAL;
    serialAttr.c_cc[VMIN] = 1;
    if (tcsetattr(m_fd, TCSANOW, &serialAttr) != 0) {
            return -1;
    }
    m_notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read, this);
    connect (m_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming_serial()));
    return 0;
}
void Running_1::close_serial()//close
{
    ::close(m_fd);
}
bool Running_1::send_serial(QString str)
{
    ::write(m_fd, str.toLatin1(), str.length());

    return 0;
}
void get_current_temp_and_power(char)
{

}

 void Running_1::remoteDataIncoming_serial()
 {
     char c;
     if (read(m_fd, &c, sizeof c) != 1) {
         QMessageBox::warning(this, tr("Error"), tr("Receive error!"));
         return;
     }
              qDebug()<<QString(QChar(c));

              if(c == '#'){
                  //QMessageBox::warning(this, tr("Error"), tr("Receive error!"));//only tgest warning
                  //begin count
                  receive_count=0;
              }
              if(receive_count<7){
                   temper_and_power[receive_count]=c;
                   receive_count++;
              }
              if(receive_count==7){
                  receive_count=10;
                  current_power[0]=temper_and_power[1];
                   current_power[1]=temper_and_power[2];
                   current_power[2]=temper_and_power[3];
                    current_power[3]='\0';
                    QString temp_power = current_power;
                     current_temperature[0]=temper_and_power[4];
                     current_temperature[1]=temper_and_power[5];
                     current_temperature[2]=temper_and_power[6];
                     current_temperature[3]='\0';
                     QString temp_temperature = current_temperature;
                     //qDebug()<<current_power;

                     //ui->lcdNumber_9->display(current_power);
                     ui->lcdNumber_9->display(temp_power.toInt());
                     //qDebug()<<current_temperature;
                     //ui->lcdNumber_8->display(current_temperature);
                     ui->lcdNumber_8->display(temp_temperature.toInt());

              }

 }

void Running_1::onTimerOut()
{
     ui->lcdNumber_3->display(duanwei);
    switch (duanwei)
    {
        case 1:
                    if(temp12!=0){
                        ui->lcdNumber_6->display(--temp12);
                        ui->lcdNumber->display(temp11);
                    }
                    else{
                        if(temp11!=0){
                            ui->lcdNumber->display(--temp11);
                            temp12=60;
                            ui->lcdNumber_6->display(--temp12);

                        }
                        else{//分和秒都为0
                            //timer->stop();
                            //应该装载下一次，并且段位加一
                            duanwei++;
                            //send duanwei 2 cmd
                            on_pushButton_clicked();

                        }
                    }
                    break;
        case 2:
                    if(temp22!=0){
                        ui->lcdNumber_6->display(--temp22);
                        ui->lcdNumber->display(temp21);
                    }
                    else{
                        if(temp21!=0){
                            ui->lcdNumber->display(--temp21);
                            temp22=60;
                            ui->lcdNumber_6->display(--temp22);

                        }
                        else{//分和秒都为0
                            //timer->stop();
                            //应该装载下一次，并且段位加一
                            duanwei++;
                            //send duanwei 3 cmd
                            on_pushButton_clicked();
                        }
                    }
                    break;
        case 3:
                    if(temp32!=0){
                        ui->lcdNumber_6->display(--temp32);
                        ui->lcdNumber->display(temp31);
                    }
                    else{
                        if(temp31!=0){
                            ui->lcdNumber->display(--temp31);
                            temp32=60;
                            ui->lcdNumber_6->display(--temp32);

                        }
                        else{//分和秒都为0
                            //timer->stop();
                            //应该装载下一次，并且段位加一
                            duanwei++;
                            //send duanwwei 4 cmd
                            on_pushButton_clicked();
                        }
                    }
                    break;
        case 4:
                    if(temp42!=0){
                        ui->lcdNumber_6->display(--temp42);
                        ui->lcdNumber->display(temp41);
                    }
                    else{
                        if(temp41!=0){
                            ui->lcdNumber->display(--temp41);
                            temp42=60;
                            ui->lcdNumber_6->display(--temp42);

                        }
                        else{//分和秒都为0
                            //timer->stop();
                            //应该装载下一次，并且段位加一
                            duanwei++;
                            //send duanwei 5 cmd
                            on_pushButton_clicked();
                        }
                    }
                    break;
        case 5:
                    if(temp52!=0){
                        ui->lcdNumber_6->display(--temp52);
                        ui->lcdNumber->display(temp51);
                    }
                    else{
                        if(temp51!=0){
                            ui->lcdNumber->display(--temp51);
                            temp52=60;
                            ui->lcdNumber_6->display(--temp52);

                        }
                        else{//分和秒都为0
                            //timer->stop();
                            //应该装载下一次，并且段位加一
                            //duanwei++;
                            //send stop CMD
                            timer->stop();
                            qDebug()<<"Game over";
                        }
                    }
                    break;
    default:
        break;

    }


}

Running_1::~Running_1()
{
    delete ui;
}

void Running_1::on_pushButton_4_clicked()//返回按钮
{
    duanwei=1;
    timer->stop();
    send_serial("STP");
   //close_serial();
    //this->close();
    if(g_running==NULL)
    {
    g_running = new Running ;
    g_running->show();
    g_running->exec();
    }
    else
    {
        delete g_running;
        g_running = new Running ;
        g_running->show();
        g_running->exec();
    }
}

void Running_1::on_pushButton_clicked()//开始运行button
{
    //启动定时器
       //从display中得到value,发送出去//严格意义上讲不要发送时间，功率和温度就行
       timer->start();
       switch (duanwei)
       {
           case 1:
           //send arr_setting[0][0] arr_setting[0][3]
               qDebug()<<"START:Temperature"+arr_setting[0][0]+"Power"+arr_setting[0][3];
               //send_serial("START:Temperature"+arr_setting[0][0]+"Power"+arr_setting[0][3]);
               send_serial("STA");
               if(arr_setting[0][0].length()==3){
                   send_serial(arr_setting[0][0]);
               }
               else if(arr_setting[0][0].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[0][0]);
               }
               else if(arr_setting[0][0].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[0][0]);
               }


               if(arr_setting[0][3].length()==3){
                   send_serial(arr_setting[0][3]);
               }
               else if(arr_setting[0][3].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[0][3]);
               }
               else if(arr_setting[0][3].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[0][3]);
               }


               //send_serial("STA"+arr_setting[0][0]+arr_setting[0][3]);
               break;
           case 2:
               qDebug()<<"START:Temperature"+arr_setting[1][0]+"Power"+arr_setting[1][3];
               //send_serial("START:Temperature"+arr_setting[1][0]+"Power"+arr_setting[1][3]);
               send_serial("STA");
               if(arr_setting[1][0].length()==3){
                   send_serial(arr_setting[1][0]);
               }
               else if(arr_setting[1][0].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[1][0]);
               }
               else if(arr_setting[1][0].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[1][0]);
               }


               if(arr_setting[1][3].length()==3){
                   send_serial(arr_setting[1][3]);
               }
               else if(arr_setting[1][3].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[1][3]);
               }
               else if(arr_setting[1][3].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[1][3]);
               }
               break;
           case 3:
               qDebug()<<"START:Temperature"+arr_setting[2][0]+"Power"+arr_setting[2][3];
               //send_serial("START:Temperature"+arr_setting[2][0]+"Power"+arr_setting[2][3]);
               send_serial("STA");
               if(arr_setting[2][0].length()==3){
                   send_serial(arr_setting[2][0]);
               }
               else if(arr_setting[2][0].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[2][0]);
               }
               else if(arr_setting[2][0].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[2][0]);
               }


               if(arr_setting[2][3].length()==3){
                   send_serial(arr_setting[2][3]);
               }
               else if(arr_setting[2][3].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[2][3]);
               }
               else if(arr_setting[2][3].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[2][3]);
               }
               break;
           case 4:
               qDebug()<<"START:Temperature"+arr_setting[3][0]+"Power"+arr_setting[3][3];
               //send_serial("START:Temperature"+arr_setting[3][0]+"Power"+arr_setting[3][3]);
               send_serial("STA");
               if(arr_setting[3][0].length()==3){
                   send_serial(arr_setting[3][0]);
               }
               else if(arr_setting[3][0].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[3][0]);
               }
               else if(arr_setting[3][0].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[3][0]);
               }


               if(arr_setting[3][3].length()==3){
                   send_serial(arr_setting[3][3]);
               }
               else if(arr_setting[3][3].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[3][3]);
               }
               else if(arr_setting[3][3].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[3][3]);
               }
               break;
           case 5:
               qDebug()<<"START:Temperature"+arr_setting[4][0]+"Power"+arr_setting[4][3];
               //send_serial("START:Temperature"+arr_setting[4][0]+"Power"+arr_setting[4][3]);
               send_serial("STA");
               if(arr_setting[4][0].length()==3){
                   send_serial(arr_setting[4][0]);
               }
               else if(arr_setting[4][0].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[4][0]);
               }
               else if(arr_setting[4][0].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[4][0]);
               }


               if(arr_setting[4][3].length()==3){
                   send_serial(arr_setting[4][3]);
               }
               else if(arr_setting[4][3].length()==2){
                   send_serial("0");
                   send_serial(arr_setting[4][3]);
               }
               else if(arr_setting[4][3].length()==1){
                   send_serial("00");
                   send_serial(arr_setting[4][3]);
               }
               break;
           default:
               break;
       }

}
void Running_1::on_pushButton_2_clicked()//暂停运行button
{
    //停止定时器
    timer->stop();
    send_serial("STP");
    qDebug()<<"PAUSE";
}

void Running_1::on_pushButton_3_clicked()
{
    //终止
    timer->stop();
    qDebug()<<"STOP";
    send_serial("STP");
    Page_init();
}
