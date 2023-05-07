#include <QApplication>

#include "addressbook.h"

int main(int argc, char **argv) {
    // create the main app
    QApplication app(argc, argv);

    addressBook book;
    book.show();

    return app.exec();
}
