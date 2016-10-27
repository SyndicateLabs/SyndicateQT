#ifndef MYINVENTORY_H
#define MYINVENTORY_H

#include <QDialog>

namespace Ui {
class MyInventory;
}

class MyInventory : public QDialog
{
    Q_OBJECT

public:
    explicit MyInventory(QWidget *parent = 0);
    ~MyInventory();

private:
    Ui::MyInventory *ui;
};

#endif // MYINVENTORY_H
