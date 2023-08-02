/********************************************************************************
** Form generated from reading UI file 'volunteering.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUNTEERING_H
#define UI_VOLUNTEERING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolunteeringClass
{
public:

    void setupUi(QWidget *VolunteeringClass)
    {
        if (VolunteeringClass->objectName().isEmpty())
            VolunteeringClass->setObjectName("VolunteeringClass");
        VolunteeringClass->resize(600, 400);

        retranslateUi(VolunteeringClass);

        QMetaObject::connectSlotsByName(VolunteeringClass);
    } // setupUi

    void retranslateUi(QWidget *VolunteeringClass)
    {
        VolunteeringClass->setWindowTitle(QCoreApplication::translate("VolunteeringClass", "Volunteering", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolunteeringClass: public Ui_VolunteeringClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUNTEERING_H
