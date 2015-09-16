#include "Patient.h"
#include <QDebug>
#include <QFileInfo>
#include <QDir>


//!----------------------------------------------------------------------------
//!
//! \brief Patient::ThreadImageProcessing::run
//!
void Patient::ThreadImageProcessing::run(){

    //! check if patient's mraImage exist in the personnel mra path....
    QFileInfo checkMHDFile(patient->myPath + "/mra_tridimensionel__image/" + patient->name + ".mhd");
    //! check if file exists and if yes: Is it really a file and no directory?
    if((checkMHDFile.exists() && checkMHDFile.isFile()) ){
        patient->mhdFileReader->doParseMHDFile(checkMHDFile.filePath(),patient->originImage);
    }
}

//!----------------------------------------------------------------------------
//!
//! \brief Patient::Patient
//! \param myPath
//!
Patient::Patient(QString myPath){
    this->myPath = myPath;

    //! fetch name and birth of the patient
    QStringList temp = myPath.split("/");
    QStringList patientInfo = temp[temp.size()-1].split("__");
    name = patientInfo[0];
    birthday = patientInfo[1];

    originImage = new IgssImage();

    doImageProcessing();
}

//!------------------------------------------------------------------------------
//!
//! \brief Patient::getBirthdayOfPatient
//! \return
//!
QString Patient::getBirthdayOfPatient(){
    return this->birthday;
}

//!------------------------------------------------------------------------------
//!
//! \brief Patient::doImageProcessing
//!
void Patient::doImageProcessing(){
    imageProcessingThread.patient = this;
    imageProcessingThread.start();
}

//!------------------------------------------------------------------------------
//!
//! \brief Patient::getMRAPath
//! \return
//!
QString Patient::getMRAPath(){
    return this->myPath;
}

//!------------------------------------------------------------------------------
//!
//! \brief Patient::getName
//! \return
//!
QString Patient::getName(){
    return this->name;
}

