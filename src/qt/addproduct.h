#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include "myinventory.h"

#include <QDialog>

namespace Ui {
class AddProduct;
}

class AddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = 0);
    ~AddProduct();
public:
    void updateAll();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddProduct *ui;
    MyInventory inventory;

};

#endif // ADDPRODUCT_H
