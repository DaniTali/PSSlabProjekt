#pragma once
#include "Regulator.h"
class PI :
    private Regulator
{
public:
    //PI(int typ, double a, double b);
    PI(std::vector<double> parametryGeneratora);
    PI(std::vector<double> parametryGeneratora, double k, double Ti);
    ~PI();
    double symuluj(double u) override;

//private:
    /*double k, Ti, Esuma, e;
    double SP;
    const double h = 0.1;*/
};

