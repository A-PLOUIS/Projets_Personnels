#include <QCoreApplication>
#include "OAuth.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    OAuth test;
    test.demanderAutorisation("1047243032515-81a9j70fb7dk1n6girfi0ps6t6aogqqd.apps.googleusercontent.com","urn:ietf:wg:oauth:2.0:oob","email%20profile");
    return a.exec();
}
