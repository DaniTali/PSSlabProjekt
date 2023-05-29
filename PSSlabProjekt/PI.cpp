#include "PI.h"

PI::PI(std::vector<double> parametryGeneratora) :Regulator(parametryGeneratora)
{
	k = 1.0;
	Ti = 20.0;
	Esuma = 0.0;
}


PI::PI(std::vector<double> parametryGeneratora, double k, double Ti) : Regulator(parametryGeneratora)
{
	this->k = k;
	this->Ti = Ti;
	Esuma = 0.0;
}



PI::~PI()
{
}


double PI::symuluj(double u)
{
	SP = symulujSP();

	return czlonP(u) + czlonI(u);
}

