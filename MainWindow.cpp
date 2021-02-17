#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qevent.h>
#include <qdebug.h>
#include <QMouseEvent>
#include <MyTooltip.h>
#include <qapplication.h>

MainWindow::MainWindow(QWidget* parent)
    :QWidget(parent)
{
    resize(500,500);
    m_tooltip = new MyTooltip(this);
	m_pShowWindowBtn = new QPushButton(this);
    m_pShowWindowBtn->setToolTip("Show a window");
    m_pShowWindowBtn->move(250,250);
    initConnect();
}

MainWindow::~MainWindow() 
{

}

void MainWindow::initConnect()
{

}

bool MainWindow::eventFilter(QObject* obj, QEvent* e)
{
    static QPoint mouseGloblePos;
    QWidget* pReceiveWidget = qobject_cast<QWidget*>(obj);
    QString tooltipText;
    if (pReceiveWidget) {
        tooltipText = pReceiveWidget->toolTip();
    }

    if (e->type() == QEvent::MouseMove) {
        mouseGloblePos = static_cast<QMouseEvent*>(e)->globalPos();
    }
    if (e->type() == QEvent::ToolTip) {        
        auto h_ = static_cast<QHelpEvent*>(e);
        
        if (!tooltipText.isEmpty()) {
            //m_tooltip->setParent(pReceiveWidget);
            m_tooltip->setText(tooltipText);
            QHelpEvent HE(QEvent::Type(MainWindow::MyToolTipEvent), QPoint(), mouseGloblePos);
            QApplication::sendEvent(m_tooltip, &HE);
        }
        return true;
        //delete btn;
    }
    if (e->type() == QEvent::Leave) {
        m_tooltip->onHide();
    }
    return __super::eventFilter(obj,e);
}
