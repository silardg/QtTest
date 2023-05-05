#include "mywindow.h"

#include <configuration.h>

#include <QPushButton>

// creates the my window class
// it takes in a parent class as qwidget
// inherits all the functions from qwidget
// passes the parent to the qwidget
MyWindow::MyWindow(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(windowMainWidth, windowMainHeight);

    m_button = new QPushButton("Testing button!", this);
}
