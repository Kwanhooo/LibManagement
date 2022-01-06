#ifndef LISTVIEWDELEGATE_H
#define LISTVIEWDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

typedef struct {
  //文字
  QString titleText;
  //开关状态
  QString state;
  //按钮
  QWidget *widget;
} itemProperty;
Q_DECLARE_METATYPE(itemProperty)

class listViewDelegate : public QStyledItemDelegate
{
public:
    explicit listViewDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index)
               const override;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index)
                   const override;
};

#endif // LISTVIEWDELEGATE_H
