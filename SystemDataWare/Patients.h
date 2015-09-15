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
    void findPatientExisted();
    void setPatientsPath(QString patients_path);

private:
    QList<Patient*> patients;
    QString patients_path;
};

#endif // PATIENTS_H
