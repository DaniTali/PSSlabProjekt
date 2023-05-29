#include "PID.h"

PID::PID(std::vector<double> parametryGeneratora) : Regulator(parametryGeneratora)
{
	k = 1.0;
}

PID::PID(std::vector<double> parametryGeneratora, double k) : Regulator(parametryGeneratora)
{
	this->k = k;
}

PID::~PID()
{
}

double PID::symuluj(double u)
{
	SP = symulujSP();
	
	return czlonP(u) + czlonI(u) + czlonD(u);
}
