#ifndef DATASETOFPATIENT_H
#define DATASETOFPATIENT_H

#include <QString>
#include <QList>
#include <IgssImage.h>

class DataSetOfPatient
{
public:
    DataSetOfPatient();

private:
    //! personnel informations
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
