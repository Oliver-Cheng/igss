#include "IgssMainWindow.h"
#include "SystemDispatcher.h"
#include "SystemDataBase.h"
#include <QApplication>

//extern "C" void tesmain(void);

int main(int argc, char *argv[]){    

    QApplication analyser(argc, argv);
    analyser.setOrganizationName("CAS - SIAT");
    analyser.setApplicationName("igss");
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
