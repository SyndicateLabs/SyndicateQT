#ifndef MYINVENTORY_H
#define MYINVENTORY_H

#include "employeemanager.h"

#include <QDialog>

namespace Ui {
class MyInventory;
}

class MyInventory : public QDialog
{
    Q_OBJECT

public:
    explicit MyInventory(QWidget *parent = 0);
    ~MyInventory();

public:
    QSqlDatabase inventorydb;
    QSqlQueryModel *inventorymodal;
    QString currentSum;
    QString currentNet;
    QString quantSum;

    bool openInventoryDatabase()
    {
        QString databasepath = QDir::homePath();
        databasepath = databasepath + QString("/Syndicate/Databases/Decrypted/InventoryDatabase.db");

        inventorydb = QSqlDatabase::addDatabase("QSQLITE");
        inventorydb.setDatabaseName(databasepath);

        if(!inventorydb.open())
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

    void closeInventoryDatabase()
    {
        inventorydb.close();
        inventorydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    void createInventoryDatabase()
    {
        openInventoryDatabase();
        QSqlQuery query;
        query.prepare("CREATE TABLE inventoryinfo (`Product Name` varchar(255), Manufacturer varchar(255),"
                      "Quantity integer, SKU varchar(255),Barcode varchar(255), `Retail Price` integer,"
                      " `Vendor Cost` integer, Discount integer)");
        query.exec();
        closeInventoryDatabase();
    }

    void login();
    void logout();
    void viewInventory();
    void listSum();
    void netSum();
    void quanSum();
    void profitTotal();

private slots:
    void on_inventoryLoginButton_clicked();
    void on_inventoryPassword_returnPressed();
    void on_inventoryUsername_returnPressed();
    void on_addProductButton_clicked();

private:
    Ui::MyInventory *ui;
    EmployeeManager empman;
    int count;
};

#endif // MYINVENTORY_H
