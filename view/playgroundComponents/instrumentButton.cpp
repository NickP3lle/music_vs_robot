#include "instrumentButton.h"
#include <QDebug>

MusicInstruments *InstrumentButton::instrumentSelected = nullptr;

InstrumentButton::InstrumentButton(MusicInstruments *i, QString title, QWidget *parent)
    : QPushButton(title, parent), instrument(i) {
    setFocusPolicy(Qt::ClickFocus);
    setFixedSize(100, 50);
    // setStyleSheet("QPushButton:focus { outline: none; border: 2px solid red; }");
    // installEventFilter(this);
    connect(this, &QPushButton::clicked, this, [this] {
        instrumentSelected = instrument;
        qDebug() << "InstrumentButton::clicked";
    });
}

MusicInstruments *InstrumentButton::getSelectedInstrument() { return instrumentSelected; }

bool InstrumentButton::removeSelectedInstrument() {
    if (instrumentSelected) {
        instrumentSelected = nullptr;
        return true;
    }
    return false;
}

bool InstrumentButton::isInstrumentSelected() { return instrumentSelected != nullptr; }