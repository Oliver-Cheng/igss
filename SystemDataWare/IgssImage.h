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
    void getElementSpacing(float *spaces);
    int getNumberOfDimension();
    int getElementByteOrderMSB();

    void setLengthOfDataSet();
    void setValueByIndex(int index, unsigned short value);

    QString getRawFileName();

private:
    int NDims;
    int DimSize[3];
    float ElementSpacing[3];
    float Position[3];
    int Orientation[9];
    int CenterOfRotation[3];

    int ElementByteOrderMSB;
    int ElementNumberOfChannels;

    QString AnatomicalOrientation;
    QString ElementType;
    QString ElementDataFile;

    unsigned short *values;

};

#endif // MRAIMAGE_H
