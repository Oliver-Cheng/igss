#ifndef VESSELENHANCEMENTFILTER_H
#define VESSELENHANCEMENTFILTER_H

#include "Options.h"
#include "IgssImage.h"
#include "MRAFileReader.h"
#include "Derivation.h"
#include "Convolution.h"

class VesselEnhancementFilter
{
public:
    VesselEnhancementFilter();
    QString doVesselEnhancement(IgssImage *input,IgssImage *output);

private:

    Options *option;
    IgssImage *mraImage;
    MRAFileReader *mraFileReader;
    Derivation* gaussDerivation;
    Convolution* hessionConvolution;

};

#endif // VESSELENHANCEMENTFILTER_H
