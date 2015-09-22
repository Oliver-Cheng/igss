#ifndef IMAGEPROCESSINGFACTORY_H
#define IMAGEPROCESSINGFACTORY_H
#include "VesselEnhancementFilter.h"
#include "ErrorMessage.h"

class ImageProcessingFactory
{
public:
    ImageProcessingFactory();
    eProcessingErrorCode doProcessingByCommand(IgssImage *input, IgssImage *output, int dim, QString method);

private:
    VesselEnhancementFilter *vesselEnhancementFilter;

};

#endif // IMAGEPROCESSINGFACTORY_H
