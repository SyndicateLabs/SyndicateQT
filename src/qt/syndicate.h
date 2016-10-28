#ifndef SYNDICATE_H
#define SYNDICATE_H

#include "employeemanager.h"
#include "loginportal.h"
#include "syndicatetools.h"
#include "mybusiness.h"
#include "myfinancials.h"
#include "myinventory.h"

#include <QWidget>
#include <QDir>

namespace Ui {
class Syndicate;
}

class Syndicate : public QWidget
{
    Q_OBJECT

public:
    void createSyndicateDirectories()
    {
        QString decryptedFolder = QDir::homePath();
        decryptedFolder = decryptedFolder + QString("/Syndicate/Databases/Decrypted");

        QString encryptedFolder = QDir::homePath();
        encryptedFolder = encryptedFolder + QString("/Syndicate/Databases/Encrypted");

        QDir::home().mkpath(decryptedFolder);
        QDir::home().mkpath(encryptedFolder);
    }

public:
    explicit Syndicate(QWidget *parent = 0);
    ~Syndicate();

private slots:
    void on_mybusinessButton_clicked();
    void on_myinventoryButton_clicked();
    void on_myfinancialsButton_clicked();
    void on_employeemanagerButton_clicked();
    void on_employeeportalButton_clicked();
    void on_toolButton_clicked();

private:
    Ui::Syndicate *ui;
    EmployeeManager *employeeman;
    LoginPortal *portal;
    SyndicateTools *tools;
    MyInventory *inventory;
    MyFinancials *financials;
    MyBusiness *business;
};

#endif // SYNDICATE_H
