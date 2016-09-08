#ifndef MYFINANCIALS_H
#define MYFINANCIALS_H

#include <QWidget>

namespace Ui {
class MyFinancials;
}

class MyFinancials : public QWidget
{
    Q_OBJECT

public:
    explicit MyFinancials(QWidget *parent = 0);
    ~MyFinancials();

private:
    Ui::MyFinancials *ui;
};

#endif // MYFINANCIALS_H
