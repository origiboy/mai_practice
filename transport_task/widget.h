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
#include <vector>
#include <algorithm>

#include <iostream>

const int ROWS_MAX = 6, COLUMNS_MAX = 6;



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QSpinBox *data[ROWS_MAX+1][COLUMNS_MAX+1];
    int  cashPrices[ROWS_MAX][COLUMNS_MAX];
    int  cashOrders[COLUMNS_MAX];
    int  cashStocks[ROWS_MAX];

    int rowPrev = 0;
    int columnPrev = 0;


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
    void on_pushButtonAddOrders_clicked();
    void on_pushButtonDeleteStocks_clicked();
    void on_pushButtonDeleteOrders_clicked();

};
#endif // WIDGET_H
