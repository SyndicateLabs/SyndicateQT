#ifndef BLOCKEXPLORER_H
#define BLOCKEXPLORER_H

#include <QWidget>

namespace Ui {
class BlockExplorer;
}

class BlockExplorer : public QWidget
{
    Q_OBJECT

public:
    explicit BlockExplorer(QWidget *parent = 0);
    ~BlockExplorer();

private slots:
    void on_movementButton_clicked();
    void on_beButton_clicked();
    void on_networkButton_clicked();
    void on_top100Button_clicked();
    void on_marketsButton_clicked();
    void on_apiButton_clicked();
private:
    Ui::BlockExplorer *ui;
};

#endif // BLOCKEXPLORER_H
