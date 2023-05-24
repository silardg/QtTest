/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *scanButton;
    QTabWidget *tabs;
    QWidget *tabTemperature;
    QLabel *temperatureLabel;
    QDial *temperatureTab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tabHumidity;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *humidityLabel;
    QDial *humidityTab;
    QLabel *label_10;
    QWidget *tabOther;
    QMenuBar *menubar;
    QMenu *menuSerialWeather;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(418, 259);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setEnabled(true);
        listWidget->setGeometry(QRect(320, 10, 91, 161));
        scanButton = new QPushButton(centralwidget);
        scanButton->setObjectName("scanButton");
        scanButton->setGeometry(QRect(320, 180, 91, 24));
        tabs = new QTabWidget(centralwidget);
        tabs->setObjectName("tabs");
        tabs->setGeometry(QRect(10, 10, 291, 201));
        tabTemperature = new QWidget();
        tabTemperature->setObjectName("tabTemperature");
        tabTemperature->setMinimumSize(QSize(287, 0));
        temperatureLabel = new QLabel(tabTemperature);
        temperatureLabel->setObjectName("temperatureLabel");
        temperatureLabel->setGeometry(QRect(103, 76, 81, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(temperatureLabel->sizePolicy().hasHeightForWidth());
        temperatureLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(13);
        temperatureLabel->setFont(font);
        temperatureLabel->setFrameShadow(QFrame::Plain);
        temperatureLabel->setLineWidth(1);
        temperatureLabel->setAlignment(Qt::AlignCenter);
        temperatureTab = new QDial(tabTemperature);
        temperatureTab->setObjectName("temperatureTab");
        temperatureTab->setEnabled(false);
        temperatureTab->setGeometry(QRect(70, 30, 141, 121));
        temperatureTab->setMaximum(40);
        temperatureTab->setValue(0);
        temperatureTab->setTracking(false);
        label = new QLabel(tabTemperature);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 49, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tabTemperature);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 130, 49, 16));
        label_3 = new QLabel(tabTemperature);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 130, 49, 16));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(tabTemperature);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 60, 49, 16));
        label_5 = new QLabel(tabTemperature);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 60, 49, 16));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabs->addTab(tabTemperature, QString());
        tabHumidity = new QWidget();
        tabHumidity->setObjectName("tabHumidity");
        label_6 = new QLabel(tabHumidity);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 60, 49, 16));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(tabHumidity);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 130, 49, 16));
        label_8 = new QLabel(tabHumidity);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 130, 49, 16));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(tabHumidity);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(200, 60, 49, 16));
        humidityLabel = new QLabel(tabHumidity);
        humidityLabel->setObjectName("humidityLabel");
        humidityLabel->setGeometry(QRect(101, 76, 81, 31));
        sizePolicy.setHeightForWidth(humidityLabel->sizePolicy().hasHeightForWidth());
        humidityLabel->setSizePolicy(sizePolicy);
        humidityLabel->setFont(font);
        humidityLabel->setFrameShadow(QFrame::Plain);
        humidityLabel->setLineWidth(1);
        humidityLabel->setAlignment(Qt::AlignCenter);
        humidityTab = new QDial(tabHumidity);
        humidityTab->setObjectName("humidityTab");
        humidityTab->setEnabled(false);
        humidityTab->setGeometry(QRect(70, 30, 141, 121));
        humidityTab->setMaximum(100);
        humidityTab->setValue(0);
        humidityTab->setTracking(false);
        label_10 = new QLabel(tabHumidity);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(120, 20, 49, 16));
        label_10->setAlignment(Qt::AlignCenter);
        tabs->addTab(tabHumidity, QString());
        tabOther = new QWidget();
        tabOther->setObjectName("tabOther");
        tabs->addTab(tabOther, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 418, 21));
        menuSerialWeather = new QMenu(menubar);
        menuSerialWeather->setObjectName("menuSerialWeather");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSerialWeather->menuAction());

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SerialWeather", nullptr));
        scanButton->setText(QCoreApplication::translate("MainWindow", "Scan Ports", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("MainWindow", "0.0\302\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "20\302\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "40\302\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "30\302\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "10\302\260", nullptr));
        tabs->setTabText(tabs->indexOf(tabTemperature), QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "25%", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "75%", nullptr));
        humidityLabel->setText(QCoreApplication::translate("MainWindow", "0.0%", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "50%", nullptr));
        tabs->setTabText(tabs->indexOf(tabHumidity), QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        tabs->setTabText(tabs->indexOf(tabOther), QCoreApplication::translate("MainWindow", "Other", nullptr));
        menuSerialWeather->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
