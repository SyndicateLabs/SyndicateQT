#include "employeemanager.h"
#include "ui_employeemanager.h"
#include "editemployees.h"
#include "addemployee.h"
#include "syndicate.h"

#include <QFile>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <string>

#include <QMessageBox>

EmployeeManager::EmployeeManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeManager)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);
    setWindowTitle(tr("Employee Manager"));
    createEmployeeDatabase();
    ui->loginpage->show();
    ui->addpage->hide();
}

EmployeeManager::~EmployeeManager()
{
    delete ui;
}

void EmployeeManager::on_loginlogin_clicked()
{
    if(ui->loginusername->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
    }
    else if(ui->loginpassword->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
    }
    else
    {
       QString username,password;
       username=ui->loginusername->text();
       password=ui->loginpassword->text();

       openEmployeeDatabase();
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
               closeEmployeeDatabase();
               viewEmployees();
               login();
           }
           if(count<1)
           {
               closeEmployeeDatabase();
               logout();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void EmployeeManager::on_loginusername_returnPressed()
{    
    if(ui->loginusername->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
    }
    else if(ui->loginpassword->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
    }
    else
    {
       QString username,password;
       username=ui->loginusername->text();
       password=ui->loginpassword->text();

       openEmployeeDatabase();
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
               closeEmployeeDatabase();
               viewEmployees();
               login();
           }
           if(count<1)
           {
               closeEmployeeDatabase();
               logout();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void EmployeeManager::on_loginpassword_returnPressed()
{
    if(ui->loginusername->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
    }
    else if(ui->loginpassword->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
    }
    else
    {
       QString username,password;
       username=ui->loginusername->text();
       password=ui->loginpassword->text();

       openEmployeeDatabase();
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
               closeEmployeeDatabase();
               viewEmployees();
               login();
           }
           if(count<1)
           {
               closeEmployeeDatabase();
               logout();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void EmployeeManager::on_viewemployees_clicked()
{
    viewEmployees();
}

void EmployeeManager::on_editemployees_clicked()
{
    EditEmployees editemployees;
    editemployees.setModal(true);
    editemployees.exec();
}

void EmployeeManager::on_logoutbutton_clicked()
{    
    logout();
}

void EmployeeManager::on_viewemployeetable_doubleClicked(const QModelIndex &index)
{
    EditEmployees editemployees;
    editemployees.setModal(true);
    editemployees.exec();
}

void EmployeeManager::login()
{
    ui->loginpage->hide();
    ui->addpage->show();
    ui->loginusername->clear();
    ui->loginpassword->clear();
}

void EmployeeManager::logout()
{
    ui->loginpage->show();
    ui->addpage->hide();
}

void EmployeeManager::on_pushButton_clicked()
{
    AddEmployee add;
    add.setModal(true);
    add.exec();
}

void EmployeeManager::viewEmployees()
{
    openEmployeeDatabase();
    modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(myemployees);
    query->prepare("select [Employee ID], Permissions, [First Name], "
                   "[Last Name], Age, [Date Of Birth], Address, City, "
                   "State, [Zip Code], [Home Phone], [Cell Phone], Email, "
                   "Username from employeeinfo");
    query->exec();
    modal->setQuery(*query);
    ui->viewemployeetable->setModel(modal);
    ui->viewemployeetable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    closeEmployeeDatabase();
}
