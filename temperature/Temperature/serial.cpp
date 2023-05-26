#include "serial.h"
#include "qobjectdefs.h"

#include <QDebug>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

/**
 * @brief serial::serial
 * @param port
 */
serial::serial(QSerialPort *port, QWidget *parent) : QWidget(parent) {

    // set the serial object
    m_serial = port;

    // connect the readyread function
    connect(m_serial, &QSerialPort::readyRead, this, &serial::readUART);
}

/**
 * @brief serial::get_ports
 * @return a string vector with the names of the ports
 */
QVector<QString> serial::get_ports() {

    // get an array of the available ports
    const auto serialPortInfos = QSerialPortInfo::availablePorts();

    // create a vector string
    QVector<QString> availablePorts;

    // loop the ports available
    for (const QSerialPortInfo &portInfo : serialPortInfos) {

        // append it
        availablePorts.append(portInfo.portName());

        // debugging
        qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());
    }

    // return the read vector strings
    return availablePorts;
}

/**
 * @brief serial::open
 * @return 1 on successful open, 0 on failed open
 */
bool serial::open() {

    // set the name from the port chosen
    m_serial->setPortName(m_port_chosen);

    // set the parameters. If they are not set to new, default is used
    // TODO be able to change these
    m_serial->setBaudRate(m_config_baud);
    m_serial->setDataBits(m_config_databits);
    m_serial->setParity(m_config_parity);
    m_serial->setStopBits(m_config_stopbit);
    m_serial->setFlowControl(m_config_flow);
    m_serial->setReadBufferSize(0);

    // try to open it
    if (m_serial->open(m_config_openMode)) {

        m_serial->setDataTerminalReady(true);

        qInfo() << "Opened port at " << m_port_chosen;

        // call the connected signal
        connected();

        return 1;
    }

    qInfo() << "Couldn't open";
    return 0;
}

/**
 * @brief serial::close
 */
void serial::close() {
    // if it is open, force close it
    if (m_serial->isOpen())
        m_serial->close();

    // set the sensor status
    m_sensorStatus = -3;

    qInfo() <<  "Closed port at " <<  m_port_chosen;
}

/**
 * @brief event_error
 * @param error
 */
void serial::event_error(QSerialPort::SerialPortError error) {
    // TODO extend this a bit
    qInfo() << "Error in the serial communication";
    close();
}

/**
 * @brief serial::readUART
 */
void serial::readUART() {
    if (m_serial->bytesAvailable() > 5) {
        rawData += m_serial->readLine();
        // TODO put this part into a separate class or file
        if (/*test.contains("[|]") && test.contains("[&]")  && */rawData.contains("\r\n")) {
            // get the \r\n down
            rawData.chop(2);
            // split the data by ,
            QStringList data = rawData.split(',');
            // debug
            qInfo() << "Temperature: " << data[1] << "Humidity: " << data[2] << "Status: " << data[0];
            // TODO set index names
            // get the temperature
            m_temperature = data[1].toFloat();
            // get the humidity
            m_humidity = data[2].toFloat();
            // get the status
            m_sensorStatus = data[0].toInt();
            // call the event
            sensorDataReceived();
            // reset the buffer
            rawData = "";
        }
    }

}

/**
 * @brief serial::getTemperature
 * @return current temperature
 */
float serial::getTemperature() {
    return m_temperature;
}

/**
 * @brief serial::getHumidity
 * @return current humidity
 */
float serial::getHumidity() {
    return m_humidity;
}

/**
 * @brief serial::getSensorStatus
 * @return sensor status
 */
int serial::getSensorStatus() {
    return m_sensorStatus;
}

/**
 * @brief serial::set_selectedPort
 * @param port
 */
void serial::set_selectedPort(QString port) {
    m_port_chosen = port;

    open();
}

/**
 * @brief serial::~serial
 */
serial::~serial() {
    // on destruction, always close it
    close();
}
