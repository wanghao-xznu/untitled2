#ifndef SETTING_4_H
#define SETTING_4_H

#include <QDialog>

namespace Ui {
class Setting_4;
}

class Setting_4 : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_4(QWidget *parent = 0);
    ~Setting_4();
    QString ret;//这是一个返回值



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();


    void on_pushButton_8_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

private:
    Ui::Setting_4 *ui;
    void load_cfg();
};

#endif // SETTING_4_H
