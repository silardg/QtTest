#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_serial(new serial(new QSerialPort(this), this))
{
    ui->setupUi(this);

    // when the scan button is clicked, call the scan function to display the current ports onto the list
    connect(ui->scanButton, SIGNAL (clicked()), this, SLOT (scan()));

    // automatically scan the list and showcase it
    scan();
}

/**
 * @brief MainWindow::scan
 */
void MainWindow::scan() {

    // clear the list on every scan
    ui->listWidget->clear();

    // get the ports available
    QVector<QString> ports;
    ports = m_serial->get_ports();

    // add each port to the list
    ui->listWidget->addItems(ports);
}

MainWindow::~MainWindow()
{
    qInfo() << "Destroy main window";
    delete ui;
}

