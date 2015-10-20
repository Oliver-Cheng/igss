#include "CurveReformationWindow.h"

CurveReformationWindow::CurveReformationWindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,600);
    this->setWindowTitle("Curved Planar Reformation");
    this->constructIHM();
    this->setConnections();

}

CurveReformationWindow::~CurveReformationWindow()
{

}

void CurveReformationWindow::constructIHM(){

    topWidget = new QWidget();
    topWidget->setFixedHeight(275);
    topLayout = new QHBoxLayout(topWidget);
    sourceImgBox = new QGroupBox();
    sourceImgBox->setFixedSize(400,240);
    sourceImgBox->setTitle("sourceImgData window");
    sourceImgBox->setAlignment(Qt::AlignCenter);
    sourceImgBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    sourceImgBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    slicerImgBox =new QGroupBox();
    slicerImgBox->setFixedSize(400,240);
    slicerImgBox->setTitle("slicerImgData window");
    slicerImgBox->setAlignment(Qt::AlignCenter);
    slicerImgBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    slicerImgBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    topLayout->addWidget(sourceImgBox);
    topLayout->addWidget(slicerImgBox);
    topLayout->setSpacing(0);
    topLayout->setMargin(1);

    //!-------------------------------------------------------------------------

    middleWidget = new QWidget();
    middleWidget->setFixedHeight(275);
    middleLayout = new QHBoxLayout(middleWidget);
    vesselBox = new QGroupBox();
    vesselBox->setFixedSize(400,240);
    vesselBox->setTitle("vesselImgData window");
    vesselBox->setAlignment(Qt::AlignCenter);
    vesselBox->setStyleSheet("color:red");
    vesselBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    vesselBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    outComingcprImgBox =new QGroupBox();
    outComingcprImgBox->setFixedSize(400,240);
    outComingcprImgBox->setTitle("outComingCprImgData window");
    outComingcprImgBox->setAlignment(Qt::AlignCenter);
    outComingcprImgBox->setStyleSheet("color:blue");
    outComingcprImgBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    outComingcprImgBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    middleLayout->addWidget(vesselBox);
    middleLayout->addWidget(outComingcprImgBox);
    middleLayout->setSpacing(0);
    middleLayout->setMargin(1);

    //!--------------------------------------------------------------------------
    controlBarWidget = new QWidget();
    controlBarLayout = new QHBoxLayout(controlBarWidget);
    OkBtn = new QPushButton("OK");
    ResetBtn = new QPushButton("EXIT");
    controlBarSpace = new QSpacerItem(1,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    controlBarLayout->addItem(controlBarSpace);
    controlBarLayout->addWidget(OkBtn);
    controlBarLayout->addWidget(ResetBtn);
    controlBarLayout->setSpacing(0);


    //!------------------------------------------------------

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(topWidget);
    mainLayout->addWidget(middleWidget);
    mainLayout->addWidget(controlBarWidget);
}


void CurveReformationWindow::setConnections(){
    this->connect(ResetBtn,SIGNAL(clicked()),this,SLOT(brea()));
    //this->connect(OkBtn,SIGNAL(clicked(),this,SLOT()));
}

//!
//! \brief CurveReformationWindow::brea
//!

void CurveReformationWindow::brea(){
    this->close();
}
