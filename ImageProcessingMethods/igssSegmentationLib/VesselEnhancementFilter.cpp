#include "VesselEnhancementFilter.h"


VesselEnhancementFilter::VesselEnhancementFilter(){
    option = new Options();
    mraImage = new IgssImage();
    mraFileReader = new MRAFileReader();

    option->init();
    mraFileReader->doParseMHDFile("/home/bigboom/Documents/CanalyserWorkspace/PatientsDataware/He_Shiyu__1990_09_03/mra_tridimensionel__image/He_Shiyu.mhd",mraImage);

}


void VesselEnhancementFilter::doVesselEnhancement(){

}
