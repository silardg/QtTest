#include "addressbook.h"

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMap>
#include <QHBoxLayout>

#include<QDebug>

addressBook::addressBook(QWidget *parent) : QWidget(parent)
{
    contacts = new QMap<QString, QString>;

    // input labels and fields
    m_labelName        = new QLabel("Name");
    m_labelAddress     = new QLabel("Address");
    m_lineEditName     = new QLineEdit();
    m_textEditAddress  = new QTextEdit();
    m_lineEditName->setEnabled(false);
    m_textEditAddress->setEnabled(false);

    // set the layout for the inputs
    QGridLayout *m_mainLayout = new QGridLayout();

    // create the interface box for the buttons
    // by default submit and cancel should be hidden
    m_interactionBox    = new QVBoxLayout();
    m_buttonAdd         = new QPushButton("Add");
    m_buttonSubmit      = new QPushButton("Submit");
    m_buttonSubmit->hide();
    m_buttonCancel      = new QPushButton("Cancel");
    m_buttonCancel->hide();
    m_interactionBox->addWidget(m_buttonAdd, Qt::AlignTop);
    m_interactionBox->addWidget(m_buttonSubmit);
    m_interactionBox->addWidget(m_buttonCancel);
    m_interactionBox->addStretch();


    // labelSize is showing how many contacts we have and at what position we are at
    // prev and next buttons are used for navigation
    m_labelSize     = new QLabel("0/0");
    m_buttonPrev    = new QPushButton("Previous");
    m_buttonNext    = new QPushButton("Next");
    m_buttonPrev->hide();
    m_buttonNext->hide();
//    m_labelSize->hide();
    // create a horizontal box and add the buttons to it
    m_navigationBox = new QHBoxLayout();
    m_navigationBox->addWidget(m_buttonPrev);
    m_navigationBox->addWidget(m_buttonNext);

    // adding the widgets and making sure it fits the design
    m_mainLayout->addWidget(m_labelName, 0, 0);
    m_mainLayout->addWidget(m_lineEditName, 0, 1);
    m_mainLayout->addWidget(m_labelAddress, 1, 0, Qt::AlignTop);
    m_mainLayout->addWidget(m_textEditAddress, 1, 1);
    m_mainLayout->addLayout(m_interactionBox, 1, 2);
    m_mainLayout->addWidget(m_labelSize, 2,0);
    m_mainLayout->addLayout(m_navigationBox, 2,1);


    // setup the signals from the buttons
    connect(m_buttonAdd, SIGNAL (clicked()), this, SLOT (actionAdd()));
    connect(m_buttonSubmit, SIGNAL (clicked()), this, SLOT (actionSubmit()));
    connect(m_buttonCancel, SIGNAL (clicked()), this, SLOT (actionCancel()));

    // set this layout as the main
    setLayout(m_mainLayout);

    // set the title of the window
    setWindowTitle("Address Book");
}

/**
 * @brief addressBook::actionAdd
 */
void addressBook::actionAdd() {
    qInfo("Add");

    // sets the name and address fields to be able to get written
    m_lineEditName->setEnabled(true);
    m_textEditAddress->setEnabled(true);

    // shows the submit and cancel buttons
    m_buttonSubmit->show();
    m_buttonCancel->show();

    // clears the name and address fields
    m_lineEditName->clear();
    m_textEditAddress->clear();

    m_buttonAdd->hide();
}

/**
 * @brief addressBook::actionSubmit
 */
void addressBook::actionSubmit() {
    qInfo("Submit");

    // get the name and address
    QString addedName = m_lineEditName->text();
    QString addedAddress = m_textEditAddress->toPlainText();

    // both have to be with some data
    if (addedName.isEmpty() || addedAddress.isEmpty()) {
        qWarning("Something is missing");
        return;
    }
    // checks if it is already part of the address book
    if (contacts->contains(addedName)) {
        qWarning("Already in database");
        return;
    }

    // if it is not part, add it
    contacts->insert(addedName, addedAddress);

    // set the number of contacts available
    m_labelSize->setText(QString::number(contacts->count()));
    m_labelSize->show();

    // clear it
    actionCancel();
}

/**
 * @brief addressBook::actionCancel
 */
void addressBook::actionCancel() {

    m_lineEditName->setEnabled(false);
    m_textEditAddress->setEnabled(false);

    m_buttonSubmit->hide();
    m_buttonCancel->hide();

    // clears the name and address fields
    m_lineEditName->clear();
    m_textEditAddress->clear();

    m_buttonAdd->show();
}
