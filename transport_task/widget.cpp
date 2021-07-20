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

vector <int> min_elem(int **&prices, int &providers, int &consumers, vector <int> &block_i, vector <int> &block_j)
{
    vector <int> indexes(2);
    int low = 9999;
    bool unlocked_i = true, unlocked_j = true;
    for (int i = 0; i < providers; i++)
    {
        for (int j = 0; j < consumers; j++)
        {
            if (find(block_i.begin(), block_i.end(), i) != block_i.end())
            {
                unlocked_i = false;
            }

            if (find(block_j.begin(), block_j.end(), j) != block_j.end())
            {
                unlocked_j = false;
            }

            if (low > prices[i][j] && unlocked_i && unlocked_j)
            {
                low = prices[i][j];
                indexes[0] = i;
                indexes[1] = j;
            }
            unlocked_i = true;
            unlocked_j = true;
        }
    }
    return indexes;
}

void least_cost(int **&plan, int **&prices, int *&stocks, int *&orders, int &providers, int &consumers)
{
    vector <int> block_i, block_j;
    vector <int> indexes(2);
    int *copy_orders = new  int [consumers];
    int *copy_stocks = new  int [providers];
    int a = 0, b = 0, p = 0, i_min = 0, j_min = 0;
    copy(orders, orders + consumers, copy_orders);
    copy(stocks, stocks + providers, copy_stocks);
    for (int i = 0; i < providers; i++)
    {
        a += stocks[i];
    }
    for (int i = 0; i < consumers; i++)
    {
        b += orders[i];
    }
    while (true)
    {
        if (a == 0 && b == 0)
        {
            break;
        }
        indexes = min_elem(prices, providers, consumers, block_i, block_j);
        i_min = indexes[0];
        j_min = indexes[1];
        if (copy_stocks[i_min] <= copy_orders[j_min])
        {
            plan[i_min][j_min] = copy_stocks[i_min];
            a -= copy_stocks[i_min];
            b -= copy_stocks[i_min];
            copy_orders[j_min] -= copy_stocks[i_min];
            block_i.push_back(i_min);
        }
        else if (copy_stocks[i_min] >= copy_orders[j_min])
        {
            plan[i_min][j_min] = copy_orders[j_min];
            a -= copy_orders[j_min];
            b -= copy_orders[j_min];
            copy_stocks[i_min] -= copy_orders[j_min];
            block_j.push_back(j_min);
        }
    }
    delete [] copy_orders;
    delete [] copy_stocks;
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

    ui->inputTable->setRowCount(0);
    ui->inputTable->setColumnCount(0);

    ui->inputTable->setRowCount(3 + row);
    ui->inputTable->setColumnCount(2 + column);


    int i = 0; //строка
    int j = 0; //столбец


  for (i = 0; i < 3 + row; i++) {
      for (j = 0; j < 2 + column; j++) {
          if (i < 2 || j < 1) {
              if (i == 0 && j == 0 ) {
                  QTableWidgetItem *item = new QTableWidgetItem("Поставщик");
                  item->setTextAlignment(Qt::AlignCenter);
                  item->setBackgroundColor("#c1caca");
                  ui->inputTable->setItem(i, j, item);
                  ui->inputTable->setSpan(i, j, 2, 1);
              }
              if (i == 0 && j == 1 ) {
                  QTableWidgetItem *item = new QTableWidgetItem("Потребитель");
                  item->setTextAlignment(Qt::AlignCenter);
                  item->setBackgroundColor("#c1caca");
                  ui->inputTable->setItem(i, j, item);
                  ui->inputTable->setSpan(i, j, 1, column);
              }

              if (i == 1 && j >= 1 && j <= column) {
                  QTableWidgetItem *item = new QTableWidgetItem("B"+QString::number(j));
                  item->setTextAlignment(Qt::AlignCenter);
                  item->setBackgroundColor("#c1caca");
                  ui->inputTable->setItem(i, j, item);
              }

              if (j == 0 && i >= 2 && i <= row + 1) {
                  QTableWidgetItem *item = new QTableWidgetItem("A"+QString::number(i-1));
                  item->setTextAlignment(Qt::AlignCenter);
                  item->setBackgroundColor("#c1caca");
                  ui->inputTable->setItem(i, j, item);
              }
              if (i == 0 && j == column + 1 ) {
                  QTableWidgetItem *item = new QTableWidgetItem("Запас");
                  item->setTextAlignment(Qt::AlignCenter);
                  ui->inputTable->setItem(i, j, item);
                  item->setBackgroundColor("#c1caca");
                  ui->inputTable->setSpan(i, j, 2, 1);
              }
              if (i == row + 2 && j == 0 ) {
                  QTableWidgetItem *item = new QTableWidgetItem("Потребность");
                  item->setTextAlignment(Qt::AlignCenter);
                  item->setBackgroundColor("#c1caca");
                  ui->inputTable->setItem(i, j, item);
              }

          }
          else {
            if (i >= 2 && j >= 1 && !(i == row + 2 && j == column + 1)) {
                data[i-2][j-1] = new QSpinBox();
                data[i-2][j-1]->setAlignment(Qt::AlignCenter);
                ui->inputTable->setCellWidget(i, j, data[i-2][j-1]);
                data[i-2][j-1]->setButtonSymbols(QSpinBox::NoButtons);
            }

                    QTableWidgetItem *item = new QTableWidgetItem();
                    item->setTextAlignment(Qt::AlignCenter);
                    item->setBackgroundColor("#998200");
                    ui->inputTable->setItem(i, j, item);


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
            if (!(i == row && j == column)) {
                data[i][j]->setValue(0);
            }
        }
    }
}

void Widget::on_pushButtonSolve_clicked() {

    // Подготовка данных
    int i = 0; //строка
    int j = 0; //столбец

    bool method = ui->methodFirst->isChecked();

    int taskData[row+1][column+1];


    for (i = 0; i < row+1; i++) {
        for (j = 0; j < column+1; j++) {

            if (!(i == row && j == column)) {
                taskData[i][j] = data[i][j]->value();
            } else {
                taskData[i][j] = 0;
            }

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

        if (method) {
            northwest_corner(plan, stocks, orders, providers, consumers);
        } else {
            least_cost(plan, prices, stocks, orders, providers, consumers);
        }


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
          delete [] prices[i];
      }


      delete [] prices;
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

