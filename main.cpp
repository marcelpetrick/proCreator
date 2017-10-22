// TODO write some crap about what kind of project this is ..

#include "ProFileWriter.h"

// Qt includes
#include <QtCore/QDebug>
#include <QCoreApplication> //for arg-list

int main(int argc, char *argv[])
{
    //for easier access to the arguments; without real parsing
    QCoreApplication app(argc, argv);
    QStringList argList(app.arguments());

//    //check the arguments
//    {
//        qDebug() << "main(): argc = " << argc << endl;
//        // print the current argument list
//        for(int i = 0; i < argList.size(); ++i)
//        {
//            qDebug() << QString("argv #%1 is %2").arg(i).arg(argList[i]) << endl;
//        }
//    }

    // if the second argument exists, assume it is the path to use.
    // Currently no validation is done. If wrong - your problem :)
    QString pathToUse(".");
    if(argList.size() >= 2) //check for existance of at least one "real" parameter
    {
        pathToUse = argList[1];
    }
//    else
//    {
//        qDebug() << "not enough input - will use default path, which means \".\" now";
//    }

    // do the processing
    ProFileWriter writer(pathToUse);
    writer.writeEverything();
}
