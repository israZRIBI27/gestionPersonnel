#include "passwordforgot.h"
#include "ui_passwordforgot.h"
#include "mainwindow.h"
PasswordForgot::PasswordForgot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordForgot)
{
    ui->setupUi(this);
}

PasswordForgot::~PasswordForgot()
{
    delete ui;
}

void PasswordForgot::on_buttonClose_4_clicked()
{
    MainWindow *w = new MainWindow;
    w->setAttribute(Qt::WA_TranslucentBackground);
    w->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w->show();
    this->close();
}
