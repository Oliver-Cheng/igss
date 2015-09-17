#include "Derivation.h"
#include <math.h>
#include <QDebug>

Derivation::Derivation(){

}

//!--------------------------------------------------------------------------------------------------------------------------
//!calculate 3D Gauss kernel,
//! sigma: scale
//! define gaussKernel_x_size:the x_size of kernel matrix(similarly gaussKernel_y_size,gaussKernel_z_size )
//! define gaussKernel_xx:the second derivation of Gauss function
//! By the gaussKernel_x_size and gaussKernel_xx and so on ,calculate Gauss kernel
//! \brief Derivation::do_3D_Derivation
//! \param sigma
//!
void Derivation::do_3D_Derivation(float sigma){
    gaussKernel_x_size = 2*round(3*sigma) + 1;
    gaussKernel_y_size = 2*round(3*sigma) + 1;
    gaussKernel_z_size = 2*round(3*sigma) + 1;

    gaussKernel_xx = new float[gaussKernel_x_size*gaussKernel_x_size];
    gaussKernel_yy = new float[gaussKernel_y_size*gaussKernel_y_size];
    gaussKernel_zz = new float[gaussKernel_z_size*gaussKernel_z_size];
    gaussKernel_xy = new float[gaussKernel_x_size*gaussKernel_y_size];
    gaussKernel_xz = new float[gaussKernel_x_size*gaussKernel_z_size];
    gaussKernel_yz = new float[gaussKernel_y_size*gaussKernel_z_size];

    int i = 0;
    int j = 0;
    int k = 0;
    for(int x = -round(3*sigma); x <= round(3*sigma); x++){
        for(int y = -round(3*sigma); y <= round(3*sigma); y++){
            for(int z = -round(3*sigma); z <= round(3*sigma); z++){
                gaussKernel_xx[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k] =
                        1.0f/(pow(sqrt(2.0f*M_PI*sigma*sigma),3) * pow(sigma,2)) * (x*x/pow(sigma,2) - 1) * exp(-(x*x + y*y + z*z)/(2.0f*pow(sigma,2)));

                gaussKernel_xy[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k] =
                        1.0f/(pow(sqrt(2.0f*M_PI*sigma*sigma),3) * (x*y/pow(sigma,4)))* exp(-(x*x + y*y + z*z)/(2.0f*pow(sigma,2)));

                gaussKernel_xz[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k] =
                        1.0f/(pow(sqrt(2.0f*M_PI*sigma*sigma),3) * (x*z/pow(sigma,4)))* exp(-(x*x + y*y + z*z)/(2.0f*pow(sigma,2)));

                gaussKernel_yz[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k] =
                        1.0f/(pow(sqrt(2.0f*M_PI*sigma*sigma),3) * (y*z/pow(sigma,4)))* exp(-(x*x + y*y + z*z)/(2.0f*pow(sigma,2)));
                gaussKernel_yy[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k] = gaussKernel_xx[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k];
                gaussKernel_zz[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k] = gaussKernel_xx[(i*gaussKernel_y_size +j)*gaussKernel_z_size+k];
                k++;
            }
            j++;
        }
        i++;
    }

}

int Derivation::getKernelSizeX(){
    return this->gaussKernel_x_size;
}

int Derivation::getKernelSizeY(){
    return this->gaussKernel_y_size;
}

int Derivation::getKernelSizeZ(){
    return this->gaussKernel_z_size;
}

//!
//! \brief Derivation::do_2D_Derivation
//! \param sigma
//!
//!calculate 2D Gauss kernel
//! sigma: scale
//! define gaussKernel_x_size:the x_size of kernel matrix(similarly gaussKernel_y_size)
//! define gaussKernel_xx:the second derivation of Gauss function
//! By the gaussKernel_x_size and gaussKernel_xx and so on ,calculate Gauss kernel
//! \brief Derivation::do_3D_Derivation
//!
void Derivation::do_2D_Derivation(float sigma){
    this->gaussKernel_x_size = 2 * round(3*sigma) + 1;
    this->gaussKernel_y_size = 2 * round(3*sigma) + 1;

    gaussKernel_xx = new float[gaussKernel_x_size * gaussKernel_y_size];
    gaussKernel_yy = new float[gaussKernel_x_size * gaussKernel_y_size];
    gaussKernel_xy = new float[gaussKernel_x_size * gaussKernel_y_size];

    int i = 0, j = 0;
    for(int x = -round(3 * sigma); x <= round(3 * sigma); x++){
        for(int y = -round(3 * sigma); y <= round(3 * sigma); y++){
            gaussKernel_xx[i * gaussKernel_y_size + 1] = 1/(2 * M_PI * pow(sigma, 4)) * (pow(x, 2)/pow(sigma,2) - 1) * exp(-(pow(x,2)+pow(y,2))/(2*pow(sigma,2)));
            gaussKernel_yy[i * gaussKernel_y_size + 1] = 1/(2 * M_PI * pow(sigma, 4)) * (pow(y, 2)/pow(sigma,2) - 1) * exp(-(pow(x,2)+pow(y,2))/(2*pow(sigma,2)));
            gaussKernel_xy[i * gaussKernel_y_size + 1] = 1/(2 * M_PI * pow(sigma, 4)) * (x * y/pow(sigma,2)) * exp(-(pow(x,2)+pow(y,2))/(2*pow(sigma,2)));
            j++;
        }
        i++;
    }

}
