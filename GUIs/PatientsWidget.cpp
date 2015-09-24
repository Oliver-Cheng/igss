#include "PatientsWidget.h"

PatientsWidget::PatientsWidget(SystemDispatcher* dispatcher,
                               AlgorithmTestPlatform *algorithmTestPlatform,
                               int appWidth,
                               int appHeight){

    this->dispatcher = dispatcher;
    this->algorithmTestPlatform = algorithmTestPlatform;
    this->appWidth = appWidth;
    this->appHeight = appHeight;

    this->constructIHM();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::findPatientExisted
//!
void PatientsWidget::findPatientExisted(){
    int numberOfPatient = this->dispatcher->findPatientExisted();

//    for(int cpt = 0; cpt < numberOfPatient; cpt++){
//        addPatientToWidget(this->dispatcher->getPatientById(cpt)->getName(),
//                            skyblue   this->dispatcher->getPatientById(cpt)->getPhotoPath());
//        this->PatientPhoto[cpt]->addItem(patientItem);
//    }

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::constructIHM
//!
void PatientsWidget::constructIHM(){

    this->patientsIntroduction = new QWidget();


    this->waittingPatientsAndBlackAreaWindow = new QWidget();
    //this->waittingPatientsWindow->setViewMode(QListWidget::IconMode);

    this->upBlackArea = new QWidget();
    this->upBlackArea->setFixedHeight(this->appHeight*0.185*0.2);
    this->upBlackArea->setStyleSheet("background-color:transparent");

    this->waittingPatientPhotoes = new QWidget();
    this->downBlackArea = new QWidget();
    this->downBlackArea->setFixedHeight(this->appHeight*0.185*0.2);

    this->leftBlackArea = new QWidget();
    this->leftBlackArea->setFixedWidth(this->appHeight*0.34*0.05);
    this->leftBlackArea->setStyleSheet("background-color:transparent");

    this->firstPatientPhoto = new QWidget();
    this->firstPatientPhoto->setStyleSheet("background-color:skyblue");
    this->secondPatientPhoto = new QWidget();
    this->secondPatientPhoto->setStyleSheet("background-color:skyblue");
    this->thirdPatientPhoto = new QWidget();
    this->thirdPatientPhoto->setStyleSheet("background-color:skyblue");
    this->fourthPatientPhoto = new QWidget();
    this->fourthPatientPhoto->setStyleSheet("background-color:skyblue");
    this->fifthPatientPhoto = new QWidget();
    this->fifthPatientPhoto->setStyleSheet("background-color:skyblue");

    this->rightBlackArea = new QWidget();
    this->rightBlackArea->setFixedWidth(this->appHeight*0.34*0.01);
    this->rightBlackArea->setStyleSheet("background-color:transparent");

    this->waittingPatientPhotoesLayout = new QHBoxLayout(waittingPatientPhotoes);
    this->waittingPatientPhotoesLayout->addWidget(leftBlackArea);
    this->waittingPatientPhotoesLayout->addWidget(firstPatientPhoto);
    this->waittingPatientPhotoesLayout->addWidget(secondPatientPhoto);
    this->waittingPatientPhotoesLayout->addWidget(thirdPatientPhoto);
    this->waittingPatientPhotoesLayout->addWidget(fourthPatientPhoto);
    this->waittingPatientPhotoesLayout->addWidget(fifthPatientPhoto);
    this->waittingPatientPhotoesLayout->addWidget(rightBlackArea);
    this->waittingPatientPhotoesLayout->setSpacing(2);
    this->waittingPatientPhotoesLayout->setMargin(0);

    this->waittingPatientsAndBlackAreaWindowLayout = new QVBoxLayout(waittingPatientsAndBlackAreaWindow);
    this->waittingPatientsAndBlackAreaWindowLayout->addWidget(upBlackArea);
    this->waittingPatientsAndBlackAreaWindowLayout->addWidget(waittingPatientPhotoes);
    this->waittingPatientsAndBlackAreaWindowLayout->addWidget(downBlackArea);
    this->waittingPatientsAndBlackAreaWindowLayout->setSpacing(0);
    this->waittingPatientsAndBlackAreaWindowLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the left select button
    //!--------------------------------------------------------------------------------------
    this->leftSelectButton = new QPushButton();
    this->leftSelectButton->setFixedSize(this->appWidth*0.021,this->appHeight*0.093);
    this->leftSelectButton->setIcon(QIcon(":/images/splitter_left.png"));
    this->leftSelectButton->setStyleSheet("background-color:transparent");
    //!--------------------------------------------------------------------------------------
    //!current patient widget
    //!--------------------------------------------------------------------------------------
    this->currentPatient = new QWidget();
    this->currentPatient->setFixedWidth(this->appWidth*0.857*0.15);
    this->currentPatient->setStyleSheet("background-color:blue");

    //!--------------------------------------------------------------------------------------
    //!the right select button
    //!--------------------------------------------------------------------------------------
    this->rightSelectButton = new QPushButton();
    this->rightSelectButton->setFixedSize(this->appWidth*0.021,this->appHeight*0.093);
    this->rightSelectButton->setIcon(QIcon(":/images/splitter_right.png"));
    this->rightSelectButton->setStyleSheet("background-color:transparent");

    //!--------------------------------------------------------------------------------------
    //!patient photo widget: there are 3 photoes of waitting patients and 1 current patient
    //!--------------------------------------------------------------------------------------
    this->patientsPhotoWidget = new QWidget();
    this->patientsPhotoWidgetLayout = new QHBoxLayout(this->patientsPhotoWidget);
    this->patientsPhotoWidgetLayout->addWidget(waittingPatientsAndBlackAreaWindow);
    this->patientsPhotoWidgetLayout->addWidget(leftSelectButton);
    this->patientsPhotoWidgetLayout->addWidget(currentPatient);
    this->patientsPhotoWidgetLayout->addWidget(rightSelectButton);
    this->patientsPhotoWidgetLayout->setSpacing(0);
    this->patientsPhotoWidgetLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the information of the current patient
    //!--------------------------------------------------------------------------------------
    this->personalInformation = new QWidget();
    this->personalInformation->setFixedWidth(this->appWidth*0.857*0.4);
    this->personalInformation->setStyleSheet("background-color:red");

    //!--------------------------------------------------------------------------------------
    //!the interface of the introduction about patients
    //!--------------------------------------------------------------------------------------
    this->patientsIntroductionLayout = new QHBoxLayout(this->patientsIntroduction);
    this->patientsIntroductionLayout->addWidget(patientsPhotoWidget);
    this->patientsIntroductionLayout->addWidget(personalInformation);
    this->patientsIntroductionLayout->setSpacing(0);
    this->patientsIntroductionLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!this area will put something else
    //!--------------------------------------------------------------------------------------
    this->somethingelse = new QWidget();
    this->somethingelse->setFixedHeight(this->appHeight*0.509);
    this->somethingelse->setStyleSheet("background-color:yellow");

    this->controlBar = new QWidget();
    this->controlBar->setFixedHeight(this->appHeight*0.025);
    this->controlBar->setStyleSheet("background-color:green");

    //!--------------------------------------------------------------------------------------
    //!the total information of patient and doctors
    //!--------------------------------------------------------------------------------------
    this->totalInformation = new QWidget();
    this->totalInformationLayout = new QVBoxLayout(this->totalInformation);
    this->totalInformationLayout->addWidget(this->patientsIntroduction);
    this->totalInformationLayout->addWidget(this->somethingelse);
    this->totalInformationLayout->setSpacing(0);
    this->totalInformationLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the layout of patients widget
    //!--------------------------------------------------------------------------------------

    this->totalInformation->setStyleSheet("QListWidget {show-decoration-selected: 2;background: transparent; border:1px solid gainsboro; color: aliceBlue}"
                                                     "QListWidget::item:alternate { background: transparent;}"
                                                     "QListWidget::item:selected {border: 0px;}"
                                                     "QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightBlue, stop: 1 skyBlue);color:aliceBlue}"
                                                     "QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightgray, stop: 1 gainsboro);color:aliceBlue}"
                                                     "QListWidget::item:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FAFBFE, stop: 1 #DCDEF1);}");


    this->patientsWidgetLayout = new QVBoxLayout(this);
    this->patientsWidgetLayout->addWidget(this->controlBar);
    this->patientsWidgetLayout->addWidget(this->totalInformation);
    this->patientsWidgetLayout->setSpacing(0);
    this->patientsWidgetLayout->setMargin(0);
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::addPatientToListWidget
//! \param patients
//!
void PatientsWidget::addPatientToWidget(QString name, QString path){

    QListWidgetItem *patientItem = new QListWidgetItem();
    qDebug()<<path;
    patientItem->setIcon(QIcon(path));

    patientItem->setText(name);
    patientItem->setTextAlignment(Qt::AlignBottom);

}
