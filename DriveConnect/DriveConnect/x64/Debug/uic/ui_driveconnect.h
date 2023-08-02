/********************************************************************************
** Form generated from reading UI file 'driveconnect.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVECONNECT_H
#define UI_DRIVECONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DriveConnectClass
{
public:

    void setupUi(QWidget *DriveConnectClass)
    {
        if (DriveConnectClass->objectName().isEmpty())
            DriveConnectClass->setObjectName("DriveConnectClass");
        DriveConnectClass->resize(600, 400);

        retranslateUi(DriveConnectClass);

        QMetaObject::connectSlotsByName(DriveConnectClass);
    } // setupUi

    void retranslateUi(QWidget *DriveConnectClass)
    {
        DriveConnectClass->setWindowTitle(QCoreApplication::translate("DriveConnectClass", "DriveConnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DriveConnectClass: public Ui_DriveConnectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVECONNECT_H
