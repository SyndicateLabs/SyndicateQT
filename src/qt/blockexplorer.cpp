#include "blockexplorer.h"
#include "ui_blockexplorer.h"

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
