#pragma once
#include "Regulator.h"
class P :
    private Regulator
{
public:
    P(std::vector<double> parametryGeneratora);
    P(std::vector<double> parametryGeneratora, double k);
    ~P();
    double symuluj(double u) override;
};

