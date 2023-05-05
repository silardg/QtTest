#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QIcon>
#include <QtResource>
#include <QSize>
#include <QWidget>

#include <configuration.h>

#include <mywindow.h>

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    MyWindow window;
    window.show();

//    QWidget mainWindow;
//    mainWindow.setFixedSize(windowMainWidth, windowMainHeight);

//    // added a resources file and copied the path to the logo
//    QIcon iconMain(":/content/content/logo.png");
//    QSize iconSize(buttonIconWidth, buttonIconHeight);

//    // create an italic courier font
//    QFont fontCourier("Courier", -1, -1, true);

//    // create a button
//    // set the parent as the main window
//    QPushButton button ("Testing button!", &mainWindow);
//    // makes it flat design
//    button.setFlat(true);
//    // set courier font for the button
//    button.setFont(fontCourier);
//    // set the icon
//    button.setIcon(iconMain);
//    button.setIconSize(iconSize);
//    // set its position and size
//    button.setGeometry(windowMainWidth/4, windowMainHeight/4, buttonWidth, buttonHeight);

//    // makes the button visible - from QWidget
//    mainWindow.show();

    return app.exec();
}
