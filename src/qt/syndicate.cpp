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
<<<<<<< HEAD

=======
    business = new MyBusiness (this);
    business->show();
>>>>>>> parent of 1a604f1... Revert "Updates"
}

void Syndicate::on_myinventoryButton_clicked()
{
<<<<<<< HEAD

=======
    inventory = new MyInventory(this);
    inventory->show();
>>>>>>> parent of 1a604f1... Revert "Updates"
}

void Syndicate::on_myfinancialsButton_clicked()
{
<<<<<<< HEAD

=======
    financials = new MyFinancials(this);
    financials->show();
>>>>>>> parent of 1a604f1... Revert "Updates"
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

<<<<<<< HEAD
void Syndicate::on_poeButton_clicked()
{

=======
void Syndicate::on_toolButton_clicked()
{
    tools = new SyndicateTools(this);
    tools->show();
>>>>>>> parent of 1a604f1... Revert "Updates"
}
