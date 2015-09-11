#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <MHDFileReader.h>
#include <IgssImage.h>
#include <vtkSmartPointer.h>
#include "IgssVtkImageConverter.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
#ifdef win32
    ~Widget();
#endif
    void readImageFileFrom(QString path);
    void readImageFromVtkConvert();

private:
    QString mhdImagePath;
    IgssImage* mraImage;
    IgssImage* igssImage;
    MHDFileReader* mhdFileReader;
    vtkSmartPointer<vtkImageData>vtkImage;
    IgssVtkImageConverter* igssVtkImageConverter;
};

#endif // WIDGET_H
