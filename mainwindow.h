#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QDir>
#include <QKeyEvent>
#include <QSystemTrayIcon>

#include "menu.h"
#include "input.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStringList getAllFunctionFile();
    void setFunctionList(QStringList );

    //右下最小化圖標
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    bool eventFilter(QObject *obj, QEvent *event);
    //void keyPressEvent(QKeyEvent *e);
    void deleteItem();
//public slots:
    void openMainWindow(QString );
    void openMenu();
    void slotSelctClick();

    void viewCode();
    void viewCodeUpdate();
signals:
    void signalOpenViewCode();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    Ui::MainWindow *ui;
    Menu menu;
    Input input;

    //窗口移動
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

    QStringList functionFiles;
    QSystemTrayIcon *trayIcon;


};

#endif // MAINWINDOW_H
