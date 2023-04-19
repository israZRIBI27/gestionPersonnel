#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include "personnel.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
bool connecter();
private slots:
    void on_buttonLogin_4_clicked();

private:
    Ui::login *ui;
    personnel p ;


};

#endif // LOGIN_H
