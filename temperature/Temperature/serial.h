#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QVector>

class serial
{
public:
    serial(QSerialPort *port);
    ~serial();

    bool open();
    void close();
private:
    // store the serial object
    QSerialPort *m_serial = nullptr;

    // the port info that is being used
    QSerialPortInfo m_port_chosen;

    // default is 9600
    int m_config_baud = QSerialPort::Baud9600;
    QSerialPort::DataBits m_config_databits = QSerialPort::Data8;
    QSerialPort::Parity m_config_parity = QSerialPort::EvenParity;
    QSerialPort::StopBits m_config_stopbit = QSerialPort::OneStop;
    QSerialPort::FlowControl m_config_flow = QSerialPort::NoFlowControl;
    QIODevice::OpenModeFlag m_config_openMode = QIODevice::ReadWrite;

};

#endif // SERIAL_H
