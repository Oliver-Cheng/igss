#ifndef DATASETOFPATIENT_H
#define DATASETOFPATIENT_H

#include <QString>
#include <QList>
#include <IgssImage.h>

class Patient
{
public:
    Patient(QString myPath);
    QString getBirthdayOfPatient();

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
};

#endif // DATASETOFPATIENT_H
