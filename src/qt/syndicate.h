#ifndef SYNDICATE_H
#define SYNDICATE_H

#include "employeemanager.h"
#include "loginportal.h"

#include <QWidget>

namespace Ui {
class Syndicate;
}

class Syndicate : public QWidget
{
    Q_OBJECT

public:
    explicit Syndicate(QWidget *parent = 0);
    ~Syndicate();

private slots:
    void on_mybusinessButton_clicked();
    void on_myinventoryButton_clicked();
    void on_myfinancialsButton_clicked();
    void on_employeemanagerButton_clicked();
    void on_employeeportalButton_clicked();
    void on_poeButton_clicked();

private:
    Ui::Syndicate *ui;
    EmployeeManager *employeeman;
    LoginPortal *portal;
};

#endif // SYNDICATE_H
