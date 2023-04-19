#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QString>
#include<QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts>
#include <QChartView>


class personnel
{
    private:
    int cin;
    QString nom;
    QString prenom;
    QDate date_em;
    QString tel;
    QString poste;
    QString mail;
    float salaire;

public:
    personnel();
    personnel(int,QString ,QString  ,QDate ,QString ,QString ,QString ,float);
    QString getnom(){return nom ; }
    QString getprenom(){return prenom; }
    QString getposte(){return poste ; }
    QString getmail(){return mail; }
    float getsalaire(){return salaire;}
    QString gettel(){return tel;}
    int getcin(){return cin ; }
    QDate getdate_em(){return date_em;}
    void settel(QString tel1){tel=tel1;}
    void setnom(QString nom1){nom=nom1;}
    void setprenom(QString prenom1){prenom=prenom1;}
    void setmail(QString maill){mail=maill;}
    void setdate(QDate d){date_em=d;}
    void setposte(QString poste1){poste=poste1;}
    void setcin(int cin1){cin=cin1;}
    void  setsalaire(float sal){salaire=sal;}
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher_id();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString critere);


    QChartView *stat_date_em();
    QChartView *stat_poste();
    bool connecter();

};

#endif // PERSONNEL_H
