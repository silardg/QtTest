#include <QApplication>

// for basic widgets and push button
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QRect>

#include <QLineEdit>

// line up childs horizontally/vertically
#include <QBoxLayout>
// create forms
#include <QFormLayout>
// create the grid
#include <QGridLayout>

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    // create the main window in which we will place the whole project
    QWidget window1(nullptr);
    window1.setFixedSize(300,300);

    // create the layout box with the configuration of up to down
    QBoxLayout *layoutBox = new QBoxLayout(QBoxLayout::Up, &window1);

    // buttons used for layoutBox
    QPushButton btn0("btn0");
    QPushButton btn1("btn1");
    QPushButton btn2("btn2");

    // inserting buttons and adding a spacing between
    layoutBox->insertWidget(0, &btn0);
    layoutBox->insertSpacing(1, 100);
    layoutBox->insertWidget(2, &btn1);
    layoutBox->insertWidget(3, &btn2);

    // ---------------------------------------------------------------------------------------

    QWidget window2(nullptr);
    window2.setFixedSize(300,300);

    // create the form layout
    QFormLayout *formLayout = new QFormLayout(&window2);

    // create the labels for the form
    QLabel *label = new QLabel(QString("label1"));
    QLabel *label2 = new QLabel(QString("label2"));

    // we can also use grid layout for this, but extra code needed
    formLayout->addRow(label, label2);
    formLayout->setSpacing(100);

    // ---------------------------------------------------------------------------------------

    QWidget window3(nullptr);
    window3.setFixedSize(300,300);

    // creating a layout widget
    QWidget *gridLayoutObject = new QWidget(&window3);
    // creating the window for the grid
    QRect *windowGridLayout = new QRect(0,0, 300,75);
    // setting the geometry of the layout to the rect
    gridLayoutObject->setGeometry(*windowGridLayout);

    // creating the labels and line edits
    QLabel *label3 = new QLabel(QString("Something1"));
    QLabel *label4 = new QLabel(QString("Something2"));
    QLineEdit *qLine1 = new QLineEdit("Something in here");
    QLineEdit *qLine2 = new QLineEdit("Something in here");

    // creating the grid layout
    QGridLayout *gridLayout = new QGridLayout(gridLayoutObject);

    // parameters
    gridLayout->setSpacing(10);
    gridLayout->setHorizontalSpacing(10);

    // adding them based on coloumn and row
    gridLayout->addWidget(label3, 0,0);
    gridLayout->addWidget(label4, 0,1);
    gridLayout->addWidget(qLine1, 1,0);
    gridLayout->addWidget(qLine2, 1,1);

    // ---------------------------------------------------------------------------------------

    // showing the window
    window1.show();
    window2.show();
    window3.show();

    return app.exec();
}
