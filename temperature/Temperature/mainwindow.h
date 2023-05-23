#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serial.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class serial;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    serial *m_serial;
};
#endif // MAINWINDOW_H
