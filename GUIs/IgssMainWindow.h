#ifndef WIDGET_H
#define WIDGET_H

#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)

#include <QWidget>
#include <QVBoxLayout>
#include <QVTKWidget.h>
#include <MRAFileReader.h>
#include <IgssImage.h>
#include <vtkSmartPointer.h>
#include "IgssVtkImageConverter.h"
#include "SystemDispatcher.h"
#include <vtkImageData.h>
#include <vtkVolume.h>
#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkVolumeRayCastMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>


class IgssMainWindow : public QWidget
{
    Q_OBJECT

public:
    IgssMainWindow();
#ifdef win32
    ~Widget();
#endif
    void display();
    void displayMraImage(vtkImageData* input);
    void setSystemDispatecher(SystemDispatcher* dispatcher);
    void readImageFileFrom(QString path);
    void readImageFromVtkConvert();

private:
    QVBoxLayout* igssMainWindowLayout;
    QVTKWidget* mraImageDisplayWindow;

    //! component for mra image display
    vtkVolumeRayCastMapper* volumeMapper;
    vtkVolumeRayCastCompositeFunction *compositeFunction;
    vtkVolume *volume;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderer> renderer;


    SystemDispatcher* dispatcher;
    QString mhdImagePath;
    IgssImage* mraImage;
    IgssImage* igssImage;
    MRAFileReader* mhdFileReader;
    vtkSmartPointer<vtkImageData>vtkImage;
    IgssVtkImageConverter* igssVtkImageConverter;


};

#endif // WIDGET_H
