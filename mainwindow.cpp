#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ui_camera.h"
#include"personnel.h"
#include<QString>
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QIntValidator>
#include <QScrollBar>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextStream>
#include <QDataStream>
#include <QTextDocument>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{/* bool verif=true;

    QRegExp emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

    if(cin.length()!=8)
        {QMessageBox::critical(nullptr, QObject::tr("Erreur! "),
                               QObject::tr("cin invalide [8] !.\n"
                                           "Click Cancel to try again"), QMessageBox::Cancel);


        verif=false;}

    else if(tel.length()!=8)
        {QMessageBox::critical(nullptr, QObject::tr("Erreur! "),
                               QObject::tr("tel invalide [8 chiffres] !.\n"
                                           "Click Cancel to try again"), QMessageBox::Cancel);


        verif=false;}
*/

  /*  QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z.-]+\\.[A-Z]{2,4}\\b",
            QRegularExpression::CaseInsensitiveOption);
            ui->AjouterAdresse->setValidator(new QRegularExpressionValidator(rx, this));
*/
    ui->setupUi(this);
    ui->affichageperso->setModel(ptmp.afficher());
    ui->AjouterCin->setValidator(new QIntValidator(99,99999999,this));
    ui->AjouterNom->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->AjouterPrenom->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->Ajoutersalaire->setValidator(new QIntValidator(0,99999,this));
    ui->AjouterNum->setValidator(new QIntValidator(99,99999999,this));
    ui->cin2->setValidator(new QIntValidator(99,99999999,this));
    ui->nom2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->prenom2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->poste2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->salaire2->setValidator(new QIntValidator(99,99999999,this));
    ui->num2->setValidator(new QIntValidator(99,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BouttonAjouter_clicked()
{
    int cin=ui->AjouterCin->text().toInt();
    QString nom=ui->AjouterNom->text();
    QString prenom=ui->AjouterPrenom->text();
    QDate date_em=ui->datebar->date();
    QString mail=ui->AjouterAdresse->text();
    QString poste=ui->comboBox->currentText();
    float salaire=ui->Ajoutersalaire->text().toFloat();
    QString tel=ui->AjouterNum->text();
    personnel p(cin,nom,prenom,date_em,tel,poste,mail,salaire);
    bool test = p.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("Ajout non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    ui->QTabBar->setCurrentIndex(1);
    ui->affichageperso->setModel(ptmp.afficher());

}

void MainWindow::on_supprimerClient_7_clicked()
{
    int cin = ui->cin2->text().toInt();
    bool test=ptmp.supprimer(cin);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                 QObject::tr("Suppression non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
    ui->affichageperso->setModel(ptmp.afficher());


    ui->nom2->clear();
    ui->prenom2->clear();
    ui->cin2->clear();
    ui->salaire2->clear();
    ui->num2->clear();
     ui->mail2->clear();
      ui->poste2->clear();





}

void MainWindow::on_affichageperso_clicked(const QModelIndex &index)
{
    QString val=ui->affichageperso->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from personnel where cin=:val or nom=:val or prenom=:val or poste=:val or mail=:val or salaire=:val or tel=:val");
    qry.bindValue(":val",val);
    if (qry.exec())
    {
        while(qry.next())
        {
            ui->cin2->setText(qry.value(0).toString());
            ui->nom2->setText(qry.value(1).toString());
            ui->prenom2->setText(qry.value(2).toString());
            ui->date2->setDate(qry.value(3).toDate());
            ui->num2->setText(qry.value(4).toString());
            ui->poste2->setText(qry.value(5).toString());
            ui->mail2->setText(qry.value(6).toString());
            ui->salaire2->setText(qry.value(7).toString());
        }
    }
        else
        {
           QMessageBox::warning(this,"error","no information");
        }
}




void MainWindow::on_modifierClient_7_clicked()
   {
        int cin=ui->cin2->text().toInt();
        QString nom=ui->nom2->text();
        QString prenom=ui->prenom2->text();
        QDate date_em=ui->date2->date();
        QString mail=ui->mail2->text();
        QString poste=ui->poste2->text();
        float salaire=ui->salaire2->text().toFloat();
        QString tel=ui->num2->text();
        personnel p(cin,nom,prenom,date_em,tel,poste,mail,salaire);
        bool test = p.modifier();
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Modification effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                     QObject::tr("Modification non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);


        ui->affichageperso->setModel(ptmp.afficher());

    }




void MainWindow::on_tri_4_clicked()
{
    ui->affichageperso->setModel(ptmp.afficher());

}

void MainWindow::on_tri_5_clicked()
{
    personnel e;
    QGridLayout *StatsLayout1 = ui->QTabBar->findChild<QGridLayout*>("gridLayout1");
    StatsLayout1->addWidget(e.stat_poste(), 0, 0);
}


void MainWindow::on_QTabBar_currentChanged(int index)
{
    personnel e;
    QGridLayout *StatsLayout1 = ui->QTabBar->findChild<QGridLayout*>("gridLayout1");
    StatsLayout1->addWidget(e.stat_poste(), 0, 0);
}

void MainWindow::on_Rechercher_clicked()
{
    personnel e;
    QLineEdit *rechercher_em = ui->QTabBar->findChild<QLineEdit*>("Recherchecin");
    QString critere = rechercher_em->text();
    QTableView *Tableviewem = ui->QTabBar->findChild<QTableView*>("affichageperso");
    Tableviewem->setModel(e.recherche(critere));
}

void MainWindow::on_pdf_9_clicked()
{
    QSqlDatabase db;

                                    QTableView tableView;
                                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                                    QSqlQuery qry;
                                     qry.prepare("SELECT* FROM PERSONNEL");
                                     qry.exec();
                                     Modal->setQuery(qry);
                                     tableView.setModel(Modal);

                                     db.close();

                                     QString strStream;
                                     QTextStream out(&strStream);

                                     const int rowCount = tableView.model()->rowCount();
                                     const int columnCount =  tableView.model()->columnCount();

                                     const QString strTitle ="Listedespersonnel";

                                     out <<  "<html>\n"
                                             "<img src='C:/Users/kamel/OneDrive/Documents/test projet/yahomaaa/logo.png' height='155' width='140'/>"
                                         "<head>\n"
                                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                         <<  QString("<title>%1</title>\n").arg(strTitle)
                                         <<  "</head>\n"
                                         "<body bgcolor=#ffffff link=#5000A0>\n"
                                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("LISTE DES PERSONNEL")
                                        <<"<br>"

                                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                                     out << "<thead><tr bgcolor=#f0f0f0>";
                                     for (int column = 0; column < columnCount; column++)
                                         if (!tableView.isColumnHidden(column))
                                             out << QString("<th>%1</th>").arg(tableView.model()->headerData(column, Qt::Horizontal).toString());
                                     out << "</tr></thead>\n";

                                     for (int row = 0; row < rowCount; row++)
                                     {
                                         out << "<tr>";
                                         for (int column = 0; column < columnCount; column++)
                                         {
                                             if (!tableView.isColumnHidden(column))
                                             {
                                                 QString data = tableView.model()->data(tableView.model()->index(row, column)).toString().simplified();
                                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                             }
                                         }
                                         out << "</tr>\n";
                                     }
                                     out <<  "</table>\n"
                                             "<br><br>"
                                             <<"<br>"
                                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                                         out << "<thead><tr bgcolor=#f0f0f0>";

                                             out <<  "</table>\n"

                                         "</body>\n"
                                         "</html>\n";

                                     QTextDocument *ListeDesPersonnel= new QTextDocument();
                                     ListeDesPersonnel->setHtml(strStream);

                                     QPrinter printer;
                                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                                     if (dialog->exec() == QDialog::Accepted)
                                     {

                                         ListeDesPersonnel->print(&printer);
                                     }
                                     printer.setOutputFormat(QPrinter::PdfFormat);
                                     printer.setPaperSize(QPrinter::A4);
                                     printer.setOutputFileName("/tmp/Produit.pdf");
                                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                                     delete ListeDesPersonnel;

}

void MainWindow::on_pushButton_clicked()
{
    // Récupérer les statistiques des conférences
                QSqlQueryModel model;
                model.setQuery("SELECT COUNT(*) as poste, poste FROM PERSONNEL GROUP BY poste;");

                // Calculer le total des conférences
                int total = 0;
                while (model.canFetchMore())
                    model.fetchMore();
                for (int i = 0; i < model.rowCount(); ++i) {
                    total += model.data(model.index(i, 0)).toInt();
                }

                // Créer un graphique à secteurs pour représenter les statistiques
                QPieSeries *series = new QPieSeries();
                for (int i = 0; i < model.rowCount(); ++i) {
                    QString mode = model.data(model.index(i, 1)).toString();
                    int categories = model.data(model.index(i, 0)).toInt();
                    qreal percentage = (qreal) categories / total * 100.0;
                    QString label = QString("%1 (%2%)").arg(mode).arg(QString::number(percentage, 'f', 2));
                    series->append(label, categories);
                }

                QChart *chart = new QChart();
                chart->addSeries(series);
                chart->setTitle("Statistiques des poste");
                chart->setAnimationOptions(QChart::AllAnimations);
                chart->legend()->setAlignment(Qt::AlignLeft);
                chart->legend()->setFont(QFont("Arial", 10));

                // Afficher le graphique dans une boîte de dialogue
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->setMinimumSize(800, 600);

                QDialog *dialog = new QDialog();
                QVBoxLayout *layout = new QVBoxLayout(dialog);
                layout->addWidget(chartView);
                dialog->setWindowTitle("Statistiques des poste");
                dialog->exec();

                // Nettoyer les objets alloués dynamiquement
              //  delete series;
               // delete chart;
               // delete chartView;
               // delete dialog;
    }


void MainWindow::on_pushButton_2_clicked()
{
    c= new camera ();
    c->show();
}
