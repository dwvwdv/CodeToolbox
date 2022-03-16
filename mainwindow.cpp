#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setWindowIcon();

    //進入選單menu，選擇後再跳轉進來
    menu.show();
    connect(&menu,&Menu::signalMenuClose,this,&MainWindow::openMainWindow);

    QPushButton *exit = ui->back;
    connect(exit,QPushButton::clicked,this,&MainWindow::openMenu);
}

void MainWindow::openMainWindow(QString formName){
//    ui->back->setText(formName);
    this->setWindowTitle(formName);
    this->show();
    menu.hide();
}

void MainWindow::openMenu(){
    menu.show();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
