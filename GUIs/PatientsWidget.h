#ifndef PATIENTSWIDGET_H
#define PATIENTSWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <SystemDispatcher.h>
#include <Patients.h>
#include <QDebug>
#include <QTextEdit>
#include <AlgorithmTestPlatform.h>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "DicomCDRomReader.h"
#include "SurgeryPlanWindow.h"

class PatientsWidget : public QWidget
{
    Q_OBJECT
public:
    PatientsWidget(SystemDispatcher* dispatcher,
                   AlgorithmTestPlatform *algorithmTestPlatform,
                   QFont *caracterStyle,
                   int appWidth,
                   int appHeight);

    void initVariable();
    void constructIHM();
    void findPatientExisted();
    void setConnections();
    void addPatientToWidget(QString path);

private:
    SystemDispatcher* dispatcher;

    QVBoxLayout* patientsWidgetLayout;
    QVBoxLayout* totalInformationLayout;
    QHBoxLayout* patientsIntroductionLayout;
    QHBoxLayout* patientsPhotoWidgetLayout;
    QVBoxLayout* waittingPatientsAndBlackAreaWindowLayout;
    QHBoxLayout* waittingPatientPhotoesLayout;
    QVBoxLayout* currentPatientLayout;
    QHBoxLayout* pictureInfoAreaLayout;
    QHBoxLayout* controlBarLayout;
    QHBoxLayout* personalInformationLayout;
    QGridLayout* patientInfoContainerLayout;  
    QGridLayout* doctorInfoContainerLayout;
    QVBoxLayout* doctorCommentLayout;

    QWidget* controlBar;
    QWidget* patientsIntroduction;
    QWidget* personalInformation;
    QWidget* patientsPhotoWidget;
    QWidget* somethingelse;
    QWidget* totalInformation;
    QWidget* currentPatient;
    QWidget* pictureInfoArea;
    QWidget* currentPatientPicture;
    QWidget* pictureLeftArea;
    QWidget* pictureRightArea;
    QWidget* upBlackArea;
    QWidget* waittingPatientPhotoes;
    QWidget* downBlackArea;
    QWidget* leftBlackArea;
    QWidget* rightBlackArea;
    QLabel* firstPatientPhoto;
    QLabel* secondPatientPhoto;
    QLabel* thirdPatientPhoto;
    QLabel* fourthPatientPhoto;
    QLabel* fifthPatientPhoto;
    QWidget* patientInfoContainer;
    QWidget* doctorComment;
    QWidget* doctorInfoContainer;

    QTextEdit* commentTextEdit;

    QLabel* nameLabel;
    QLabel* birthdayLabel;
    QLabel* sexualLabel;
    QLabel* idNumberLabel;
    QLabel* leadDoctorLabel;
    QLabel* therapyTimeLabel;

    QLineEdit* nameLineEdit;
    QLineEdit* birthdayLineEdit;
    QLineEdit* sexualLineEdit;
    QLineEdit* idNumberEdit;
    QLineEdit* leadDoctorEdit;
    QLineEdit* therapyTimeEdit;

    QFont *caracterStyle;

    QWidget* waittingPatientsAndBlackAreaWindow;

    QPushButton* leftSelectButton;
    QPushButton* rightSelectButton;
    QPushButton* cdRomParseButton;
    QPushButton* surgeryLaunchButton;

    AlgorithmTestPlatform *algorithmTestPlatform;

    SurgeryPlanWindow* surgeryPlanWindow;

    QSpacerItem* controlBarSpacer;
    QSpacerItem* patientInfoContainerSpacer;

    DicomCDRomReader *dicomCDRomReader;

    int appWidth;
    int appHeight;

    QString labelStyleSheet;

signals:

public slots:
    void doParseCdRom();
    void launchSurgery();

};

#endif // PATIENTSWIDGET_H
