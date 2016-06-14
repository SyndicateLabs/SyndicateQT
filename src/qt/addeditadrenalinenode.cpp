#include "addeditadrenalinenode.h"
#include "ui_addeditadrenalinenode.h"
#include "masternodeconfig.h"
#include "masternodemanager.h"
#include "ui_masternodemanager.h"

#include "walletdb.h"
#include "wallet.h"
#include "ui_interface.h"
#include "util.h"
#include "key.h"
#include "script.h"
#include "init.h"
#include "base58.h"
#include "rpcconsole.h"
#include <QMessageBox>

AddEditAdrenalineNode::AddEditAdrenalineNode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditAdrenalineNode)
{
    ui->setupUi(this);

    //Hide donation
    ui->donationaddressLineEdit->setVisible(false);
    ui->donationpercentageLineEdit->setVisible(false);

    //Labels
    ui->aliasLineEdit->setPlaceholderText("Enter your Masternode alias");
    ui->addressLineEdit->setPlaceholderText("Enter your IP & port");
    ui->privkeyLineEdit->setPlaceholderText("Enter your Masternode private key");
    ui->txhashLineEdit->setPlaceholderText("Enter your 5000 SYNX TXID");
    ui->outputindexLineEdit->setPlaceholderText("Enter your transaction output index");

}

AddEditAdrenalineNode::~AddEditAdrenalineNode()
{
    delete ui;
}


void AddEditAdrenalineNode::on_okButton_clicked()
{
    if(ui->aliasLineEdit->text() == "")
    {
        QMessageBox msg;
        msg.setText("Please enter an alias.");
        msg.exec();
        return;
    }
    else if(ui->addressLineEdit->text() == "")
    {
        QMessageBox msg;
        msg.setText("Please enter your ip & port.");
        msg.exec();
        return;
    }
    else if(ui->privkeyLineEdit->text() == "")
    {
        QMessageBox msg;
        msg.setText("Please enter your masternode's private key.");
        msg.exec();
        return;
    }
    else if(ui->txhashLineEdit->text() == "")
    {
        QMessageBox msg;
        msg.setText("Please enter the transaction hash for the transaction that has 5000 coins");
        msg.exec();
        return;
    }
    else if(ui->outputindexLineEdit->text() == "")
    {
        QMessageBox msg;
        msg.setText("Please enter a transaction output index.");
        msg.exec();
        return;
    }
    else
    {
        std::string sAlias = ui->aliasLineEdit->text().toStdString();
        std::string sAddress = ui->addressLineEdit->text().toStdString();
        std::string sMasternodePrivKey = ui->privkeyLineEdit->text().toStdString();
        std::string sTxHash = ui->txhashLineEdit->text().toStdString();
        std::string sOutputIndex = ui->outputindexLineEdit->text().toStdString();
        std::string sDonationAddress = ui->donationaddressLineEdit->text().toStdString();
        std::string sDonationPercentage = ui->donationpercentageLineEdit->text().toStdString();

        boost::filesystem::path pathConfigFile = GetDataDir() / "masternode.conf";
        boost::filesystem::ofstream stream (pathConfigFile.string(), ios::out | ios::app);
        if (stream.is_open())
        {
            stream << sAlias << " " << sAddress << " " << sMasternodePrivKey << " " << sTxHash << " " << sOutputIndex;
            if (sDonationAddress != "" && sDonationAddress != ""){
                stream << " " << sDonationAddress << " " << sDonationPercentage << std::endl;
            } else {
                stream << std::endl;
            }
            stream.close();
        }
        masternodeConfig.add(sAlias, sAddress, sMasternodePrivKey, sTxHash, sOutputIndex, sDonationAddress, sDonationPercentage);
        accept();
    }
}

void AddEditAdrenalineNode::on_cancelButton_clicked()
{
    reject();
}
