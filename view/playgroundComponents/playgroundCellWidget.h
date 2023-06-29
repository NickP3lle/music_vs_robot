#ifndef PLAYGROUND_CELL_WIDGET_H
#define PLAYGROUND_CELL_WIDGET_H

#include "../../game/entity.h"
#include "../../game/include.h"

#include <QPainter>
#include <QPixmap>
#include <QStyleOption>
#include <QWidget>

class PlaygroundCellWidget : public QWidget {
    Q_OBJECT

  private:
    QPixmap *pixmap;
    // ptr<Entity> entity;

  protected:
    void mousePressEvent(QMouseEvent *event) override;

  public:
    PlaygroundCellWidget(QWidget *parent = 0);

    void setImage(QPixmap *pmap);

    // Questa funzione è stata aggiunta per un bug che non permette alle classi figlie di QWidget di avere grafica ereditando
    // il metodo setStyleSheet(). Per questo motivo, è stato necessario ridefinire il metodo paintEvent()
    void paintEvent(QPaintEvent *event) override;

  signals:
    void clicked();
};

#endif