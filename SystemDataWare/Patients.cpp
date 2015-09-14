#include "Patients.h"

Patients::Patients(){

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief Patients::findPatientExisted
//!
void Patients::findPatientExisted(){
    QDir patientsPath(this->patients_path);

    patientsPath.setFilter(QDir::Dirs);

    QFileInfoList list = patientsPath.entryInfoList();

    for(unsigned char cpt = 0; cpt < list.size(); cpt++){
        if(list.at(cpt).filePath().contains(".") || list.at(cpt).filePath().contains("..")){
            continue;
        }
        QString currentPath = list.at(cpt).filePath();
        QStringList temp = currentPath.split(this->patients_path);
        QStringList patientInfo = temp[1].split("__");
        DataSetOfPatient *datasetOfPatient = new DataSetOfPatient(patientInfo[0],patientInfo[1]);
        patients.append(datasetOfPatient);
    }
}

void Patients::setPatientsPath(QString patients_path){
    this->patients_path = patients_path;
}
