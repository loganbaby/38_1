#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoundButton soundButton(nullptr);
    soundButton.setFixedSize(100, 100);
    soundButton.move(1000, 500);
    soundButton.show();
    return a.exec();
}
