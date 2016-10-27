#ifndef EDITEMPLOYEES_H
#define EDITEMPLOYEES_H

#include <QDialog>

namespace Ui {
class EditEmployees;
}

class EditEmployees : public QDialog
{
    Q_OBJECT

public:
    explicit EditEmployees(QWidget *parent = 0);
    ~EditEmployees();

private slots:
    void on_savebutton_clicked();
    void on_einlistview_clicked(const QModelIndex &index);
    void on_deletebutton_clicked();

private:
    Ui::EditEmployees *ui;
};

#endif // EDITEMPLOYEES_H
