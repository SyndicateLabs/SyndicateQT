#include "myinventory.h"
#include "ui_myinventory.h"

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
               ui->loginPage->hide();
               ui->inventoryPage->show();
               ui->inventoryUsername->clear();
               ui->inventoryPassword->clear();
           }
           if(count<1)
           {
               empman.closeEmployeeDatabase();
               ui->loginPage->show();
               ui->inventoryPage->hide();
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
               ui->loginPage->hide();
               ui->inventoryPage->show();
               ui->inventoryUsername->clear();
               ui->inventoryPassword->clear();
           }
           if(count<1)
           {
               empman.closeEmployeeDatabase();
               ui->loginPage->show();
               ui->inventoryPage->hide();
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
               ui->loginPage->hide();
               ui->inventoryPage->show();
               ui->inventoryUsername->clear();
               ui->inventoryPassword->clear();
           }
           if(count<1)
           {
               empman.closeEmployeeDatabase();
               ui->loginPage->show();
               ui->inventoryPage->hide();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}
