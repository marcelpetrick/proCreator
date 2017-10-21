#include "ProFileWriter.h"

// Qt includes
#include <QtCore/QDebug>

ProFileWriter::ProFileWriter()
{
    //qDebug() << "ctor ProFileWriter()"; //todom remove
}

//###############################################

void ProFileWriter::writeEverything(const QString targetName)
{
    //qDebug() << "ProFileWriter::writeEverything: targetName=" << targetName; //todom remove

    // create the header
    writeHeader(targetName);

    //SOURCES
    {
        QStringList exampleList;
        exampleList << "file0.cpp"; // << "file1.h" << "file2";
        QString sectioName("SOURCES");
        writeSection(sectioName, exampleList);
    }

    //HEADERS
    {
        QStringList exampleList;
        exampleList << "file0.h" << "file1.h" << "file2";
        QString sectioName("HEADERS");
        writeSection(sectioName, exampleList);
    }

    //FORMS
    {
        QStringList exampleList;
        //exampleList << "file0" << "file1" << "file2";
        QString sectioName("FORMS");
        writeSection(sectioName, exampleList);
    }

    //RESOURCES
    {
        QStringList exampleList;
        //exampleList << "file0" << "file1" << "file2";
        QString sectioName("RESOURCES");
        writeSection(sectioName, exampleList);
    }
}

//###############################################


void ProFileWriter::writeSection(const QString sectionName, QStringList items)
{
    //qDebug() << "ProFileWriter::writeSection: sectionName=" << sectionName << " | items=" << items; //todom remove

    //0. if the list it empty, then don't write the seection at all (TODO TBD - mayb as empty section)
    //1. else: add items. Per item some tabs, then filename, then space, then backslash
    //2. last item get's no slash

    // see 0.: by now empty sections shall be omitted. Just comment the return, if not.
    if(items.isEmpty())
    {
        //qDebug() << "\t" << "empty list - early return";
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

    // additional spacer
    output.append("\n");

    //qDebug() << "result:";
    qDebug().noquote() << output;
}

//###############################################

void ProFileWriter::writeHeader(const QString targetName)
{
    QString output;

    output.append(QString() + "##########################################################" + "\n");
    output.append(QString() + "# pro-file created by proCreator                         #" + "\n"); //TODO maybe add some date ... but, IDC
    output.append(QString() + "#   project: https://github.com/marcelpetrick/proCreator #" + "\n");
    output.append(QString() + "#   contact: mail@marcelpetrick.it                       #" + "\n");
    output.append(QString() + "##########################################################" + "\n");
    output.append("\n");
    output.append(QString() + "QT += core gui" + "\n");
    output.append("\n");
    output.append(QString() + "greaterThan(QT_MAJOR_VERSION, 4): QT += widgets" + "\n");
    output.append("\n");
    output.append(QString() + "TARGET = " + targetName + "\n");
    output.append(QString() + "TEMPLATE = app" + "\n");

    qDebug().noquote() << output;
}
