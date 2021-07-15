#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
      ui->setupUi(this);

      int i = 6; //строка
      int j = 5; //столбец

      QLabel *title = new QLabel("1 ячейка", this);
      ui->gridLayout->addWidget(title, 0, 0, 1, 1);

      title = new QLabel("2 ячейка", this);
      ui->gridLayout->addWidget(title, 0, 1, 1, 1);

      title = new QLabel("3 ячейка", this);
      ui->gridLayout->addWidget(title, 1, 0, 1, 1);

      title = new QLabel("4 ячейка", this);
      ui->gridLayout->addWidget(title, 1, 1, 1, 1);


}

Widget::~Widget()
{
    delete ui;
}

