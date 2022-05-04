#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
           qDebug() << "key " << keyEvent->key() << "from" << obj;
        if(obj == ui->SelectList){
            if(keyEvent->key() == Qt::Key_D){
                deleteItem();
            }
        }
        else if(keyEvent->key() == Qt::Key_Escape){
            this->hide();
            trayIcon->show();
        }
    }
    return QObject::eventFilter(obj, event);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason){
    switch(reason){
    case QSystemTrayIcon::DoubleClick :
        this->setWindowState(Qt::WindowActive);
        this->activateWindow();
        this->show();
        qDebug() << "get icon double click!" << endl;
        break;
    default:
        break;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(750,450);

    this->setWindowIcon(QIcon(":/icon.ico"));       //Icon設定
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/icon.ico"));
    trayIcon->show();
    connect(trayIcon,&QSystemTrayIcon::activated,this,&MainWindow::iconActivated);

    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明化
    this->setWindowFlags(Qt::FramelessWindowHint);   //無邊窗口
    qApp->installEventFilter(this);

    this->setFocusPolicy(Qt::StrongFocus);

    menu.show();
    QDesktopWidget *screenResolution = QApplication::desktop();
    menu.setGeometry(screenResolution->width() - menu.geometry().width(),
                  screenResolution->height()- menu.geometry().height(),
                  menu.geometry().width(),
                  menu.geometry().height());

    QListWidget *list = ui->SelectList;

    //Enter MainWindow
    connect(&menu,&Menu::signalMenuClose,this,&MainWindow::openMainWindow);

    //Enter Menu
    QPushButton *exit = ui->back;
    connect(exit,QPushButton::clicked,this,&MainWindow::openMenu);

    //Edit CodeView
    connect(list,&QListWidget::itemDoubleClicked,this,&MainWindow::slotSelctClick);

    //Delete QListItem
//    connect(list,&QKeyEvent::,this,&MainWindow::deleteItem);

    //Display CodeView
    connect(list,&QListWidget::itemClicked,this,&MainWindow::viewCode);

    //Edit CodeView result update
    connect(&input,&Input::signalInputCode,this,&MainWindow::viewCodeUpdate);

}

void MainWindow::deleteItem(){
    QListWidgetItem *item = ui->SelectList->currentItem();
    if(item == nullptr)
        return;

    QString dFile = QDir::currentPath() + "/Manager/" + this->windowTitle() + "/" + item->text();
    bool isFinshDelete = QFile::remove(dFile);
    if(isFinshDelete)
        qDebug() << "Delete Finish!" << endl;
    else
        qDebug() << "Error,Check File in " << dFile << endl;
    ui->SelectList->removeItemWidget(item);
    delete item;
}

QStringList MainWindow::getAllFunctionFile(){
    QDir dir(QDir::currentPath() + "/Manager/" + this->windowTitle());
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    functionFiles = dir.entryList();
    return functionFiles;
}

void MainWindow::viewCodeUpdate(){
    this->viewCode();
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
        QString newItemName = QInputDialog::getText(this,tr("Create"),tr("Input your item name."),QLineEdit::Normal,"");
        QList<QListWidgetItem *> items = ui->SelectList->findItems(newItemName,Qt::MatchExactly);
            if(items.size() > 0)
                return ;
        if(newItemName != nullptr)
            ui->SelectList->addItem(newItemName);
    }
    //Modify code
    else{
        input.setWindowTitle(ui->SelectList->currentItem()->text());
        input.setTag(this->windowTitle());
        input.openThisWindow();
    }
}

void MainWindow::viewCode(){
    if(ui->SelectList->currentItem()->text() == "Add Code...")
        return;

    QTextEdit *codeView = ui->CodeView;
    QString con = read_data(ui->SelectList->currentItem()->text(),this->windowTitle());
    codeView->setText(con);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        mouseStartPoint = event->globalPos();
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        QPoint distance = event->globalPos() - mouseStartPoint;
        this->move(windowTopLeftPoint + distance);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
    else if(event->button() == Qt::RightButton){
        QApplication::exit();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
