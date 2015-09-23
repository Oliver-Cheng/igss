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

    this->controlBar = new QWidget();
    this->controlBar->setFixedWidth(35);
    this->patientListWidget = new QListWidget();
    this->patientListWidget->setStyleSheet("QListWidget {show-decoration-selected: 2;background: transparent; border:1px solid gainsboro; color: aliceBlue}"
                                                     "QListWidget::item:alternate { background: transparent;}"
                                                     "QListWidget::item:selected {border: 0px;}"
                                                     "QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightBlue, stop: 1 skyBlue);color:aliceBlue}"
                                                     "QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightgray, stop: 1 gainsboro);color:aliceBlue}"
                                                     "QListWidget::item:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FAFBFE, stop: 1 #DCDEF1);}");

    this->patientsWidgetLayout = new QHBoxLayout(this);
    this->patientsWidgetLayout->addWidget(this->controlBar);
    this->patientsWidgetLayout->addWidget(this->patientListWidget);
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

    this->patientListWidget->addItem(patientItem);



}
