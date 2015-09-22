#include "ImageProcessingFactory.h"

ImageProcessingFactory::ImageProcessingFactory()
{
    this->vesselEnhancementFilter = new VesselEnhancementFilter();
}

eProcessingErrorCode ImageProcessingFactory::doProcessingByCommand(IgssImage *input, IgssImage *output, int dim, QString method){
    eProcessingErrorCode ret = PROCESSING_NO_ERRROR;
    if(dim == 3){
        if(method == "vef"){
            ret = this->vesselEnhancementFilter->doVesselEnhancement(input,output);
        }
    }
    return ret;
}
