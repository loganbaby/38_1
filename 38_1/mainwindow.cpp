#include "mainwindow.h"

#include <QTimer>

SoundButton::SoundButton(QWidget *parent) {
    setParent(parent);
    player = new QMediaPlayer(nullptr);
    player->setMedia(QUrl::fromLocalFile("res/paw.mp3"));
    player->setVolume(75);

    buttonUpPixmap = new QPixmap("res/up.jpg");
    buttonDownPixmap = new QPixmap("res/down.jpg");
    currentButtonPixmap = buttonUpPixmap;
    setGeometry(currentButtonPixmap->rect());
    connect(this, &QPushButton::clicked, this, &SoundButton::setDown);
}

void SoundButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(event->rect(), *currentButtonPixmap);
}

void SoundButton::setDown() {
    currentButtonPixmap = buttonDownPixmap;
    update();
    QTimer::singleShot(100, this, &SoundButton::setUp);
}

void SoundButton::setUp() {
    currentButtonPixmap = buttonUpPixmap;
    update();
}

void SoundButton::keyPressEvent(QKeyEvent *event) {
    setDown();
    player->play();
}
