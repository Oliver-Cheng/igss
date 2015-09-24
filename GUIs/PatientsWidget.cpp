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

    for(int cpt = 0; cpt < numberOfPatient; cpt++){
        addPatientToListWidget(this->dispatcher->getPatientById(cpt)->getName(),
                               this->dispatcher->getPatientById(cpt)->getPhotoPath());
    }
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::constructIHM
//!
void PatientsWidget::constructIHM(){

    this->patientsIntroduction = new QWidget();
    this->somethingelse = new QWidget();

    this->waittingPatients = new QListWidget();
    this->waittingPatients->setViewMode(QListWidget::IconMode);

    //!--------------------------------------------------------------------------------------
    //!the left select button
    //!--------------------------------------------------------------------------------------
    this->leftSelectButton = new QPushButton();
    this->leftSelectButton->setFixedSize(40,100);
    this->leftSelectButton->setIcon(QIcon(":/images/splitter_left.png"));

    //!--------------------------------------------------------------------------------------
    //!current patient widget
    //!--------------------------------------------------------------------------------------
    this->currentPatient = new QWidget();
    this->currentPatient->setFixedWidth(this->appWidth*0.857*0.15);
    //this->currentPatient->setStyleSheet("background-color:red");

    //!--------------------------------------------------------------------------------------
    //!the right select button
    //!--------------------------------------------------------------------------------------
    this->rightSelectButton = new QPushButton();
    this->rightSelectButton->setFixedSize(40,100);
    this->rightSelectButton->setIcon(QIcon(":/images/splitter_right.png"));

    //!--------------------------------------------------------------------------------------
    //!patient photo widget: there are 3 photoes of waitting patients and 1 current patient
    //!--------------------------------------------------------------------------------------
    this->patientsPhotoWidget = new QWidget();
    this->patientsPhotoListWidgetLayout = new QHBoxLayout(this->patientsPhotoWidget);
    this->patientsPhotoListWidgetLayout->addWidget(waittingPatients);
    this->patientsPhotoListWidgetLayout->addWidget(leftSelectButton);
    this->patientsPhotoListWidgetLayout->addWidget(currentPatient);
    this->patientsPhotoListWidgetLayout->addWidget(rightSelectButton);
    this->patientsPhotoListWidgetLayout->setSpacing(0);
    this->patientsPhotoListWidgetLayout->setMargin(0);

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
    this->somethingelse->setFixedHeight(550);

    this->controlBar = new QWidget();
    this->controlBar->setFixedHeight(30);

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
void PatientsWidget::addPatientToListWidget(QString name, QString path){

    QListWidgetItem *patientItem = new QListWidgetItem();
    qDebug()<<path;
    patientItem->setIcon(QIcon(path));

    patientItem->setText(name);
    patientItem->setTextAlignment(Qt::AlignBottom);

    this->waittingPatients->addItem(patientItem);
}
