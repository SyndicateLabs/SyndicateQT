#include "myemployees.h"
#include "ui_myemployees.h"
#include "editemployees.h"

#include <QFile>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <string>

#include <QMessageBox>

MyEmployees::MyEmployees(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyEmployees)
{
    ui->setupUi(this);

        ui->loginpage->show();
        ui->addpage->hide();
        ui->status_2->hide();
        ui->tabWidget->hide();

    openEmployeeDatabase();
    QSqlQuery query;
    query.prepare("CREATE TABLE employeeinfo (`Employee ID` varchar(255) primary key, Permissions varchar(255),"
                  "`First Name` varchar(255),`Last Name` varchar(255),Age integer, `Date Of Birth` varchar(255),"
                  "Address varchar(255),City varchar(255),State varchar(255), `Zip Code` integer,"
                  "`Home Phone` varchar(255),`Cell Phone` varchar(255),Email varchar(255),Username varchar(255),"
                  "Password varchar(255))");
    query.exec();
    query.prepare("INSERT INTO employeeinfo ([Employee ID], Permissions, Username, Password)"
                  "values ('001', 'Admin', 'Admin', 'Admin')");
    query.exec();
    closeEmployeeDatabase();

    if(!openEmployeeDatabase())
    {
        ui->status->setText("Not Connected to Database..");
        ui->status_2->setText("Not Connected to Database..");
    }
    else
    {
        ui->status->setText("Connected to Database..");
        ui->status_2->setText("Connected to Database..");
    }
}

MyEmployees::~MyEmployees()
{
    delete ui;
}

void MyEmployees::on_loginlogin_clicked()
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
               ui->loginpage->hide();
               ui->status_2->show();
               ui->addpage->show();
               ui->tabWidget->show();
               ui->loginusername->clear();
               ui->loginpassword->clear();
           }
           if(count<1)
           {
               closeEmployeeDatabase();
               ui->loginpage->show();
               ui->addpage->hide();
               ui->status_2->hide();
               ui->tabWidget->hide();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void MyEmployees::on_loginusername_returnPressed()
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
               ui->loginpage->hide();
               ui->status_2->show();
               ui->addpage->show();
               ui->tabWidget->show();
               ui->loginusername->clear();
               ui->loginpassword->clear();
           }
           if(count<1)
           {
               closeEmployeeDatabase();
               ui->loginpage->show();
               ui->addpage->hide();
               ui->status_2->hide();
               ui->tabWidget->hide();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void MyEmployees::on_loginpassword_returnPressed()
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
               ui->loginpage->hide();
               ui->status_2->show();
               ui->addpage->show();
               ui->tabWidget->show();
               ui->loginusername->clear();
               ui->loginpassword->clear();
           }
           if(count<1)
           {
               closeEmployeeDatabase();
               ui->loginpage->show();
               ui->addpage->hide();
               ui->status_2->hide();
               ui->tabWidget->hide();
               QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
           }
       }
   }
}

