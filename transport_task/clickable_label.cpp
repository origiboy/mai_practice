#include "clickable_label.h"

clickable_label::clickable_label(QWidget *parent): QLabel(parent)
{

}

void clickable_label::mousePressEvent(QMouseEvent *event)
{
    emit Mouse_Pressed();
}
