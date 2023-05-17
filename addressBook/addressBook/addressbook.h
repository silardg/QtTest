#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

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
    void actionCancel();
private:
    void printDatabase();
    void setPositionLabel(int currentPosition);
    void setInputFields(int currentPosition);

private:
    QLabel      *m_labelName;
    QLabel      *m_labelAddress;
    QLabel      *m_labelSize;
    QLineEdit   *m_lineEditName;
    QTextEdit   *m_textEditAddress;

    QGridLayout *m_mainLayout;

    QPushButton *m_buttonAdd;
    QPushButton *m_buttonSubmit;
    QPushButton *m_buttonCancel;
    QVBoxLayout *m_interactionBox;

    QPushButton *m_buttonPrev;
    QPushButton *m_buttonNext;
    QHBoxLayout *m_navigationBox;

    QMap<QString, QString> *contacts;

};

#endif // ADDRESSBOOK_H
