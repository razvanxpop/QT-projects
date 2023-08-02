/********************************************************************************
** Form generated from reading UI file 'delivernow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELIVERNOW_H
#define UI_DELIVERNOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeliverNowClass
{
public:

    void setupUi(QWidget *DeliverNowClass)
    {
        if (DeliverNowClass->objectName().isEmpty())
            DeliverNowClass->setObjectName("DeliverNowClass");
        DeliverNowClass->resize(600, 400);

        retranslateUi(DeliverNowClass);

        QMetaObject::connectSlotsByName(DeliverNowClass);
    } // setupUi

    void retranslateUi(QWidget *DeliverNowClass)
    {
        DeliverNowClass->setWindowTitle(QCoreApplication::translate("DeliverNowClass", "DeliverNow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeliverNowClass: public Ui_DeliverNowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELIVERNOW_H
