#ifndef INSTRUMENT_BUTTON_H
#define INSTRUMENT_BUTTON_H

#include "../../game/include.h"
#include "../../music/music_instrument.h"

#include <QFocusEvent>
#include <QPushButton>
#include <QString>

class InstrumentButton : public QPushButton {
    Q_OBJECT

  private:
    MusicInstruments *instrument;
    static MusicInstruments *instrumentSelected;

  protected:
    // // Update button appearance when it gains focus
    // void focusInEvent(QFocusEvent *event) override {
    //     setStyleSheet("outline: 2px solid red;");
    //     QPushButton::focusInEvent(event);
    // }

    // // Update button appearance when it loses focus
    // void focusOutEvent(QFocusEvent *event) override {
    //     setStyleSheet("");
    //     QPushButton::focusOutEvent(event);
    // }

    // void mousePressEvent(QMouseEvent *event) override {
    //     setFocus(); // Set focus when the button is clicked
    //     QPushButton::mousePressEvent(event);
    // }

    // bool eventFilter(QObject *obj, QEvent *event) override {
    //     if (event->type() == QEvent::FocusIn) {
    //         // Update button appearance when it gains focus
    //         setStyleSheet("outline: 2px solid red;");
    //     } else if (event->type() == QEvent::FocusOut) {
    //         // Update button appearance when it loses focus
    //         setStyleSheet("");
    //     } else if (event->type() == QEvent::MouseButtonPress) {
    //         // Check if the clicked object is the button or its child
    //         QWidget *widget = qobject_cast<QWidget *>(obj);
    //         if (widget && (widget == this || isAncestorOf(widget))) {
    //             // Set focus to the button
    //             setFocus();
    //         } else {
    //             // Clear focus from the button
    //             clearFocus();
    //         }
    //     }

    //     return QPushButton::eventFilter(obj, event);
    // }

  public:
    InstrumentButton(MusicInstruments *i, QString title, QWidget *parent = 0);
    static MusicInstruments *getSelectedInstrument();
    static bool removeSelectedInstrument();
};

#endif