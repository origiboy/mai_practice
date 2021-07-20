#include "widget.h"
#include "ui_widget.h"
#include "QAbstractSpinBox"
#include "clickable_label.h"

using namespace std;

void closure(int *&mas, int &size, int value)
{
    int *newmas = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        newmas[i] = mas[i];
    }
    newmas[size] = value;

    delete [] mas;

    mas = newmas;

    size++;
}

void northwest_corner(int **&plan, int *&stocks, int *&orders, int &providers, int &consumers)
{
    int last_order = 0;

    int *copy_orders = new  int [consumers];

    copy(orders, orders + consumers, copy_orders);

    for (int i = 0; i < providers; i++)
    {
        int stock = stocks[i];
        for (int j = last_order; j < consumers; j++)
        {
            if (stock > copy_orders[j])
            {
                plan[i][j] = copy_orders[j];
                stock -= copy_orders[j];
            }
            else
            {
                plan[i][j] = stock;
                copy_orders[j] -= stock;
                last_order = j;
                break;
            }
        }
    }

    delete [] copy_orders;
}

int z(int **&plan, int **&prices, int &providers, int &consumers)
{
    int z = 0;

    for (int i = 0; i < providers; i++)
    {
        for (int j = 0; j < consumers; j++)
        {
            z += plan[i][j] * prices[i][j];
        }
    }

    return z;
}



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{


        window = new info_window();

        ui->setupUi(this);
        connect(ui->label, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed_info()));
        connect(this, &Widget::table_change_signal, this, &Widget::table_change);

        ui->pushButtonDeleteStocks->setDisabled(true);
        ui->pushButtonDeleteOrders->setDisabled(true);


        table_change_signal();
}

