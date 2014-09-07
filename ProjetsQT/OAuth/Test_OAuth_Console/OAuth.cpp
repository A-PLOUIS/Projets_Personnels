#include "OAuth.h"

OAuth::OAuth()
{
    manager = new QNetworkAccessManager();
    connect(this->manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(ReceptionReponse(QNetworkReply*)));
}

OAuth::~OAuth()
{
    delete manager;
}

void OAuth::demanderAutorisation(QString clientID, QString redirectionURI, QString scope)
{
    this->demandeAuto = true;
    this->demandeToken = false;
    //Adresse avec parametres
    QString adresseAuto = this->adresse + "&client_id=" + clientID +"&redirect_uri=" + redirectionURI + "&scope=" + scope;


    manager->get(QNetworkRequest(QUrl(adresseAuto)));

}

void OAuth::ReceptionReponse(QNetworkReply *rep)
{
    qDebug() << "Succès";
    if(this->demandeAuto){
        QByteArray reponse(rep->readAll());
        qDebug() << "Autorisation : " << reponse;
    }
}
