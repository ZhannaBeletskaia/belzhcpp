/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "pane.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *btnSquare;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    Pane *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1025, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 981, 81));
        btnSquare = new QPushButton(groupBox);
        btnSquare->setObjectName("btnSquare");
        btnSquare->setGeometry(QRect(20, 20, 131, 51));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 20, 131, 51));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 20, 111, 51));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(420, 20, 121, 51));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(550, 20, 93, 51));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(660, 20, 93, 51));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(760, 20, 93, 51));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(870, 20, 93, 51));
        widget = new Pane(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 120, 971, 401));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1025, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        btnSquare->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\321\217\320\267\321\214", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
