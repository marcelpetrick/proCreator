#include "ProFileWriter.h"
#include <QDebug>

ProFileWriter::ProFileWriter()
{
    qDebug() << "ctor ProFileWriter()"; //todom remove
}

void ProFileWriter::writeSection(const QString sectionName, QStringList items)
{
    qDebug() << "ProFileWriter::writeSection: sectionName=" << sectionName << " | items=" << items; //todom remove

    //! @TODO create now the string which will be like:
    // HEADERS  += \
    //          item0 \
    //          item1 \
    //          item2

    //0. if the list it empty, then don't write the seection at all (TODO TBD - mayb as empty section)
    //1. else: add items. Per item some tabs, then filename, then space, then backslash
    //2. last item get's no slash

    // see 0.
    if(items.isEmpty())
    {
        qDebug() << "\t" << "empty list - early return";
        return;
    }

    QString output;
    // see 1.
    output.append(sectionName + " += \\" + "\n");

    for(auto elem : items)
    {
        output.append("\t" + elem + " \\" + "\n");
    }

    // see 2.: simple version, just remove the last two characters ... instead of doing some special handling for the last item of the list ..
    output = output.left(output.length() - 2);

    qDebug() << "resut:";
    qDebug().noquote() << output;
}
