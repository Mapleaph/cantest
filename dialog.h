#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QFormLayout>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QPushButton *configure_btn;
    QPushButton *open_device_btn;
    QPushButton *cls_device_btn;
    QPushButton *start_test_btn;
    QPushButton *stop_test_btn;

    QGroupBox *control_box;

    void create_control_box();


    QLineEdit *status_le;
    QLineEdit *interval_le;
    QLineEdit *baudrate_le;
    QLineEdit *ff_le;
    QLineEdit *dlc_le;
    QLineEdit *rtr_le;

    QGroupBox *can_param_box;

    void create_can_param_box();

    QLabel *can0_tx_data_lb;
    QLineEdit *can0_tx_data_le;

    QLabel *can1_tx_data_lb;
    QLineEdit *can1_tx_data_le;

    QLabel *can0_rx_data_lb;
    QLineEdit *can0_rx_data_le;

    QLabel *can1_rx_data_lb;
    QLineEdit *can1_rx_data_le;

    QLabel *can0_tx_cnt_lb;
    QLineEdit *can0_tx_cnt_le;

    QLabel *can1_tx_cnt_lb;
    QLineEdit *can1_tx_cnt_le;

    QLabel *can0_rx_cnt_lb;
    QLineEdit *can0_rx_cnt_le;

    QLabel *can1_rx_cnt_lb;
    QLineEdit *can1_rx_cnt_le;

    QLabel *can0_err_cnt_lb;
    QLineEdit *can0_err_cnt_le;

    QLabel *can1_err_cnt_lb;
    QLineEdit *can1_err_cnt_le;

    QGroupBox *test_disp_box_can0;
    QGroupBox *test_disp_box_can1;

    void create_test_disp_box_can0();

    void create_test_disp_box_can1();


};

#endif // DIALOG_H
