#ifndef PLAYGROUND_WIDGET_H
#define PLAYGROUND_WIDGET_H

#include <QWidget>

class PlaygroundWidget : public QWidget {
    Q_OBJECT
  public:
    PlaygroundWidget(QWidget *parent = 0);
};

#endif