#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <MHDFileReader.h>
#include <IgssImage.h>
#include <vtkSmartPointer.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void readImageFileFrom(QString path);

private:
    QString mhdImagePath;
    IgssImage* mraImage;
    IgssImage* igssImage;
    MHDFileReader* mhdFileReader;
    vtkSmartPointer<vtkImageData>vtkImage;
    IgssVtkImageConverter* igssVtkImageConverter;
};

#endif // WIDGET_H
