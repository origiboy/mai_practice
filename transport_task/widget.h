#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include <QMessageBox>
#include <QGridLayout>
#include <QSpinBox>
#include <QString>

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
    QGridLayout *gridLayout, *answerGrid;
    QSpinBox *data[6][6];

    int row = 3;
    int column = 3;

private:
    Ui::Widget *ui;

public slots:
    void on_pushButtonSolve_clicked();

};
#endif // WIDGET_H
