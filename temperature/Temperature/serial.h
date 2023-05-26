#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QWidget>

#include <QVector>

class serial : public QWidget
{
    Q_OBJECT
public:

    serial(QSerialPort *port = nullptr, QWidget *parent = nullptr);
    ~serial();

    bool open();
    void close();
    QVector<QString> get_ports();
    void set_selectedPort(QString port);

    float getTemperature();
    float getHumidity();
    int getSensorStatus();

private:
    // store the serial object
    QSerialPort *m_serial = nullptr;

    // the port info that is being used
    QString m_port_chosen;

    int m_config_baud = 460800;// QSerialPort::Baud9600;
    QSerialPort::DataBits m_config_databits = QSerialPort::Data8;
    QSerialPort::Parity m_config_parity = QSerialPort::NoParity;
    QSerialPort::StopBits m_config_stopbit = QSerialPort::OneStop;
    QSerialPort::FlowControl m_config_flow = QSerialPort::HardwareControl;
    QIODevice::OpenModeFlag m_config_openMode = QIODevice::ReadWrite;

    QString rawData;

    float m_temperature, m_humidity;
    int m_sensorStatus = -3;

public slots:
    void event_error(QSerialPort::SerialPortError error);
    void readUART();

signals:
    void sensorDataReceived();
    void connected();


};

#endif // SERIAL_H
