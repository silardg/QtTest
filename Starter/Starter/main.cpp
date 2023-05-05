#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QIcon>
#include <QtResource>
#include <QSize>

#include <configuration.h>

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    // added a resources file and copied the path to the logo
    QIcon iconMain(":/content/content/logo.png");
    QSize iconSize(buttonIconWidth, buttonIconHeight);

    // create an italic courier font
    QFont fontCourier("Courier", -1, -1, true);

    // create a button
    QPushButton button ("Testing button!");
    // makes it flat design
    button.setFlat(true);
    // set courier font for the button
    button.setFont(fontCourier);
    // set the icon
    button.setIcon(iconMain);
    button.setIconSize(iconSize);

    // creating a child button for the above button
    QPushButton childButton("Wee wee", &button);

    // makes the button visible - from QWidget
    // when a parent is shown, the children will be shown as well
    button.show();

    return app.exec();
}
