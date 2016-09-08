#include "myfinancials.h"
#include "ui_myfinancials.h"

MyFinancials::MyFinancials(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFinancials)
{
    ui->setupUi(this);
}

MyFinancials::~MyFinancials()
{
    delete ui;
}
