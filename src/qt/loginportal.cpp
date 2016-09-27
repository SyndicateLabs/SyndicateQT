#include "loginportal.h"
#include "ui_loginportal.h"

#include <QFile>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <string>

#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>

LoginPortal::LoginPortal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPortal)
{
    ui->setupUi(this);

        ui->loginpage->show();
        ui->clockinpage->hide();
        ui->portalstatus2->hide();

        openEmployeePortal();
        QSqlQuery query;
        query.prepare("CREATE TABLE employeeportal (`Time In` varchar(255), `Time Out` varchar(255))");
        query.exec();
        closeEmployeePortal();

    if(!openEmployeePortal())
    {
        ui->portalstatus->setText("Not Connected to Database..");
        ui->portalstatus2->setText("Not Connected to Database..");
    }
    else
    {
        ui->portalstatus->setText("Connected to Database..");
        ui->portalstatus2->setText("Connected to Database..");
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(localTime()));
    timer->start();	
}

LoginPortal::~LoginPortal()
{
    delete ui;
}

void LoginPortal::localTime()
{
    QTime localTime = QTime::currentTime();
    QString timetext = localTime.toString("hh : mm : ss");
    ui->currenttime->setText(timetext);
}

void LoginPortal::on_portalloginlogin_clicked()
{    
    if(ui->portalloginusername->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
        }
        else if(ui->portalloginpassword->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
        }
        else
        {
        QString username,password;
        username=ui->portalloginusername->text();
        password=ui->portalloginpassword->text();

        login.openEmployeeDatabase();
        QSqlQuery query;
        query.prepare("SELECT * FROM employeeinfo where username='"+username+"' and password='"+password+"'");
        if(query.exec( ))
        {
            count=0;
            while(query.next())
            {
                count++;
            }
            if(count==1)
            {
                login.closeEmployeeDatabase();
                ui->loginpage->hide();
                ui->portalstatus2->show();
                ui->clockinpage->show();
                ui->portalloginusername->clear();
                ui->portalloginpassword->clear();
                ui->logoutbutton->show();
            }
            if(count<1)
            {
                login.closeEmployeeDatabase();
                ui->loginpage->show();
                ui->clockinpage->hide();
                QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));

            }
        }
      }
}

void LoginPortal::on_portalloginusername_returnPressed()
{
    if(ui->portalloginusername->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
        }
        else if(ui->portalloginpassword->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
        }
        else
        {
        QString username,password;
        username=ui->portalloginusername->text();
        password=ui->portalloginpassword->text();

        login.openEmployeeDatabase();
        QSqlQuery query;
        query.prepare("SELECT * FROM employeeinfo where username='"+username+"' and password='"+password+"'");
        if(query.exec( ))
        {
            count=0;
            while(query.next())
            {
                count++;
            }
            if(count==1)
            {
                login.closeEmployeeDatabase();
                ui->loginpage->hide();
                ui->portalstatus2->show();
                ui->clockinpage->show();
                ui->portalloginusername->clear();
                ui->portalloginpassword->clear();
                ui->logoutbutton->show();
            }
            if(count<1)
            {
                login.closeEmployeeDatabase();
                ui->loginpage->show();
                ui->clockinpage->hide();
                QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));

            }
        }
      }
}

void LoginPortal::on_portalloginpassword_returnPressed()
{
    if(ui->portalloginusername->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter a username!"));
        }
        else if(ui->portalloginpassword->text() == "")
        {
            QMessageBox::critical(this,tr("Error!"),tr("Please enter your password!"));
        }
        else
        {
        QString username,password;
        username=ui->portalloginusername->text();
        password=ui->portalloginpassword->text();

        login.openEmployeeDatabase();
        QSqlQuery query;
        query.prepare("SELECT * FROM employeeinfo where username='"+username+"' and password='"+password+"'");
        if(query.exec( ))
        {
            count=0;
            while(query.next())
            {
                count++;
            }
            if(count==1)
            {
                login.closeEmployeeDatabase();
                ui->loginpage->hide();
                ui->portalstatus2->show();
                ui->clockinpage->show();
                ui->portalloginusername->clear();
                ui->portalloginpassword->clear();
                ui->logoutbutton->show();
            }
            if(count<1)
            {
                login.closeEmployeeDatabase();
                ui->loginpage->show();
                ui->clockinpage->hide();
                QMessageBox::critical(this,tr("Failed"),tr("Username and/or Password is Incorrect"));
            }
        }
      }
}

void LoginPortal::on_logoutbutton_clicked()
{
    ui->loginpage->show();
    ui->clockinpage->hide();
}

void LoginPortal::on_clockinbutton_clicked()
{
    std::string loginClicked = currentTime();
    QString clockin = QString::fromStdString(loginClicked);

    openEmployeePortal();
    QSqlQuery query;
    query.prepare("INSERT INTO employeeportal ([Time In]) values ('"+clockin+"')");


    if(query.exec( ))
    {
        QMessageBox::information(this,tr("Success!"),tr("Clocked In!"));
        closeEmployeePortal();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void LoginPortal::on_clockoutbutton_clicked()
{

    std::string logoutClicked = currentTime();
    QString clockout = QString::fromStdString(logoutClicked);

    openEmployeePortal();
    QSqlQuery query;
    query.prepare("INSERT INTO employeeportal ([Time Out]) values ('"+clockout+"')");


    if(query.exec( ))
    {
        QMessageBox::information(this,tr("Success!"),tr("Clocked Out!"));
        closeEmployeePortal();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void LoginPortal::on_historyButton_clicked()
{
    openEmployeePortal();
    modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(employeePortalDatabase);
    query->prepare("select [Time In], [Time Out] from employeeportal");
    query->exec();
    modal->setQuery(*query);
    ui->timecardtableView->setModel(modal);
    ui->timecardtableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    closeEmployeePortal();
}
