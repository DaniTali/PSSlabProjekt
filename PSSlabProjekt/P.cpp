#include "P.h"

P::P(std::vector<double> parametryGeneratora) : Regulator(parametryGeneratora)
{
	k = 1.0;
}

P::P(std::vector<double> parametryGeneratora, double k) : Regulator(parametryGeneratora)
{
	this->k = k;
}

P::~P()
{
}

double P::symuluj(double u)
{
	SP = symulujSP();
	return czlonP(u);
}
