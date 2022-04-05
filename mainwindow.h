#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QDir>

#include <menu.h>
#include <input.h>

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
//public slots:
    void openMainWindow(QString );
    void openMenu();
    void slotSelctClick();
    void viewCode();
signals:
    void signalOpenViewCode();

private:
    Ui::MainWindow *ui;
    Menu menu;
    Input input;
};

#endif // MAINWINDOW_H
