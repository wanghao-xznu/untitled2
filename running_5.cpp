#include "running_5.h"
#include "ui_running_5.h"
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

Running_5 *g_running_5=NULL;


extern QString arr_setting[5][6];
void Running_5::Page_init()
{
    temp10=arr_setting[0][0].toInt();
    temp11=arr_setting[0][1].toInt();
    temp12=arr_setting[0][2].toInt();
    temp13=arr_setting[0][3].toInt();
    temp20=arr_setting[1][0].toInt();
    temp21=arr_setting[1][1].toInt();
    temp22=arr_setting[1][2].toInt();
    temp23=arr_setting[1][3].toInt();
    temp30=arr_setting[2][0].toInt();
    temp31=arr_setting[2][1].toInt();
    temp32=arr_setting[2][2].toInt();
    temp33=arr_setting[2][3].toInt();
    temp41=arr_setting[3][0].toInt();
    temp41=arr_setting[3][1].toInt();
    temp42=arr_setting[3][2].toInt();
    temp42=arr_setting[3][3].toInt();
    temp51=arr_setting[4][0].toInt();
    temp51=arr_setting[4][1].toInt();
    temp52=arr_setting[4][2].toInt();
    temp52=arr_setting[4][3].toInt();
    duanwei=1;
    receive_count=10;
    ui->lcdNumber->display(temp11);
    ui->lcdNumber_6->display(temp12);

    ui->lcdNumber_2->display(temp11);
    ui->lcdNumber_7->display(temp12);

    ui->lcdNumber_3->display(duanwei);
    ui->lcdNumber_4->display(temp10);
    ui->lcdNumber_5->display(temp13);
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    ui->lcdNumber_2->setMode(QLCDNumber::Dec);
    ui->lcdNumber_3->setMode(QLCDNumber::Dec);
    ui->lcdNumber_4->setMode(QLCDNumber::Dec);
    ui->lcdNumber_5->setMode(QLCDNumber::Dec);
    ui->lcdNumber_6->setMode(QLCDNumber::Dec);
    ui->lcdNumber_7->setMode(QLCDNumber::Dec);
    flag_00 = 1;
    flag_10 = 1;
    flag_20 = 1;
    flag_30 = 1;
    flag_40 = 1;

}

Running_5::Running_5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Running_5)
{
    QFile file("bilang_5.cfg");
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
    Page_init();
    open_serial();


    //新建一个QTimer对象
    timer = new QTimer();
    //设置定时器每个多少毫秒发送一个timeout()信号
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//去掉标题栏
}
int Running_5::open_serial()
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
void Running_5::close_serial()//close
{
    ::close(m_fd);
}
bool Running_5::send_serial(QString str)
{
    ::write(m_fd, str.toLatin1(), str.length());

    return 0;
}

 void Running_5::remoteDataIncoming_serial()
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
                     temp_power = current_power;
                     current_temperature[0]=temper_and_power[4];
                     current_temperature[1]=temper_and_power[5];
                     current_temperature[2]=temper_and_power[6];
                     current_temperature[3]='\0';
                     temp_temperature = current_temperature;
                     //qDebug()<<current_power;

                     //ui->lcdNumber_9->display(current_power);
                     ui->lcdNumber_9->display(temp_power.toInt());
                     //qDebug()<<current_temperature;
                     //ui->lcdNumber_8->display(current_temperature);
                     ui->lcdNumber_8->display(temp_temperature.toInt());

              }

 }

void Running_5::onTimerOut()
{
    int reach_time=0;
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
                           ui->lcdNumber_4->display(temp20);//temperature
                           ui->lcdNumber_5->display(temp23);//power
                           //send duanwei 2 cmd
                           on_pushButton_clicked();

                       }
                   }
                   if((temp_temperature.toInt()>=arr_setting[0][0].toInt())&&flag_00)
                   {
                       flag_00 = 0;
                       reach_time = 60*arr_setting[0][1].toInt() + arr_setting[0][2].toInt() - temp11*60 - temp12;
                       arr_setting[0][4] = QString::number(reach_time/60);
                       arr_setting[0][5] = QString::number(reach_time%60);
                       Save_config_file("bilang_5.cfg");
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
                           ui->lcdNumber_4->display(temp30);//temperature
                           ui->lcdNumber_5->display(temp33);//power
                           //send duanwei 3 cmd
                           on_pushButton_clicked();
                       }
                   }
                   if((temp_temperature.toInt()>=arr_setting[1][0].toInt())&&flag_10)
                   {
                       flag_10 = 0;
                       reach_time = 60*arr_setting[1][1].toInt() + arr_setting[1][2].toInt() - temp21*60 - temp22;
                       arr_setting[1][4] = QString::number(reach_time/60);
                       arr_setting[1][5] = QString::number(reach_time%60);
                       Save_config_file("bilang_5.cfg");
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
                           ui->lcdNumber_4->display(temp40);//temperature
                           ui->lcdNumber_5->display(temp43);//power
                           //send duanwwei 4 cmd
                           on_pushButton_clicked();
                       }
                   }
                   if((temp_temperature.toInt()>=arr_setting[2][0].toInt())&&flag_20)
                   {
                       flag_20 = 0;
                       reach_time = 60*arr_setting[2][1].toInt() + arr_setting[2][2].toInt() - temp31*60 - temp32;
                       arr_setting[2][4] = QString::number(reach_time/60);
                       arr_setting[2][5] = QString::number(reach_time%60);
                       Save_config_file("bilang_5.cfg");
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
                           ui->lcdNumber_4->display(temp50);//temperature
                           ui->lcdNumber_5->display(temp53);//power
                           //send duanwei 5 cmd
                           on_pushButton_clicked();
                       }
                   }
                   if((temp_temperature.toInt()>=arr_setting[3][0].toInt())&&flag_30)
                   {
                       flag_30 = 0;
                       reach_time = 60*arr_setting[3][1].toInt() + arr_setting[3][2].toInt() - temp41*60 - temp42;
                       arr_setting[3][4] = QString::number(reach_time/60);
                       arr_setting[3][5] = QString::number(reach_time%60);
                       Save_config_file("bilang_5.cfg");
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
                   if((temp_temperature.toInt()>=arr_setting[4][0].toInt())&&flag_40)
                   {
                       flag_40 = 0;
                       reach_time = 60*arr_setting[4][1].toInt() + arr_setting[4][2].toInt() - temp51*60 - temp52;
                       arr_setting[4][4] = QString::number(reach_time/60);
                       arr_setting[4][5] = QString::number(reach_time%60);
                       Save_config_file("bilang_5.cfg");
                   }
                   break;
   default:
       break;

   }



}

Running_5::~Running_5()
{
    delete ui;
}

void Running_5::on_pushButton_4_clicked()//返回按钮
{
    duanwei=1;
    timer->stop();
    send_serial("STP");
    close_serial();
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

void Running_5::on_pushButton_clicked()//开始运行button
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
void Running_5::on_pushButton_2_clicked()//暂停运行button
{
    //停止定时器
    timer->stop();
    send_serial("STP");
    qDebug()<<"PAUSE";
}

void Running_5::on_pushButton_3_clicked()
{
    //终止
    timer->stop();
    qDebug()<<"STOP";
    send_serial("STP");
    Page_init();
}
