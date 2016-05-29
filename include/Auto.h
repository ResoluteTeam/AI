#ifndef AUTO_H
#define AUTO_H
#include <string>

class Auto
{
    public:
        Auto(std::string _number, std::string _fuelType, float _fuelCount);
        virtual ~Auto();

    protected:

    private:
        std::string number;
        std::string fuelType;
        float fuelCount;

    public:
        std::string getNumber();
        std::string getFuelType();
        float getFuelCount();
};

#endif // AUTO_H
