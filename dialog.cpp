#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QGridLayout *main_layout = new QGridLayout;

    create_control_box();
    create_can_param_box();
    create_test_disp_box_can0();
    create_test_disp_box_can1();

    main_layout->addWidget(control_box, 0, 0, 1, 1);
    main_layout->addWidget(can_param_box, 1, 0, 1, 1);
    main_layout->addWidget(test_disp_box_can0, 2, 0, 1, 1);
    main_layout->addWidget(test_disp_box_can1, 3, 0, 1, 1);


    // centering the dialog by default
    QRect screen_rec = QApplication::desktop()->screenGeometry();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), screen_rec));

    setLayout(main_layout);

    setWindowTitle(tr("CAN Port Test"));

    // set fixed size
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    setSizeGripEnabled(false);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::create_control_box()
{
    configure_btn = new QPushButton(tr("Configure"));
    open_device_btn = new QPushButton(tr("Open Device"));
    cls_device_btn = new QPushButton(tr("Close Device"));
    start_test_btn = new QPushButton(tr("Start Test"));
    stop_test_btn = new QPushButton(tr("Stop Test"));

    control_box = new QGroupBox;

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(configure_btn, 0, 0, 1, 1);
    layout->addWidget(open_device_btn, 0, 1, 1, 1);
    layout->addWidget(cls_device_btn, 0, 2, 1, 1);
    layout->addWidget(start_test_btn, 0, 3, 1, 1);
    layout->addWidget(stop_test_btn, 0, 4, 1, 1);

    control_box->setLayout(layout);

}

void Dialog::create_can_param_box()
{

    status_le = new QLineEdit;
    interval_le = new QLineEdit;
    baudrate_le = new QLineEdit;
    ff_le = new QLineEdit;
    dlc_le = new QLineEdit;
    rtr_le = new QLineEdit;

    can_param_box = new QGroupBox(tr("CAN Params"));

    QFormLayout *layout1 = new QFormLayout;
    QFormLayout *layout2 = new QFormLayout;
    QFormLayout *layout3 = new QFormLayout;
    QGridLayout *layout = new QGridLayout;


    layout1->addRow(tr("Status"), status_le);
    layout1->addRow(tr("FF"), ff_le);
    layout1->setLabelAlignment(Qt::AlignRight);

    layout2->addRow(tr("Interval(ms)"), interval_le);
    layout2->addRow(tr("DLC"), dlc_le);
    layout2->setLabelAlignment(Qt::AlignRight);

    layout3->addRow(tr("Baudrate(kbps)"), baudrate_le);
    layout3->addRow(tr("RTR"), rtr_le);
    layout3->setLabelAlignment(Qt::AlignRight);


    layout->addLayout(layout1, 0, 0, 1, 1);
    layout->addLayout(layout2, 0, 1, 1, 1);
    layout->addLayout(layout3, 0, 2, 1, 1);

    can_param_box->setLayout(layout);


}

void Dialog::create_test_disp_box_can0()
{

    can0_tx_data_lb = new QLabel(tr("Tx Data"));
    can0_rx_data_lb = new QLabel(tr("Rx Data"));
    can0_tx_cnt_lb = new QLabel(tr("Tx Count"));
    can0_rx_cnt_lb = new QLabel(tr("Rx Count"));
    can0_err_cnt_lb = new QLabel(tr("Error Count"));

    can0_tx_data_lb->setAlignment(Qt::AlignRight);
    can0_rx_data_lb->setAlignment(Qt::AlignRight);
    can0_tx_cnt_lb->setAlignment(Qt::AlignRight);
    can0_rx_cnt_lb->setAlignment(Qt::AlignRight);
    can0_err_cnt_lb->setAlignment(Qt::AlignRight);

    can0_tx_data_le = new QLineEdit;
    can0_rx_data_le = new QLineEdit;
    can0_tx_cnt_le = new QLineEdit;
    can0_rx_cnt_le = new QLineEdit;
    can0_err_cnt_le = new QLineEdit;

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(can0_tx_data_lb, 0, 0, 1, 1);
    layout->addWidget(can0_tx_data_le, 0, 1, 1, 30);
    layout->addWidget(can0_rx_data_lb, 1, 0, 1, 1);
    layout->addWidget(can0_rx_data_le, 1, 1, 1, 30);
    layout->addWidget(can0_tx_cnt_lb, 2, 0, 1, 1);
    layout->addWidget(can0_tx_cnt_le, 2, 1, 1, 1);
    layout->addWidget(can0_rx_cnt_lb, 3, 0, 1, 1);
    layout->addWidget(can0_rx_cnt_le, 3, 1, 1, 1);
    layout->addWidget(can0_err_cnt_lb, 4, 0, 1, 1);
    layout->addWidget(can0_err_cnt_le, 4, 1, 1, 1);


    test_disp_box_can0 = new QGroupBox(tr("CAN0"));

    test_disp_box_can0->setLayout(layout);

}

void Dialog::create_test_disp_box_can1()
{

    can1_tx_data_lb = new QLabel(tr("Tx Data"));
    can1_rx_data_lb = new QLabel(tr("Rx Data"));
    can1_tx_cnt_lb = new QLabel(tr("Tx Count"));
    can1_rx_cnt_lb = new QLabel(tr("Rx Count"));
    can1_err_cnt_lb = new QLabel(tr("Error Count"));

    can1_tx_data_lb->setAlignment(Qt::AlignRight);
    can1_rx_data_lb->setAlignment(Qt::AlignRight);
    can1_tx_cnt_lb->setAlignment(Qt::AlignRight);
    can1_rx_cnt_lb->setAlignment(Qt::AlignRight);
    can1_err_cnt_lb->setAlignment(Qt::AlignRight);

    can1_tx_data_le = new QLineEdit;
    can1_rx_data_le = new QLineEdit;
    can1_tx_cnt_le = new QLineEdit;
    can1_rx_cnt_le = new QLineEdit;
    can1_err_cnt_le = new QLineEdit;

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(can1_tx_data_lb, 0, 0, 1, 1);
    layout->addWidget(can1_tx_data_le, 0, 1, 1, 30);
    layout->addWidget(can1_rx_data_lb, 1, 0, 1, 1);
    layout->addWidget(can1_rx_data_le, 1, 1, 1, 30);
    layout->addWidget(can1_tx_cnt_lb, 2, 0, 1, 1);
    layout->addWidget(can1_tx_cnt_le, 2, 1, 1, 1);
    layout->addWidget(can1_rx_cnt_lb, 3, 0, 1, 1);
    layout->addWidget(can1_rx_cnt_le, 3, 1, 1, 1);
    layout->addWidget(can1_err_cnt_lb, 4, 0, 1, 1);
    layout->addWidget(can1_err_cnt_le, 4, 1, 1, 1);


    test_disp_box_can1 = new QGroupBox(tr("CAN1"));

    test_disp_box_can1->setLayout(layout);

}
