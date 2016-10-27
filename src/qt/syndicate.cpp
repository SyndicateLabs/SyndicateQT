#include "syndicate.h"
#include "ui_syndicate.h"

Syndicate::Syndicate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Syndicate)
{
    ui->setupUi(this);
    createSyndicateDirectories();
}

Syndicate::~Syndicate()
{
    delete ui;
}

void Syndicate::on_mybusinessButton_clicked()
{

}

void Syndicate::on_myinventoryButton_clicked()
{

}

void Syndicate::on_myfinancialsButton_clicked()
{

}

void Syndicate::on_employeemanagerButton_clicked()
{
    employeeman = new EmployeeManager(this);
    employeeman->show();
}

void Syndicate::on_employeeportalButton_clicked()
{
    portal = new LoginPortal(this);
    portal->show();
}

void Syndicate::on_poeButton_clicked()
{

}
