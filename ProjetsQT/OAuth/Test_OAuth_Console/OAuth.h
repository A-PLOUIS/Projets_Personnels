#ifndef OAUTH_H
#define OAUTH_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

class OAuth : public QObject
{
    Q_OBJECT

public:
    OAuth();
    ~OAuth();

    void demanderAutorisation(QString clientID,QString redirectionURI,QString scope);

public slots:
    void ReceptionReponse(QNetworkReply* rep);
private:
    QNetworkAccessManager *manager;
    QString adresse = "https://accounts.google.com/o/oauth2/auth?response_type=code";
    bool demandeAuto=false;
    bool demandeToken = false;

};

#endif // OAUTH_H
