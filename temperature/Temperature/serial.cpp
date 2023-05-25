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

    m_serial = port;

    connect(m_serial, &QSerialPort::readyRead, this, &serial::readUART);
}

/**
 * @brief serial::get_ports
 * @return a string vector with the names of the ports
 */
QVector<QString> serial::get_ports() {

    const auto serialPortInfos = QSerialPortInfo::availablePorts();

    QVector<QString> availablePorts;

    for (const QSerialPortInfo &portInfo : serialPortInfos) {

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

void serial::readUART() {

    if (m_serial->bytesAvailable() > 5) {
        rawData += m_serial->readLine();
        if (/*test.contains("[|]") && test.contains("[&]")  && */rawData.contains("\r\n")) {
            // get the \r\n down
            rawData.chop(2);
            QStringList data = rawData.split(',');
            qInfo() << "Temperature: " << data[1] << "Humidity: " << data[2] << "Status: " << data[0];
            m_temperature = data[1].toFloat();
            m_humidity = data[2].toFloat();
            m_sensorStatus = data[0].toInt();
            sensorDataReceived();
            rawData = "";
        }
    }

}

float serial::getTemperature() {
    return m_temperature;
}

float serial::getHumidity() {
    return m_humidity;
}

int serial::getSensorStatus() {
    return m_sensorStatus;
}

void serial::set_selectedPort(QString port) {
    m_port_chosen = port;
}

serial::~serial() {
    // on destruction, always close it
    close();
}
