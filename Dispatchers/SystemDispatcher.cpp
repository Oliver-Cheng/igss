#include "SystemDispatcher.h"

SystemDispatcher::SystemDispatcher(){
    this->initializeSystemPaths();
}

//!---------------------------------------------------------------------------------------------------------
//!
//! \brief get_username
//! \return
//!
QString SystemDispatcher::get_username(){
    QString name = qgetenv("USER");
        if (name.isEmpty())
            name = qgetenv("USERNAME");
    return name;
}

//!---------------------------------------------------------------------------------------------------------
//!
//! \brief SystemDispatcher::initializeSystemPaths
//!
void SystemDispatcher::initializeSystemPaths(){

    //! ------create some folders by predefined paths as the workspaces of the application-------------------
    QString username = get_username();

    if(username != "unknown") {
        //! define the software's deault path according to the os type
        #ifdef linux
        workspace_path = "/home/" + username + "/Documents/CanalyserWorkspace/";
        patients_path = workspace_path + "PatientsDataware/";
        metadata_path = workspace_path + "CanalyserMetadata/";
        image_center_path = workspace_path + "CanalyserImageCenter/";
        #elif _WIN64
        workspace_path = "C:\\Users\\" + username + "\\Documents\\CanalyserWorkspace\\";
        patients_path = workspace_path + "PatientsDataware\\";
        metadata_path = workspace_path + "CanalyserMetadata\\";
        image_center_path = workspace_path + "CanalyserImageCenter\\";
        #endif
    }
    else{
        qDebug()<<"exception";
        return;
    }

    QFileInfo folder(workspace_path);
    if(!folder.isDir()){
        QDir path;
        path.mkdir(workspace_path);
        path.mkdir(patients_path);
        path.mkdir(metadata_path);
        path.mkdir(image_center_path);
    }
}

//!---------------------------------------------------------------------------------------------------------
//!
//! \brief SystemDispatcher::setSystemDataBase
//! \param database
//!
void SystemDispatcher::setSystemDataBase(SystemDataBase* database){
    this->database = database;
    this->database->setPaths(this->workspace_path,
                             this->patients_path,
                             this->metadata_path,
                             this->image_center_path);
}

//!---------------------------------------------------------------------------------------------------------
//!
//! \brief SystemDispatcher::findPatientExisted
//!
void SystemDispatcher::findPatientExisted(){
    this->database->findPatientsExisted();
}
