#include "PID.h"

PID::PID(std::vector<double> parametryGeneratora) : Regulator(parametryGeneratora)
{
	k = 1.0;
}

PID::PID(std::vector<double> parametryGeneratora, double k, double Ti, double Td) : Regulator(parametryGeneratora)
{
	this->k = k;
	this->Ti = Ti;
	this->Td = Td;
}

PID::~PID()
{
}

double PID::symuluj(double u)
{
	SP = symulujSP();
	
	return czlonP(u) + czlonI(u) + czlonD(u);
}
