#include "SystemDataBase.h"


SystemDataBase::SystemDataBase(){
    this->patients = new Patients();
    this->metaData = new SystemMetaData();
}
//!--------------------------------------------------------------------------------------------
//!
//! \brief SystemDataBase::setPaths
//! \param workspace_path
//! \param patients_path
//! \param metadata_path
//! \param image_center_path
//!
void SystemDataBase::setPaths(QString workspace_path,  QString patients_path, QString metadata_path, QString image_center_path){
    this->metaData->setSystemPaths(workspace_path,  patients_path,  metadata_path, image_center_path);
    this->patients->setPatientsPath(patients_path);
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief SystemDataBase::getSystemWorkSpace
//! \return
//!
QString SystemDataBase::getSystemWorkSpace(){
    return this->metaData->getSystemWorkSpace();
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief SystemDataBase::getPatientsPath
//! \return
//!
QString SystemDataBase::getPatientsPath(){
    return this->metaData->getPatientsPath();
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief SystemDataBase::getMetaData
//! \return
//!
QString SystemDataBase::getMetaData(){
    return this->metaData->getMetaData();
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief SystemDataBase::getImageCenterPath
//! \return
//!
QString SystemDataBase::getImageCenterPath(){
    return this->metaData->getImageCenterPath();
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief SystemDataBase::findPatientsExisted
//!
void SystemDataBase::findPatientsExisted(){
    this->patients->findPatientExisted();
}
