#include "input.h"
#include "ui_input.h"
#include <QDebug>

//#include "mainwindow.h"

Input::Input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Input)
{
    ui->setupUi(this);
    setFixedSize(660,470);
//    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口

    QPushButton *inputCodeBtn = ui->InputCode;
    connect(inputCodeBtn,QPushButton::clicked,this,&Input::inputCode);

    QPushButton *exitBtn = ui->ExitBtn;
    connect(exitBtn,QPushButton::clicked,this,&Input::closeThisWindow);

}

Input::~Input()
{
    delete ui;
}

void Input::setTag(QString tag){
    this->Tag = tag;
}


void Input::inputCode(){
    QTextEdit *codeEdit = ui->textEdit;
    write_data(this->windowTitle(),codeEdit->toPlainText(),this->Tag);
    closeThisWindow();
    emit signalInputCode();
}

void Input::closeThisWindow(){
    this->hide();
}

void Input::openThisWindow(){
    this->ui->textEdit->setText(read_data(this->windowTitle(),Tag));
    qDebug() << read_data(this->windowTitle(),Tag) << "test";
    this->show();
}
