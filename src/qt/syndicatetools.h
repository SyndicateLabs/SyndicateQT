#ifndef SYNDICATETOOLS_H
#define SYNDICATETOOLS_H

#include "sendmessagesentry.h"
#include "sendmessagesdialog.h"

#include <QDialog>

namespace Ui {
class SyndicateTools;
}

class SyndicateTools : public QDialog
{
    Q_OBJECT

public:
    explicit SyndicateTools(QWidget *parent = 0);
    ~SyndicateTools();

private slots:
    void on_generateChecksums_clicked();
    void shaGenerator();
    void sha256Generator();
    void md5Generator();
    void on_browseFiles_clicked();

    void on_messageButton_clicked();

private:
    MessageModel *model;
    Ui::SyndicateTools *ui;
    SendMessagesDialog *encryptedm;
    SendMessagesEntry *encryptedms;
};

#endif // SYNDICATETOOLS_H
