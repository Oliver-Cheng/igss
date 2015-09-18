#ifndef SYSTEMDATABASE_H
#define SYSTEMDATABASE_H

#include "Patients.h"
#include "SystemMetaData.h"


class SystemDataBase
{
public:
    SystemDataBase();

    void setPaths(QString workspace_path,  QString patients_path, QString metadata_path, QString image_center_path);

    QString getSystemWorkSpace();
    QString getPatientsPath();
    QString getMetaData();
    QString getImageCenterPath();

    void findPatientsExisted();

    Patient* getPatientByPesonnelInfo(QString name, QString birth);


private:
    Patients* patients;
    SystemMetaData* metaData;

};

#endif // SYSTEMDATABASE_H
