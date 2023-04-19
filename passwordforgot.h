#ifndef PASSWORDFORGOT_H
#define PASSWORDFORGOT_H

#include <QDialog>

namespace Ui {
class PasswordForgot;
}

class PasswordForgot : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordForgot(QWidget *parent = nullptr);
    ~PasswordForgot();

private slots:
    void on_buttonClose_4_clicked();

private:
    Ui::PasswordForgot *ui;
};

#endif // PASSWORDFORGOT_H
