#include "ProFileWriter.h"

#include <QCoreApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
//    QCoreApplication a(argc, argv);

//    return a.exec();

    ProFileWriter writer;
    writer.writeEverything();

    //qDebug() << "end of program";
}
