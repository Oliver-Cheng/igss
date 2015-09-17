#include "Options.h"

Options::Options(){
    init();
}

void Options::init(){
    this->sigma_MIN = 1.0;
    this->sigma_MAX = 5.0;
    this->sigma_Step = 1;
    this->alpha = 0.5;
    this->beta = 0.5;
    this->c = 600;
}
