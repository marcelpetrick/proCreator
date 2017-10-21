#pragma once

class DirectoryReader
{
public:
    DirectoryReader();

    //! Parse the current (given?) directory for all pre-defined file-filters and return them in a nice map of QStringList
    void getFiles(); //TODO fix the returnValue
};
