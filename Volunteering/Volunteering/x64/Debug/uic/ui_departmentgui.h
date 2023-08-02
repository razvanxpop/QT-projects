/********************************************************************************
** Form generated from reading UI file 'departmentgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTGUI_H
#define UI_DEPARTMENTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepartmentGuiClass
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *descriptionLabel;
    QVBoxLayout *verticalLayout_3;
    QListWidget *volunteersList;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *emailLineEdit;
    QLabel *label_3;
    QLineEdit *interestsLineEdit;
    QPushButton *addButton;
    QVBoxLayout *verticalLayout;
    QListWidget *unassignedVolunteersList;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QPushButton *assignButton;

    void setupUi(QWidget *DepartmentGuiClass)
    {
        if (DepartmentGuiClass->objectName().isEmpty())
            DepartmentGuiClass->setObjectName("DepartmentGuiClass");
        DepartmentGuiClass->resize(600, 400);
        verticalLayout_4 = new QVBoxLayout(DepartmentGuiClass);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        descriptionLabel = new QLabel(DepartmentGuiClass);
        descriptionLabel->setObjectName("descriptionLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        descriptionLabel->setFont(font);

        verticalLayout_4->addWidget(descriptionLabel);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        volunteersList = new QListWidget(DepartmentGuiClass);
        volunteersList->setObjectName("volunteersList");
        volunteersList->setFont(font);

        verticalLayout_3->addWidget(volunteersList);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label = new QLabel(DepartmentGuiClass);
        label->setObjectName("label");
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameLineEdit = new QLineEdit(DepartmentGuiClass);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        label_2 = new QLabel(DepartmentGuiClass);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        emailLineEdit = new QLineEdit(DepartmentGuiClass);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, emailLineEdit);

        label_3 = new QLabel(DepartmentGuiClass);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        interestsLineEdit = new QLineEdit(DepartmentGuiClass);
        interestsLineEdit->setObjectName("interestsLineEdit");
        interestsLineEdit->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, interestsLineEdit);


        verticalLayout_2->addLayout(formLayout);

        addButton = new QPushButton(DepartmentGuiClass);
        addButton->setObjectName("addButton");
        addButton->setFont(font);

        verticalLayout_2->addWidget(addButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        unassignedVolunteersList = new QListWidget(DepartmentGuiClass);
        unassignedVolunteersList->setObjectName("unassignedVolunteersList");
        unassignedVolunteersList->setFont(font);

        verticalLayout->addWidget(unassignedVolunteersList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(DepartmentGuiClass);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font);

        horizontalLayout->addWidget(checkBox);

        assignButton = new QPushButton(DepartmentGuiClass);
        assignButton->setObjectName("assignButton");
        assignButton->setFont(font);

        horizontalLayout->addWidget(assignButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);


        retranslateUi(DepartmentGuiClass);

        QMetaObject::connectSlotsByName(DepartmentGuiClass);
    } // setupUi

    void retranslateUi(QWidget *DepartmentGuiClass)
    {
        DepartmentGuiClass->setWindowTitle(QCoreApplication::translate("DepartmentGuiClass", "DepartmentGui", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("DepartmentGuiClass", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("DepartmentGuiClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("DepartmentGuiClass", "Email", nullptr));
        label_3->setText(QCoreApplication::translate("DepartmentGuiClass", "Interests", nullptr));
        addButton->setText(QCoreApplication::translate("DepartmentGuiClass", "Add Volunteer", nullptr));
        checkBox->setText(QCoreApplication::translate("DepartmentGuiClass", "Most suitable volunteers", nullptr));
        assignButton->setText(QCoreApplication::translate("DepartmentGuiClass", "Assign", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepartmentGuiClass: public Ui_DepartmentGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTGUI_H
