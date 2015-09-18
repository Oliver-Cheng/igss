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
    bool doParseMHDFile(QString mhdFilePath, IgssImage*image);
    bool getReadCompleteFlag();
    void setReadCompleteFlag(bool flag);

private:
    IgssImage *image;
    bool readCompleteFlag;
};

#endif // MRAFILEREADER_H
