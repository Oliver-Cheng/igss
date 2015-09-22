#ifndef PATIENT_H
#define PATIENT_H
#include <QList>
#include <IgssImage.h>
#include <QFileInfo>
#include <QDir>
#include <QThread>
#include "MRAFileReader.h"

class Patient
{
private:
    class ThreadImageProcessing : public QThread{
        public:
            void run();
            Patient *patient;
    };

public:
    Patient(QString myPath, int id);
    int getIdNumber();
    bool readFinished();
    QString getBirthdayOfPatient();
    void doImageProcessing();
    QString getMRAPath();
    QString getName();
    QString getPhotoPath();
    IgssImage *getOriginImage();

private:
    bool MraImageReadComplete;

    QString myPath;
    QString myPhotoPath;

    //! personnel informations
    QString name;
    QString birthday;
    QString firstName;
    QString lastName;
    QString sex;
    QString IdentityNumber;

    int age;
    int id;

    //! tridimensionnel Image (MRA)
    IgssImage *originImage;
    //IgssImage *ImageTreated;

    //! bidimensionnel Image (CT) captured while operation
    QList<IgssImage *> cImageSequence;

    //! parameter of image......

    //! Handle du thread
    ThreadImageProcessing imageProcessingThread;
    MRAFileReader *mhdFileReader;

};

#endif // PATIENT_H
