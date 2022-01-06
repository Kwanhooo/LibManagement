#ifndef BOOKINFORMATION_H
#define BOOKINFORMATION_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class BookInformation;
}

class BookInformation : public QWidget
{
    Q_OBJECT

public:
    explicit BookInformation(QWidget *parent = nullptr);
    ~BookInformation();
public slots:
    void open();
private:
    Ui::BookInformation *ui;
    QPoint m_lastPos;
    bool isPressedWidget;

    void mousePressEvent(QMouseEvent *event)
    {
        m_lastPos = event->globalPos();
        isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        if (isPressedWidget) {
            this->move(this->x() + (event->globalX() - m_lastPos.x()),
                       this->y() + (event->globalY() - m_lastPos.y()));
            m_lastPos = event->globalPos();
        }
    }

    void mouseReleaseEvent(QMouseEvent *event)
    {
        m_lastPos = event->globalPos();
        isPressedWidget = false;
    }
};

#endif // BOOKINFORMATION_H
