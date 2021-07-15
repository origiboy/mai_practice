#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
      ui->setupUi(this);
        QGridLayout *gridLayout = new QGridLayout(this);
        gridLayout->setVerticalSpacing(1);
          gridLayout->setHorizontalSpacing(1);
      int i = 0; //строка
      int j = 0; //столбец

      QLabel *title = new QLabel("", this);

      for (i = 0; i < 6; i++) {
          for (j = 0; j < 5; j++) {
              if (i < 2 || j < 1) {
                  if (i == 0 && j == 0 ) {
                      title = new QLabel("Поставщик", this);
                      gridLayout->addWidget(title, 0, 0, 2, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 0 && j == 1 ) {
                      title = new QLabel("Потребитель", this);
                      gridLayout->addWidget(title, 0, 1, 1, 3, Qt::AlignCenter | Qt::AlignVCenter);

                  }
                  if (i == 0 && j == 4 ) {
                      title = new QLabel("Запас", this);
                      gridLayout->addWidget(title, 0, 4, 2, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 1 && j == 1 ) {
                      title = new QLabel("B1", this);
                      gridLayout->addWidget(title, 1, 1, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 1 && j == 2 ) {
                      title = new QLabel("B2", this);
                      gridLayout->addWidget(title, 1, 2, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 1 && j == 3 ) {
                      title = new QLabel("B3", this);
                      gridLayout->addWidget(title, 1, 3, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }

                  if (i == 2 && j == 0 ) {
                      title = new QLabel("A1", this);
                      gridLayout->addWidget(title, 2, 0, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 3 && j == 0 ) {
                      title = new QLabel("A2", this);
                      gridLayout->addWidget(title, 3, 0, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 4 && j == 0 ) {
                      title = new QLabel("A3", this);
                      gridLayout->addWidget(title, 4, 0, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 5 && j == 0 ) {
                      title = new QLabel("Потребность", this);
                      gridLayout->addWidget(title, 5, 0, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
              }
              else {
                  QSpinBox *input = new QSpinBox();
                  gridLayout->addWidget(input, i, j, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
              }
          }
      }
gridLayout->setSpacing(0);

ui->graphicsView->setLayout(gridLayout);



}

Widget::~Widget()
{
    delete ui;
}

