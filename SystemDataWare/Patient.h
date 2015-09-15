#ifndef PATIENT_H
#define PATIENT_H

#include <QList>
#include <IgssImage.h>
#include <QFileInfo>
#include <QDir>

class Patient
{
private:

    class ThreadImageProcessing : public QThread{
        public:
            void run();

            Patient *patient;

    };

public:
    Patient(QString myPath);
    QString getBirthdayOfPatient();
    void doImageProcessing();
    QString getMRAPath();
    QString getName();

private:

    QString myPath;

    //! personnel informations
    QString name;
    QString birthday;
    QString firstName;
    QString lastName;
    QString sex;
    QString IdentityNumber;

    int age;

    //! tridimensionnel Image (MRA)
    IgssImage *originImage;
    //IgssImage *ImageTreated;

    //! bidimensionnel Image (CT) captured while operation
    QList<IgssImage *> cImageSequence;

    //! parameter of image......

public:

    ThreadImageProcessing imageProcessingThread;

};

#endif // PATIENT_H
