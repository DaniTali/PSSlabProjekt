#include "Regulator.h"

Regulator::Regulator(int typ, double a, double b)
{
	//generator = new Generator(typ, a, b);
}

Regulator::Regulator(std::vector<double> parametry)
{
	parametryGeneratora = parametry;
	tworzenieGeneratorow();

}

Regulator::~Regulator()
{
	/*if (generator != nullptr) {
		delete generator;
		generator = nullptr;
	}*/
}

double Regulator::symuluj(double u)
{
	return u;
}


void Regulator::tworzenieGeneratorow()
{
	/**
	 * @brief Generator impulsu
	*/
	if (parametryGeneratora[0] != 0) {
		
		generatory.push_back(new Generator());

	}
	/**
	 * @brief Generator skoku
	*/
	if (parametryGeneratora[1] != 0) {
		generatory.push_back(new Generator(2, parametryGeneratora[1]));

	}
	/**
	 * @brief Generator trojkata
	*/
	if (parametryGeneratora[2] != 0 && parametryGeneratora[3] != 0) {
		generatory.push_back(new Generator(3, parametryGeneratora[2], parametryGeneratora[3]));

	}
	/**
	 * @brief Generator sinus
	*/
	if (parametryGeneratora[4] != 0 && parametryGeneratora[5] != 0) {
		generatory.push_back(new Generator(4, parametryGeneratora[4], parametryGeneratora[5]));

	}
	/**
	 * @brief Generator szum
	*/
	if (parametryGeneratora[6] != 0 && parametryGeneratora[7] != 0) {
		generatory.push_back(new Generator(5, parametryGeneratora[6], parametryGeneratora[7]));

	}

}

double Regulator::symulujSP()
{
	double SP = 0;
	for (auto obiekt : generatory) {
		SP += obiekt->symuluj();
	}
	return SP;
}





