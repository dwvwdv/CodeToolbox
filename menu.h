#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private:
    Ui::Menu *ui;
    void SelctClick();
slots:
    void def();
};
#endif // MENU_H
