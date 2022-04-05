#include "input.h"
#include "ui_input.h"


//#include "mainwindow.h"

Input::Input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Input)
{
    ui->setupUi(this);
    QPushButton *inputCodeBtn = ui->InputCode;

    connect(inputCodeBtn,QPushButton::clicked,this,&Input::inputCode);
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
}

void Input::closeThisWindow(){
    this->hide();
}

void Input::openThisWindow(){
    this->show();
}
