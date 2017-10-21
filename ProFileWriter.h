#pragma once

#include <QString>
#include <QStringList>

class ProFileWriter
{
public:
    ProFileWriter();

    //! Shall do all method-calls for writing the sections.
    //! Shall be used as main call.
    void writeEverything(QString const targetName = "proCreatorProject");

private:
    //! Used to create a section with fitting name: like "HEADERS".
    //! The content is added then based on the number of items.
    //! Special cases are the empty list. Also care for the last item, so that it gets no newline-backslash.
    void writeSection(QString const sectionName, QStringList items);
};
