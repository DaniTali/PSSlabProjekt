#include "Plik.h"

Plik::Plik()
{
	nazwaPliku = "data.txt";
	plik.open(nazwaPliku, std::ios::in | std::ios::out | std::ios::trunc);



}

Plik::Plik(std::string nazwa)
{
	nazwaPliku = nazwa;
	plik.open(nazwaPliku, std::ios::in | std::ios::out | std::ios::trunc);
}

int Plik::odczytParametrow_Plik(ARX obiekt)
{
	if(plik.is_open()){
		std::string linia;
		//while(std::get)
			
		return 0;
	}
	else {
		return -1;
	}

}

int Plik::zapisParametrow_Plik(ARX obiekt)
{

	if(plik.is_open())
	{
		std::vector<std::vector<double>> parametry = obiekt.wypiszParametry();
		if (parametry.size() < 2) {
			return -1;
		}
		std::vector<double> wektorA = parametry[0];
		std::vector<double> wektorB = parametry[1];
		if (wektorA.size() > 0) {
			plik << "Wielomian A:\n";
			for (auto i = wektorA.begin(); i != wektorA.end(); i++) {
				plik << "a(" << i - wektorA.begin() <<
					") = " << *i;
				if (i != wektorA.end())
					plik << "; ";
			}
		}

		plik << std::endl;
		if (wektorB.size() > 0) {
			plik << "Wielomian B:\n";
			for (auto i = wektorB.begin(); i != wektorB.end(); i++) {
				plik << "b(" << i - wektorB.begin() <<
					") = " << *i;
				if (i != wektorB.end())
					plik << "; ";
			}
		}

		return 0;
	}
	else{
		return -1;
	}
	
}

int Plik::zapisSymulacji(ARX obiekt)
{
	if (plik.is_open()) {

		return 0;
	}
	else{
		return -1;
	}
	
}

Plik::~Plik()
{
	plik.close();
	std::cout << "Plik zamkniety!!!";

}
