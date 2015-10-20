#include "GuidewareTrackingWindow.h"

GuidewareTrackingWindow::GuidewareTrackingWindow(int x,
                                                 int y,
                                                 int width,
                                                 int height,
                                                 QFont *caracterStyle,
                                                 SystemDispatcher* systemDispatcher) : QWidget(){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->caracterStyle = caracterStyle;
    this->systemDispatcher = systemDispatcher;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);// | Qt::WindowStaysOnTopHint);
    this->setWindowOpacity(1);
    this->setMouseTracking(true);
    this->setAutoFillBackground(true);
    this->constructionIHM();

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::~GuidewareTrackingWindow
//!
GuidewareTrackingWindow::~GuidewareTrackingWindow(){

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::displayWindow
//!
void GuidewareTrackingWindow::displayWindow(){
    this->resize(this->width, this->height);
    this->move(this->x, this->y);
    this->show();
}

//!
//! \brief GuidewareTrackingWindow::initVariable
//!
void GuidewareTrackingWindow::initVariable(){
    this->labelStyleSheet = "border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue";
}

//!
//! \brief GuidewareTrackingWindow::constructionIHM
//!
void GuidewareTrackingWindow::constructionIHM(){
    //!----------------------------------------------------------------------------------------------------
    //! name bar:display name of this window
    //!----------------------------------------------------------------------------------------------------
    this->nameBar = new QWidget();
    this->nameBar->setStyleSheet("background-color:red");
    this->nameBar->setFixedSize(width*0.20,height*0.04);

    //!----------------------------------------------------------------------------------------------------
    //! vtk display bar:display name of VTKImage
    //!----------------------------------------------------------------------------------------------------
    this->vtkDisplayBar = new QWidget();
    this->vtkDisplayBar->setStyleSheet("background-color:green");

    //!----------------------------------------------------------------------------------------------------
    //! surgery information:including surgerID,patientName,surgeryDate
    //!----------------------------------------------------------------------------------------------------
    this->surgeryID = new QLabel();
    this->surgeryID = new QLabel("surgeryID:");
    this->surgeryID->setFont(*this->caracterStyle);
    this->surgeryID->setStyleSheet(this->labelStyleSheet);

    this->patientName = new QLabel();
    this->surgeryDate = new QLabel();

    this->surgeryInformation = new QWidget();
    this->surgeryInformationLayout = new QVBoxLayout(this->surgeryInformation);
    this->surgeryInformationLayout->addWidget(surgeryID);
    this->surgeryInformationLayout->addWidget(patientName);
    this->surgeryInformationLayout->addWidget(surgeryDate);

    //!----------------------------------------------------------------------------------------------------
    //! control button area
    //!----------------------------------------------------------------------------------------------------
    this->controlButtonArea = new QWidget();

    //!----------------------------------------------------------------------------------------------------
    //! unknown area
    //!----------------------------------------------------------------------------------------------------
    this->unknownArea = new QWidget();


    //!----------------------------------------------------------------------------------------------------
    //!guideControlBoard:including guideControlBoard,controlButtonArea,unknownArea
    //!----------------------------------------------------------------------------------------------------
    this->guideControlBoard = new QWidget();
    this->guideControlBoard->setStyleSheet("background-color:blue");
    this->guideControlBoardLayout = new QVBoxLayout(this->guideControlBoard);
    this->guideControlBoardLayout->addWidget(this->surgeryInformation);
    this->guideControlBoardLayout->addWidget(this->controlButtonArea);
    this->guideControlBoardLayout->addWidget(this->unknownArea);


    //!----------------------------------------------------------------------------------------------------
    //!primary display
    //!----------------------------------------------------------------------------------------------------
    this->primaryDisplay = new QWidget();

    //!----------------------------------------------------------------------------------------------------
    //!guideware tracking display
    //!----------------------------------------------------------------------------------------------------
    this->guidewareTrackingDisplay = new QWidget();

    //!----------------------------------------------------------------------------------------------------
    //!vtkDisplayBoard:including primaryDisplay,guidewareTrackingDisplay
    //!----------------------------------------------------------------------------------------------------
    this->vtkDisplayBoard = new QWidget();
    this->vtkDisplayBoardLayout = new QHBoxLayout(this->vtkDisplayBoard);
    this->vtkDisplayBoardLayout->addWidget(primaryDisplay);
    this->vtkDisplayBoardLayout->addWidget(guidewareTrackingDisplay);

    //!----------------------------------------------------------------------------------------------------
    //!main window
    //!----------------------------------------------------------------------------------------------------
    this->guidewareTrackingLayout = new QGridLayout(this);
    this->guidewareTrackingLayout->addWidget(this->nameBar, 0, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBar, 0, 1);
    this->guidewareTrackingLayout->addWidget(this->guideControlBoard, 1, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBoard, 1, 1);



}
