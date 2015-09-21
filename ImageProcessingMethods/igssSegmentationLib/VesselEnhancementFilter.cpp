#include "VesselEnhancementFilter.h"


VesselEnhancementFilter::VesselEnhancementFilter(){
    option = new Options();
    option->init();
}


QString VesselEnhancementFilter::doVesselEnhancement(IgssImage *input, IgssImage *output){
    int sigma[3];
    option->getSigmaValue(sigma);
    gaussDerivation = new Derivation();
    hessionConvolution = new Convolution();
    for(int scale = sigma[0]; scale<sigma[1]; scale += sigma[2]){
        gaussDerivation->do_3D_Derivation(scale);
        hessionConvolution->do_3D_Convolution(input,gaussDerivation);
    }
    return "hession";
}
