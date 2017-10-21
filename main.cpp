#include "DirectoryReader.h"
#include "ProFileWriter.h"

// Qt includes
//#include <QCoreApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

//    QCoreApplication a(argc, argv);
//    return a.exec();

    //for the input functionality; mean: parse the directory content
    // TODO the DirectoryReader shall return a map of QStringList
    DirectoryReader reader;
    reader.getFiles(); //TODO maybe rename .. not the most descriptive name for the method which shall do "everything"
#if 0
    //for the output functionality
    ProFileWriter writer;
    writer.writeEverything();
#endif

    //qDebug() << "end of program";
}
