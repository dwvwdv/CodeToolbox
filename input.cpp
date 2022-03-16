#include "input.h"
#include "ui_input.h"

Input::Input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Input)
{
    ui->setupUi(this);
}

Input::~Input()
{
    delete ui;
}
