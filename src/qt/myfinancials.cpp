#include "myfinancials.h"
#include "ui_myfinancials.h"

MyFinancials::MyFinancials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyFinancials)
{
    ui->setupUi(this);
    setWindowTitle(tr("My Financials"));
    setWindowFlags(Qt::Window);
}

MyFinancials::~MyFinancials()
{
    delete ui;
}
