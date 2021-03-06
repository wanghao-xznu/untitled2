#ifndef RUNNING_1_H
#define RUNNING_1_H

#include <QDialog>
#include <qsocketnotifier.h>


namespace Ui {
class Running_1;
}

class Running_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Running_1(QWidget *parent = 0);
    ~Running_1();

private slots:
    void on_pushButton_4_clicked();
    void onTimerOut();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void remoteDataIncoming_serial();

private:

    void Page_init();
    void get_current_temp_and_power(char);

private:
    Ui::Running_1 *ui;
    QTimer *timer;
    int open_serial();
    void close_serial();
    bool send_serial(QString);

private:
    int m_fd;
    char current_temperature[4];
    char current_power[4];
    QString temp_power;
    QString temp_temperature;
    char temper_and_power[7];
    int receive_count;//can not little than 4
    QSocketNotifier *m_notifier;
};

#endif // RUNNING_1_H
