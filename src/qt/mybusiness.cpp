#include "mybusiness.h"
#include "ui_mybusiness.h"

MyBusiness::MyBusiness(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyBusiness)
{
    ui->setupUi(this);
    setWindowTitle(tr("My Business"));
}

MyBusiness::~MyBusiness()
{
    delete ui;
}
