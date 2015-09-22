#ifndef PATIENTSWIDGET_H
#define PATIENTSWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <SystemDispatcher.h>
#include <Patients.h>
#include <QDebug>

class PatientsWidget : public QWidget
{
public:
    explicit PatientsWidget(SystemDispatcher* dispatcher);
    void constructIHM();
    void findPatientExisted();

    void addPatientToListWidget(QString name, QString path);

private:
    SystemDispatcher* dispatcher;
    QHBoxLayout* patientsWidgetLayout;
    QWidget* controlBar;
    QListWidget* patientListWidget;

signals:

public slots:

};

#endif // PATIENTSWIDGET_H
