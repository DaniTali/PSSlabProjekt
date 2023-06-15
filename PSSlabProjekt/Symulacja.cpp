#include "Symulacja.h"

Symulacja::Symulacja(Regulator& regulator, ARX& arx)
{
	this->regulator = &regulator;
	this->arx = &arx;
	petlaSymulacji();
}

Symulacja::Symulacja()
{
	/**
	 * @brief domyslna nazwa pliku do odczytu
	*/
	nazwaPliku = "data.json";
	plik = new Plik_JSON(nazwaPliku);

	/**
	 * @brief Domyslne nazwy obiektow wczytywanych z pliku
	*/
	nazwaARX = "arx1";
	nazwaRegulatora = "pid1";

	/**
	 * @brief Stworzenie instancji obiektu regulowanego 
	*/
	arx = new ARX();
	plik->odczytParametrow_Plik(*arx, nazwaARX);


	/**
	 * @brief Stworzenie instancji odpowiedniego regulatora
	 * typ:
	 * 1 - p
	 * 10 - I
	 * 100 - D
	 * 11 - PI
	 * 101 - PD
	 * 111 - PID
	*/
	std::vector<double> parametryRegulatora = plik->odczytParametrowRegulatora(nazwaRegulatora);
	//char typ[3];
	//std::string typRegulatora;
	int typ = 0;

	if (parametryRegulatora[0] != 0)
		typ += 1;
		//typ[0] = 'P';

	if (parametryRegulatora[1] != 0)
		typ += 10;
		//typ[1] = 'I';

	if (parametryRegulatora[2] != 0)
		typ += 100;
		//typ[2] = 'D';
	
	//typRegulatora.assign(typ, typ + 3);
	k = parametryRegulatora[0];
	Ti = parametryRegulatora[1];
	Td = parametryRegulatora[2];

	parametryGeneratora.push_back(5.0);
	parametryGeneratora.push_back(2.0);
	parametryGeneratora.push_back(0.2);


	switch (typ)
	{
	case 1:
		regulator = new P(parametryGeneratora, k);
	case 11:
		regulator = new PI(parametryGeneratora, k, Ti);
	case 101:
		regulator = new PD(parametryGeneratora, k, Td);
	case 111:
		regulator = new PID(parametryGeneratora, k, Ti, Td);

	}
	

}

Symulacja::~Symulacja()
{
	if (regulator != nullptr)
		delete regulator;
	if (arx != nullptr)
		delete arx;
	if (plik != nullptr)
		delete plik;
}

void Symulacja::petlaSymulacji()
{

}
