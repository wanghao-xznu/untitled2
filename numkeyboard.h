#ifndef NUMKEYBOARD_H
#define NUMKEYBOARD_H

#include <QDialog>

namespace Ui {
class NumKeyBoard;
}

class NumKeyBoard : public QDialog
{
    Q_OBJECT

public:
    explicit NumKeyBoard(QWidget *parent = 0);
    ~NumKeyBoard();
    QString returnValue();//keyboard.h声明
    QString inputBuf;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

//private:
public:
    Ui::NumKeyBoard *ui;
};

#endif // NUMKEYBOARD_H
