/********************************************************************************
** Form generated from reading UI file 'usergui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERGUI_H
#define UI_USERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserGuiClass
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QListWidget *itemsList;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *categoryLineEdit;
    QLabel *label_3;
    QLineEdit *priceLineEdit;
    QPushButton *addButton;
    QVBoxLayout *verticalLayout_3;
    QListWidget *offersList;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *bidPriceLineEdit;
    QPushButton *bidButton;

    void setupUi(QWidget *UserGuiClass)
    {
        if (UserGuiClass->objectName().isEmpty())
            UserGuiClass->setObjectName("UserGuiClass");
        UserGuiClass->resize(600, 400);
        verticalLayout_4 = new QVBoxLayout(UserGuiClass);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        comboBox = new QComboBox(UserGuiClass);
        comboBox->setObjectName("comboBox");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        comboBox->setFont(font);

        verticalLayout_2->addWidget(comboBox);

        itemsList = new QListWidget(UserGuiClass);
        itemsList->setObjectName("itemsList");
        itemsList->setFont(font);

        verticalLayout_2->addWidget(itemsList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label = new QLabel(UserGuiClass);
        label->setObjectName("label");
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameLineEdit = new QLineEdit(UserGuiClass);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        label_2 = new QLabel(UserGuiClass);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        categoryLineEdit = new QLineEdit(UserGuiClass);
        categoryLineEdit->setObjectName("categoryLineEdit");
        categoryLineEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, categoryLineEdit);

        label_3 = new QLabel(UserGuiClass);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        priceLineEdit = new QLineEdit(UserGuiClass);
        priceLineEdit->setObjectName("priceLineEdit");
        priceLineEdit->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, priceLineEdit);


        verticalLayout->addLayout(formLayout);

        addButton = new QPushButton(UserGuiClass);
        addButton->setObjectName("addButton");
        addButton->setFont(font);

        verticalLayout->addWidget(addButton);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        offersList = new QListWidget(UserGuiClass);
        offersList->setObjectName("offersList");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(12);
        font1.setBold(false);
        offersList->setFont(font1);

        verticalLayout_3->addWidget(offersList);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName("formLayout_2");
        label_4 = new QLabel(UserGuiClass);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        bidPriceLineEdit = new QLineEdit(UserGuiClass);
        bidPriceLineEdit->setObjectName("bidPriceLineEdit");
        bidPriceLineEdit->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, bidPriceLineEdit);

        bidButton = new QPushButton(UserGuiClass);
        bidButton->setObjectName("bidButton");
        bidButton->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, bidButton);


        verticalLayout_3->addLayout(formLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(UserGuiClass);

        QMetaObject::connectSlotsByName(UserGuiClass);
    } // setupUi

    void retranslateUi(QWidget *UserGuiClass)
    {
        UserGuiClass->setWindowTitle(QCoreApplication::translate("UserGuiClass", "UserGui", nullptr));
        label->setText(QCoreApplication::translate("UserGuiClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("UserGuiClass", "Category", nullptr));
        label_3->setText(QCoreApplication::translate("UserGuiClass", "Price", nullptr));
        addButton->setText(QCoreApplication::translate("UserGuiClass", "Add item", nullptr));
        label_4->setText(QCoreApplication::translate("UserGuiClass", "Bid price", nullptr));
        bidButton->setText(QCoreApplication::translate("UserGuiClass", "Place bid", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserGuiClass: public Ui_UserGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERGUI_H
