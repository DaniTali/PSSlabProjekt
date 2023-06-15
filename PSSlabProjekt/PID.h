#pragma once
#include "Regulator.h"
class PID :
    private Regulator
{
public:
    PID(std::vector<double> parametryGeneratora);
    PID(std::vector<double> parametryGeneratora, double k, double Ti, double Td);
    ~PID();
    double symuluj(double u) override;
};

