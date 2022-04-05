#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../icon.png"));

    menu.show();
    QListWidget *list = ui->SelectList;


    //????? MainWindow
    connect(&menu,&Menu::signalMenuClose,this,&MainWindow::openMainWindow);

    //?????? menu
    QPushButton *exit = ui->back;
    connect(exit,QPushButton::clicked,this,&MainWindow::openMenu);

    //?? CodeView
    connect(list,&QListWidget::itemDoubleClicked,this,&MainWindow::slotSelctClick);

    //?? CodeView
    connect(list,&QListWidget::itemClicked,this,&MainWindow::viewCode);

}

QStringList MainWindow::getAllFunctionFile(){
    QDir dir(QDir::currentPath() + "/" + this->windowTitle());
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QStringList functionFiles = dir.entryList();
    return functionFiles;
}

void MainWindow::setFunctionList(QStringList functionNames){
    ui->SelectList->clear();

    ui->SelectList->addItem("Add Code...");
    ui->SelectList->addItems(functionNames);
}



void MainWindow::openMainWindow(QString formName){
    this->setWindowTitle(formName);
    //??????code????
    QStringList FileNames = this->getAllFunctionFile();
    this->setFunctionList(FileNames);

    this->show();
    menu.hide();
}

void MainWindow::openMenu(){
    menu.show();
    this->hide();
}

void MainWindow::slotSelctClick(){
    //Add function code
    if(ui->SelectList->currentItem()->text() == "Add Code..."){
        QString newItemName = QInputDialog::getText(this,tr("Input"),tr("Input Item Name:"),QLineEdit::Normal,"Your New Item");
        ui->SelectList->addItem(newItemName);
    }
    //Modify code
    else{
        input.setWindowTitle(ui->SelectList->currentItem()->text());
        input.setTag(this->windowTitle());
        input.show();
    }
}

void MainWindow::viewCode(){
    if(ui->SelectList->currentItem()->text() == "Add Code...")
        return;

    QTextEdit *codeView = ui->CodeView;
    QString con = read_data(ui->SelectList->currentItem()->text(),this->windowTitle());
    codeView->setText(con);
}

MainWindow::~MainWindow()
{
    delete ui;
}
