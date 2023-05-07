#include "addressbook.h"

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include<QDebug>

addressBook::addressBook(QWidget *parent) : QWidget(parent)
{
    // input labels and fields
    m_labelName        = new QLabel("Name");
    m_labelAddress     = new QLabel("Address");
    m_lineEditName     = new QLineEdit();
    m_textEditAddress  = new QTextEdit();

    // set the layout for the inputs
    QGridLayout *m_mainLayout = new QGridLayout();

    // create the interface box for the buttons
    // by default submit and cancel should be hidden
    m_interactionBox    = new QVBoxLayout();
    m_buttonAdd         = new QPushButton("Add");
    m_buttonSubmit      = new QPushButton("Submit");
//    m_buttonSubmit->hide();
    m_buttonCancel      = new QPushButton("Cancel");
//    m_buttonCancel->hide();
    m_interactionBox->addWidget(m_buttonAdd, Qt::AlignTop);
    m_interactionBox->addWidget(m_buttonSubmit);
    m_interactionBox->addWidget(m_buttonCancel);
    m_interactionBox->addStretch();

    // adding the widgets and making sure it fits the design
    m_mainLayout->addWidget(m_labelName, 0, 0);
    m_mainLayout->addWidget(m_lineEditName, 0, 1);
    m_mainLayout->addWidget(m_labelAddress, 1, 0, Qt::AlignTop);
    m_mainLayout->addWidget(m_textEditAddress, 1, 1);
    m_mainLayout->addLayout(m_interactionBox, 1, 2);

    connect(m_buttonAdd, SIGNAL (clicked()), this, SLOT (actionAdd()));
    connect(m_buttonSubmit, SIGNAL (clicked()), this, SLOT (actionSubmit()));
    connect(m_buttonCancel, SIGNAL (clicked()), this, SLOT (actionCancel()));


    // set this layout as the main
    setLayout(m_mainLayout);

    // set the title of the window
    setWindowTitle("Address Book");
}

void addressBook::actionAdd() {
    qInfo("Add");
}
void addressBook::actionSubmit() {
    qInfo("Submit");
}
void addressBook::actionCancel() {
    qInfo("Cancel");
}
