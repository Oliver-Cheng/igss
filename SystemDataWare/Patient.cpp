#include "Patient.h"

Patient::Patient(QString myPath){
    this->myPath = myPath;

    //! fetch name and birth of the patient
    QStringList temp = myPath.split("/");
    QStringList patientInfo = temp[temp.size()-1].split("__");
    name = patientInfo[0];
    birthday = patientInfo[1];
}

QString Patient::getBirthdayOfPatient(){
    return this->birthday;
}
