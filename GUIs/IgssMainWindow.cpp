#include "IgssMainWindow.h"
#include "vtkImageData.h"


IgssMainWindow::IgssMainWindow(SystemDispatcher* dispatcher): QWidget(){

    this->systemDispatcher = dispatcher;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->drawBackground();

}

void IgssMainWindow::constructIHM(){

    //!----------------------------------------------------------------------------------------------------
    //! status bar area
    //!----------------------------------------------------------------------------------------------------
    algorithmTestPlatform = new AlgorithmTestPlatform(this->systemDispatcher,
                                                                                                this->englishCaracterStyle,
                                                                                                this->primary_screen_width,
                                                                                                this->primary_screen_height);

    //!------------------------------------------------------------------------------------------
    //! configurationBoard:
    //!------------------------------------------------------------------------------------------
    configurationBoard = new QWidget();
    configurationBoard->setFixedWidth(this->primary_screen_width*0.13);

    //!------------------------------------------------------------------------------------------
    //! system information board: a place where all information about pa    //qDebug()<<patient->MraImageReadComplete;tient, doctor and replays
    //! in the system will be displayed here
    //!------------------------------------------------------------------------------------------
    patientsWidget = new PatientsWidget(this->systemDispatcher,
                                                                       this->algorithmTestPlatform,
                                                                       this->surgeryPlanWindow,
                                                                       this->guidewareTrackingWindow,
                                                                       this->englishCaracterStyle,
                                                                       this->primary_screen_width,
                                                                       this->primary_screen_height);

    replaysWidget = new ReplaysWidget();
    surgerySystemWidget = new SurgerySystemWidget();

    systemInformationBoard = new QTabWidget();
    systemInformationBoard->setStyleSheet(this->systemInformationBoardStyleSheet);

    systemInformationBoard->insertTab(0, patientsWidget, "Patients");
    systemInformationBoard->insertTab(1, surgerySystemWidget, "System");
    systemInformationBoard->insertTab(2, replaysWidget, "History");

    //!------------------------------------------------------------------------------------------
    //! controlBoard:
    //!------------------------------------------------------------------------------------------
    controlBoard = new QWidget();
    controlBoard->setFixedWidth(this->primary_screen_width*0.024);
    closeButton = new QPushButton();
    closeButton->setIcon(QIcon(":/images/close.png"));
    closeButton->setIconSize(QSize(this->primary_screen_width*0.018,this->primary_screen_width*0.018));
    closeButton->setStyleSheet("background-color:transparent");

    closeButton->setFixedSize(this->primary_screen_width*0.023, this->primary_screen_width*0.023);

    controlArea = new QWidget();
    //controlArea->setStyleSheet("background-color:red");
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
    //! main window
    //!----------------------------------------------------------------------------------------------------
    igssMainWindowLayout =  new QVBoxLayout(this);
    igssMainWindowLayout->addWidget(mainPlatform);
    igssMainWindowLayout->addWidget(algorithmTestPlatform);
    igssMainWindowLayout->setSpacing(2);
    igssMainWindowLayout->setMargin(0);
}

//!
//! \brief IgssMainWindow::findPatientExisted
//!
void IgssMainWindow::findPatientExisted(){
   patientsWidget->findPatientExisted();
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief AnalyserMainWindow::drawBackground
//!
void IgssMainWindow::drawBackground(){
    pixmap = new QPixmap(":/images/images_1_1.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(this->primary_screen_width, this->primary_screen_height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//!---------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::initVariable
//!
void IgssMainWindow::initVariable(){

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);// | Qt::WindowStaysOnTopHint);
    this->setWindowOpacity(1);
    this->setMouseTracking(true);
    this->setAutoFillBackground(true);

    desktop = QApplication::desktop();
    screen_count = desktop->screenCount();
    primary_screen = desktop->primaryScreen();
    screen = new Screen[screen_count];

    for(unsigned char i = 0; i < screen_count; i++){
        screen[i].screenIndex = primary_screen + i;
        screen[i].rect = desktop->screenGeometry(primary_screen + i);
        qDebug()<<i<<screen[i].rect .width()<<screen[i].rect .height();
    }

    primary_screen_width = screen[0].rect.width();
    primary_screen_height = screen[0].rect.height();
    this->resize(primary_screen_width,primary_screen_height);



    flag = 0;

    this->systemInformationBoardStyleSheet =
                       "QTabWidget::pane {border: 0.5px solid AliceBlue;}" \
                       "QTabWidget::tab-bar {left: 0px; /* move to the right by 0px */}  " \
                       "QTabBar::tab {background-color: aliceBlue; color: white; padding: 10px;"\
                       "border: 1px solid #C4C4C3;border-bottom-color: #C2C7CB; /* same as the pane color */border-top-left-radius: 0px;border-top-right-radius: 0px;min-width: 8ex;padding: 2px; color:darkGreen;} " \
                       "QTabBar::tab:selected, QTabBar::tab:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 LightSteelBlue, stop: 0.4 #f4f4f4,stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);}" \
                       "QTabBar::tab:selected { border-color: #9B9B9B;border-bottom-color: #C2C7CB; /* same as pane color */ }" \
                       "QTabBar::tab:!selected {margin-top: 1px; /* make non-selected tabs look smaller */}"\
                       "QTabBar::close-button{border-image: url(:/no.png)}" \
                       "QTabBar::close-button:hover {border-image: url(:/images/close-hover.png)}";

    this->englishCaracterStyle = new QFont("Times",8,QFont::AnyStyle, false);

    this->surgeryPlanWindow = new SurgeryPlanWindow(-screen[2].rect.width(), 50, screen[2].rect.width(), screen[2].rect.height(), this->systemDispatcher);

    this->guidewareTrackingWindow = new GuidewareTrackingWindow(screen[0].rect.width(), 50, screen[1].rect.width(), screen[1].rect.height(), this->systemDispatcher);

}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setConnectios
//!
void IgssMainWindow::setConnections(){
    this->connect(closeButton, SIGNAL(clicked()), this, SLOT(closeSystem()));
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
    this->showMaximized();
    this->showFullScreen();
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setSystemDispatecher
//! \param dispatcher
//!
void IgssMainWindow::setSystemDispatecher(SystemDispatcher* dispatcher){
    this->systemDispatcher = dispatcher;
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

//!----------------------------------------------------------------------------------------
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

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::closeSystem
//!
void IgssMainWindow::closeSystem(){
    this->close();
}

