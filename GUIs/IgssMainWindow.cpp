#include "IgssMainWindow.h"
#include "vtkImageData.h"

/*
readImageFileFrom("C://Users//duyue//Documents//CanalyserWorkspace//PatientsDataware//Wang_Dechun__1990_09_04//mra_tridimensionel__image//Wang_Dechun.mhd");
readImageFileFrom("/home/bigboom/Documents/CanalyserWorkspace/PatientsDataware/He_Shiyu__1990_09_03/mra_tridimensionel__image/He_Shiyu.mhd");
readImageFileFrom("/home/vincent/Documents/CanalyserWorkspace/PatientsDataware/He_Shiyu__1990_09_03/mra_tridimensionel__image/He_Shiyu.mhd");
readImageFileFrom("/home/sky/Documents/CanalyserWorkspace/PatientsDataware/He_Shiyu__1990_09_03/mra_tridimensionel__image/He_Shiyu.mhd");

vtkSmartPointer<vtkImageData> input = vtkSmartPointer<vtkImageData>::New();
IgssVtkImageConverter *c = new IgssVtkImageConverter();
c->IgssToVtk(mraImage, input);
readImageFromVtkConvert();*/
//mraImageDisplayWindow = new QVTKWidget();
//igssMainWindowLayout->addWidget(mraImageDisplayWindow);

IgssMainWindow::IgssMainWindow(): QWidget(){
    this->setWindowState(Qt::WindowFullScreen);

    this->constructIHM();
    this->setConnections();

}

void IgssMainWindow::constructIHM(){
    //!------------------------------------------------------------------------------------------
    //! configurationBoard:
    //!------------------------------------------------------------------------------------------
    configurationBoard = new QWidget();
    configurationBoard->setFixedWidth(250);
    configurationBoard->setStyleSheet("background-color:yellow");

    //!------------------------------------------------------------------------------------------
    //! system information board: a place where all information about patient, doctor and replays
    //! in the system will be displayed here
    //!------------------------------------------------------------------------------------------
    systemInformationBoard = new QTabWidget();
    systemInformationBoard->setStyleSheet("background-color:green");

    //!------------------------------------------------------------------------------------------
    //! controlBoard:
    //!------------------------------------------------------------------------------------------
    controlBoard = new QWidget();
    controlBoard->setStyleSheet("background-color:blue");

    closeButton = new QPushButton("X");
    closeButton->setFixedSize(40,40);

    controlArea = new QWidget();

    controlBoardLayout = new QVBoxLayout(controlBoard);
    controlBoardLayout->addWidget(closeButton);
    controlBoardLayout->addWidget(controlArea);
    controlBoardLayout->setSpacing(0);
    controlBoardLayout->setMargin(0);

    //!----------------------------------------------------------------------------------------------------
    //! main platform
    //!----------------------------------------------------------------------------------------------------
    mainPlatform = new QWidget();
    mainPlatformLayout = new QHBoxLayout(mainPlatform);
    mainPlatformLayout->addWidget(configurationBoard);
    mainPlatformLayout->addWidget(systemInformationBoard);
    mainPlatformLayout->addWidget(controlBoard);
    mainPlatformLayout->setSpacing(0);
    mainPlatformLayout->setMargin(0);

    //!----------------------------------------------------------------------------------------------------
    //! status bar area
    //!----------------------------------------------------------------------------------------------------
    statusBar = new QWidget();
    statusBar->setFixedHeight(50);
    statusBar->setStyleSheet("background-color:red");

    //!----------------------------------------------------------------------------------------------------
    //! main window
    //!----------------------------------------------------------------------------------------------------
    igssMainWindowLayout =  new QVBoxLayout(this);
    igssMainWindowLayout->addWidget(mainPlatform);
    igssMainWindowLayout->addWidget(statusBar);
    igssMainWindowLayout->setSpacing(0);
    igssMainWindowLayout->setMargin(0);
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setConnectios
//!
void IgssMainWindow::setConnections(){
    this->connect(closeButton, SIGNAL(released()), this, SLOT(closeSystem()));
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::initVisualizationComponents
//!
void IgssMainWindow::initVisualizationComponents(){
    volumeMapper = vtkVolumeRayCastMapper::New();
    compositeFunction = vtkVolumeRayCastCompositeFunction::New();
    volume = vtkVolume::New();
    renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::display
//!
void IgssMainWindow::display(){
    this->show();
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setSystemDispatecher
//! \param dispatcher
//!
void IgssMainWindow::setSystemDispatecher(SystemDispatcher* dispatcher){
    this->dispatcher = dispatcher;
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::displayMraImage
//! \param input
//!
void IgssMainWindow::displayMraImage(vtkImageData* input){
    this->volumeMapper->SetVolumeRayCastFunction(compositeFunction);
    this->volumeMapper->SetInputData(input);
    this->volume->SetMapper(volumeMapper);
    this->renderer->AddVolume(volume);
    this->renderer->SetBackground(0.1, 0.21, 0.31);
    this->renderWindow->AddRenderer(renderer);
    this->renderer->ResetCamera();
    this->mraImageDisplayWindow->SetRenderWindow(this->renderWindow);

}

//!----------------------------------------------------------------------------------------
//!
//! \brief Widget::readImageFileFrom
//! \param path
//!
void IgssMainWindow::readImageFileFrom(QString path){
    mhdImagePath = path;
    mraImage = new IgssImage();
    mhdFileReader = new MRAFileReader();
    mhdFileReader->doParseMHDFile(mhdImagePath ,mraImage);

}

//!
//! \brief Widget::readImageFromVtkConvert
//!
void IgssMainWindow::readImageFromVtkConvert()
{
    igssImage = new IgssImage();
    vtkImage = vtkImageData::New();
    vtkImage->SetDimensions(25,25,25);
    vtkImage->SetSpacing(1.0,1.0,1.0);
    vtkImage->SetOrigin(0.0,0.0,0.0);
    vtkImage->AllocateScalars(VTK_UNSIGNED_SHORT,1);
    unsigned short *ptr = (unsigned short*)vtkImage->GetScalarPointer();
    for(long i=0;i<25*25*25;i++)
    {
        *ptr++ = i;
    }
    igssVtkImageConverter = new IgssVtkImageConverter();
    igssVtkImageConverter->VtkToIgss(vtkImage,igssImage);
}

void IgssMainWindow::closeSystem(){
    this->close();
}
