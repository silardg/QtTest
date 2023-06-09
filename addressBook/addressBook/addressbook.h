#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "qvector.h"
#include <QObject>
#include <QWidget>

class QLabel;
class QLineEdit;
class QTextEdit;
class QGridLayout;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class addressBook : public QWidget
{
    Q_OBJECT
public:
    addressBook(QWidget *parent = nullptr);
public slots:
    void actionAdd();
    void actionSubmit();
    void actionDelete();
//    void actionCancel();
    void actionNext();
    void actionPrev();
private:
    void printDatabase();
    inline void setPositionLabel();
    inline void setInputFields();
    inline void updateNavigationButtons();
    inline void updateInterface();
private:

    struct contact {
        QString name;
        QString address;
    };

    QLabel      *m_labelName;
    QLabel      *m_labelAddress;
    QLabel      *m_labelSize;
    QLineEdit   *m_lineEditName;
    QTextEdit   *m_textEditAddress;

    QGridLayout *m_mainLayout;

    QPushButton *m_buttonAdd;
    QPushButton *m_buttonSubmit;
    QPushButton *m_buttonCancel;
    QPushButton *m_buttonDelete;
    QVBoxLayout *m_interactionBox;

    QPushButton *m_buttonPrev;
    QPushButton *m_buttonNext;
    QHBoxLayout *m_navigationBox;

    QVector<contact> m_contacts;


    int m_currentPosition = 0;

};

#endif // ADDRESSBOOK_H
