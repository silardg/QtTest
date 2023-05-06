#include <QApplication>

// for basic widgets and push button
#include <QPushButton>
#include <QWidget>

// line up childs horizontally/vertically
#include <QBoxLayout>

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    // create the main window in which we will place the whole project
    QWidget window(nullptr);
    window.setFixedSize(400,400);


    QPushButton btn1("btn1", &window);

    // showing the window
    window.show();

    return app.exec();
}
