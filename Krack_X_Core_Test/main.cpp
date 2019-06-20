#include <QCoreApplication>
#include <QtDebug>
#include <core.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Test";
    core cored;
    return a.exec();
}
