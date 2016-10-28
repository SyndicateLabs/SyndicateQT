#ifndef MYFINANCIALS_H
#define MYFINANCIALS_H

#include <QDialog>

namespace Ui {
class MyFinancials;
}

class MyFinancials : public QDialog
{
    Q_OBJECT

public:
    explicit MyFinancials(QWidget *parent = 0);
    ~MyFinancials();

private:
    Ui::MyFinancials *ui;
};

#endif // MYFINANCIALS_H
