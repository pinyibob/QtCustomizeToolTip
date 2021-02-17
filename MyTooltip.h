#pragma once
#include <qwidget.h>
#include <QLabel>
#include <QTimer>
#include <qpoint.h>
class MyTooltip :
    public QLabel
{
public:
    MyTooltip(QWidget* parent);
    void onShow(const QPoint& point);

    void onHide();

protected:
    bool event(QEvent* e) override;
    void showEvent(QShowEvent* e) override;

private:
    QTimer *timer = nullptr;

};

