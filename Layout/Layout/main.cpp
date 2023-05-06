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


    QBoxLayout layoutBox(QBoxLayout::LeftToRight, &window);

    // buttons used for layoutBox
    QPushButton btn0("btn0");
    QPushButton btn1("btn1");
    QPushButton btn2("btn2");

    // inserting buttons and adding a spacing between
    layoutBox.insertWidget(0, &btn0);
    layoutBox.insertSpacing(1, 100);
    layoutBox.insertWidget(2, &btn1);
    layoutBox.insertWidget(3, &btn2);

//    QWidget::connect(&btn0, SIGNAL (clicked(bool)), &layoutBox, SLOT ());


    // showing the window
    window.show();

    return app.exec();
}
