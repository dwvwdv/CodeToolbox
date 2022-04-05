#include "menu.h"
#include "ui_menu.h"

#include <QDir>
#include <QDebug>
#include <regex>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../icon.png"));
    setFixedSize(300,270);

    //DefaultDir [C++ Python C# Java PHP Shell]
    QDir dir(QDir::currentPath());
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QString defaultDirs[] = {"C++","Python","C#","Java","PHP","Shell"};
    for(auto dDirName:defaultDirs){
        QDir dD(dir.currentPath() + dDirName);
        if(!dD.exists()){
            dir.mkdir(dDirName);
        }
    }

    //Enter MainWindow
    QListWidget *list = ui->SelectList;
    connect(list,&QListWidget::itemDoubleClicked,this,&Menu::slotSelctClick);


}

Menu::~Menu()
{
    delete ui;
}

void Menu::slotSelctClick()
{
//    ui->SelcctBtn->setText(ui->SelectList->currentItem()->text());
    emit signalMenuClose(ui->SelectList->currentItem()->text());
}

