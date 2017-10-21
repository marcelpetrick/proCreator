#include "ProFileWriter.h"

#include <QCoreApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
//    QCoreApplication a(argc, argv);

//    return a.exec();

    QStringList exampleList;
    exampleList << "file0" << "file1" << "file2";
    QString sectioName("HEADERS");
    ProFileWriter writer;
    writer.writeSection(sectioName, exampleList);

    qDebug() << "end of program";
}
