// TODO write some crap about what kind of project this is ..

#include "ProFileWriter.h"

// Qt includes
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    //for the input functionality; mean: parse the directory content
    // TODO the DirectoryReader shall return a map of QStringList
    //DirectoryReader reader;
    //reader.getFiles(); //TODO maybe rename .. not the most descriptive name for the method which shall do "everything"

    ProFileWriter writer;
    writer.writeEverything();

    //qDebug() << "end of program";
}
