/********************************************************************************
** Form generated from reading UI file 'statisticsgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSGUI_H
#define UI_STATISTICSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsGuiClass
{
public:

    void setupUi(QWidget *StatisticsGuiClass)
    {
        if (StatisticsGuiClass->objectName().isEmpty())
            StatisticsGuiClass->setObjectName("StatisticsGuiClass");
        StatisticsGuiClass->resize(600, 400);

        retranslateUi(StatisticsGuiClass);

        QMetaObject::connectSlotsByName(StatisticsGuiClass);
    } // setupUi

    void retranslateUi(QWidget *StatisticsGuiClass)
    {
        StatisticsGuiClass->setWindowTitle(QCoreApplication::translate("StatisticsGuiClass", "StatisticsGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsGuiClass: public Ui_StatisticsGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSGUI_H
