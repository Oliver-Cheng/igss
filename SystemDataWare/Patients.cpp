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
        Patient *patient = new Patient(list.at(cpt).filePath());
        patients.append(patient);
    }
}

void Patients::setPatientsPath(QString patients_path){
    this->patients_path = patients_path;
}
