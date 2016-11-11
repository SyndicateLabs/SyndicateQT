#include "addemployee.h"
#include "ui_addemployee.h"

#include <QMessageBox>

AddEmployee::AddEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployee)
{
    ui->setupUi(this);
    setWindowTitle(tr("Employee Registration"));
}

AddEmployee::~AddEmployee()
{
    delete ui;
}

void AddEmployee::on_savebutton_clicked()
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

        emp.openEmployeeDatabase();
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
        emp.closeEmployeeDatabase();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
        emp.closeEmployeeDatabase();
    }
  }
}

void AddEmployee::on_clearinfo_clicked()
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
