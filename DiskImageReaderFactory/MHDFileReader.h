#ifndef MHDFILEREADER_H
#define MHDFILEREADER_H

#include <QString>
#include <QStringList>
#include <IgssImage.h>
#include <QFile>

class MHDFileReader
{
public:
    MHDFileReader();
    void doParseMHDFile(QString mhdFilePath, IgssImage*image);
};

#endif // MHDFILEREADER_H
