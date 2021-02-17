#include "MyTooltip.h"
#include <QEvent>
#include <qtimer.h>
#include <QHelpEvent>
#include <qdebug.h>

MyTooltip::MyTooltip(QWidget* parent)
    :QLabel(parent)
{
    setFixedHeight(24);
    setWindowFlags(Qt::ToolTip /*| Qt::Window*/);
    
    timer = new QTimer();
    timer->setInterval(3000);
    connect(timer, &QTimer::timeout, this, [this]() {setVisible(false); });
    
    setAlignment(Qt::AlignCenter);
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background:red;color:blue;padding:4px;");
}

void MyTooltip::onShow(const QPoint& pos)
{
    if (!isVisible()) {
        timer->start();
        setVisible(true);
        move(pos);
    }
}

void MyTooltip::onHide()
{
    timer->stop();
    setVisible(false);
}

bool MyTooltip::event(QEvent* e)
{
    if (e->type() == 1001 && !isVisible()) {
        auto e_ = static_cast<QHelpEvent*>(e);
        auto pos = e_->globalPos();
        onShow(QPoint(pos.x(),pos.y() + 10));
        e->accept();

        qDebug() << "isvisible:"<<isVisible()<<'\t'<<"pos:"<<geometry();
        qDebug() << "text:"<<text();
    }
    return __super::event(e);
}

void MyTooltip::showEvent(QShowEvent* e)
{
    adjustSize();
    setMask(QRegion(rect(),QRegion::Ellipse));
}
