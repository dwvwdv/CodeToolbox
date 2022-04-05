#ifndef MENU_H
#define MENU_H

#include <QWidget>

#include <QListWidget>
#include <QDebug>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
signals:
    void signalMenuClose(QString );

private:
    Ui::Menu *ui;

    void slotSelctClick();
};
#endif // MENU_H
