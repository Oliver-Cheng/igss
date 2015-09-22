#include "VesselEnhancementFilter.h"
#include "QDebug"
//!-----------------------------------------------------------------------------------------------------
//!
//! \brief VesselEnhancementFilter::VesselEnhancementFilter
//!
VesselEnhancementFilter::VesselEnhancementFilter(){
    option = new Options();
    option->init();
    option->getSigmaValue(sigma);
    gaussDerivation = new Derivation();
    hessionConvolution = new Convolution();
}

//!-----------------------------------------------------------------------------------------------------
//!
//! \brief VesselEnhancementFilter::doVesselEnhancement
//! \param input
//! \param output
//! \return
//!
eProcessingErrorCode VesselEnhancementFilter::do_3D_VesselEnhancement(IgssImage *input, IgssImage *output){
    eProcessingErrorCode ret = PROCESSING_NO_ERRROR;
    for(int scale = sigma[0]; scale<=sigma[1]; scale += sigma[2]){
        gaussDerivation->do_3D_Derivation(scale);
        //hessionConvolution->do_3D_Convolution(input,gaussDerivation);
    }
    return ret;
}
