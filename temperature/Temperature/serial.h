#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>

class serial
{
public:
    serial(QSerialPort *port);
    ~serial();
private:
    QSerialPort *m_serial = nullptr;
};

#endif // SERIAL_H
