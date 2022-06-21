#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMediaPlayer>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>

class SoundButton : public QPushButton
{
    Q_OBJECT

public:
    explicit SoundButton() = default;
    explicit SoundButton(QWidget *parent = nullptr);
    ~SoundButton(){};

protected:
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;

private slots:
    void setDown();
    void setUp();

private:
    QPixmap *currentButtonPixmap = nullptr;
    QPixmap *buttonDownPixmap = nullptr;
    QPixmap *buttonUpPixmap = nullptr;
    QMediaPlayer* player = nullptr;
};
#endif // MAINWINDOW_H
