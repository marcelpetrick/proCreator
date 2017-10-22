#include "DirectoryReader.h"

// Qt includes
#include <QtCore/QDir>
#include <QtCore/QDebug>

// TODO add the path as parameter
DirectoryReader::DirectoryReader()
{

}

//###############################################

void DirectoryReader::getFiles()
{
    qDebug() << "DirectoryReader::getFiles()"; //todom remove

    QDir directory(".");

    // initialize the filters
    QStringList filter;
    filter << "*.h" << "*.hpp"; // todo make more dynamic
    //directory.setNameFilters(filter);

    QStringList const fileNames = directory.entryList(filter, QDir::Files);
    qDebug() << "fileNames:" << fileNames; //todom remove
}
