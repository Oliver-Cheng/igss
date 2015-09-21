#include "IgssMainWindow.h"
#include "SystemDispatcher.h"
#include "SystemDataBase.h"
#include <QApplication>


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    SystemDataBase*   database       = new SystemDataBase();
    SystemDispatcher* dispatcher     = new SystemDispatcher();
    IgssMainWindow*   igssMainWindow = new IgssMainWindow();
    ImageProcessingFactory *imageProcessingFactory = new ImageProcessingFactory();

    igssMainWindow->setSystemDispatecher(dispatcher);
    dispatcher->setSystemDataBase(database);
    dispatcher->setImageProcessingFactory(imageProcessingFactory);

    dispatcher->findPatientExisted();
    igssMainWindow->display();

    return a.exec();
}
