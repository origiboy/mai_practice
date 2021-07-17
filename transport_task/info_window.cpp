#include "info_window.h"
#include "ui_info_window.h"

info_window::info_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info_window)
{
    ui->setupUi(this);
}

info_window::~info_window()
{
    delete ui;
}
