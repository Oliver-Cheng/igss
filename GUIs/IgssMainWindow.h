#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <MHDFileReader.h>
#include <IgssImage.h>
#include <vtkSmartPointer.h>
#include "IgssVtkImageConverter.h"
#include "SystemDispatcher.h"

class IgssMainWindow : public QWidget
{
    Q_OBJECT

public:
    IgssMainWindow();
#ifdef win32
    ~Widget();
#endif
    void setSystemDispatecher(SystemDispatcher* dispatcher);
    void readImageFileFrom(QString path);
    void readImageFromVtkConvert();

private:
    SystemDispatcher* dispatcher;

    QString mhdImagePath;
    IgssImage* mraImage;
    IgssImage* igssImage;
    MHDFileReader* mhdFileReader;
    vtkSmartPointer<vtkImageData>vtkImage;
    IgssVtkImageConverter* igssVtkImageConverter;
};

#endif // WIDGET_H
