#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}


void Register::on_buttonClose_4_clicked()
{
    this->close();

}

void Register::on_buttonRegister_5_clicked()
{
    MainWindow *w = new MainWindow;
    w->setAttribute(Qt::WA_TranslucentBackground);
    w->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w->show();
    this->close();
}
