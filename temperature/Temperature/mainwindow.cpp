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

    // when there is sensor data received, we will send a signal
    connect(m_serial, &serial::sensorDataReceived, this, &MainWindow::getSensorData);

    // connect the serial connected function to signal that we have connected
    // this is used to enable the disable button
    connect(m_serial, &serial::connected, this, &MainWindow::serialConnected);

    // connect the disconnect button to a function
    connect(ui->disconnectButton, &QPushButton::clicked, this, &MainWindow::serialDisconnect);

    // automatically scan the list and showcase it
    scan();

    // default
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

    // depending on the sensor status, we write values
    switch(m_serial->getSensorStatus()) {
    case 0: {
        // as its a temperature, we add the celsius
        // TODO add conversion between celsius and the american way
        ui->temperatureLabel->setText(QString::number(value) + "°");
        // set the value of the knob/tab
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
    case -3: {
        ui->temperatureLabel->setText("0.0°");
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
    //TODO setTemperature and setHumidity has most of the same code, we can create an optimization here

    // depending on the sensor status, we write values
    switch(m_serial->getSensorStatus()) {
    case 0: {
        // as its a temperature, we add the celsius
        // TODO add conversion between celsius and the american way
        ui->humidityLabel->setText(QString::number(value) + "%");
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
    case -3: {
        ui->humidityLabel->setText("0.0%");
        ui->humidityTab->setValue(0.0f);
        break;
    }
    }
}

/**
 * @brief MainWindow::serialDisconnect
 */
void MainWindow::serialDisconnect() {
    // when the disconnect button is clicked
    // force close serial and disable the button
    // TODO check if it was really disconnected
    m_serial->close();
    ui->disconnectButton->setDisabled(true);

    // update the UI
    getSensorData();
}

/**
 * @brief MainWindow::serialConnected
 */
void MainWindow::serialConnected() {
    // enable the disconnect button
    ui->disconnectButton->setDisabled(false);
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
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

