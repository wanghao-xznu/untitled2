#ifndef SETTING_11_H
#define SETTING_11_H

#include <QDialog>

namespace Ui {
class Setting_11;
}

class Setting_11 : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_11(QWidget *parent = 0);
    ~Setting_11();
    QString ret;//这是一个返回值

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Setting_11 *ui;
};

#endif // SETTING_11_H
