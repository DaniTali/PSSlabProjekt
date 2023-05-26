#pragma once
#include <iostream>
#include <fstream>
#include "ARX.h"
//#include "json.hpp"
//
//using json = nlohmann::json;

class Plik
{
private:
	std::string nazwaPliku;
	std::fstream plik;

public:
	Plik();
	Plik(std::string nazwa);
	int odczytParametrow_Plik(ARX obiekt);
	int zapisParametrow_Plik(ARX obiekt);
	int zapisSymulacji(ARX obiekt);
	~Plik();

};



