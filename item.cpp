
#include "item.h"

//按钮的高、宽以及坐标点
#define WIDGET_LEFT_MARGIN 270
#define WIDGET_TOP_MARGIN 20
#define WIDGET_WIDTH 80
#define WIDGET_HEIGHT 50
//每个item的高度
#define LISTVIEW_ITEM_HEIGHT 100
//分割item的线的颜色
#define LINE_COLOR "#CECECE"
//文字的颜色
#define TEXT_COLOR "#130c0e"
//文字的大小
#define TEXT_SIZE 15

listViewDelegate::listViewDelegate(QObject *parent) :
  QStyledItemDelegate(parent) {
}

void listViewDelegate::paint(QPainter *painter,
  const QStyleOptionViewItem &option,
  const QModelIndex &index)
  const {
    if (index.isValid()) {
      QVariant dataVar = index.data(Qt::UserRole + 1);
      itemProperty itemData = dataVar.value<itemProperty>();
      painter->save();

      //每个item的区域
      QRectF rect;
      rect.setX(option.rect.x());
      rect.setY(option.rect.y());
      rect.setWidth(option.rect.width() - 1);
      rect.setHeight(option.rect.height() - 1);

      //text的区域
      QRect textRect = QRect(
        0 + 10, rect.top() + WIDGET_TOP_MARGIN, 100, WIDGET_HEIGHT);
      painter->setPen(QPen(TEXT_COLOR));
      painter->setFont(QFont("SourceHanSansCN-Normal", TEXT_SIZE));
      painter->drawText(textRect, itemData.titleText);

      //widget的区域
      QRect widgetRect = QRect(
        WIDGET_LEFT_MARGIN, rect.top() + WIDGET_TOP_MARGIN, WIDGET_WIDTH, WIDGET_HEIGHT);
      if (itemData.widget) {
        itemData.widget->setGeometry(widgetRect);
        itemData.widget->show();
      }

      //设置线的颜色
      painter->setPen(QPen(QColor(LINE_COLOR)));
      //两点确定一条直线
      //线的起点：x一定是0，并且每一条线的x是一样的，y是每个item的顶部坐标 + 1
      //线的终点：y一定是和起点的y是一样的，那么只需要给出x的长度，线的长度就是每个item的宽度
      painter->drawLine(QPointF(0, rect.bottom() - 1), QPointF(rect.width(), rect.bottom() - 1));
    }

    painter->restore();
}

QSize listViewDelegate::sizeHint(
    const QStyleOptionViewItem &option,
    const QModelIndex &index)
    const {
  Q_UNUSED(index)
  return QSize(option.rect.width(), LISTVIEW_ITEM_HEIGHT);
}

