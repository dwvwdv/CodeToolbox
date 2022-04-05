#ifndef DATAPROCESS_H
#define DATAPROCESS_H


#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void write_data(QString filename,QString content,QString tag);
QString read_data(QString filename ,QString tag);

#endif // DATAPROCESS_H

