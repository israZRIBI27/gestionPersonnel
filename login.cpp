#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_buttonLogin_4_clicked()
{
p.setnom(ui->lineEdit_11->text());
p.setcin(ui->lineEdit_12->text().toInt());
if (connecter())
{

   close() ;
}

}
bool login::connecter()
{
    return p.connecter();
}
