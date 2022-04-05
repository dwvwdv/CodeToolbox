#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include <QString>
#include <QMouseEvent>

#include "dataprocess.h"

namespace Ui {
class Input;
}

class Input : public QWidget
{
    Q_OBJECT

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

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

    //窗口移動
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;
//    MainWindow mainwindow;

};

#endif // INPUT_H
