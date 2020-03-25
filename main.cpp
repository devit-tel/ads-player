#include "mainwindow.h"

#include <QApplication>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QMediaPlayer* player = new QMediaPlayer;
    QMediaPlaylist* pl = new QMediaPlaylist(player);
    QVideoWidget* vw = new QVideoWidget;

    pl->addMedia(QMediaContent(QUrl::fromLocalFile("/Users/nv4re/Downloads/01.mp4")));
    pl->addMedia(QMediaContent(QUrl::fromLocalFile("/Users/nv4re/Downloads/02.mp4")));
    pl->addMedia(QMediaContent(QUrl::fromLocalFile("/Users/nv4re/Downloads/03.mp4")));
    pl->addMedia(QMediaContent(QUrl::fromLocalFile("/Users/nv4re/Downloads/04.mp4")));
    pl->addMedia(QMediaContent(QUrl::fromLocalFile("/Users/nv4re/Downloads/05.mp4")));
    pl->addMedia(QMediaContent(QUrl::fromLocalFile("/Users/nv4re/Downloads/03.mp4")));

    pl->setPlaybackMode(pl->Loop);

    player->setPlaylist(pl);
    player->setVideoOutput(vw);

    vw->setGeometry(100, 100, 500, 600);
    vw->show();

    player->play();

    qDebug() << player->state();

    return a.exec();
}

