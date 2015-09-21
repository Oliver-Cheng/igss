#include "Patients.h"

Patients::Patients(){

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief Patients::getPatientsStatus
//! \return
//!
QStringList Patients::getPatientsStatus(){
    QStringList statusInfo;
    for(unsigned char cpt = 0; cpt < patients.size(); cpt++){
        if((patients.at(cpt)->readFinished())){
            statusInfo<<"patient "+QString::number(patients.at(cpt)->getIdNumber())+
                        " mra image lecture finished";
        }
    }
    return statusInfo;
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief Patients::getPatientByPesonnelInfo
//! \param name
//! \param birth
//! \return
//!
Patient* Patients::getPatientByPesonnelInfo(QString name, QString birth){
    for(unsigned char cpt = 0; cpt < patients.size(); cpt++){
        if((patients.at(cpt)->getName() == name)&&(patients.at(cpt)->getBirthdayOfPatient() == birth)){
            return patients.at(cpt);
        }
    }
    return NULL;
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief Patients::findPatientExisted
//!
void Patients::findPatientExisted(){

    QDir patientsPath(this->patients_path);

    patientsPath.setFilter(QDir::Dirs);

    QFileInfoList list = patientsPath.entryInfoList();
    int id;
    for(unsigned char cpt = 0; cpt < list.size(); cpt++){
        if(list.at(cpt).filePath().contains(".") || list.at(cpt).filePath().contains("..")){
            continue;
        }

        Patient *patient = new Patient(list.at(cpt).filePath(), id);
        patients.append(patient);
        id++;
    }
}

void Patients::setPatientsPath(QString patients_path){
    this->patients_path = patients_path;
}

IgssImage* Patients::getPatientMRAImageById(int id){
    return this->patients.at(id)->getOriginImage();
}
