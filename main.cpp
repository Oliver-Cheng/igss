#include "IgssMainWindow.h"
#include "SystemDispatcher.h"
#include "SystemDataBase.h"
#include <QApplication>


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    SystemDataBase*   database       = new SystemDataBase();
    SystemDispatcher* dispatcher     = new SystemDispatcher();
    IgssMainWindow*   igssMainWindow = new IgssMainWindow();

    igssMainWindow->setSystemDispatecher(dispatcher);
    dispatcher->setSystemDataBase(database);

    dispatcher->findPatientExisted();
    igssMainWindow->show();

    return a.exec();
}
