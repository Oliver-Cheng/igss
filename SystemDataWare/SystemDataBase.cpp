#include "SystemDataBase.h"


SystemDataBase::SystemDataBase(){
    this->patients = new Patients();
    this->metaData = new SystemMetaData();
}

void SystemDataBase::setPaths(QString workspace_path,  QString patients_path, QString metadata_path, QString image_center_path){
    this->metaData->setSystemPaths(workspace_path,  patients_path,  metadata_path, image_center_path);
}

QString SystemDataBase::getSystemWorkSpace(){
    return this->metaData->getSystemWorkSpace();
}

QString SystemDataBase::getPatientsPath(){
    return this->metaData->getPatientsPath();
}

QString SystemDataBase::getMetaData(){
    return this->metaData->getMetaData();
}

QString SystemDataBase::getImageCenterPath(){
    return this->metaData->getImageCenterPath();
}
