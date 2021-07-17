#ifndef CLICKABLE_LABEL_H
#define CLICKABLE_LABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

class clickable_label: public QLabel
{
    Q_OBJECT
public:
    explicit clickable_label(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
signals:
    void Mouse_Pressed();
public slots:
};

#endif // CLICKABLE_LABEL_H
