#include "GuidewareTrackingWindow.h"

GuidewareTrackingWindow::GuidewareTrackingWindow(int x,
                                                 int y,
                                                 int width,
                                                 int height,
                                                 SystemDispatcher* systemDispatcher) : QWidget(){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
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
void GuidewareTrackingWindow::constructionIHM(){
    this->nameBar = new QWidget();
    this->nameBar->setStyleSheet("background-color:red");

    this->vtkDisplayBar = new QWidget();
    this->vtkDisplayBar->setStyleSheet("background-color:green");

    this->surgeryID = new QLabel();
    this->patientName = new QLabel();
    this->surgeryDate = new QLabel();

    this->surgeryInformation = new QWidget();
    this->surgeryInformationLayout = new QVBoxLayout(this->surgeryInformation);
    this->surgeryInformationLayout->addWidget(surgeryID);
    this->surgeryInformationLayout->addWidget(patientName);
    this->surgeryInformationLayout->addWidget(surgeryDate);

    this->controlButtonArea = new QWidget();

    this->unknownArea = new QWidget();

    this->primaryDisplay = new QWidget();
    this->guidewareTrackingDisplay = new QWidget();

    this->vtkDisplayBoard = new QWidget();
    this->vtkDisplayBoardLayout = new QHBoxLayout(this->vtkDisplayBoard);
    this->vtkDisplayBoardLayout->addWidget(primaryDisplay);
    this->vtkDisplayBoardLayout->addWidget(guidewareTrackingDisplay);

    this->guideControlBoard = new QWidget();
    this->guideControlBoard->setStyleSheet("background-color:blue");
    this->guideControlBoardLayout = new QVBoxLayout(this->guideControlBoard);
    this->guideControlBoardLayout->addWidget(this->surgeryInformation);
    this->guideControlBoardLayout->addWidget(this->controlButtonArea);
    this->guideControlBoardLayout->addWidget(this->unknownArea);

    this->guidewareTrackingLayout = new QGridLayout(this);
    this->guidewareTrackingLayout->addWidget(this->nameBar, 0, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBar, 0, 1);
    this->guidewareTrackingLayout->addWidget(this->guideControlBoard, 1, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBoard, 1, 1);



}
