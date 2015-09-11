#include "widget.h"
#include "vtkImageData.h"

Widget::Widget(QWidget *parent) : QWidget(parent){
    readImageFileFrom("/home/vincent/Documents/CanalyserWorkspace/PatientsDataware/Lan_Xiuying__1990_09_03/mra_tridimensionel__image/Lan_Xiuying.mhd");
    readImageFromVtkConvert();
}

Widget::~Widget(){

}

void Widget::readImageFileFrom(QString path){
    mhdImagePath = path;
    mraImage = new IgssImage();
    mhdFileReader = new MHDFileReader();
    mhdFileReader->doParseMHDFile(mhdImagePath, mraImage);

}
//!
//! \brief Widget::readImageFromVtkConvert
//!
void Widget::readImageFromVtkConvert()
{
    igssImage = new IgssImage();
    vtkImage = vtkImageData::New();
    vtkImage->SetDimensions(25,25,25);
    vtkImage->SetSpacing(1.0,1.0,1.0);
    vtkImage->SetOrigin(0.0,0.0,0.0);
    vtkImage->AllocateScalars(VTK_UNSIGNED_SHORT,1);
    unsigned short *ptr = (unsigned short*)vtkImage->GetScalarPointer();
    for(long i=0;i<25*25*25;i++)
    {
        *ptr++ = i;
    }
    igssVtkImageConverter = new IgssVtkImageConverter();
    igssVtkImageConverter->vtkImageToIgss(vtkImage,igssImage);
}
