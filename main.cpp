#include "mainwindow.h"
#include <QApplication>
#include <QFile>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   QFile qss(R"(C:\Users\USER\Desktop\example.qss)");
    qss.open(QFile::ReadOnly);
    if(qss.isOpen()){
        qApp->setStyleSheet(qss.readAll());
        qss.close();
//        return a.exec();
    }

    MainWindow w;
//    w.show();


    return a.exec();
}