void Widget::table_change()
{
    ui->inputTable->verticalHeader()->hide();
    ui->inputTable->horizontalHeader()->hide();


    ui->inputTable->setRowCount(3 + row);
    ui->inputTable->setColumnCount(2 + column);


    int i = 0; //строка
    int j = 0; //столбец



  QLabel *title = new QLabel("", this);

  for (i = 0; i < 3 + row; i++) {
      for (j = 0; j < 2 + column; j++) {
          if (i < 2 || j < 1) {
              if (i == 0 && j == 0 ) {
                  title = new QLabel("Поставщик", this);
                  ui->inputTable->setCellWidget(i, j, title);
              }
              if (i == 0 && j == 1 ) {
                  title = new QLabel("Потребитель", this);
                  ui->inputTable->setCellWidget(i, j, title);
              }
              if (i == 0 && j == column + 1 ) {
                  title = new QLabel("Запас", this);
                  ui->inputTable->setCellWidget(i, j, title);
              }
              if (i == 1 && j >= 1 && j <= column) {
                  title = new QLabel("B"+QString::number(j), this);
                  ui->inputTable->setCellWidget(i, j, title);
              }

              if (j == 0 && i >= 2 && i <= row + 1) {
                  title = new QLabel("A"+QString::number(i-1), this);
                  ui->inputTable->setCellWidget(i, j, title);
              }
              if (i == row + 2 && j == 0 ) {
                  title = new QLabel("Потребность", this);
                  ui->inputTable->setCellWidget(i, j, title);
              }

          }
          else {
            if (i >= 2 && j >= 1) {
                data[i-2][j-1] = new QSpinBox();
                ui->inputTable->setCellWidget(i, j, data[i-2][j-1]);
                data[i-2][j-1]->setButtonSymbols(QSpinBox::NoButtons);
            }

          }
      }
  }


  ui->inputTable->horizontalHeader()->resizeSections(QHeaderView::Stretch);
  ui->inputTable->verticalHeader()->resizeSections(QHeaderView::Stretch);
  ui->inputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void Widget::on_pushButtonClear_clicked() {
    int i = 0; //строка
    int j = 0; //столбец
    for (i = 0; i < row+1; i++) {
        for (j = 0; j < column+1; j++) {
            data[i][j]->setValue(0);
        }
    }
}

void Widget::on_pushButtonSolve_clicked() {

    // Подготовка данных
    int i = 0; //строка
    int j = 0; //столбец

    int taskData[row+1][column+1];


    for (i = 0; i < row+1; i++) {
        for (j = 0; j < column+1; j++) {
            taskData[i][j] = data[i][j]->value();
        }
    }




    // Движок расчёта задачи

      int providers = row;
      int consumers = column;

      ui->answerTable->verticalHeader()->hide();
      ui->answerTable->horizontalHeader()->hide();

      int *stocks = new int [providers];
      int *orders = new int [consumers];


      for (int i = 0; i < providers; i++)
      {
          stocks[i] = taskData[i][column];
      }

      for (int j = 0; j < consumers; j++)
      {
          orders[j] = taskData[row][j];
      }

      int a = 0, b = 0;

      for (int i = 0; i < providers; i++)
      {
          a += stocks[i];
      }

      for (int i = 0; i < consumers; i++)
      {
          b += orders[i];
      }


      if (a < b)
      {
          closure(stocks, providers, b - a);
      } else if (a > b)
      {
          closure(orders, consumers, a - b);
      }

      ui->answerTable->setRowCount(providers);
      ui->answerTable->setColumnCount(consumers);

      int **plan = new int* [providers];
      int **prices = new int* [providers];

      for (int i = 0; i < providers; i++)
      {
          prices[i] = new int [consumers];
      }



      for (int i = 0; i < providers; i++)
      {
          for (int j = 0; j < consumers; j++)
          {
            prices[i][j] = taskData[i][j];
          }
      }

      for (int i = 0; i < providers; i++)
      {
          plan[i] = new int [consumers];
      }

      for (int i = 0; i < providers; i++)
      {
          for (int j = 0; j < consumers; j++)
          {
              plan[i][j] = 0;
          }
      }

      northwest_corner(plan, stocks, orders, providers, consumers);

      ui->functionValue->setText(QString("Значение целевой функции = ") + QString::number(z(plan, prices, providers, consumers)));


      for (int i = 0; i < providers; i++)
      {
          for (int j = 0; j < consumers; j++)
          {
              QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(plan[i][j]));
              item->setTextAlignment(Qt::AlignCenter);
              ui->answerTable->setItem(i, j, item);
          }
      }

      ui->answerTable->horizontalHeader()->resizeSections(QHeaderView::Stretch);
      ui->answerTable->verticalHeader()->resizeSections(QHeaderView::Stretch);
      ui->answerTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //Чтобы нельзя было редачить


      for (int i = 0; i < providers; i++)
      {
          delete [] plan[i];
      }


    //  delete [] prices;
      delete [] stocks;
      delete [] orders;
      delete [] plan;
}

void Widget::on_pushButtonAddStocks_clicked() {
    if (row < ROWS_MAX) {
        row++;
        ui->pushButtonDeleteStocks->setDisabled(false);
        if (row == ROWS_MAX) {
            ui->pushButtonAddStocks->setDisabled(true);
        }
        table_change_signal();
    }
}

void Widget::on_pushButtonAddOrders_clicked() {
    if (column < COLUMNS_MAX) {
        column++;
        ui->pushButtonDeleteOrders->setDisabled(false);
        if (column == COLUMNS_MAX) {
            ui->pushButtonAddOrders->setDisabled(true);
        }
        table_change_signal();
    }
}

void Widget::on_pushButtonDeleteStocks_clicked() {
    if (row > 3) {
        row--;
        ui->pushButtonAddStocks->setDisabled(false);
        if (row == 3) {
            ui->pushButtonDeleteStocks->setDisabled(true);
        }
        table_change_signal();
    }
}

void Widget::on_pushButtonDeleteOrders_clicked() {
    if (column > 3) {
        ui->pushButtonAddOrders->setDisabled(false);
        column--;
        if (column == 3) {
            ui->pushButtonDeleteOrders->setDisabled(true);
        }
        table_change_signal();
    }
}

void Widget::Mouse_Pressed_info()
{
    window->show();
}

Widget::~Widget()
{
    delete ui;
}

