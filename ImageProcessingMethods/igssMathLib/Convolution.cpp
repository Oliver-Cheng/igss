#include "Convolution.h"

Convolution::Convolution(){

}

bool Convolution::do_3D_Convolution(IgssImage *igssImage, Derivation *gaussDerivation){

    int x, y, z, m, n, l, mm, nn, ll;

    int kCenterX,kCenterY,kCenterZ;

    int abscissa_X, ordinate_Y,isometric_Z;

    int dims[3];
    int kernelSize[3];
    this->hxx = 0.0;
    this->hyy = 0.0;
    this->hzz = 0.0;
    this->hxy = 0.0;
    this->hxz = 0.0;
    this->hyz = 0.0;
    igssImage->getDimensionSize(dims);
    gaussDerivation->getKernelSize(kernelSize);

    if(!igssImage || !gaussDerivation ) return false;
    if(dims[0] <= 0 || kernelSize[0] <= 0) return false;

    kCenterX = kernelSize[0] / 2;
    kCenterY = kernelSize[1] / 2;
    kCenterZ = kernelSize[2] / 2;

    for(int voxels = 0; voxels < dims[0] * dims[1] * dims[2]; voxels++){

        z = (int)(voxels/(dims[0] * dims[1]));
        y = (int)((voxels%(dims[0] * dims[1]))/dims[1]);
        x = (int)((voxels%(dims[0] * dims[1]))%dims[1]);

        for(m = 0; m < kernelSize[2]; m++){
            mm = kernelSize[2] - 1 - m;
            for(n = 0; n < kernelSize[1]; n++){
                nn = kernelSize[1] - 1 - n;
                for(l = 0; l < kernelSize[0]; l++){
                    ll = kernelSize[0] - 1 -l;
                    abscissa_X = x + m - kCenterX;
                    ordinate_Y = y + n - kCenterY;
                    isometric_Z = z + l - kCenterZ;

                    if(abscissa_X >= 0 && abscissa_X <= kernelSize[2] && ordinate_Y >= 0 && ordinate_Y <= kernelSize[1] && isometric_Z >= 0 && isometric_Z <= kernelSize[0]){
                        this->hxx += (float)(igssImage->getValueByIndex((isometric_Z * dims[2] + ordinate_Y) * dims[1] + abscissa_X) * gaussDerivation->getGaussKernel_xx((mm * kernelSize[2] + nn) * kernelSize[1] + ll));
                        this->hyy += (float)(igssImage->getValueByIndex((isometric_Z * dims[2] + ordinate_Y) * dims[1] + abscissa_X) * gaussDerivation->getGaussKernel_yy((mm * kernelSize[2] + nn) * kernelSize[1] + ll));
                        this->hzz += (float)(igssImage->getValueByIndex((isometric_Z * dims[2] + ordinate_Y) * dims[1] + abscissa_X) * gaussDerivation->getGaussKernel_zz((mm * kernelSize[2] + nn) * kernelSize[1] + ll));
                        this->hxy += (float)(igssImage->getValueByIndex((isometric_Z * dims[2] + ordinate_Y) * dims[1] + abscissa_X) * gaussDerivation->getGaussKernel_xy((mm * kernelSize[2] + nn) * kernelSize[1] + ll));
                        this->hxz += (float)(igssImage->getValueByIndex((isometric_Z * dims[2] + ordinate_Y) * dims[1] + abscissa_X) * gaussDerivation->getGaussKernel_xz((mm * kernelSize[2] + nn) * kernelSize[1] + ll));
                        this->hyz += (float)(igssImage->getValueByIndex((isometric_Z * dims[2] + ordinate_Y) * dims[1] + abscissa_X) * gaussDerivation->getGaussKernel_yz((mm * kernelSize[2] + nn) * kernelSize[1] + ll));
                    }

                }
            }
        }

        this->hession_3D[0][0] = this->hxx;
        this->hession_3D[0][1] = this->hxy;
        this->hession_3D[0][2] = this->hxz;
        this->hession_3D[1][1] = this->hyy;
        this->hession_3D[1][2] = this->hyz;
        this->hession_3D[2][2] = this->hzz;
    }

    return true;
}
