#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>

class QPushButton;
class QIcon;
class QSize;
class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);
private:
    QPushButton *m_button;
    QIcon *m_iconMain;
    QSize *m_iconSize;
    QFont *m_fontCourier;

signals:

};

#endif // MYWINDOW_H
