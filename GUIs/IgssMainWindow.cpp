#include "IgssMainWindow.h"
#include "vtkImageData.h"


IgssMainWindow::IgssMainWindow(): QWidget(){
    this->setWindowState(Qt::WindowFullScreen);

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->drawBackground();

}

void IgssMainWindow::constructIHM(){
    //!------------------------------------------------------------------------------------------
    //! configurationBoard:
    //!------------------------------------------------------------------------------------------
    configurationBoard = new QWidget();
    configurationBoard->setFixedWidth(250);
    //configurationBoard->setStyleSheet("background-color:yellow");

    //!------------------------------------------------------------------------------------------
    //! system information board: a place where all information about patient, doctor and replays
    //! in the system will be displayed here
    //!------------------------------------------------------------------------------------------
    patientsWidget = new PatientsWidget(this->dispatcher);
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

    closeButton = new QPushButton("X");
    closeButton->setFixedSize(25,25);

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
    statusBar->setFixedHeight(200);
    statusBarLayout = new QGridLayout(statusBar);

    displayStatusButton = new QPushButton("display");
    systemStatus = new QTextEdit();
    systemCommand = new QLineEdit("vef mri 0");

    statusBarLayout->addWidget(displayStatusButton,0,0);
    statusBarLayout->addWidget(systemStatus,0,1);
    statusBarLayout->addWidget(systemCommand, 1, 1);

    //!----------------------------------------------------------------------------------------------------
    //! main window
    //!----------------------------------------------------------------------------------------------------
    igssMainWindowLayout =  new QVBoxLayout(this);
    igssMainWindowLayout->addWidget(mainPlatform);
    igssMainWindowLayout->addWidget(statusBar);
    igssMainWindowLayout->setSpacing(0);
    igssMainWindowLayout->setMargin(0);
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief AnalyserMainWindow::drawBackground
//!
void IgssMainWindow::drawBackground(){
    pixmap = new QPixmap(":/images/background_darkBlue.png");
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
    desktop = QApplication::desktop();
    primary_screen_width = desktop->screen(0)->width();
    primary_screen_height = desktop->screen(0)->height();
    qDebug()<<primary_screen_width<<primary_screen_height;

    flag = 0;
    this->systemInformationBoardStyleSheet =
                       "QTabWidget::pane {border: 0.5px solid AliceBlue;}" \
                       "QTabWidget::tab-bar {left: 0px; /* move to the right by 0px */}  " \
                       "QTabBar::tab {background-color: aliceBlue; color: white; padding: 10px;"\
                       "border: 1px solid #C4C4C3;border-bottom-color: #C2C7CB; /* same as the pane color */border-top-left-radius: 0px;border-top-right-radius: 0px;min-width: 8ex;padding: 2px; color:gray} " \
                       "QTabBar::tab:selected, QTabBar::tab:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 LightSteelBlue, stop: 0.4 #f4f4f4,stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);}" \
                       "QTabBar::tab:selected { border-color: #9B9B9B;border-bottom-color: #C2C7CB; /* same as pane color */ }" \
                       "QTabBar::tab:!selected {margin-top: 3px; /* make non-selected tabs look smaller */}"\
                       "QTabBar::close-button{border-image: url(:/no.png)}" \
                       "QTabBar::close-button:hover {border-image: url(:/images/close-hover.png)}";
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setConnectios
//!
void IgssMainWindow::setConnections(){
    this->connect(closeButton, SIGNAL(clicked()), this, SLOT(closeSystem()));
    //displayStatusButton
    this->connect(displayStatusButton, SIGNAL(clicked()), this, SLOT(getPatientsStatus()));
    //systemCommand
    this->connect(systemCommand,SIGNAL(returnPressed()),this,SLOT(doParseCommand()));

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

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setSystemStatus
//!
void IgssMainWindow::setSystemStatus(QString status){
    this->systemStatus->setText(QString::number(flag)+"\n"+status+"\n");
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

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::getPatientsStatus
//!
void IgssMainWindow::getPatientsStatus(){
    flag++;
    QStringList s = this->dispatcher->getPatientsStatus();
    QString info = "";
    for(int i = 0; i < s.length(); i++){
        info += s[i]+"\n";
    }
    this->setSystemStatus(info);
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::doParseCommand
//!
void IgssMainWindow::doParseCommand(){
    QString cmd = systemCommand->text();
    QString msg;

    if(cmd.contains("vef")){
        if(cmd.contains("mri")){
            QStringList temp = cmd.split(" mri ");
            int id = temp[1].toInt(0,10);
            msg = this->dispatcher->doImageProcessingByMethodType(id, 3, "vef");
        }
        else{
            //!do 2d vessel enhancement
        }
    }
    this->setSystemStatus(msg);

    /*
    QStringList temp = cmd.split(" do ");
    QStringList temp1 = temp[0].split("patient ");
    QStringList temp2 = temp[1].split("3d ");
    int id = temp1[1].toInt(0, 10);
    if(temp[1].contains("3d")){
        this->dispatcher->doImageProcessingByMethodType(id, 3, temp2[1]);
    }
    this->setSystemStatus(this->dispatcher->doImageProcessingByMethodType(id, 3, temp2[1]));*/




}
