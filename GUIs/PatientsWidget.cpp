#include "PatientsWidget.h"

PatientsWidget::PatientsWidget(SystemDispatcher* dispatcher, AlgorithmTestPlatform*algorithmTestPlatform){
    this->dispatcher = dispatcher;
    this->algorithmTestPlatform = algorithmTestPlatform;

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

    this->leftSelectButton = new QPushButton();
    this->leftSelectButton->setFixedSize(40,100);
    this->leftSelectButton->setIcon(QIcon(":/images/splitter_left.png"));

    this->currentPatient = new QWidget();
    this->currentPatient->setFixedWidth(180);
    this->currentPatient->setStyleSheet("background-color:red");

    this->rightSelectButton = new QPushButton();
    this->rightSelectButton->setFixedSize(40,100);
    this->rightSelectButton->setIcon(QIcon(":/images/splitter_right.png"));

    this->patientsPhotoWidget = new QWidget();
    this->patientsPhotoListWidgetLayout = new QHBoxLayout(this->patientsPhotoWidget);
    this->patientsPhotoListWidgetLayout->addWidget(waittingPatients);
    this->patientsPhotoListWidgetLayout->addWidget(leftSelectButton);
    this->patientsPhotoListWidgetLayout->addWidget(currentPatient);
    this->patientsPhotoListWidgetLayout->addWidget(rightSelectButton);
    this->patientsPhotoListWidgetLayout->setSpacing(0);
    this->patientsPhotoListWidgetLayout->setMargin(0);

    this->personalInformation = new QWidget();
    this->personalInformation->setFixedWidth(300);
    this->personalInformation->setStyleSheet("background-color:red");


    this->patientsIntroductionLayout = new QHBoxLayout(this->patientsIntroduction);
    this->patientsIntroductionLayout->addWidget(patientsPhotoWidget);
    this->patientsIntroductionLayout->addWidget(personalInformation);
    this->patientsIntroductionLayout->setSpacing(0);
    this->patientsIntroductionLayout->setMargin(0);


    this->somethingelse->setFixedHeight(400);

    this->controlBar = new QWidget();
    this->controlBar->setFixedWidth(35);

    this->totalInformation = new QWidget();
    this->patientsInformationLayout = new QVBoxLayout(this->totalInformation);
    this->patientsInformationLayout->addWidget(patientsIntroduction);
    this->patientsInformationLayout->addWidget(somethingelse);
    this->patientsInformationLayout->setSpacing(0);
    this->patientsInformationLayout->setMargin(0);


    this->waittingPatients->setViewMode(QListWidget::IconMode);
    this->totalInformation->setStyleSheet("QListWidget {show-decoration-selected: 2;background: transparent; border:1px solid gainsboro; color: aliceBlue}"
                                                     "QListWidget::item:alternate { background: transparent;}"
                                                     "QListWidget::item:selected {border: 0px;}"
                                                     "QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightBlue, stop: 1 skyBlue);color:aliceBlue}"
                                                     "QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightgray, stop: 1 gainsboro);color:aliceBlue}"
                                                     "QListWidget::item:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FAFBFE, stop: 1 #DCDEF1);}");

    this->patientsWidgetLayout = new QHBoxLayout(this);
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
