#include "mainwindow.h"
#include <QApplication>
#include <QFile>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QDesktopWidget *screenResolution = QApplication::desktop();
    qDebug() << w.geometry().width() << " " << w.geometry().height();
    qDebug() << screenResolution->width() << screenResolution->height();
    w.setGeometry(screenResolution->width() - w.geometry().width(),
                  screenResolution->height()- w.geometry().height() - 50,
                  w.geometry().width(),
                  w.geometry().height());
//    w.show();


    return a.exec();
}
