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
    Patient* getPatientByPesonnelInfo(QString name, QString birth);
    QStringList getPatientsStatus();
    IgssImage* getPatientMRAImageById(int id);

private:
    QList<Patient*> patients;
    QString patients_path;
};

#endif // PATIENTS_H
