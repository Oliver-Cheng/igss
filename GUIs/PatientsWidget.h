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

class PatientsWidget : public QWidget
{
public:
    explicit PatientsWidget(SystemDispatcher* dispatcher,
                            AlgorithmTestPlatform *algorithmTestPlatform,
                            int appWidth,
                            int appHeight);
    void constructIHM();
    void findPatientExisted();
    void addPatientToWidget(QString name, QString path);

private:
    SystemDispatcher* dispatcher;

    QVBoxLayout* patientsWidgetLayout;
    QVBoxLayout* totalInformationLayout;
    QHBoxLayout* patientsIntroductionLayout;
    QHBoxLayout* patientsPhotoWidgetLayout;
    QVBoxLayout* waittingPatientsAndBlackAreaWindowLayout;
    QHBoxLayout* waittingPatientPhotoesLayout;

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

    QWidget* waittingPatientsAndBlackAreaWindow;

    QPushButton* leftSelectButton;
    QPushButton* rightSelectButton;

    AlgorithmTestPlatform *algorithmTestPlatform;

    int appWidth;
    int appHeight;

signals:

public slots:

};

#endif // PATIENTSWIDGET_H
