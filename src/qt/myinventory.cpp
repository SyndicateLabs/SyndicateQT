#include "myinventory.h"
#include "ui_myinventory.h"

MyInventory::MyInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyInventory)
{
    ui->setupUi(this);
}

MyInventory::~MyInventory()
{
    delete ui;
}
