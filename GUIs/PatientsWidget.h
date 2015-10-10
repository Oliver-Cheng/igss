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

class PatientsWidget : public QWidget
{
    Q_OBJECT
public:
    PatientsWidget(SystemDispatcher* dispatcher,
                            AlgorithmTestPlatform *algorithmTestPlatform,
                            int appWidth,
                            int appHeight);
    void constructIHM();
    void findPatientExisted();
    void setConnections();
    void addPatientToWidget(QString name, QString path);

private:
    SystemDispatcher* dispatcher;

    QVBoxLayout* patientsWidgetLayout;
    QVBoxLayout* totalInformationLayout;
    QHBoxLayout* patientsIntroductionLayout;
    QHBoxLayout* patientsPhotoWidgetLayout;
    QVBoxLayout* waittingPatientsAndBlackAreaWindowLayout;
    QHBoxLayout* waittingPatientPhotoesLayout;
    QHBoxLayout* controlBarLayout;
    QHBoxLayout* personalInformationLayout;
    QGridLayout* patientInfoContainerLayout;
    QVBoxLayout* doctorCommentLayout;
    QGridLayout* doctorInfoContainerLayout;

    QWidget* controlBar;
    QWidget* patientsIntroduction;
    QWidget* personalInformation;
    QWidget* patientsPhotoWidget;
    QWidget* somethingelse;
    QWidget* totalInformation;
    QWidget* currentPatient;
    QWidget* upBlackArea;
    QWidget* waittingPatientPhotoes;
    QWidget* downBlackArea;
    QWidget* leftBlackArea;
    QWidget* rightBlackArea;
    QWidget* firstPatientPhoto;
    QWidget* secondPatientPhoto;
    QWidget* thirdPatientPhoto;
    QWidget* fourthPatientPhoto;
    QWidget* fifthPatientPhoto;
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

    QWidget* waittingPatientsAndBlackAreaWindow;

    QPushButton* leftSelectButton;
    QPushButton* rightSelectButton;
    QPushButton* cdRomParseButton;

    AlgorithmTestPlatform *algorithmTestPlatform;

    QSpacerItem* controlBarSpacer;

    DicomCDRomReader *dicomCDRomReader;

    int appWidth;
    int appHeight;

signals:

public slots:
    void doParseCdRom();

};

#endif // PATIENTSWIDGET_H
