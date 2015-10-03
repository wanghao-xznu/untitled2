#ifndef SELECT_H
#define SELECT_H

#include <QDialog>

namespace Ui {
class Select;
}

class Select : public QDialog
{
    Q_OBJECT

public:
    explicit Select(QWidget *parent = 0);
    ~Select();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Select *ui;
};

#endif // SELECT_H
