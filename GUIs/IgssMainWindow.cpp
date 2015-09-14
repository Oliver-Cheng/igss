#include "IgssMainWindow.h"
#include "vtkImageData.h"


IgssMainWindow::IgssMainWindow(SystemDispatcher* dispatcher): QWidget(){

    this->dispatcher = dispatcher;

    //readImageFileFrom("C://Users//duyue//Documents//CanalyserWorkspace//PatientsDataware//Wang_Dechun__1990_09_04//mra_tridimensionel__image//Wang_Dechun.mhd");
    //readImageFileFrom("/home/bigboom/Documents/CanalyserWorkspace/PatientsDataware/He_Shiyu__1990_09_03/mra_tridimensionel__image/He_Shiyu.mhd");
    //readImageFileFrom("/home/vincent/Documents/CanalyserWorkspace/PatientsDataware/He_Shiyu__1990_09_03/mra_tridimensionel__image/He_Shiyu.mhd");
   readImageFileFrom("/home/sky/Documents/CanalyserWorkspace/PatientsDataware/He_Shiyu__1990_09_03/mra_tridimensionel__image/He_Shiyu.mhd");

    vtkSmartPointer<vtkImageData> input = vtkSmartPointer<vtkImageData>::New();

    IgssVtkImageConverter *c = new IgssVtkImageConverter();
    c->IgssToVtk(mraImage, input);
    readImageFromVtkConvert();
}

//!
//! \brief Widget::readImageFileFrom
//! \param path
//!
void IgssMainWindow::readImageFileFrom(QString path){
    mhdImagePath = path;
    mraImage = new IgssImage();
    mhdFileReader = new MHDFileReader();
    mhdFileReader->doParseMHDFile(mhdImagePath ,mraImage);
}

//!
//! \brief Widget::readImageFromVtkConvert
//!
void IgssMainWindow::readImageFromVtkConvert()
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
    igssVtkImageConverter->VtkToIgss(vtkImage,igssImage);
}
