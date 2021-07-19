/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <clickable_label.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    clickable_label *label;
    QLabel *label_2;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonAddStocks;
    QPushButton *pushButtonAddOrders;
    QPushButton *pushButtonDeleteStocks;
    QPushButton *pushButtonDeleteOrders;
    QPushButton *pushButtonSolve;
    QTableWidget *inputTable;
    QTableWidget *answerTable;
    QLabel *functionValue;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1000, 600);
        QFont font;
        font.setStrikeOut(false);
        Widget->setFont(font);
        Widget->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 255);\n"
""));
        label = new clickable_label(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(770, 10, 191, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        label->setFont(font1);
        label->setCursor(QCursor(Qt::PointingHandCursor));
        label->setStyleSheet(QString::fromUtf8("text-decoration: underline;\n"
"background-image: url(:/img/info.jpg);\n"
"background-position: right;\n"
"background-repeat: no-repeat;\n"
"\n"
"\n"
"\n"
""));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 551, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setStrikeOut(false);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setLineWidth(1);
        label_2->setWordWrap(false);
        label_2->setIndent(0);
        pushButtonClear = new QPushButton(Widget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(600, 120, 151, 40));
        pushButtonClear->setFont(font2);
        pushButtonClear->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonClear->setStyleSheet(QString::fromUtf8("*{\n"
"    border-radius: 20px;\n"
"	background: #A8D8FF;\n"
"}\n"
"\n"
"\n"
"*:hover{\n"
"  background: #dbefff;\n"
"}\n"
""));
        pushButtonAddStocks = new QPushButton(Widget);
        pushButtonAddStocks->setObjectName(QString::fromUtf8("pushButtonAddStocks"));
        pushButtonAddStocks->setGeometry(QRect(600, 180, 221, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        pushButtonAddStocks->setFont(font3);
        pushButtonAddStocks->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonAddStocks->setStyleSheet(QString::fromUtf8("*{\n"
"    border-radius: 20px;\n"
"	background: #A8D8FF;\n"
"}\n"
"\n"
"\n"
"*:hover{\n"
"  background: #dbefff;\n"
"}\n"
""));
        pushButtonAddOrders = new QPushButton(Widget);
        pushButtonAddOrders->setObjectName(QString::fromUtf8("pushButtonAddOrders"));
        pushButtonAddOrders->setGeometry(QRect(600, 240, 221, 40));
        pushButtonAddOrders->setFont(font3);
        pushButtonAddOrders->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonAddOrders->setStyleSheet(QString::fromUtf8("*{\n"
"    border-radius: 20px;\n"
"	background: #A8D8FF;\n"
"}\n"
"\n"
"\n"
"*:hover{\n"
"  background: #dbefff;\n"
"}\n"
""));
        pushButtonAddOrders->setCheckable(false);
        pushButtonAddOrders->setFlat(true);
        pushButtonDeleteStocks = new QPushButton(Widget);
        pushButtonDeleteStocks->setObjectName(QString::fromUtf8("pushButtonDeleteStocks"));
        pushButtonDeleteStocks->setGeometry(QRect(840, 180, 131, 40));
        pushButtonDeleteStocks->setFont(font3);
        pushButtonDeleteStocks->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonDeleteStocks->setStyleSheet(QString::fromUtf8("*{\n"
"    border-radius: 20px;\n"
"	background: #A8D8FF;\n"
"}\n"
"\n"
"\n"
"*:hover{\n"
"  background: #dbefff;\n"
"}\n"
""));
        pushButtonDeleteOrders = new QPushButton(Widget);
        pushButtonDeleteOrders->setObjectName(QString::fromUtf8("pushButtonDeleteOrders"));
        pushButtonDeleteOrders->setGeometry(QRect(840, 240, 131, 40));
        pushButtonDeleteOrders->setFont(font3);
        pushButtonDeleteOrders->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonDeleteOrders->setStyleSheet(QString::fromUtf8("*{\n"
"    border-radius: 20px;\n"
"	background: #A8D8FF;\n"
"}\n"
"\n"
"\n"
"*:hover{\n"
"  background: #dbefff;\n"
"}\n"
""));
        pushButtonSolve = new QPushButton(Widget);
        pushButtonSolve->setObjectName(QString::fromUtf8("pushButtonSolve"));
        pushButtonSolve->setGeometry(QRect(330, 550, 221, 40));
        pushButtonSolve->setFont(font3);
        pushButtonSolve->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonSolve->setStyleSheet(QString::fromUtf8("*{\n"
"    border-radius: 20px;\n"
"	background: #A8D8FF;\n"
"}\n"
"\n"
"\n"
"*:hover{\n"
"  background: #dbefff;\n"
"}\n"
""));
        pushButtonSolve->setCheckable(false);
        pushButtonSolve->setFlat(true);
        inputTable = new QTableWidget(Widget);
        inputTable->setObjectName(QString::fromUtf8("inputTable"));
        inputTable->setGeometry(QRect(20, 120, 531, 411));
        answerTable = new QTableWidget(Widget);
        answerTable->setObjectName(QString::fromUtf8("answerTable"));
        answerTable->setGeometry(QRect(600, 350, 371, 191));
        functionValue = new QLabel(Widget);
        functionValue->setObjectName(QString::fromUtf8("functionValue"));
        functionValue->setGeometry(QRect(610, 560, 361, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(12);
        functionValue->setFont(font4);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(760, 320, 47, 13));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Segoe UI"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_3->setFont(font5);

        retranslateUi(Widget);

        pushButtonAddOrders->setDefault(true);
        pushButtonSolve->setDefault(true);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        label_2->setText(QApplication::translate("Widget", "\320\224\320\273\321\217 \321\200\320\260\321\201\321\207\321\221\321\202\320\260 \320\277\320\265\321\200\320\262\320\276\320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\277\320\273\320\260\320\275\320\260 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\321\213\321\205 \320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\276\320\272 \n"
"\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\273\321\213\320\265 \320\275\320\265\320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260.", nullptr));
        pushButtonClear->setText(QApplication::translate("Widget", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        pushButtonAddStocks->setText(QApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260 +1", nullptr));
        pushButtonAddOrders->setText(QApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\321\202\321\200\320\265\320\261\320\270\321\202\320\265\320\273\321\217 +1", nullptr));
        pushButtonDeleteStocks->setText(QApplication::translate("Widget", "\320\243\320\261\321\200\320\260\321\202\321\214 -1", nullptr));
        pushButtonDeleteOrders->setText(QApplication::translate("Widget", "\320\243\320\261\321\200\320\260\321\202\321\214 -1", nullptr));
        pushButtonSolve->setText(QApplication::translate("Widget", "\320\240\320\265\321\210\320\270\321\202\321\214", nullptr));
        functionValue->setText(QString());
        label_3->setText(QApplication::translate("Widget", "\320\236\321\202\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
