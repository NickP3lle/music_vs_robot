#ifndef PLAYGROUND_WIDGET_H
#define PLAYGROUND_WIDGET_H

#include <QHBoxLayout>
#include <QWidget>

class PlaygroundWidget : public QWidget {
    Q_OBJECT

  private:
    QHBoxLayout *navBarLayout;

  public:
    PlaygroundWidget(QWidget *parent = 0);
};

#endif