#include "ProFileWriter.h"

// Qt includes
#include <QtCore/QDir>
#include <QtCore/QDebug>

namespace
{
    QString cVersion = "0.1";
}

//###############################################

ProFileWriter::ProFileWriter(QString pathToUse)
    : m_pathToUse(pathToUse)
{
}

//###############################################

void ProFileWriter::writeEverything(const QString targetName)
{
    //qDebug() << "ProFileWriter::writeEverything: targetName=" << targetName; //todom remove

    // create the header
    writeHeader(targetName);

    //SOURCES
    writeSection(QString("SOURCES"), getFiles(QStringList({"*.cpp"})));

    //HEADERS
    writeSection(QString("HEADERS"), getFiles(QStringList({"*.h", "*.hpp"})));

    //FORMS
    writeSection(QString("FORMS"), getFiles(QStringList({"*.ui"})));

    //RESOURCES
    writeSection(QString("RESOURCES"), getFiles(QStringList({"*.qrc"})));
}

//###############################################


void ProFileWriter::writeSection(const QString sectionName, QStringList items)
{
    //0. if the list it empty, then don't write the section at all (TODO TBD - maybe as empty section)
    //1. else: add items. Per item some tabs, then filename, then space, then backslash
    //2. last item get's no slash

    // see 0.: by now empty sections shall be omitted. Just comment the return, if not.
    if(items.isEmpty())
    {
        //qDebug() << "\t" << "empty list - early return";
        return; //! @attention  comment this if empty sections shall still appear
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
    output.append(QString() + "# pro-file created by proCreator " + cVersion + "                     #" + "\n");
    output.append(QString() + "#   project: https://github.com/marcelpetrick/proCreator #" + "\n");
    output.append(QString() + "#   contact: mail@marcelpetrick.it                       #" + "\n");
    output.append(QString() + "##########################################################" + "\n");
    output.append("\n");
    output.append(QString() + "QT += core gui" + "\n");
    output.append("\n");
    output.append(QString() + "CONFIG += c++11" + "\n");
    output.append("\n");
    output.append(QString() + "DEFINES += QT_DEPRECATED_WARNINGS" + "\n");
    output.append("\n");
    output.append(QString() + "greaterThan(QT_MAJOR_VERSION, 4): QT += widgets" + "\n");
    output.append("\n");
    output.append(QString() + "TARGET = " + targetName + "\n");
    output.append(QString() + "TEMPLATE = app" + "\n");

    qDebug().noquote() << output;
}

//###############################################

QStringList ProFileWriter::getFiles(QStringList filter)
{
    QDir directory(m_pathToUse); //todo change this to the best directory

    QStringList const fileNames = directory.entryList(filter, QDir::Files);
    //qDebug() << "fileNames:" << fileNames; //todom remove

    return fileNames;
}
