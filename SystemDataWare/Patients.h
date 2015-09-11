#ifndef PATIENTS_H
#define PATIENTS_H

#include <DataSetOfPatient.h>
#include <QList>


class Patients
{
public:
    Patients();

private:
    QList<DataSetOfPatient*> patients;
};

#endif // PATIENTS_H
