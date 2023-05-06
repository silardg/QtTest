#include <QApplication>

// for basic widgets and push button
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QLabel>

// line up childs horizontally/vertically
#include <QBoxLayout>

#include <QFormLayout>

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    // create the main window in which we will place the whole project
    QWidget window(nullptr);
    window.setFixedSize(400,400);


    /*QBoxLayout layoutBox(QBoxLayout::LeftToRight, &window);

    // buttons used for layoutBox
    QPushButton btn0("btn0");
    QPushButton btn1("btn1");
    QPushButton btn2("btn2");

    // inserting buttons and adding a spacing between
    layoutBox.insertWidget(0, &btn0);
    layoutBox.insertSpacing(1, 100);
    layoutBox.insertWidget(2, &btn1);
    layoutBox.insertWidget(3, &btn2);

//    QWidget::connect(&btn0, SIGNAL (clicked(bool)), &layoutBox, SLOT ());*/

    // ---------------------------------------------------------------------------------------


    QFormLayout *formLayout = new QFormLayout(&window);

    QLabel *label = new QLabel(QString("label1"));
    QLabel *label2 = new QLabel(QString("label2"));

    // we can also use grid layout for this, but extra code needed
    formLayout->addRow(label, label2);
    formLayout->setSpacing(100);


    // showing the window
    window.show();

    return app.exec();
}
