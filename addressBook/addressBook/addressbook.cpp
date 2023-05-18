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

addressBook::addressBook(QWidget *parent) : QWidget(parent) {
    // initialize vector
    m_contacts = QVector<contact>();

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
    m_buttonDelete      = new QPushButton("Delete");
    m_buttonDelete->hide();
    m_interactionBox->addWidget(m_buttonAdd, Qt::AlignTop);
    m_interactionBox->addWidget(m_buttonSubmit);
    m_interactionBox->addWidget(m_buttonDelete);
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
    connect(m_buttonDelete, SIGNAL (clicked()), this, SLOT (actionDelete()));
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
    // sets the name and address fields to be able to get written
    m_lineEditName->setEnabled(true);
    m_textEditAddress->setEnabled(true);

    // shows the submit and cancel buttons
    m_buttonSubmit->show();
    m_buttonDelete->show();

    // hides the add button
    m_buttonAdd->hide();
}

/**
 * @brief addressBook::actionSubmit
 */
void addressBook::actionSubmit() {
    // get the name and address
    QString addedName = m_lineEditName->text();
    QString addedAddress = m_textEditAddress->toPlainText();

    // as it was submited, it can be deleted
    // showing the delete button
    m_buttonDelete->show();

    // both have to be with some data
    if (addedName.isEmpty() || addedAddress.isEmpty()) {
        qWarning("Something is missing");
        return;
    }

    // if the contact size is more than 0
    // this has to be checked so that the .at function doesnt crash
    if (m_contacts.size() > 0) {
        // get the current positions data
        contact currentContactOnPosition = m_contacts.at(m_currentPosition - 1);

        // check if the current positions name is the same as the fields
        if (addedName == currentContactOnPosition.name) {
            // this means that we will modify the value
            // we get the data and modify the positions data
            contact *contacts = m_contacts.data();
            contacts[m_currentPosition - 1] = {addedName, addedAddress};
        }
        // in case that it is new data, we just append it
        else {
            // adding data
            m_contacts.append({addedName, addedAddress});

            // setting the position to the last
            m_currentPosition = m_contacts.size();
        }
    }
    // in case that it is new data, we just append it
    else {
        // adding data
        m_contacts.append({addedName, addedAddress});

        // setting the position to the last
        m_currentPosition = m_contacts.size();
    }

    // if there is more than 1 contact in the database, add the navigation buttons
    if (m_currentPosition > 1) {
        // do navigation here
        m_buttonPrev->show();
        m_buttonNext->show();

        // update the state of the buttons
        updateNavigationButtons();
    } else {
        // remove the navigation buttons
        m_buttonPrev->hide();
        m_buttonNext->hide();
    }

    // set the position label updated with the amount of data
    setPositionLabel();

    printDatabase();
}

/**
 * @brief addressBook::actionDelete
 */
void addressBook::actionDelete() {
    // in case there is more than 1 in the database, remove it
    if (m_contacts.size() > 0) {
        m_contacts.remove(m_currentPosition - 1);
    }

    // after deleting always go to the first element
    m_currentPosition = 1;

    // if the size is 0, thus no records, go back to default mode
    if (m_contacts.size() == 0) {
        // clear the inputs
        m_lineEditName->clear();
        m_textEditAddress->clear();

        // update the position label
        setPositionLabel();

        // hide the delete button
        m_buttonDelete->hide();
        return;
    }

    updateInterface();

    printDatabase();

}

/**
 * @brief addressBook::actionNext
 */
void addressBook::actionNext() {
    // increment the position
    m_currentPosition++;


    updateInterface();
}

/**
 * @brief addressBook::actionPrev
 */
void addressBook::actionPrev() {
    // decrement the position
    m_currentPosition--;

    updateInterface();
}

/**
 * @brief addressBook::updateInterface
 */
void addressBook::updateInterface() {
    setInputFields();
    setPositionLabel();
    updateNavigationButtons();
}

/**
 * @brief addressBook::printDatabase
 */
void addressBook::printDatabase() {
    qInfo("-------------------------");
    QVectorIterator<contact> i(m_contacts);

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
    m_labelSize->setText(QString::number(m_currentPosition) + "/" +QString::number(m_contacts.size()));
}

/**
 * @brief addressBook::setInputFields
 */
void addressBook::setInputFields() {
    // get the current contact data
    const contact current = m_contacts.at(m_currentPosition - 1);

    // show it in the input fields
    m_lineEditName->setText(current.name);
    m_textEditAddress->setText(current.address);
}

/**
 * @brief addressBook::updateNavigationButtons
 */
void addressBook::updateNavigationButtons() {
    // set them to not be disabled by default
    m_buttonNext->setDisabled(false);
    m_buttonPrev->setDisabled(false);

    // our position is at the end, disable the next button
    if (m_currentPosition == m_contacts.size()) {
        m_buttonNext->setDisabled(true);
    }
    // our position is at the start, disable the previous button
    else if (m_currentPosition == 1) {
        m_buttonPrev->setDisabled(true);
    }

    // in case that we are in the first position and that the contact size is 1, we don't need the buttons
    if(m_currentPosition == 1 && m_contacts.size() == 1) {
        m_buttonNext->hide();
        m_buttonPrev->hide();
    }
}
