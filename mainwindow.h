#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QDir>
#include <QKeyEvent>

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

private:
    Ui::MainWindow *ui;
    Menu menu;
    Input input;

    QStringList functionFiles;
};

#endif // MAINWINDOW_H
