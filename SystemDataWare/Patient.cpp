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

void Patient::doImageProcessing(){
    imageProcessingThread.patient = this;
    imageProcessingThread.start();
}

QString Patient::getMRAPath(){
    return this->myPath;
}

QString Patient::getName(){
    return this->name;
}

void Patient::ThreadImageProcessing::run(){
    //! check if patient's mra image exist in the personnel mra path....
    QFileInfo checkMHDFile(patient->myPath + patient->name + ".mhd");
    QString mraImageFilePath;

    //! check if file exists and if yes: Is it really a file and no directory?
    //if()

}
