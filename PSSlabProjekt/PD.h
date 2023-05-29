#pragma once
#include "Regulator.h"
class PD :
    private Regulator
{
public:
    PD(std::vector<double> parametryGeneratora);
    PD(std::vector<double> parametryGeneratora, double k);
    ~PD();
    double symuluj(double u) override;
};

