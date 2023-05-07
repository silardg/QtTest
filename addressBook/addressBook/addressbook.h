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
    QLabel      *m_labelName;
    QLabel      *m_labelAddress;
    QLineEdit   *m_lineEditName;
    QTextEdit   *m_textEditAddress;

    QGridLayout *m_mainLayout;

    QPushButton *m_buttonAdd;
    QPushButton *m_buttonSubmit;
    QPushButton *m_buttonCancel;
    QVBoxLayout *m_interactionBox;

    QMap<QString, QString> *contacts;

};

#endif // ADDRESSBOOK_H
