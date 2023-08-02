/********************************************************************************
** Form generated from reading UI file 'patientmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMANAGEMENT_H
#define UI_PATIENTMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientManagementClass
{
public:

    void setupUi(QWidget *PatientManagementClass)
    {
        if (PatientManagementClass->objectName().isEmpty())
            PatientManagementClass->setObjectName("PatientManagementClass");
        PatientManagementClass->resize(600, 400);

        retranslateUi(PatientManagementClass);

        QMetaObject::connectSlotsByName(PatientManagementClass);
    } // setupUi

    void retranslateUi(QWidget *PatientManagementClass)
    {
        PatientManagementClass->setWindowTitle(QCoreApplication::translate("PatientManagementClass", "PatientManagement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientManagementClass: public Ui_PatientManagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMANAGEMENT_H
