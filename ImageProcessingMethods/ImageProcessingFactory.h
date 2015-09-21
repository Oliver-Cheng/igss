#ifndef IMAGEPROCESSINGFACTORY_H
#define IMAGEPROCESSINGFACTORY_H
#include "VesselEnhancementFilter.h"

class ImageProcessingFactory
{
public:
    ImageProcessingFactory();
    QString doProcessingByCommand(IgssImage *input, IgssImage *output, int dim, QString method);

private:
    VesselEnhancementFilter *vesselEnhancementFilter;

};

#endif // IMAGEPROCESSINGFACTORY_H
