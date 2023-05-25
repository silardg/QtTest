#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serial.h"
#include <QListWidgetItem>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void getSensorData();
    void setTemperature(float value);
    void setHumidity(float value);

    void serialConnected();
    void serialDisconnect();
private slots:
    void scan();
    void onListClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

    serial *m_serial;
};
#endif // MAINWINDOW_H
