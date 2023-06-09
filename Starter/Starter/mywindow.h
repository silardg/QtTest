#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>

class QPushButton;
class QIcon;
class QSize;
class QSlider;
class QProgressBar;
class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);
signals:
    void counterReached();
private:
    QPushButton *m_button;
    QIcon *m_iconMain;
    QSize *m_iconSize;
    QFont *m_fontCourier;
    QSlider *m_slider;
    QProgressBar *m_progressBar;

    int m_counter = 0;
private slots:
    void slotButtonClicked(bool status);

signals:

};

#endif // MYWINDOW_H
