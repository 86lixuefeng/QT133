#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QDateTime>
#include <QFont>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();   
private:
    Ui::Widget *ui;
    QTimer *timer_date;
    QFont ft;
};

#endif // WIDGET_H
