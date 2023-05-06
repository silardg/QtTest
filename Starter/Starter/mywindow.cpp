#include "mywindow.h"

#include <configuration.h>

#include <QPushButton>
#include <QFont>
#include <QIcon>
#include <QtResource>
#include <QSize>
#include <QProgressBar>
#include <QSlider>

#include <QApplication>

// creates the my window class
// it takes in a parent class as qwidget
// inherits all the functions from qwidget
// passes the parent to the qwidget
MyWindow::MyWindow(QWidget *parent)
    : QWidget{parent}
{
    // setting the size of the window, fixed!
    setFixedSize(windowMainWidth, windowMainHeight);

    /*
     *  Setting up the button
     */

    // added a resources file and copied the path to the logo
    m_iconMain = new QIcon(pathIcon);
    m_iconSize = new QSize(buttonIconWidth, buttonIconHeight);

    // create an italic courier font
    m_fontCourier = new QFont("Courier", -1, -1, true);

    // create a button
    // set the parent as the main window
    m_button = new QPushButton("Quit app!", this);
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

    // End of button setup

    /*
     *  Setting up the slider and progress bar
     */

    // create new slider and assign it to this window
    m_slider = new QSlider(Qt::Horizontal, this);
    // set the min and max range
    m_slider->setRange(0, 100);
    // set the starting value
    m_slider->setValue(0);
    // set the geometry same as for the button
    m_slider->setGeometry(windowMainWidth/4, windowMainHeight/2, sliderProgressWidth, sliderProgressHeight);

    // create new progress and assign it to this window
    // has all the same parameters as the slider
    m_progressBar = new QProgressBar(this);
    m_progressBar->setRange(0, 100);
    m_progressBar->setValue(0);
    m_progressBar->setGeometry(windowMainWidth/4, windowMainHeight-100, sliderProgressWidth, sliderProgressHeight);

    // connecting the slider and the progressbar together
    // m_slider->valueChanged() -> the signal
    // m_progressBar->setValue() -> the slot
    connect(m_slider, SIGNAL (valueChanged(int)), m_progressBar, SLOT (setValue(int)));

    // End of slider and progress bar setup


}
