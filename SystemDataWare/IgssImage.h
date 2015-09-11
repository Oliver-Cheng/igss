#ifndef MRAIMAGE_H
#define MRAIMAGE_H

#include <QString>
#include <QDebug>

class IgssImage{

public:
    IgssImage();
    void setNumberOfDimension(int NDims);
    void setDimensionSize(int x, int y, int z);
    void setElementSpacing(float x_spacing, float y_spacing, float z_spacing);
    void setElementType(QString type);
    void setElementByteOrderMSB(int order);
    void setRawFileName(QString rawFileName);

    void getDimensionSize(int *dims);
    void getElementSpacing(double *spaces);
    int getNumberOfDimension();
    int getElementByteOrderMSB();

    void setLengthOfDataSet();
    void setValueByIndex(int index, unsigned short value);

    QString getRawFileName();
    long getLengthOfDataset();
    unsigned short getValueByIndex(long i);


private:
    int NDims;
    int DimSize[3];
    double ElementSpacing[3];
    float Position[3];
    int Orientation[9];
    int CenterOfRotation[3];

    int ElementByteOrderMSB;
    int ElementNumberOfChannels;

    QString AnatomicalOrientation;
    QString ElementType;
    QString ElementDataFile;

    unsigned short *values;
    long length ;

};

#endif // MRAIMAGE_H
