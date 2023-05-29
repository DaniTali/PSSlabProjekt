#include "PD.h"

PD::PD(std::vector<double> parametryGeneratora) : Regulator(parametryGeneratora)
{
	k = 1.0;
	Td = 0.0;
}

PD::PD(std::vector<double> parametryGeneratora, double k) : Regulator(parametryGeneratora)
{
	this->k = k;
	this->Td = Td;
}

PD::~PD()
{
}

double PD::symuluj(double u)
{
	SP = symulujSP();
	return czlonP(u) + czlonD(u);
}