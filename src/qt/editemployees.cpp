#include "editemployees.h"
#include "ui_editemployees.h"
#include "myemployees.h"

#include <QMessageBox>

EditEmployees::EditEmployees(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEmployees)
{
    ui->setupUi(this);
    setWindowTitle(tr("Edit Employee Info"));

    MyEmployees myemp;

    myemp.openEmployeeDatabase();
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(myemp.myemployees);
    query->prepare("select [Employee ID] from employeeinfo");
    query->exec();
    modal->setQuery(*query);
    ui->einlistview->setModel(modal);
    myemp.closeEmployeeDatabase();

    if(!myemp.openEmployeeDatabase())
    {
        ui->statuslabel->setText("Not Connected to Database..");
    }
    else
    {
        ui->statuslabel->setText("Connected to Database..");
    }
    myemp.closeEmployeeDatabase();
}

EditEmployees::~EditEmployees()
{
    delete ui;
}

void EditEmployees::on_savebutton_clicked()
{
    MyEmployees myemp;

        if(ui->einlineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter an employee identification number!"));
        }
        else if(ui->permissionslineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter employee permissions!"));
        }
        else if(ui->firstnameedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a first name!"));
        }
        else if(ui->lastnameedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a last name!"));
        }
        else if(ui->agelineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter an age!"));
        }
        else if(ui->doblineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a date of birth!"));
        }
        else if(ui->addresslineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter an address!"));
        }
        else if(ui->citylineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a city!"));
        }
        else if(ui->statelineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a state!"));
        }
        else if(ui->zipcodelineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a the zip code!"));
        }
        else if(ui->homelineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a home phone number!"));
        }
        else if(ui->celllineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a cell phone number!"));
        }
        else if(ui->emaillineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a cell phone number!"));
        }
        else if(ui->usernamelineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter an username!"));
        }
        else if(ui->passwordlineedit2->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a strong password!"));
        }
        else
        {
            QString ein, permissions, firstname, lastname, age, dob, address, city, state,
                    zipcode, home, cell, email, username, password;

            ein=ui->einlineedit2->text();
            permissions=ui->permissionslineedit2->text();
            firstname=ui->firstnameedit2->text();
            lastname=ui->lastnameedit2->text();
            age=ui->agelineedit2->text();
            dob=ui->doblineedit2->text();
            address=ui->addresslineedit2->text();
            city=ui->citylineedit2->text();
            state=ui->statelineedit2->text();
            zipcode=ui->zipcodelineedit2->text();
            home=ui->homelineedit2->text();
            cell=ui->celllineedit2->text();
            email=ui->emaillineedit2->text();
            username=ui->usernamelineedit2->text();
            password=ui->passwordlineedit2->text();

            myemp.openEmployeeDatabase();
            QSqlQuery query;
            query.prepare("UPDATE employeeinfo set [Employee ID]='"+ein+"', Permissions='"+permissions+"',"
                          "[First Name]='"+firstname+"', [Last Name]='"+lastname+"', Age='"+age+"',"
                          "[Date Of Birth]='"+dob+"', Address='"+address+"', City='"+city+"', State='"+state+"',"
                          "[Zip Code]='"+zipcode+"',[Home Phone]='"+home+"', [Cell Phone]='"+cell+"',"
                          "Email='"+email+"', Username='"+username+"', Password='"+password+"' where [Employee ID]='"+ein+"'");

            ui->einlineedit2->clear();
            ui->permissionslineedit2->clear();
            ui->firstnameedit2->clear();
            ui->lastnameedit2->clear();
            ui->agelineedit2->clear();
            ui->doblineedit2->clear();
            ui->addresslineedit2->clear();
            ui->citylineedit2->clear();
            ui->statelineedit2->clear();
            ui->zipcodelineedit2->clear();
            ui->homelineedit2->clear();;
            ui->celllineedit2->clear();
            ui->emaillineedit2->clear();
            ui->usernamelineedit2->clear();
            ui->passwordlineedit2->clear();

        if(query.exec( ))
        {
            QMessageBox::information(this,tr("Success!"),tr("Employee Information Updated!"));
            myemp.closeEmployeeDatabase();
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }

      }
}

void EditEmployees::on_einlistview_clicked(const QModelIndex &index)
{
    QString val=ui->einlistview->model()->data(index).toString();

    MyEmployees myemp;
    myemp.openEmployeeDatabase();
    QSqlQuery query;
    query.prepare("select * from employeeinfo where [Employee ID]='"+val+"'");

    if (query.exec( ))
    {
        while(query.next())
        {
            ui->einlineedit2->setText(query.value(0).toString());
            ui->permissionslineedit2->setText(query.value(1).toString());
            ui->firstnameedit2->setText(query.value(2).toString());
            ui->lastnameedit2->setText(query.value(3).toString());
            ui->agelineedit2->setText(query.value(4).toString());
            ui->doblineedit2->setText(query.value(5).toString());
            ui->addresslineedit2->setText(query.value(6).toString());
            ui->citylineedit2->setText(query.value(7).toString());
            ui->statelineedit2->setText(query.value(8).toString());
            ui->zipcodelineedit2->setText(query.value(9).toString());
            ui->homelineedit2->setText(query.value(10).toString());
            ui->celllineedit2->setText(query.value(11).toString());
            ui->emaillineedit2->setText(query.value(12).toString());
            ui->usernamelineedit2->setText(query.value(13).toString());
            ui->passwordlineedit2->setText(query.value(14).toString());
        }
        myemp.closeEmployeeDatabase();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void EditEmployees::on_deletebutton_clicked()
{
    QString ein;

    ein=ui->einlineedit2->text();

    MyEmployees myemp;
    myemp.openEmployeeDatabase();
    QSqlQuery query;
    query.prepare("DELETE from employeeinfo where [Employee ID]='"+ein+"'");

    if(query.exec( ))
    {
        QMessageBox::information(this,tr("Success!"),tr("Employee Deleted!"));
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(myemp.myemployees);
    qry->prepare("select [Employee ID] from employeeinfo");
    qry->exec();
    modal->setQuery(*qry);
    ui->einlistview->setModel(modal);
    myemp.closeEmployeeDatabase();

    ui->einlineedit2->clear();
    ui->permissionslineedit2->clear();
    ui->firstnameedit2->clear();
    ui->lastnameedit2->clear();
    ui->agelineedit2->clear();
    ui->doblineedit2->clear();
    ui->addresslineedit2->clear();
    ui->citylineedit2->clear();
    ui->statelineedit2->clear();
    ui->zipcodelineedit2->clear();
    ui->homelineedit2->clear();;
    ui->celllineedit2->clear();
    ui->emaillineedit2->clear();
    ui->usernamelineedit2->clear();
    ui->passwordlineedit2->clear();
}
