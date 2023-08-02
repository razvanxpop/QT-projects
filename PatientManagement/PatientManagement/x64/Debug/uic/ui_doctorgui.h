/********************************************************************************
** Form generated from reading UI file 'doctorgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORGUI_H
#define UI_DOCTORGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorGuiClass
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *patientsList;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *diagnosisLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *specializationLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *doctorLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *dateLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox;
    QPushButton *addButton;
    QPushButton *updateButton;

    void setupUi(QWidget *DoctorGuiClass)
    {
        if (DoctorGuiClass->objectName().isEmpty())
            DoctorGuiClass->setObjectName("DoctorGuiClass");
        DoctorGuiClass->resize(815, 542);
        verticalLayout = new QVBoxLayout(DoctorGuiClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        patientsList = new QListWidget(DoctorGuiClass);
        patientsList->setObjectName("patientsList");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        patientsList->setFont(font);

        verticalLayout->addWidget(patientsList);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label = new QLabel(DoctorGuiClass);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_5->addWidget(label);

        nameLineEdit = new QLineEdit(DoctorGuiClass);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setFont(font);

        horizontalLayout_5->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(DoctorGuiClass);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        diagnosisLineEdit = new QLineEdit(DoctorGuiClass);
        diagnosisLineEdit->setObjectName("diagnosisLineEdit");
        diagnosisLineEdit->setFont(font);

        horizontalLayout_4->addWidget(diagnosisLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(DoctorGuiClass);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        specializationLineEdit = new QLineEdit(DoctorGuiClass);
        specializationLineEdit->setObjectName("specializationLineEdit");
        specializationLineEdit->setFont(font);

        horizontalLayout_3->addWidget(specializationLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(DoctorGuiClass);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        doctorLineEdit = new QLineEdit(DoctorGuiClass);
        doctorLineEdit->setObjectName("doctorLineEdit");
        doctorLineEdit->setFont(font);

        horizontalLayout_2->addWidget(doctorLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(DoctorGuiClass);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        dateLineEdit = new QLineEdit(DoctorGuiClass);
        dateLineEdit->setObjectName("dateLineEdit");
        dateLineEdit->setFont(font);

        horizontalLayout->addWidget(dateLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        checkBox = new QCheckBox(DoctorGuiClass);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font);

        horizontalLayout_6->addWidget(checkBox);

        addButton = new QPushButton(DoctorGuiClass);
        addButton->setObjectName("addButton");
        addButton->setFont(font);

        horizontalLayout_6->addWidget(addButton);

        updateButton = new QPushButton(DoctorGuiClass);
        updateButton->setObjectName("updateButton");
        updateButton->setFont(font);

        horizontalLayout_6->addWidget(updateButton);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(DoctorGuiClass);

        QMetaObject::connectSlotsByName(DoctorGuiClass);
    } // setupUi

    void retranslateUi(QWidget *DoctorGuiClass)
    {
        DoctorGuiClass->setWindowTitle(QCoreApplication::translate("DoctorGuiClass", "DoctorGui", nullptr));
        label->setText(QCoreApplication::translate("DoctorGuiClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("DoctorGuiClass", "Diagnosis", nullptr));
        label_3->setText(QCoreApplication::translate("DoctorGuiClass", "Specialization", nullptr));
        label_4->setText(QCoreApplication::translate("DoctorGuiClass", "Doctor", nullptr));
        label_5->setText(QCoreApplication::translate("DoctorGuiClass", "Admission date", nullptr));
        checkBox->setText(QString());
        addButton->setText(QCoreApplication::translate("DoctorGuiClass", "Add patient", nullptr));
        updateButton->setText(QCoreApplication::translate("DoctorGuiClass", "Update patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorGuiClass: public Ui_DoctorGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORGUI_H
