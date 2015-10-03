#ifndef RUNNING_H
#define RUNNING_H

#include <QDialog>

namespace Ui {
class Running;
}

class Running : public QDialog
{
    Q_OBJECT

public:
    explicit Running(QWidget *parent = 0);
    ~Running();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

private:
    Ui::Running *ui;
};

#endif // RUNNING_H
