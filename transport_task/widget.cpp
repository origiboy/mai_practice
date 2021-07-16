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

      for (i = 0; i < 3 + row; i++) {
          for (j = 0; j < 2 + column; j++) {
              if (i < 2 || j < 1) {
                  if (i == 0 && j == 0 ) {
                      title = new QLabel("Поставщик", this);
                      gridLayout->addWidget(title, 0, 0, 2, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 0 && j == 1 ) {
                      title = new QLabel("Потребитель", this);
                      gridLayout->addWidget(title, 0, 1, 1, 3, Qt::AlignCenter | Qt::AlignVCenter);

                  }
                  if (i == 0 && j == column + 1 ) {
                      title = new QLabel("Запас", this);
                      gridLayout->addWidget(title, 0, column + 1, 2, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == 1 && j >= 1 && j <= column) {
                      title = new QLabel("B"+QString::number(j), this);
                      gridLayout->addWidget(title, 1, j, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }

                  if (j == 0 && i >= 2 && i <= row + 1) {
                      title = new QLabel("A"+QString::number(i-1), this);
                      gridLayout->addWidget(title, i, 0, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }
                  if (i == row + 2 && j == 0 ) {
                      title = new QLabel("Потребность", this);
                      gridLayout->addWidget(title, row + 2, 0, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                  }

              }
              else {
                if (i >= 2 && j >= 1) {
                    data[i-2][j-1] = new QSpinBox();
                    gridLayout->addWidget(data[i-2][j-1], i, j, 1, 1, Qt::AlignCenter | Qt::AlignVCenter);
                    data[i-2][j-1]->setButtonSymbols(QSpinBox::NoButtons);
                }

              }
          }
      }
gridLayout->setSpacing(0);

ui->graphicsView->setLayout(gridLayout);


}


void Widget::on_pushButtonSolve_clicked() {
    // Движок расчёта задачи
    int i = 0; //строка
    int j = 0; //столбец

    int taskData[row][column];


    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            taskData[i][j] = data[i+2][j+1]->value();
        }
    }

}

Widget::~Widget()
{
    delete ui;
}

