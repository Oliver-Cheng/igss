#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "IgssImage.h"
#include "Derivation.h"

class Convolution
{
public:
    Convolution();
    void do_3D_Convolution(IgssImage *igssImage,Derivation *gaussDerivation);

private:
    float hession_3D[3][3];
    float hxx;
    float hyy;
    float hzz;
    float hxy;
    float hxz;
    float hyz;
};

#endif // CONVOLUTION_H
