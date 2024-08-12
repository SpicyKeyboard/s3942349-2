#include "GreyscalePixel.h"
#include <exception>
#include <stdexcept>

    GreyscalePixel::GreyscalePixel(unsigned int intensity) {
        this->intensity = intensity;
    }

    GreyscalePixel::GreyscalePixel(){}

    GreyscalePixel::~GreyscalePixel(){}

    unsigned int GreyscalePixel::getBrightness() const {
        return this->intensity;
    }
