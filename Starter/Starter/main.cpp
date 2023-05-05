#include <QApplication>
#include <QPushButton>
#include <QFont>

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    QFont fontCourier("Courier", -1, -1, true); // create an italic courier font

    QPushButton button ("Testing button!"); // create a button
    button.setFlat(true);                   // makes it flat design
    button.setFont(fontCourier);            // set courier font for the button
    button.show();                          // makes the button visible - from QWidget

    return app.exec();
}
