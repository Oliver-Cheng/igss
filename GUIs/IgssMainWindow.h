#ifndef WIDGET_H
#define WIDGET_H

#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)

#include <QWidget>
#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QVTKWidget.h>
#include <QLineEdit>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QApplication>

#include <MRAFileReader.h>
#include <IgssImage.h>
#include <IgssVtkImageConverter.h>
#include <SystemDispatcher.h>
#include <PatientsWidget.h>
#include <ReplaysWidget.h>
#include <SurgerySystemWidget.h>
#include <AlgorithmTestPlatform.h>

#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkVolume.h>
#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkVolumeRayCastMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>


class IgssMainWindow : public QWidget{
    Q_OBJECT

public:
    IgssMainWindow(SystemDispatcher *dispatcher);
#ifdef win32
    ~Widget();
#endif
    void findPatientExisted();
    void initVariable();
    void initVisualizationComponents();
    void constructIHM();
    void setConnections();
    void display();
    void displayMraImage(vtkImageData* input);
    void setSystemDispatecher(SystemDispatcher* dispatcher);
    void readImageFileFrom(QString path);
    void readImageFromVtkConvert();
    void setSystemStatus(QString status);
    void drawBackground();

private:
    QFont *englishCaracterStyle;

    QPixmap *pixmap;
    QDesktopWidget *desktop;

    QVBoxLayout* igssMainWindowLayout;
    QVBoxLayout *controlBoardLayout;
    QHBoxLayout *mainPlatformLayout;
    QGridLayout *statusBarLayout;

    QWidget *mainPlatform;
    QWidget *configurationBoard;
    QWidget *controlBoard;
    QWidget *statusBar;
    QWidget *controlArea;

    AlgorithmTestPlatform* algorithmTestPlatform;

    QPushButton *displayStatusButton;
    QPushButton *closeButton;

    QTabWidget *systemInformationBoard;

    QVTKWidget* mraImageDisplayWindow;

    QString systemInformationBoardStyleSheet;

    PatientsWidget* patientsWidget;
    ReplaysWidget*replaysWidget;
    SurgerySystemWidget* surgerySystemWidget;

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

    int flag;
    int primary_screen_width;
    int primary_screen_height;

private slots:
    void closeSystem();
};

#endif // WIDGET_H
