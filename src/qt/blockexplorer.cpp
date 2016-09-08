#include "blockexplorer.h"
#include "ui_blockexplorer.h"

#include <QtWebKitWidgets>

BlockExplorer::BlockExplorer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockExplorer)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("http://blockexplorer.syndicatelabs.org"));
}

BlockExplorer::~BlockExplorer()
{
    delete ui;
}

void BlockExplorer::on_beButton_clicked()
{
    ui->webView->load(QUrl("http://blockexplorer.syndicatelabs.org"));
}

void BlockExplorer::on_movementButton_clicked()
{
    ui->webView->load(QUrl("http://blockexplorer.syndicatelabs.org/movement"));
}
void BlockExplorer::on_networkButton_clicked()
{
    ui->webView->load(QUrl("http://blockexplorer.syndicatelabs.org/network"));
}

void BlockExplorer::on_top100Button_clicked()
{
    ui->webView->load(QUrl("http://blockexplorer.syndicatelabs.org/richlist"));
}

void BlockExplorer::on_marketsButton_clicked()
{
    ui->webView->load(QUrl("http://blockexplorer.syndicatelabs.org/markets/bittrex"));
}

void BlockExplorer::on_apiButton_clicked()
{
    ui->webView->load(QUrl("http://blockexplorer.syndicatelabs.org/info"));
}
