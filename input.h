#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include <QString>
#include "dataprocess.h"

namespace Ui {
class Input;
}

class Input : public QWidget
{
    Q_OBJECT

public:
    explicit Input(QWidget *parent = 0);
    ~Input();
    void openThisWindow();
    void closeThisWindow();
    void inputCode();
    void setTag(QString );
signals:
    void signalInputCode();

private:
    Ui::Input *ui;
    //用來記錄當前要寫入哪個資料夾下檔案
    QString Tag;
//    MainWindow mainwindow;

};

#endif // INPUT_H
