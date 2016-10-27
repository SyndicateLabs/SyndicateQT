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

private:
    Ui::BlockExplorer *ui;
};

#endif // BLOCKEXPLORER_H
