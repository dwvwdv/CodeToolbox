#include "menu.h"
#include "ui_menu.h"
#include <QSystemTrayIcon>



Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/icon.ico"));       //Icon設定
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明化
    this->setWindowFlags(Qt::FramelessWindowHint);   //無邊窗口
    setFixedSize(300,270);                           //固定窗口大小

    //DefaultDir [C++ Python C# Java PHP Shell]
    QDir dir(QDir::currentPath());
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);

    QDir dD(dir.currentPath() + "/" + manager);
    if(!dD.exists()){
        dir.mkdir(manager);
    }
    initDefaultDir(dir);

    //Enter MainWindow
    QListWidget *list = ui->SelectList;
    connect(list,&QListWidget::itemDoubleClicked,this,&Menu::slotSelctClick);


}

Menu::~Menu()
{
    delete ui;
}

void Menu::makeDirs(){

}

void Menu::initDefaultDir(QDir dir){
    QString defaultDirs[] = {"C++","Python","Unity","Java","PHP","Shell"};
    for(auto dDirName:defaultDirs){
        QDir dD(dir.currentPath() + "/" + manager + "/" + dDirName);
        qDebug() << dD.path();
        if(!dD.exists()){
            dir.mkdir(dir.currentPath() + "/" + manager + "/" + dDirName);
        }
        ui->SelectList->addItem(dDirName);
    }
}

void Menu::slotSelctClick()
{
//    ui->SelcctBtn->setText(ui->SelectList->currentItem()->text());
    emit signalMenuClose(ui->SelectList->currentItem()->text());
}


void Menu::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        mouseStartPoint = event->globalPos();
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void Menu::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        QPoint distance = event->globalPos() - mouseStartPoint;
        this->move(windowTopLeftPoint + distance);
    }
}

void Menu::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
    else if(event->button() == Qt::RightButton){
        QApplication::exit();
    }
    else if(event->button() == Qt::MidButton){
        addItem();
    }
}

void Menu::addItem(){

    QString dDirName = QInputDialog::getText(this,tr("Create"),tr("Input your item name."),QLineEdit::Normal,"");

    QDir dD(QDir::currentPath() + "/" + manager + "/" + dDirName);
    qDebug() << dD.path();
    if(!dD.exists()){
        dD.mkdir(dD.path());
    }
    if(dDirName == "")
        return ;
    ui->SelectList->addItem(dDirName);
}

void Menu::deleteItem(){
    QListWidgetItem *item = ui->SelectList->currentItem();
    if(item == nullptr)
        return;

    QDir dDir(QDir::currentPath() + "/" + manager + "/" + item->text());
    bool isFinshDelete = dDir.removeRecursively();
    if(isFinshDelete)
        qDebug() << "Delete Finish!" << endl;
    else
        qDebug() << "Error,Check File in " << dDir.path() << endl;
    ui->SelectList->removeItemWidget(item);
    delete item;
}

