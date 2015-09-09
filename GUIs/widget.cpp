#include "widget.h"
#include "vtkImageData.h"

Widget::Widget(QWidget *parent) : QWidget(parent){
    readImageFileFrom("/home/vincent/Documents/CanalyserWorkspace/PatientsDataware/Lan_Xiuying__1990_09_03/mra_tridimensionel__image/Lan_Xiuying.mhd");
}

Widget::~Widget(){

}

void Widget::readImageFileFrom(QString path){
    mhdImagePath = path;
    mraImage = new IgssImage();
    mhdFileReader = new MHDFileReader();
    mhdFileReader->doParseMHDFile(mhdImagePath, mraImage);

}
