#include "personnel.h"

personnel::personnel()
{
    cin =0; nom =" "; prenom =" "; poste =" "; mail =" "; salaire =0; tel ="";
}
personnel::personnel(int i,QString s,QString r  ,QDate a ,QString  z ,QString t,QString h,float o)
{
    this->cin= i;
    this->nom= s;
    this->prenom= r;
    this->date_em= a;
    this->poste= t;
    this->mail= h;
    this->salaire= o;
    this->tel= z;
}

bool personnel::ajouter()
{
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString salaire_string = QString::number(salaire);
    //QString tel_string = QString::number(tel);
    query.prepare("insert into personnel (cin, nom, prenom, date_em, tel, poste, mail, salaire)" "values (:cin, :nom, :prenom, :date_em, :tel, :poste, :mail, :salaire)");

    query.bindValue(":cin",cin_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_em",date_em);
    query.bindValue(":poste",poste);
    query.bindValue(":mail",mail);
    query.bindValue(":salaire",salaire_string);
    query.bindValue(":tel",tel);

    return query.exec();
}
bool personnel::supprimer(int cin)
{
    QSqlQuery query;
    QString res = QString::number(cin);
    query.prepare("Delete from personnel where cin = :cin");
    query.bindValue(":cin",res);
    return  query.exec();
}
QSqlQueryModel * personnel::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * from personnel");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("POSTE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("MAIL"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("SALAIRE"));
    return model;
}
bool personnel::modifier()
{
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString salaire_string = QString::number(salaire);
    //QString tel_string = QString::number(tel);
    query.prepare("UPDATE personnel SET cin=:cin, nom=:nom, prenom=:prenom, date_em=:date_em, tel=:tel, poste=:poste, mail=:mail, salaire=:salaire "
                  "WHERE cin = '"+cin_string+"'");
    query.bindValue(":cin", cin_string);

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_em",date_em);
    query.bindValue(":poste",poste);
    query.bindValue(":mail",mail);
    query.bindValue(":salaire",salaire_string);
    query.bindValue(":tel",tel);

    return query.exec();
}

QSqlQueryModel *personnel::afficher_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM PERSONNEL ORDER BY cin ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin "));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_em"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("tel"));
          return model;
}

QSqlQueryModel *personnel::recherche(QString critere)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM PERSONNEL WHERE LOWER(nom) = LOWER(:nom) or cin=:nom");
    query.bindValue(":nom", critere);
    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_em"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("tel"));
    return model;
}























QChartView *personnel::stat_poste(){

    int admin=0;
    int medecin=0;
    int chef=0;
    int employee=0;


    QSqlQuery query;
    query.prepare("select * from PERSONNEL where POSTE='Admin'");
    query.exec();
    while(query.next())
        admin++;

    query.prepare("select * from PERSONNEL where POSTE='Medecin'");
    query.exec();
    while(query.next())
        medecin++;

    query.prepare("select * from PERSONNEL where POSTE='Chef'");
    query.exec();
    while(query.next())
        chef++;

    query.prepare("select * from PERSONNEL where POSTE='Employee'");
    query.exec();
    while(query.next())
        employee++;


    QPieSeries *series = new QPieSeries();
        series->append("Admin", admin);
        series->append("Medecin", medecin);
        series->append("Chef", chef);
        series->append("Employee", employee);


        QPieSlice *slice = series->slices().at(0);
        slice->setExploded(true);
        slice->setColor("#F4C2C2");
        QPieSlice *slice2 = series->slices().at(1);
        slice2->setColor("#A89EE0");
        QPieSlice *slice3 = series->slices().at(2);
        slice3->setColor("#DDA0DD");
        QPieSlice *slice4 = series->slices().at(3);
        slice4->setColor("#FF1493");
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("statistics");

        series->setLabelsVisible();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->chart()->setAnimationOptions(QChart::AllAnimations);
        chartView->chart()->legend()->hide();
        return chartView;
}
bool personnel::connecter()
{
    QSqlQuery query;

       query.prepare("SELECT * FROM personnel where nom= :nom and cin= :cin");
       query.bindValue(":nom",nom);
       query.bindValue(":cin",cin);
       if (query.exec() && query.next())
       {
       return true;
       }
       else
       {
           qDebug() << "cin wala id ghalet " << "nom = " <<nom << "cin = " << cin;
           return false;
       }
}
