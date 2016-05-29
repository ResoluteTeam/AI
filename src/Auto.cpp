#include "Auto.h"

Auto::Auto(std::string _number, std::string _fuelType, float _fuelCount)
{
    number = _number;
    fuelType = _fuelType;
    fuelCount = _fuelCount;
}

Auto::~Auto()
{

}

std::string Auto::getNumber() {
    return number;
}
std::string Auto::getFuelType() {
    return fuelType;
}
float Auto::getFuelCount() {
    return fuelCount;
}
