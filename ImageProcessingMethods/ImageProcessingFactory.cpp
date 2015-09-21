#include "ImageProcessingFactory.h"

ImageProcessingFactory::ImageProcessingFactory()
{
    this->vesselEnhancementFilter = new VesselEnhancementFilter();
}

QString ImageProcessingFactory::doProcessingByCommand(IgssImage *input, IgssImage *output, int dim, QString method){
    if(dim == 3){
        if(method.contains("vessel enhancement")){
            return this->vesselEnhancementFilter->doVesselEnhancement(input,output);
        }
    }
}
