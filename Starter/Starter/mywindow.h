#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>

class QPushButton;
class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);
private:
    QPushButton *m_button;

signals:

};

#endif // MYWINDOW_H
