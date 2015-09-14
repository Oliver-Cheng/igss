#include "DataSetOfPatient.h"

DataSetOfPatient::DataSetOfPatient(QString name,QString birthday){
    this->name = name;
    this->birthday = birthday;
}

QString DataSetOfPatient::getBirthdayOfPatient(){
    return this->birthday;
}
