#ifndef VESSELENHANCEMENTFILTER_H
#define VESSELENHANCEMENTFILTER_H

#include "Options.h"
#include "IgssImage.h"
#include "MRAFileReader.h"

class VesselEnhancementFilter
{
public:
    VesselEnhancementFilter();
    void doVesselEnhancement();
private:
    Options *option;
    IgssImage *mraImage;
    MRAFileReader *mraFileReader;
};

#endif // VESSELENHANCEMENTFILTER_H
