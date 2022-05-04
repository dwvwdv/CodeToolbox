#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QMouseEvent>
#include <QListWidget>
#include <QDebug>
#include <Qdir>
#include <QInputDialog>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

    void setLanguageList(QStringList );
signals:
    void signalMenuClose(QString );
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::Menu *ui;

//    void eventFilter(QObject *obj,QEvent *event);
    void slotSelctClick();
    void makeDirs();
    void initDefaultDir(QDir dir);
    void deleteItem();
    void addItem();
    void openMenuWindow();
    QStringList getAllLanguage();

    const QString manager = "Manager";
    QStringList languageNames;

    //窗口移動
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

};
#endif // MENU_H
