#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "select.h"

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
    this->close();
    Select select;
    select.show();
    //this->close();
    select.exec();
    //this->close();

}
