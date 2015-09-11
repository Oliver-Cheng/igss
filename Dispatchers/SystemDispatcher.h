#ifndef SYSTEMDISPATCHER_H
#define SYSTEMDISPATCHER_H

#include <SystemDataBase.h>

class SystemDispatcher
{
public:
    SystemDispatcher(SystemDataBase* database);
    void findPatientExisted();

private:
    SystemDataBase* database;
};

#endif // SYSTEMDISPATCHER_H
