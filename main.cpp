#include "IgssMainWindow.h"
#include "SystemDispatcher.h"
#include "SystemDataBase.h"
#include <QApplication>


int main(int argc, char *argv[]){

    QApplication analyser(argc, argv);
    //analyser.setStyle("cleanlooks");
    analyser.setOrganizationName("Chinese Acdemic of Science -- SIAT");
    analyser.setApplicationName("InterventionalTherapyAnalyser");
    analyser.setWindowIcon(QIcon(":/images/icon.png"));

    SystemDataBase*   database       = new SystemDataBase();
    SystemDispatcher* dispatcher     = new SystemDispatcher();
    IgssMainWindow*   igssMainWindow = new IgssMainWindow(dispatcher);
    ImageProcessingFactory *imageProcessingFactory = new ImageProcessingFactory();

    igssMainWindow->setSystemDispatecher(dispatcher);
    dispatcher->setSystemDataBase(database);
    dispatcher->setImageProcessingFactory(imageProcessingFactory);

    igssMainWindow->findPatientExisted();
    igssMainWindow->display();

    return analyser.exec();
}
