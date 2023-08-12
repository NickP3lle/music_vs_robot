#ifndef START_WIDGET_H
#define START_WIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class StartWidget : public QWidget {
    Q_OBJECT

  private:
    QLabel *title;
    QPushButton *startButton;
    QPushButton *loadButton;
    QPushButton *quitButton;

  public:
    StartWidget(QWidget *parent = 0);
};

#endif