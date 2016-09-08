#ifndef MYEMPLOYEES_H
#define MYEMPLOYEES_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <memory>
#include <string>

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QString>

using namespace std;

namespace Ui {
class MyEmployees;
}

class MyEmployees : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase myemployees;
    QSqlQueryModel *modal;
    int count;

    void closeEmployeeDatabase()
    {
        myemployees.close();
        myemployees.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool openEmployeeDatabase()
    {
        QString databasepath = QDir::homePath();
        databasepath = databasepath + QString("/Syndicate/Databases/Decrypted/EmployeeDatabase.db");

        myemployees = QSqlDatabase::addDatabase("QSQLITE");
        myemployees.setDatabaseName(databasepath);

        if(!myemployees.open())
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
    explicit MyEmployees(QWidget *parent = 0);
    ~MyEmployees();

private slots:
    void on_savebutton_clicked();
    void on_viewemployees_clicked();
    void on_clearinfo_clicked();
    void on_editemployees_clicked();
    void on_loginlogin_clicked();
    void on_loginusername_returnPressed();
    void on_loginpassword_returnPressed();
    void on_logoutbutton_clicked();

private:
    Ui::MyEmployees *ui;

};

#endif // MYEMPLOYEES_H
