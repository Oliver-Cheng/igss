#include "PatientsWidget.h"

PatientsWidget::PatientsWidget(SystemDispatcher* dispatcher,
                               AlgorithmTestPlatform *algorithmTestPlatform,
                               QFont *caracterStyle,
                               int appWidth,
                               int appHeight) : QWidget(){

    this->dispatcher = dispatcher;
    this->algorithmTestPlatform = algorithmTestPlatform;
    this->caracterStyle = caracterStyle;
    this->appWidth = appWidth;
    this->appHeight = appHeight;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
}

void PatientsWidget::initVariable(){
    this->dicomCDRomReader = new DicomCDRomReader();
    this->surgeryPlanWindow = new SurgeryPlanWindow();
    this->labelStyleSheet = "border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue";
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::findPatientExisted
//!
void PatientsWidget::findPatientExisted(){
//    int numberOfPatient = this->dispatcher->findPatientExisted();
//    algorithmTestPlatform->setSystemStatus(QString::number(numberOfPatient));
//    for(int cpt = 0; cpt < numberOfPatient; cpt++){
//        addPatientToWidget(this->dispatcher->getPatientById(cpt)->getName(),
//                            skyblue   this->dispatcher->getPatientById(cpt)->getPhotoPath());
//        this->PatientPhoto[cpt]->addItem(patientItem);
//    }
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::setConnections
//!
void PatientsWidget::setConnections(){
    this->connect(this->cdRomParseButton, SIGNAL(clicked()), this, SLOT(doParseCdRom()));
    this->connect(this->surgeryLaunchButton, SIGNAL(clicked()), this, SLOT(launchSurgery()));
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::launchSurgery
//!
void PatientsWidget::launchSurgery(){
    this->surgeryPlanWindow->display();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::doParseCdRom
//!
void PatientsWidget::doParseCdRom(){
    this->algorithmTestPlatform->setSystemStatus("doParseCdRom");

    //TODO
    //dicomCDRomReader->doParseCDRom(.......);


}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::constructIHM
//!
void PatientsWidget::constructIHM(){

    this->patientsIntroduction = new QWidget();

    this->waittingPatientsAndBlackAreaWindow = new QWidget();

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
    //!the start button of surgery
    //!--------------------------------------------------------------------------------------
    this->surgeryLaunchButton = new QPushButton("Start");
    this->surgeryLaunchButton->setFixedHeight(this->appHeight*0.857*0.15*0.3);

    //!--------------------------------------------------------------------------------------
    //!current patient widget
    //!--------------------------------------------------------------------------------------

    this->pictureLeftArea = new QWidget();

    this->currentPatientPicture = new QWidget();
    this->currentPatientPicture->setFixedWidth(this->appWidth*0.857*0.15*0.6);
    this->currentPatientPicture->setStyleSheet("background-color:skyblue");

    this->pictureRightArea = new QWidget();

    this->pictureInfoArea = new QWidget();
    this->pictureInfoAreaLayout = new QHBoxLayout(pictureInfoArea);
    this->pictureInfoAreaLayout->addWidget(pictureLeftArea);
    this->pictureInfoAreaLayout->addWidget(currentPatientPicture);
    this->pictureInfoAreaLayout->addWidget(pictureRightArea);
    this->pictureInfoAreaLayout->setSpacing(0);
    this->pictureInfoAreaLayout->setMargin(0);

    this->currentPatient = new QWidget();
    this->currentPatient->setFixedWidth(this->appWidth*0.857*0.15);
    //this->currentPatient->setStyleSheet("background-color:blue");
    this->currentPatientLayout = new QVBoxLayout(currentPatient);
    this->currentPatientLayout->addWidget(pictureInfoArea);
    this->currentPatientLayout->addWidget(surgeryLaunchButton);
    this->currentPatientLayout->setSpacing(0);
    this->currentPatientLayout->setMargin(0);

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


    this->nameLabel = new QLabel("Name:");
    this->nameLabel->setFont(*this->caracterStyle);
    this->nameLabel->setStyleSheet(this->labelStyleSheet);

    this->birthdayLabel = new QLabel("Birth:");
    this->birthdayLabel->setFont(*this->caracterStyle);
    this->birthdayLabel->setStyleSheet(this->labelStyleSheet);

    this->sexualLabel = new QLabel("Sex:");
    this->sexualLabel->setFont(*this->caracterStyle);
    this->sexualLabel->setStyleSheet(this->labelStyleSheet);

    this->idNumberLabel = new QLabel("ID:");
    this->idNumberLabel->setFont(*this->caracterStyle);
    this->idNumberLabel->setStyleSheet(this->labelStyleSheet);

    this->nameLineEdit = new QLineEdit();
    this->nameLineEdit->setFont(*this->caracterStyle);
    this->nameLineEdit->setStyleSheet(this->labelStyleSheet);

    this->birthdayLineEdit = new QLineEdit();
    this->birthdayLineEdit->setFont(*this->caracterStyle);
    this->birthdayLineEdit->setStyleSheet(this->labelStyleSheet);

    this->sexualLineEdit = new QLineEdit();
    this->sexualLineEdit->setFont(*this->caracterStyle);
    this->sexualLineEdit->setStyleSheet(this->labelStyleSheet);

    this->idNumberEdit = new QLineEdit();
    this->idNumberEdit->setFont(*this->caracterStyle);
    this->idNumberEdit->setStyleSheet(this->labelStyleSheet);

    patientInfoContainerSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->patientInfoContainer = new QWidget();
    this->patientInfoContainerLayout = new QGridLayout(patientInfoContainer);
    this->patientInfoContainerLayout->addWidget(nameLabel, 0, 0);
    this->patientInfoContainerLayout->addWidget(birthdayLabel, 1, 0);
    this->patientInfoContainerLayout->addWidget(sexualLabel, 2, 0);
    this->patientInfoContainerLayout->addWidget(idNumberLabel, 3, 0);
    this->patientInfoContainerLayout->addWidget(nameLineEdit, 0, 1);
    this->patientInfoContainerLayout->addWidget(birthdayLineEdit, 1, 1);
    this->patientInfoContainerLayout->addWidget(sexualLineEdit, 2, 1);
    this->patientInfoContainerLayout->addWidget(idNumberEdit, 3, 1);
    this->patientInfoContainerLayout->addItem(patientInfoContainerSpacer, 4, 0);

    this->patientInfoContainerLayout->setSpacing(2);
    this->patientInfoContainerLayout->setMargin(0);

    this->leadDoctorLabel = new QLabel("Doctor:");
    this->leadDoctorLabel->setFont(*this->caracterStyle);
    this->leadDoctorLabel->setStyleSheet(this->labelStyleSheet);

    this->therapyTimeLabel = new QLabel("Time:");
    this->therapyTimeLabel->setFont(*this->caracterStyle);
    this->therapyTimeLabel->setStyleSheet(this->labelStyleSheet);

    this->leadDoctorEdit = new QLineEdit();
    this->leadDoctorEdit->setFont(*this->caracterStyle);
    this->leadDoctorEdit->setStyleSheet(this->labelStyleSheet);

    this->therapyTimeEdit = new QLineEdit();
    this->therapyTimeEdit->setFont(*this->caracterStyle);
    this->therapyTimeEdit->setStyleSheet(this->labelStyleSheet);

    this->doctorInfoContainer = new QWidget();
    this->doctorInfoContainerLayout = new QGridLayout(doctorInfoContainer);
    this->doctorInfoContainerLayout->addWidget(leadDoctorLabel, 0, 0);
    this->doctorInfoContainerLayout->addWidget(therapyTimeLabel, 1, 0);
    this->doctorInfoContainerLayout->addWidget(leadDoctorEdit, 0, 1);
    this->doctorInfoContainerLayout->addWidget(therapyTimeEdit, 1, 1);
    this->doctorInfoContainerLayout->setSpacing(2);
    this->doctorInfoContainerLayout->setMargin(0);

    this->commentTextEdit = new QTextEdit();
    this->commentTextEdit->setFont(*this->caracterStyle);
    this->commentTextEdit->setStyleSheet(this->labelStyleSheet);

    this->doctorComment = new QWidget();
    this->doctorCommentLayout = new QVBoxLayout(doctorComment);
    this->doctorCommentLayout->addWidget(doctorInfoContainer);
    this->doctorCommentLayout->addWidget(commentTextEdit);
    this->doctorCommentLayout->setSpacing(2);
    this->doctorCommentLayout->setMargin(0);

    this->personalInformation = new QWidget();
    this->personalInformation->setFixedWidth(this->appWidth*0.857*0.4);

    this->personalInformationLayout = new QHBoxLayout(personalInformation);
    this->personalInformationLayout->addWidget(patientInfoContainer);
    this->personalInformationLayout->addWidget(doctorComment);
    this->personalInformationLayout->setSpacing(2);
    this->personalInformationLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the interface of the introduction about patients
    //!--------------------------------------------------------------------------------------
    this->patientsIntroductionLayout = new QHBoxLayout(this->patientsIntroduction);
    this->patientsIntroductionLayout->addWidget(patientsPhotoWidget);
    this->patientsIntroductionLayout->addWidget(personalInformation);
    this->patientsIntroductionLayout->setSpacing(2);
    this->patientsIntroductionLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!this area will put something else
    //!--------------------------------------------------------------------------------------
    this->somethingelse = new QWidget();
    this->somethingelse->setFixedHeight(this->appHeight*0.509);

    this->controlBar = new QWidget();
    this->controlBar->setFixedHeight(this->appHeight*0.030);

    this->controlBarLayout = new QHBoxLayout(this->controlBar);

    this->cdRomParseButton =  new QPushButton();
    this->cdRomParseButton->setIcon(QIcon(":/images/Disk.png"));
    this->cdRomParseButton->setIconSize(QSize(this->appWidth*0.015,this->appWidth*0.015));
    this->cdRomParseButton->setStyleSheet("background-color:transparent");
    this->cdRomParseButton->setFixedSize(this->appWidth*0.020, this->appWidth*0.020);

    controlBarSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->controlBarLayout->addWidget(this->cdRomParseButton);
    this->controlBarLayout->addSpacerItem(controlBarSpacer);

    this->controlBarLayout->setSpacing(0);
    this->controlBarLayout->setMargin(0);


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
