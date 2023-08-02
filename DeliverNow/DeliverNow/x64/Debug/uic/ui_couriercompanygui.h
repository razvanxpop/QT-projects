/********************************************************************************
** Form generated from reading UI file 'couriercompanygui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIERCOMPANYGUI_H
#define UI_COURIERCOMPANYGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourierCompanyGuiClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *recipientLineEdit;
    QLabel *label_2;
    QLineEdit *adressLineEdit;
    QLabel *label_3;
    QLineEdit *locationLineEdit;
    QPushButton *addButton;
    QListWidget *packagesList;

    void setupUi(QWidget *CourierCompanyGuiClass)
    {
        if (CourierCompanyGuiClass->objectName().isEmpty())
            CourierCompanyGuiClass->setObjectName("CourierCompanyGuiClass");
        CourierCompanyGuiClass->resize(600, 400);
        verticalLayout_2 = new QVBoxLayout(CourierCompanyGuiClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label = new QLabel(CourierCompanyGuiClass);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        recipientLineEdit = new QLineEdit(CourierCompanyGuiClass);
        recipientLineEdit->setObjectName("recipientLineEdit");
        recipientLineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, recipientLineEdit);

        label_2 = new QLabel(CourierCompanyGuiClass);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        adressLineEdit = new QLineEdit(CourierCompanyGuiClass);
        adressLineEdit->setObjectName("adressLineEdit");
        adressLineEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, adressLineEdit);

        label_3 = new QLabel(CourierCompanyGuiClass);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        locationLineEdit = new QLineEdit(CourierCompanyGuiClass);
        locationLineEdit->setObjectName("locationLineEdit");
        locationLineEdit->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, locationLineEdit);


        verticalLayout->addLayout(formLayout);

        addButton = new QPushButton(CourierCompanyGuiClass);
        addButton->setObjectName("addButton");
        addButton->setFont(font);

        verticalLayout->addWidget(addButton);


        verticalLayout_2->addLayout(verticalLayout);

        packagesList = new QListWidget(CourierCompanyGuiClass);
        packagesList->setObjectName("packagesList");
        packagesList->setFont(font);

        verticalLayout_2->addWidget(packagesList);


        retranslateUi(CourierCompanyGuiClass);

        QMetaObject::connectSlotsByName(CourierCompanyGuiClass);
    } // setupUi

    void retranslateUi(QWidget *CourierCompanyGuiClass)
    {
        CourierCompanyGuiClass->setWindowTitle(QCoreApplication::translate("CourierCompanyGuiClass", "CourierCompanyGui", nullptr));
        label->setText(QCoreApplication::translate("CourierCompanyGuiClass", "Recipient", nullptr));
        label_2->setText(QCoreApplication::translate("CourierCompanyGuiClass", "Adress", nullptr));
        label_3->setText(QCoreApplication::translate("CourierCompanyGuiClass", "Location", nullptr));
        addButton->setText(QCoreApplication::translate("CourierCompanyGuiClass", "Add package", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourierCompanyGuiClass: public Ui_CourierCompanyGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIERCOMPANYGUI_H
