#ifndef SYSTEMDISPATCHER_H
#define SYSTEMDISPATCHER_H

#include <SystemDataBase.h>
#include <QProcess>
#include <QString>
#include <QDir>
#include <QFile>

class SystemDispatcher
{
public:
    SystemDispatcher();
    QString get_username();
    void initializeSystemPaths();
    void findPatientExisted();
    void setSystemDataBase(SystemDataBase* database);
    Patient* getPatientInDataBase(QString name, QString birth);

private:
    SystemDataBase* database;

    //! -------------create a workspace folder with the default path----------------------------------------
    QString workspace_path;
    QString patients_path;
    QString metadata_path;
    QString image_center_path;
};

#endif // SYSTEMDISPATCHER_H