void MyEmployees::on_savebutton_clicked()
{
    if(ui->einlineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter an employee identification number!"));
    }
    else if(ui->permissionslineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter employee permissions!"));
    }
    else if(ui->firstnameedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a first name!"));
    }
    else if(ui->lastnameedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a last name!"));
    }
    else if(ui->agelineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter an age!"));
    }
    else if(ui->doblineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a date of birth!"));
    }
    else if(ui->addresslineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter an address!"));
    }
    else if(ui->citylineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a city!"));
    }
    else if(ui->statelineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a state!"));
    }
    else if(ui->zipcodelineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a the zip code!"));
    }
    else if(ui->homelineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a home phone number!"));
    }
    else if(ui->celllineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a cell phone number!"));
    }
    else if(ui->emaillineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a cell phone number!"));
    }
    else if(ui->usernamelineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter an username!"));
    }
    else if(ui->passwordlineedit->text() == "")
    {
        QMessageBox::critical(this,tr("Error!"),tr("Please enter a strong password!"));
    }
    else
    {
        QString ein, permissions, firstname, lastname, age, dob, address, city, state,
                zipcode, home, cell, email, username, password;

        ein=ui->einlineedit->text();
        permissions=ui->permissionslineedit->text();
        firstname=ui->firstnameedit->text();
        lastname=ui->lastnameedit->text();
        age=ui->agelineedit->text();
        dob=ui->doblineedit->text();
        address=ui->addresslineedit->text();
        city=ui->citylineedit->text();
        state=ui->statelineedit->text();
        zipcode=ui->zipcodelineedit->text();
        home=ui->homelineedit->text();
        cell=ui->celllineedit->text();
        email=ui->emaillineedit->text();
        username=ui->usernamelineedit->text();
        password=ui->passwordlineedit->text();

        openEmployeeDatabase();
        QSqlQuery query;
        query.prepare("INSERT INTO employeeinfo ([Employee ID], Permissions, [First Name],"
                      "[Last Name], Age, [Date Of Birth], Address, City, State, [Zip Code],"
                      "[Home Phone], [Cell Phone], Email, Username, Password)"
                      "values ('"+ein+"', '"+permissions+"', '"+firstname+"', '"+lastname+"',"
                      "'"+age+"', '"+dob+"', '"+address+"', '"+city+"', '"+state+"', '"+zipcode+"',"
                      "'"+home+"', '"+cell+"', '"+email+"', '"+username+"', '"+password+"')");

        ui->einlineedit->clear();
        ui->permissionslineedit->clear();
        ui->firstnameedit->clear();
        ui->lastnameedit->clear();
        ui->agelineedit->clear();
        ui->doblineedit->clear();
        ui->addresslineedit->clear();
        ui->citylineedit->clear();
        ui->statelineedit->clear();
        ui->zipcodelineedit->clear();
        ui->homelineedit->clear();;
        ui->celllineedit->clear();
        ui->emaillineedit->clear();
        ui->usernamelineedit->clear();
        ui->passwordlineedit->clear();

    if(query.exec( ))
    {
        QMessageBox::information(this,tr("Success!"),tr("Employee Saved!"));
        closeEmployeeDatabase();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
        closeEmployeeDatabase();
    }
  }
}

void MyEmployees::on_clearinfo_clicked()
{
    if(" ui->einlineedit->text() == "" & "
       " ui->agelineedit->text() == "" & "
       " ui->doblineedit->text() == "" & "
       " ui->lastnameedit->text() == "" & "
       " ui->citylineedit->text() == "" & "
       " ui->homelineedit->text() == "" & "
       " ui->celllineedit->text() == "" & "
       " ui->statelineedit->text() == "" & "
       " ui->emaillineedit->text() == "" & "
       " ui->firstnameedit->text() == "" & "
       " ui->addresslineedit->text() == "" & "
       " ui->zipcodelineedit->text() == "" & "
       " ui->usernamelineedit->text() == "" & "
       " ui->passwordlineedit->text() == "" & "
       " ui->permissionslineedit->text() == "" & "
       " ui->permissionslineedit->text() == "" & "
       " ui->permissionslineedit->text() == "" & "
       " ui->permissionslineedit->text() == "" ")
    {
        QMessageBox::critical(this,tr("Error!"),tr("All fields are empty!"));
    }
    else
    {
    ui->einlineedit->clear();
    ui->permissionslineedit->clear();
    ui->firstnameedit->clear();
    ui->lastnameedit->clear();
    ui->agelineedit->clear();
    ui->doblineedit->clear();
    ui->addresslineedit->clear();
    ui->citylineedit->clear();
    ui->statelineedit->clear();
    ui->zipcodelineedit->clear();
    ui->homelineedit->clear();;
    ui->celllineedit->clear();
    ui->emaillineedit->clear();
    ui->usernamelineedit->clear();
    ui->passwordlineedit->clear();
    }
}

void MyEmployees::on_viewemployees_clicked()
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

void MyEmployees::on_editemployees_clicked()
{
    EditEmployees editemployees;
    editemployees.setModal(true);
    editemployees.exec();
}

void MyEmployees::on_logoutbutton_clicked()
{    
    ui->loginpage->show();
    ui->addpage->hide();
    ui->status_2->hide();
    ui->tabWidget->hide();
}
