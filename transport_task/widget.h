#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include <QMessageBox>
#include <QGridLayout>
#include <QSpinBox>
#include "info_window.h"

#include <iostream>





QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QSpinBox *data[6][6];

    int row = 3;
    int column = 3;

private:
    Ui::Widget *ui;
    info_window *window;

signals:
    void table_change_signal();

public slots:
    void on_pushButtonSolve_clicked();
    void on_pushButtonClear_clicked();
    void Mouse_Pressed_info();
    void table_change();

    void on_pushButtonAddStocks_clicked();

};
#endif // WIDGET_H
