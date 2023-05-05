#include <QApplication>


#include <configuration.h>

#include <mywindow.h>

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    MyWindow window;
    window.show();

    return app.exec();
}
