#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include "employeemanager.h"

#include <QDialog>

namespace Ui {
class AddEmployee;
}

class AddEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployee(QWidget *parent = 0);
    ~AddEmployee();

private slots:
    void on_savebutton_clicked();
    void on_clearinfo_clicked();

private:
    Ui::AddEmployee *ui;
    EmployeeManager emp;

};

#endif // ADDEMPLOYEE_H
