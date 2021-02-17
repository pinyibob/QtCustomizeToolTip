#pragma once
#include <qwidget.h>
#include <QEvent>
class QPushButton;
class QLabel;
class QLineEdit;
class MyTooltip;
class MainWindow : public QWidget
{
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void initConnect();

    enum MyEvent {
        MyToolTipEvent = QEvent::User + 1,
    };
protected:
    bool eventFilter(QObject* obj, QEvent* e) override;
private:
    QLabel* m_pLabel;
    QPushButton* m_pShowWindowBtn = nullptr;
    MyTooltip* m_tooltip = nullptr;
};

