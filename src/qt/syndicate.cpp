#include "syndicate.h"
#include "ui_syndicate.h"

Syndicate::Syndicate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Syndicate)
{
    ui->setupUi(this);
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

void Syndicate::on_myemployeesButton_clicked()
{

}

void Syndicate::on_employeeportalButton_clicked()
{

}

void Syndicate::on_poeButton_clicked()
{

}
