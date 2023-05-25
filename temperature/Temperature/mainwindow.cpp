#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_serial(new serial(new QSerialPort(this), this))
{
    ui->setupUi(this);

    // when the scan button is clicked, call the scan function to display the current ports onto the list
    connect(ui->scanButton, SIGNAL (clicked()), this, SLOT (scan()));

    // when an item is clicked, it is forwarded to the function
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListClicked(QListWidgetItem*)));


    connect(m_serial, &serial::sensorDataReceived, this, &MainWindow::getSensorData);

    // automatically scan the list and showcase it
    scan();

    setTemperature(0.0);
    setHumidity(0.0);

}

/**
 * @brief MainWindow::getSensorData
 */
void MainWindow::getSensorData() {
    // get the temperature and humidity values, the newest
    float temp = m_serial->getTemperature();
    float hum = m_serial->getHumidity();

    // set the values onto the UI
    setTemperature(temp);
    setHumidity(hum);
}

/**
 * @brief MainWindow::setTemperature
 * @param value
 */
void MainWindow::setTemperature(float value) {

    switch(m_serial->getSensorStatus()) {
    case 0: {
        ui->temperatureLabel->setText(QString::number(value) + "°");
        ui->temperatureTab->setValue(int(value));
        break;
    }
    case -1: {
        ui->temperatureLabel->setText("ChkSum");
        ui->temperatureTab->setValue(0.0f);
        break;
    }
    case -2: {
        ui->temperatureLabel->setText("Timeout");
        ui->temperatureTab->setValue(0.0f);
        break;
    }
    }
}

/**
 * @brief MainWindow::setHumidity
 * @param value
 */
void MainWindow::setHumidity(float value) {

    switch(m_serial->getSensorStatus()) {
    case 0: {
        ui->humidityLabel->setText(QString::number(value) + "°");
        ui->humidityTab->setValue(int(value));
        break;
    }
    case -1: {
        ui->humidityLabel->setText("ChkSum");
        ui->humidityTab->setValue(0.0f);
        break;
    }
    case -2: {
        ui->humidityLabel->setText("Timeout");
        ui->humidityTab->setValue(0.0f);
        break;
    }
    }
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

/**
 * @brief MainWindow::onListClicked
 * @param item
 */
void MainWindow::onListClicked(QListWidgetItem *item) {
    // close in case there is another one open
    m_serial->close();

    // set the variable for the port name
    m_serial->set_selectedPort(item->text());

    // open it
    if(m_serial->open()) {
        // move onto the next window

    } else {
        // error
        qInfo() << "Couldn't open it!";
    }
}

MainWindow::~MainWindow()
{
    qInfo() << "Destroy main window";
    delete ui;
}

