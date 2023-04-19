#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personnel.h"
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QApplication>
#include <QMessageBox>
#include "camera.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>

#include "camera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BouttonAjouter_clicked();

    void on_supprimerClient_7_clicked();

    void on_affichageperso_clicked(const QModelIndex &index);

    void on_modifierClient_7_clicked();

    void on_tri_4_clicked();

    void on_tri_5_clicked();

    void on_QTabBar_currentChanged(int index);

    void on_Rechercher_clicked();

    void on_pdf_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    personnel ptmp;
 camera *c;
};
#endif // MAINWINDOW_H
