#ifndef MYBUSINESS_H
#define MYBUSINESS_H

#include <QWidget>

namespace Ui {
class MyBusiness;
}

class MyBusiness : public QWidget
{
    Q_OBJECT

public:
    explicit MyBusiness(QWidget *parent = 0);
    ~MyBusiness();

private:
    Ui::MyBusiness *ui;
};

#endif // MYBUSINESS_H
