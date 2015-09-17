#ifndef DERIVATION_H
#define DERIVATION_H



class Derivation
{
public:
    Derivation();
    void do_3D_Derivation(float sigma);
    int getKernelSizeX();
    int getKernelSizeY();
    int getKernelSizeZ();

private:

    int gaussKernel_x_size;
    int gaussKernel_y_size;
    int gaussKernel_z_size;

    float *gaussKernel_xx;
    float *gaussKernel_yy;
    float *gaussKernel_zz;
    float *gaussKernel_xy;
    float *gaussKernel_xz;
    float *gaussKernel_yz;

};

#endif // DERIVATION_H
