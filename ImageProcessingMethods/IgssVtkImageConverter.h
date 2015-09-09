#ifndef IGSSVTKIMAGECONVERTER_H
#define IGSSVTKIMAGECONVERTER_H

#include <vtkImageData.h>
#include <IgssImage.h>

class IgssVtkImageConverter{

public:
    IgssVtkImageConverter();

    void IgssToVtk(IgssImage* input, vtkImageData *output);
    void VtkToIgss(vtkImageData* input, IgssImage *output);
};

#endif // IGSSVTKIMAGECONVERTER_H
