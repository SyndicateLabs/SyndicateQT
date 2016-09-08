#include "mybusiness.h"
#include "ui_mybusiness.h"

MyBusiness::MyBusiness(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyBusiness)
{
    ui->setupUi(this);
}

MyBusiness::~MyBusiness()
{
    delete ui;
}
