#pragma once

#include <QString>
#include <QStringList>

class ProFileWriter
{
public:
    ProFileWriter(QString pathToUse);

    //! Shall do all method-calls for writing the sections.
    //! Shall be used as main call.
    void writeEverything(QString const targetName = "proCreatorProject");

private:
    //[methods]

    //! Used to create a section with fitting name: like "HEADERS".
    //! The content is added then based on the number of items.
    //! Special cases are the empty list. Also care for the last item, so that it gets no newline-backslash.
    void writeSection(QString const sectionName, QStringList items);

    //! Used to create the header of the pro-file.
    void writeHeader(QString const targetName);

    //! Parse the current (given?) directory for all pre-defined file-filters and return them in a nice map of QStringList
    //! @param filter list of needed filetypes
    //! @returns the list of files which fit to the filter
    QStringList getFiles(QStringList filter);

    //[members]
    QString m_pathToUse;
};
