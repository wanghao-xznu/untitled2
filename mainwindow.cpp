#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "select.h"

#include "bilang.h"
MainWindow *g_mianwindow=NULL;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),//QMainWindow
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //this->deleteLater(); if not NULL DELETE
    if(g_select==NULL)
    {
        //this->hide();
        g_select = new Select;
        g_select->show();
        g_select->exec();
    }
    else
    {
        g_select->hide();
        g_select->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
        g_select->show();
    }

}
