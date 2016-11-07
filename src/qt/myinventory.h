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

private slots:
    void on_inventoryLoginButton_clicked();
    void on_inventoryPassword_returnPressed();
    void on_inventoryUsername_returnPressed();

private:
    Ui::MyInventory *ui;
    EmployeeManager empman;
    int count;
};

#endif // MYINVENTORY_H
