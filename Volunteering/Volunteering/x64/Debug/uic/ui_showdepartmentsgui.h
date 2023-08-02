/********************************************************************************
** Form generated from reading UI file 'showdepartmentsgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDEPARTMENTSGUI_H
#define UI_SHOWDEPARTMENTSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowDepartmentsGuiClass
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *departmentsList;

    void setupUi(QWidget *ShowDepartmentsGuiClass)
    {
        if (ShowDepartmentsGuiClass->objectName().isEmpty())
            ShowDepartmentsGuiClass->setObjectName("ShowDepartmentsGuiClass");
        ShowDepartmentsGuiClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(ShowDepartmentsGuiClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        departmentsList = new QListWidget(ShowDepartmentsGuiClass);
        departmentsList->setObjectName("departmentsList");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        departmentsList->setFont(font);

        verticalLayout->addWidget(departmentsList);


        retranslateUi(ShowDepartmentsGuiClass);

        QMetaObject::connectSlotsByName(ShowDepartmentsGuiClass);
    } // setupUi

    void retranslateUi(QWidget *ShowDepartmentsGuiClass)
    {
        ShowDepartmentsGuiClass->setWindowTitle(QCoreApplication::translate("ShowDepartmentsGuiClass", "ShowDepartmentsGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowDepartmentsGuiClass: public Ui_ShowDepartmentsGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDEPARTMENTSGUI_H
