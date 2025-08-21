/********************************************************************************
** Form generated from reading UI file 'pane.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANE_H
#define UI_PANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pane
{
public:

    void setupUi(QWidget *Pane)
    {
        if (Pane->objectName().isEmpty())
            Pane->setObjectName("Pane");
        Pane->resize(705, 610);

        retranslateUi(Pane);

        QMetaObject::connectSlotsByName(Pane);
    } // setupUi

    void retranslateUi(QWidget *Pane)
    {
        Pane->setWindowTitle(QCoreApplication::translate("Pane", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pane: public Ui_Pane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANE_H
