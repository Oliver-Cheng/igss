#include "IgssVtkImageConverter.h"
#include <QDebug>
#include <vtkSmartPointer.h>

IgssVtkImageConverter::IgssVtkImageConverter(){

}

//!--------------------------------------------------------------------------------------
//!
//! \brief IgssVtkImageConverter::IgssToVtk
//! \param input
//! \param output
//! \
//!
void IgssVtkImageConverter::IgssToVtk(IgssImage* input, vtkImageData *output){

}

//!--------------------------------------------------------------------------------------
//!
//! \brief IgssVtkImageConverter::VtkToIgss
//! \param input vtkImageData
//! \param output IgssImage
//! \author lishuai \date 2015-9-11
//!
void IgssVtkImageConverter::VtkToIgss(vtkSmartPointer<vtkImageData> input, IgssImage *output){
    int nDims[3];
    double spacings[3];
    input->GetDimensions(nDims);
    input->GetSpacing(spacings);

    //!decide the dimensions
    if(nDims[2]!=0)
    {
        output->setNumOfDimensions(3);
    }
    else
    {
        output->setNumOfDimensions(2);
    }

    output->setNumOfDimensionSize(nDims[0],nDims[1],nDims[2]);
    output->setNumOfElementSpacing(spacings[0],spacings[1],spacings[2]);
    output->setLengthOfDataset();
    qDebug()<<output->getLengthOfDataset();
    qDebug()<<nDims[2]*nDims[1]*nDims[0];
    long index = 0;
    if(input->GetScalarType()==VTK_UNSIGNED_SHORT)
    {
        unsigned short* piexl = (unsigned short*)input->GetScalarPointer();
        for(long i=0;i<nDims[2]*nDims[1]*nDims[0];i++)
        {
            output->setValueByIndex(index,*piexl++);
            index++;
        }
        qDebug()<<output->getValueByIndex(index-1);
    }

}
