#include "serial.h"

#include <QDebug>

/**
 * @brief serial::serial
 * @param port
 */
serial::serial(QSerialPort *port) {
    m_serial = port;

    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    qDebug() << serialPortInfos.size();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
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

    // testing hardcoded
    m_port_chosen = serialPortInfos[0];
    open();
}

/**
 * @brief serial::open
 * @return 1 on successful open, 0 on failed open
 */
bool serial::open() {

    // set the name from the port chosen
    m_serial->setPortName(m_port_chosen.portName());

    // set the parameters. If they are not set to new, default is used
    m_serial->setBaudRate(m_config_baud);
    m_serial->setDataBits(m_config_databits);
    m_serial->setParity(m_config_parity);
    m_serial->setStopBits(m_config_stopbit);
    m_serial->setFlowControl(m_config_flow);

    // try to open it
    if (m_serial->open(m_config_openMode)) {
        qInfo() << "Opened port at " << m_port_chosen.portName();
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

    qInfo() <<  "Closed port at " <<  m_port_chosen.portName();
}

//void serial::readAll() {

//}

//void serial::error() {

//}

serial::~serial() {
    // on destruction, always close it
    close();
}
