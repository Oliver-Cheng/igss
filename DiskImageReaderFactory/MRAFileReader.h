#ifndef MRAFILEREADER_H
#define MRAFILEREADER_H

#include <QString>
#include <QStringList>
#include <IgssImage.h>
#include <QFile>

class MRAFileReader
{
public:
    MRAFileReader();
    void doParseMHDFile(QString mhdFilePath, IgssImage*image);
private:
    IgssImage *image;
};

#endif // MRAFILEREADER_H
