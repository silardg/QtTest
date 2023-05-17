#include "addressbook.h"

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMap>
#include <QHBoxLayout>
#include <QMutableVectorIterator>

#include <QDebug>

addressBook::addressBook(QWidget *parent) : QWidget(parent)
{
//    contacts = new QMap<QString, QString>;
    m_contacts = new QVector<contact>;

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
    connect(m_buttonNext, SIGNAL (clicked()), this, SLOT (actionNext()));
    connect(m_buttonPrev, SIGNAL (clicked()), this, SLOT (actionPrev()));

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
    // in this case we will just modify it
//    if (contacts->contains(addedName)) {
//        qWarning("Already in database, updating");
//    }

//    // if it is not part, add it
//    contacts->insert(addedName, addedAddress);

//    m_currentPosition = contacts->count();

    m_contacts->append({addedName, addedAddress});

    qInfo() << m_contacts->size();

    m_currentPosition = m_contacts->size();

    setPositionLabel();

    // if there is more than 1 contact in the database, add the navigation buttons
    if (m_currentPosition > 1) {
        // do navigation here
        m_buttonPrev->show();
        m_buttonNext->show();

        updateNavigationButtons();
    } else {
        // remove the navigation buttons
        m_buttonPrev->hide();
        m_buttonNext->hide();
    }

    printDatabase();
}

/**
 * @brief addressBook::actionCancel
 */
void addressBook::actionCancel() {

    m_buttonSubmit->hide();
    m_buttonCancel->hide();

    // clears the name and address fields
    m_lineEditName->clear();
    m_textEditAddress->clear();

    m_buttonAdd->show();
}

/**
 * @brief addressBook::actionNext
 */
void addressBook::actionNext() {
    qInfo("Next action");

    m_currentPosition++;

    setInputFields();
    setPositionLabel();
    updateNavigationButtons();
}

/**
 * @brief addressBook::actionPrev
 */
void addressBook::actionPrev() {
    qInfo("Prev action");

    m_currentPosition--;

    setInputFields();
    setPositionLabel();
    updateNavigationButtons();
}

/**
 * @brief addressBook::printDatabase
 */
void addressBook::printDatabase() {
    qInfo("-------------------------");
    QVectorIterator<contact> i(*m_contacts);

    while(i.hasNext()) {
        contact c = i.next();
        qInfo() << c.name << " - " << c.address;
    }
    qInfo("-------------------------");
}

/**
 * @brief addressBook::setPositionLabel
 */
void addressBook::setPositionLabel() {
    // set the number of elements and the position
    m_labelSize->setText(QString::number(m_currentPosition) + "/" +QString::number(m_contacts->size()));
}

/**
 * @brief addressBook::setInputFields
 */
void addressBook::setInputFields() {
    const contact current = m_contacts->at(m_currentPosition - 1);

//    qInfo() << "Setting to " << current.name << " - " << current.address;

    m_lineEditName->setText(current.name);
    m_textEditAddress->setText(current.address);
}

/**
 * @brief addressBook::updateNavigationButtons
 */
void addressBook::updateNavigationButtons() {

//    qInfo() << m_currentPosition << "-" << contacts->count();

    m_buttonNext->setDisabled(false);
    m_buttonPrev->setDisabled(false);

    // our position is at the end, disable the next button
    if (m_currentPosition == m_contacts->size()) {
        m_buttonNext->setDisabled(true);
    }
    // our position is at the start, disable the previous button
    else if (m_currentPosition == 1) {
        m_buttonPrev->setDisabled(true);
    }
}
