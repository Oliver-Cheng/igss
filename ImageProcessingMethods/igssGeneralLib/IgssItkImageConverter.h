#ifndef IGSSITKIMAGECONVERTER_H
#define IGSSITKIMAGECONVERTER_H

#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkImageBase.h>
#include <IgssImage.h>

class IgssItkImageConverter
{
public:
    IgssItkImageConverter();

    void IgssToItk(IgssImage* input, itk::Image< unsigned short, 3 >::Pointer output);
    void ItkToIgss( itk::Image< unsigned short, 3 >::Pointer input, IgssImage *output);
};

#endif // IGSSITKIMAGECONVERTER_H
