#include "mywindow.h"

#include <configuration.h>

#include <QPushButton>
#include <QFont>
#include <QIcon>
#include <QtResource>
#include <QSize>

#include <QApplication>

// creates the my window class
// it takes in a parent class as qwidget
// inherits all the functions from qwidget
// passes the parent to the qwidget
MyWindow::MyWindow(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(windowMainWidth, windowMainHeight);

    // added a resources file and copied the path to the logo
    m_iconMain = new QIcon(pathIcon);
    m_iconSize = new QSize(buttonIconWidth, buttonIconHeight);

    // create an italic courier font
    m_fontCourier = new QFont("Courier", -1, -1, true);

    // create a button
    // set the parent as the main window
    m_button = new QPushButton("Testing button!", this);
    // makes it flat design
    m_button->setFlat(true);
    // set courier font for the button
    m_button->setFont(*m_fontCourier);
    // set the icon
    m_button->setIcon(*m_iconMain);
    m_button->setIconSize(*m_iconSize);
    // set its position and size
    m_button->setGeometry(windowMainWidth/4, windowMainHeight/4, buttonWidth, buttonHeight);

    // this uses the connect function from QObject
    // uses m_button->clicked() function as a SIGNAL
    // it sends that SIGNAL to the QApplication instance, which calls the callback quit
    connect(m_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}
