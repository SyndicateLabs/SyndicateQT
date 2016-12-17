#include "addproduct.h"
#include "ui_addproduct.h"

#include "QMessageBox"

AddProduct::AddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
{
    ui->setupUi(this);
    setWindowTitle(tr("Add Product"));
}

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_addButton_clicked()
{
    if(ui->nameEdit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a product name!"));
    }
    else if(ui->manEdit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter the manufacturer!"));
    }
    else if(ui->quanEdit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter the quantity!"));
    }
    else if(ui->skuEdit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter the SKU number"));
    }
    else if(ui->barEdit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter barcode number!"));
    }
    else if(ui->listEdit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter the list price!"));
    }
    else if(ui->netEdit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter the cost price!"));
    }
    else
    {
        QString name, man, quan, sku, bar, list, net, discount;

        name=ui->nameEdit->text();
        man=ui->manEdit->text();
        quan=ui->quanEdit->text();
        sku=ui->skuEdit->text();
        bar=ui->barEdit->text();
        list=ui->listEdit->text();
        net=ui->netEdit->text();
        discount=ui->disEdit->text();

        inventory.openInventoryDatabase();
        QSqlQuery query;
        query.prepare("INSERT INTO inventoryinfo ([Product Name], Manufacturer, Quantity, SKU,"
                      "Barcode, [Retail Price], [Vendor Cost], Discount)"
                      "values ('"+name+"', '"+man+"', '"+quan+"', '"+sku+"', '"+bar+"',"
                      "'"+list+"', '"+net+"', '"+discount+"')");

        ui->nameEdit->clear();
        ui->manEdit->clear();
        ui->quanEdit->clear();
        ui->skuEdit->clear();
        ui->barEdit->clear();
        ui->listEdit->clear();
        ui->netEdit->clear();
        ui->disEdit->clear();

    if(query.exec( ))
    {
        QMessageBox::information(this,tr("Success!"),tr("Product Added!"));
        inventory.closeInventoryDatabase();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
        inventory.closeInventoryDatabase();
    }

    updateAll();

  }
}

void AddProduct::updateAll()
{
    inventory.viewInventory();
    inventory.listSum();
    inventory.netSum();
    inventory.quanSum();
    inventory.profitTotal();
}
