#ifndef PATIENTS_H
#define PATIENTS_H

#include <Patient.h>
#include <QList>
#include <QDir>
#include <QDebug>


class Patients
{
public:
    Patients();
    int findPatientExisted();
    void setPatientsPath(QString patients_path);
    Patient* getPatientById(int id);
    QStringList getPatientsStatus();
    IgssImage* getPatientMRAImageById(int id);
    QList<Patient*> getPatientsList();

private:
    QList<Patient*> patients;
    QString patients_path;
    int id;
};

#endif // PATIENTS_H
