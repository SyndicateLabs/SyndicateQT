#include "myinventory.h"
#include "ui_myinventory.h"

MyInventory::MyInventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyInventory)
{
    ui->setupUi(this);
    setWindowTitle(tr("My Inventory"));
}

MyInventory::~MyInventory()
{
    delete ui;
}
