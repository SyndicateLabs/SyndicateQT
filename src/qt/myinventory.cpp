#include "myinventory.h"
#include "ui_myinventory.h"

#include "addproduct.h"

#include <QFile>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <string>

#include <QMessageBox>

MyInventory::MyInventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyInventory)
{
    ui->setupUi(this);
    setWindowTitle(tr("My Inventory"));
    ui->loginPage->show();
    ui->inventoryPage->hide();
    createInventoryDatabase();
    setWindowFlags(Qt::Window);
    listSum();
    netSum();
    quanSum();
    profitTotal();
}

MyInventory::~MyInventory()
{
    delete ui;
}

void MyInventory::on_inventoryLoginButton_clicked()
{
    if(ui->inventoryUsername->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
    }
    else if(ui->inventoryPassword->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
    }
    else
    {
       QString username,password;
       username=ui->inventoryUsername->text();
       password=ui->inventoryPassword->text();

       empman.openEmployeeDatabase();
       QSqlQuery query;
       query.prepare("SELECT * FROM employeeinfo WHERE username='"+username+"' and password='"+password+"'");
       if(query.exec())
       {
           count=0;
           while(query.next())
           {
               count++;
           }
           if(count==1)
           {
               empman.closeEmployeeDatabase();
               login();
               viewInventory();
           }
           if(count<1)
           {
               empman.closeEmployeeDatabase();
               logout();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void MyInventory::on_inventoryUsername_returnPressed()
{
    if(ui->inventoryUsername->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
    }
    else if(ui->inventoryPassword->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
    }
    else
    {
       QString username,password;
       username=ui->inventoryUsername->text();
       password=ui->inventoryPassword->text();

       empman.openEmployeeDatabase();
       QSqlQuery query;
       query.prepare("SELECT * FROM employeeinfo WHERE username='"+username+"' and password='"+password+"'");
       if(query.exec())
       {
           count=0;
           while(query.next())
           {
               count++;
           }
           if(count==1)
           {
               empman.closeEmployeeDatabase();
               login();
               viewInventory();
           }
           if(count<1)
           {
               empman.closeEmployeeDatabase();
               logout();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void MyInventory::on_inventoryPassword_returnPressed()
{
    if(ui->inventoryUsername->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
    }
    else if(ui->inventoryPassword->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
    }
    else
    {
       QString username,password;
       username=ui->inventoryUsername->text();
       password=ui->inventoryPassword->text();

       empman.openEmployeeDatabase();
       QSqlQuery query;
       query.prepare("SELECT * FROM employeeinfo WHERE username='"+username+"' and password='"+password+"'");
       if(query.exec())
       {
           count=0;
           while(query.next())
           {
               count++;
           }
           if(count==1)
           {
               empman.closeEmployeeDatabase();
               login();
               viewInventory();
           }
           if(count<1)
           {
               empman.closeEmployeeDatabase();
               logout();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void MyInventory::login()
{
    ui->loginPage->hide();
    ui->inventoryPage->show();
    ui->inventoryUsername->clear();
    ui->inventoryPassword->clear();
}

void MyInventory::logout()
{
    ui->loginPage->show();
    ui->inventoryPage->hide();
}

void MyInventory::on_addProductButton_clicked()
{
    AddProduct add;
    add.setModal(true);
    add.exec();
}

void MyInventory::viewInventory()
{
    openInventoryDatabase();
    inventorymodal=new QSqlQueryModel();
    QSqlQuery* query2=new QSqlQuery(inventorydb);
    query2->prepare("select [Product Name], Manufacturer, Quantity, SKU, "
                   "Barcode, [Retail Price], [Vendor Cost], Discount FROM inventoryinfo");
    query2->exec();
    inventorymodal->setQuery(*query2);
    ui->inventoryTable->setModel(inventorymodal);
    ui->inventoryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    closeInventoryDatabase();
}

void MyInventory::listSum()
{
    openInventoryDatabase();
    QSqlQuery query;
    query.exec("SELECT SUM ([Retail Price]) FROM inventoryinfo");
    if (query.next())
    {
        currentSum.append(query.value(0).toString());
    }
    query.finish();
    double total = currentSum.toDouble();
    QString totalSum = QString::number(total);
    ui->listSum->setText("$" + totalSum);
    closeInventoryDatabase();
}

void MyInventory::netSum()
{
    openInventoryDatabase();
    QSqlQuery query;
    query.exec("SELECT SUM ([Vendor Cost]) FROM inventoryinfo");
    if (query.next())
    {
        currentNet.append(query.value(0).toString());
    }
    query.finish();
    double total = currentNet.toDouble();
    QString totalSum = QString::number(total);
    ui->netSum->setText("$" + totalSum);
    closeInventoryDatabase();
}

void MyInventory::quanSum()
{
    openInventoryDatabase();    
    QSqlQuery query;
    query.exec("SELECT SUM (Quantity) FROM inventoryinfo");
    if (query.next())
    {
        quantSum.append(query.value(0).toString());
    }
    query.finish();
    ui->quanSum->setText(quantSum);
    closeInventoryDatabase();
}

void MyInventory::profitTotal()
{
    double list = currentSum.toDouble();
    double cost = currentNet.toDouble();

    double net = list - cost;

    QString profitTotal = QString::number(net);

    ui->profitSum->setText('$' + profitTotal);
}
