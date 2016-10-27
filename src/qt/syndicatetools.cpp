#include "syndicatetools.h"
#include "ui_syndicatetools.h"
#include "sendmessagesdialog.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QCryptographicHash>
#include <QFile>

SyndicateTools::SyndicateTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SyndicateTools)
{
    ui->setupUi(this);
    setWindowTitle(tr("Tools"));
    ui->filePath->setPlaceholderText("Please enter a file path or browse..");
}

SyndicateTools::~SyndicateTools()
{
    delete ui;
}

void SyndicateTools::on_generateChecksums_clicked()
{
    shaGenerator();
    md5Generator();
    sha256Generator();
}

void SyndicateTools::shaGenerator()
{
    if (ui->shaBox->isChecked())
    {
    QString sha1String = ui->filePath->text();

    QFile sha1File(sha1String);
        if(sha1File.open(QIODevice::ReadOnly))
        {
            QString hash = QCryptographicHash::hash(sha1File.readAll(), QCryptographicHash::Sha1).toHex().constData();
            sha1File.close();
            ui->shaCheck->setText(hash);
        }
    } else
    {

    }
}

void SyndicateTools::sha256Generator()
{

    if (ui->sha256Box->isChecked())
    {
    QString sha256String = ui->filePath->text();

    QFile sha256File(sha256String);
        if(sha256File.open(QIODevice::ReadOnly))
        {
            QString hash = QCryptographicHash::hash(sha256File.readAll(), QCryptographicHash::Sha256).toHex().constData();
            sha256File.close();
            ui->sha256Check->setText(hash);
        }
    } else
    {

    }

}

void SyndicateTools::md5Generator()
{
    if (ui->md5Box->isChecked())
    {
    QString md5String = ui->filePath->text();

    QFile md5File(md5String);
        if(md5File.open(QIODevice::ReadOnly))
        {
            QString hash = QCryptographicHash::hash(md5File.readAll(), QCryptographicHash::Md5).toHex().constData();
            md5File.close();
            ui->md5Check->setText(hash);
        }
    } else
    {

    }
}

void SyndicateTools::on_browseFiles_clicked()
{
    QString checksumfile = QFileDialog::getOpenFileName(
                this,
                tr("Choose File"),
                "C://",
                "All Files (*.*)"
                );
    ui->filePath->setText(checksumfile);

    if(QFileDialog::Accept)
    {
        shaGenerator();
        md5Generator();
        sha256Generator();
    }
}

void SyndicateTools::on_messageButton_clicked()
{
    if(!model)
        return;

    SendMessagesDialog dlg(SendMessagesDialog::Encrypted, SendMessagesDialog::Dialog, this);

    dlg.setModel(model);
    dlg.exec();
}
