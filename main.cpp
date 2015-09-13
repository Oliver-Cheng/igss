#include "IgssMainWindow.h"
#include "SystemDispatcher.h"
#include "SystemDataBase.h"
#include <QApplication>
#include <QProcess>
#include <QString>
#include <QDir>
#include <QFile>


//!---------------------------------------------------------------------------------------------------------
//!
//! \brief get_username
//! \return
//!
QString get_username(){
//    QStringList environment = QProcess::systemEnvironment();
//    int index = environment.indexOf(QRegExp("USERNAME.*"));
//    if (index != -1){
//        QStringList stringList = environment.at(index).split('=');
//        if (stringList.size() == 2){
//            return stringList.at(1);
//        }
//    }
    QString name = qgetenv("USER");
        if (name.isEmpty())
            name = qgetenv("USERNAME");
    return name;
}

//!
//! \brief main
//! \param argc
//! \param argv
//! \return
//!
int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    //! -------------create a workspace folder with the default path----------------------------------------
    QString workspace_path;
    QString patients_path;
    QString metadata_path;
    QString image_center_path;

    //! ------create some folders by predefined paths as the workspaces of the application-------------------
    //under the windows os, get the username of the system



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
        return 0;
    }

    QFileInfo folder(workspace_path);
    if(!folder.isDir()){
        QDir path;
        path.mkdir(workspace_path);
        path.mkdir(patients_path);
        path.mkdir(metadata_path);
        path.mkdir(image_center_path);
    }

    SystemDataBase* database = new SystemDataBase();
    database->setPaths(workspace_path, patients_path, metadata_path, image_center_path);

    SystemDispatcher* dispatcher = new SystemDispatcher(database);


    // Interface humain machine
    IgssMainWindow* igssMainWindow =  new IgssMainWindow(dispatcher);
    igssMainWindow->show();

    return a.exec();
}
