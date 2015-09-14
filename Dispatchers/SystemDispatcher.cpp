#include "SystemDispatcher.h"

SystemDispatcher::SystemDispatcher(SystemDataBase* database){
    this->database = database;
}

void SystemDispatcher::findPatientExisted(){
    this->database->findPatientsExisted();

}

