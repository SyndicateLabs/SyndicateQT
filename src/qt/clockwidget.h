#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>

namespace Ui {
class ClockWidget;
}

class ClockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClockWidget(QWidget *parent = 0);
    ~ClockWidget();

public:
    Ui::ClockWidget *ui;

protected:
     void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;

private:

};

#endif // CLOCKWIDGET_H
