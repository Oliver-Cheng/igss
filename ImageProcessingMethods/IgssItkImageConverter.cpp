#include "IgssItkImageConverter.h"
#include "IgssImage.h"

IgssItkImageConverter::IgssItkImageConverter()
{

}

//!--------------------------------------------------------------------------------------
//!
//! \brief IgssItkImageConverter::IgssToItk
//! \param input
//! \param output
//! \author deyuan fan
//! \date 2015.09.14
//!
void IgssItkImageConverter::IgssToItk(IgssImage* input, itk::Image< unsigned short, 3 >::Pointer output){
    int indims[3];
    double inspaces[3];
    float flposition[3];
    long z = 0;
    unsigned short ushvalues;

    typedef itk::Image< unsigned short, 3 > ImageType;

    //define elementspacing
    input->getElementSpacing(inspaces);
    output->SetSpacing(inspaces);

    //define the position of region
    input->getPosition(flposition);
    ImageType::IndexType start;
    start[0] = flposition[0];
    start[1] = flposition[1];
    start[2] = flposition[2];

    //define the size of region
    input->getDimensionSize(indims);
    ImageType::SizeType size;
    size[0] = indims[0];
    size[1] = indims[1];
    size[2] = indims[2];

    //set region with position and size
    ImageType::RegionType region;
    region.SetSize(size);
    region.SetIndex(start);
    output->SetRegions(region);
    output->Allocate();

    for(int i = 0; i < size[0]; i++){
        for(int j = 0; j < size[1]; j++){
            for(int k = 0; k < size[2]; k++){
                ImageType::IndexType pixelIndex;
                pixelIndex[0] = i;
                pixelIndex[1] = j;
                pixelIndex[2] = k;
                ushvalues = input->getValueByIndex(z);
                output->SetPixel(pixelIndex, ushvalues);
                z++;
            }
        }
    }
}

//!--------------------------------------------------------------------------------------
//!
//! \brief ItkToIgss
//! \param input
//! \param output
//! \author cheng wang
//! \date 2015.09.14
//!
void ItkToIgss( itk::Image< unsigned short, 3 >::Pointer input, IgssImage *output){
    int indims[3];
    double inspaces[3];
    float flposition[3];
    int z = 0;
    unsigned short ushvalues;

    typedef itk::Image< unsigned short, 3 > ImageType;

    //set number of dimension
    output->setNumberOfDimension(3);

    //set dimension size
    indims[0] = input->GetLargestPossibleRegion().GetSize()[0];
    indims[1] = input->GetLargestPossibleRegion().GetSize()[1];
    indims[2] = input->GetLargestPossibleRegion().GetSize()[2];
    output->setDimensionSize(indims[0], indims[1], indims[2]);

    //set the position
    flposition[0] = input->GetLargestPossibleRegion().GetIndex()[0];
    flposition[1] = input->GetLargestPossibleRegion().GetIndex()[1];
    flposition[2] = input->GetLargestPossibleRegion().GetIndex()[2];
    output->setPosition(flposition[0], flposition[1], flposition[2]);

    //set elementspacing
    inspaces[0] = input->GetSpacing()[0];
    inspaces[1] = input->GetSpacing()[1];
    inspaces[2] = input->GetSpacing()[2];
    output->setElementSpacing(inspaces[0], inspaces[1], inspaces[2]);

    //set length of data set
    output->setLengthOfDataSet();

    //set value by index
    for(int i = 0; i < indims[0]; i++){
        for(int j = 0; j < indims[1]; j++){
            for(int k = 0; k < indims[2]; k++){
                ImageType::IndexType pixelIndex;
                pixelIndex[0] = i;
                pixelIndex[1] = j;
                pixelIndex[2] = k;
                ImageType::PixelType pixelValue = input->GetPixel(pixelIndex);
                output->setValueByIndex(z++,pixelValue);
            }
        }
    }


}
