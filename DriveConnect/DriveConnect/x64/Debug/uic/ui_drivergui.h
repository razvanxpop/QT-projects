/********************************************************************************
** Form generated from reading UI file 'drivergui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVERGUI_H
#define UI_DRIVERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DriverGuiClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *driverLocationLabel;
    QLabel *driverScoreLabel;
    QVBoxLayout *verticalLayout_2;
    QListWidget *chat;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QVBoxLayout *verticalLayout;
    QListWidget *reportsList;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *descriptionLineEdit;
    QLabel *label_2;
    QLineEdit *locationLineEdit;
    QPushButton *addButton;
    QPushButton *validateButton;

    void setupUi(QWidget *DriverGuiClass)
    {
        if (DriverGuiClass->objectName().isEmpty())
            DriverGuiClass->setObjectName("DriverGuiClass");
        DriverGuiClass->resize(788, 656);
        verticalLayout_3 = new QVBoxLayout(DriverGuiClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        driverLocationLabel = new QLabel(DriverGuiClass);
        driverLocationLabel->setObjectName("driverLocationLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        driverLocationLabel->setFont(font);

        horizontalLayout->addWidget(driverLocationLabel);

        driverScoreLabel = new QLabel(DriverGuiClass);
        driverScoreLabel->setObjectName("driverScoreLabel");
        driverScoreLabel->setFont(font);

        horizontalLayout->addWidget(driverScoreLabel);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        chat = new QListWidget(DriverGuiClass);
        chat->setObjectName("chat");
        chat->setFont(font);

        verticalLayout_2->addWidget(chat);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        messageLineEdit = new QLineEdit(DriverGuiClass);
        messageLineEdit->setObjectName("messageLineEdit");
        messageLineEdit->setFont(font);

        horizontalLayout_2->addWidget(messageLineEdit);

        sendButton = new QPushButton(DriverGuiClass);
        sendButton->setObjectName("sendButton");
        sendButton->setFont(font);

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        reportsList = new QListWidget(DriverGuiClass);
        reportsList->setObjectName("reportsList");
        reportsList->setFont(font);

        verticalLayout->addWidget(reportsList);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label = new QLabel(DriverGuiClass);
        label->setObjectName("label");
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        descriptionLineEdit = new QLineEdit(DriverGuiClass);
        descriptionLineEdit->setObjectName("descriptionLineEdit");
        descriptionLineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, descriptionLineEdit);

        label_2 = new QLabel(DriverGuiClass);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        locationLineEdit = new QLineEdit(DriverGuiClass);
        locationLineEdit->setObjectName("locationLineEdit");
        locationLineEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, locationLineEdit);

        addButton = new QPushButton(DriverGuiClass);
        addButton->setObjectName("addButton");
        addButton->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, addButton);

        validateButton = new QPushButton(DriverGuiClass);
        validateButton->setObjectName("validateButton");
        validateButton->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, validateButton);


        verticalLayout->addLayout(formLayout);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(DriverGuiClass);

        QMetaObject::connectSlotsByName(DriverGuiClass);
    } // setupUi

    void retranslateUi(QWidget *DriverGuiClass)
    {
        DriverGuiClass->setWindowTitle(QCoreApplication::translate("DriverGuiClass", "DriverGui", nullptr));
        driverLocationLabel->setText(QCoreApplication::translate("DriverGuiClass", "TextLabel", nullptr));
        driverScoreLabel->setText(QCoreApplication::translate("DriverGuiClass", "TextLabel", nullptr));
        sendButton->setText(QCoreApplication::translate("DriverGuiClass", "Send", nullptr));
        label->setText(QCoreApplication::translate("DriverGuiClass", "Description", nullptr));
        label_2->setText(QCoreApplication::translate("DriverGuiClass", "Location", nullptr));
        addButton->setText(QCoreApplication::translate("DriverGuiClass", "Add report", nullptr));
        validateButton->setText(QCoreApplication::translate("DriverGuiClass", "Validate report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DriverGuiClass: public Ui_DriverGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVERGUI_H
