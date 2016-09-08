#ifndef EMPLOYEEPORTAL_H
#define EMPLOYEEPORTAL_H

#include "myemployees.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <memory>
#include <string>

#include <QDialog>
#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QString>

using namespace std;

namespace Ui {
class EmployeePortal;
}

class EmployeePortal : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase employeePortalDatabase;
    QSqlQueryModel *modal;
    MyEmployees login;
    int count;

    string currentTime()
    {
        QTime currenttime = QTime::currentTime();
        QString currentTime = currenttime.toString("hh : mm : ss");
        return currentTime.toStdString();
    }

    void closeEmployeePortal()
    {
        employeePortalDatabase.close();
        employeePortalDatabase.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool openEmployeePortal()
    {
        QString databasepath = QDir::homePath();
        databasepath = databasepath + QString("/Syndicate/Databases/Decrypted/EmployeePortal.db");

        employeePortalDatabase = QSqlDatabase::addDatabase("QSQLITE");
        employeePortalDatabase.setDatabaseName(databasepath);

        if(!employeePortalDatabase.open())
        {
            qDebug() << ("Not Connected to Database..");
            return false;
        }
        else
        {
            qDebug() << ("Connected to Database..");
            return true;
        }
    }

public:
    explicit EmployeePortal(QWidget *parent = 0);
    ~EmployeePortal();

private slots:
    void on_portalloginlogin_clicked();
    void on_portalloginusername_returnPressed();
    void on_portalloginpassword_returnPressed();
    void on_logoutbutton_clicked();
    void on_clockinbutton_clicked();
    void on_clockoutbutton_clicked();
    void on_historyButton_clicked();
    void localTime();

private:
    Ui::EmployeePortal *ui;
};

#endif // EMPLOYEEPORTAL_H
