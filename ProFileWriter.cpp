#include "ProFileWriter.h"
#include <QDebug>

ProFileWriter::ProFileWriter()
{
    qDebug() << "ctor ProFileWriter()"; //todom remove
}

void ProFileWriter::writeSection(const QString sectionName, QStringList items)
{
    qDebug() << "ProFileWriter::writeSection: sectionName=" << sectionName << " | items=" << items; //todom remove
}
