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
    business = new MyBusiness (this);
    business->show();
}

void Syndicate::on_myinventoryButton_clicked()
{
    inventory = new MyInventory(this);
    inventory->show();
}

void Syndicate::on_myfinancialsButton_clicked()
{
    financials = new MyFinancials(this);
    financials->show();
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

void Syndicate::on_toolButton_clicked()
{
    tools = new SyndicateTools(this);
    tools->show();
}
