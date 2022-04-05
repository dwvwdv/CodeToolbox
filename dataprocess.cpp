#include "dataprocess.h"


void write_data(QString filename,QString content,QString tag){
    QString filePath = "./" + tag + "/";
    QString fileName = filename;
    QFile file(filePath + fileName);
    qDebug() << filePath + fileName;
    if (!file.open(QIODevice::WriteOnly)){
        qDebug() << "Cannot open file for writing:" << qPrintable(file.errorString());
        return;
    }
    QTextStream out(&file);
    out << content << "\n";

    file.close();
}

QString read_data(QString filename,QString tag){
    QString filePath = "./" + tag + "/";
    QString fileName = filename;
    QFile file(filePath + fileName);
    qDebug() << filePath + fileName;
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() << "Cannot open file for reading:" << qPrintable(file.errorString());
        return "Empty Content or Error";
    }

    QTextStream in(&file);
    QString data;
    while(!in.atEnd()){
        QString fileline = in.readLine();
        data += fileline + '\n';
    }
    file.close();
    return data;
}
