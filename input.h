#ifndef INPUT_H
#define INPUT_H

#include <QWidget>

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

private:
    Ui::Input *ui;
//    MainWindow mainwindow;

};

#endif // INPUT_H
