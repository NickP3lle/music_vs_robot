#ifndef CHARACTER_CELL_H
#define CHARACTER_CELL_H

#include "../game/entity.h"
#include "../game/include.h"

#include <QPainter>
#include <QStyleOption>
#include <QWidget>

class CharacterCell : public QWidget {
    Q_OBJECT

    //   private:
    // ptr<Entity> entity;

  public:
    CharacterCell(QWidget *parent = 0);

    // Questa funzione è stata aggiunta per un bug che non permette alle classi figlie di QWidget di avere grafica ereditando
    // il metodo setStyleSheet(). Per questo motivo, è stato necessario ridefinire il metodo paintEvent()
    void paintEvent(QPaintEvent *event) override;
};

#endif