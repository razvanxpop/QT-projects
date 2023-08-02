/********************************************************************************
** Form generated from reading UI file 'couriergui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIERGUI_H
#define UI_COURIERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourierGuiClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *courierZoneLabel;
    QComboBox *comboBox;
    QPushButton *deliverButton;
    QListWidget *undeliveredPackagesList;

    void setupUi(QWidget *CourierGuiClass)
    {
        if (CourierGuiClass->objectName().isEmpty())
            CourierGuiClass->setObjectName("CourierGuiClass");
        CourierGuiClass->resize(736, 504);
        verticalLayout = new QVBoxLayout(CourierGuiClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        courierZoneLabel = new QLabel(CourierGuiClass);
        courierZoneLabel->setObjectName("courierZoneLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        courierZoneLabel->setFont(font);

        horizontalLayout->addWidget(courierZoneLabel);

        comboBox = new QComboBox(CourierGuiClass);
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font);

        horizontalLayout->addWidget(comboBox);

        deliverButton = new QPushButton(CourierGuiClass);
        deliverButton->setObjectName("deliverButton");
        deliverButton->setFont(font);

        horizontalLayout->addWidget(deliverButton);


        verticalLayout->addLayout(horizontalLayout);

        undeliveredPackagesList = new QListWidget(CourierGuiClass);
        undeliveredPackagesList->setObjectName("undeliveredPackagesList");
        undeliveredPackagesList->setFont(font);

        verticalLayout->addWidget(undeliveredPackagesList);


        retranslateUi(CourierGuiClass);

        QMetaObject::connectSlotsByName(CourierGuiClass);
    } // setupUi

    void retranslateUi(QWidget *CourierGuiClass)
    {
        CourierGuiClass->setWindowTitle(QCoreApplication::translate("CourierGuiClass", "CourierGui", nullptr));
        courierZoneLabel->setText(QCoreApplication::translate("CourierGuiClass", "TextLabel", nullptr));
        deliverButton->setText(QCoreApplication::translate("CourierGuiClass", "Deliver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourierGuiClass: public Ui_CourierGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIERGUI_H
