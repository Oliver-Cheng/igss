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
    void addPatientToListWidget(QString name, QString path);

private:
    SystemDispatcher* dispatcher;

    QVBoxLayout* patientsWidgetLayout;
    QVBoxLayout* totalInformationLayout;
    QHBoxLayout* patientsIntroductionLayout;
    QHBoxLayout* patientsPhotoListWidgetLayout;

    QWidget* controlBar;
    QWidget* patientsIntroduction;
    QWidget* personalInformation;
    QWidget* patientsPhotoWidget;
    QWidget* somethingelse;
    QWidget* totalInformation;
    QWidget* currentPatient;

    QListWidget* waittingPatients;

    QPushButton* leftSelectButton;
    QPushButton* rightSelectButton;

    AlgorithmTestPlatform *algorithmTestPlatform;

    int appWidth;
    int appHeight;

signals:

public slots:

};

#endif // PATIENTSWIDGET_H
