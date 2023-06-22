#include "Symulacja.h"


Symulacja::Symulacja()
{
	// @brief domyslna nazwa pliku do odczytu
	
	nazwaPliku = "data.json";
	plik = new Plik_JSON(nazwaPliku);

	// @brief Domyslne nazwy obiektow wczytywanych z pliku
	
	nazwaARX = "arx1";
	nazwaRegulatora = "pid1";
	// @brief Wywolanie metody tworzacej obiekty sumulowane 
	
	stworzenieObiektow();

}


void Symulacja::zapisDoPliku(std::vector<double>& wektorU, std::vector<double>& wektorY)
{
	plik->zapisSymulacji("sumulacja1", wektorU, wektorY);
}

void Symulacja::stworzenieObiektow()
{
	plik = new Plik_JSON(nazwaPliku);

	// @brief Stworzenie instancji obiektu regulowanego
	
	arx = new ARX(1, 1, 1);
	plik->odczytParametrow_Plik(*arx, nazwaARX);


	//
	// Stworzenie instancji odpowiedniego regulatora
	// typ:
	// 1 - p
	// 10 - I
	// 100 - D
	// 11 - PI
	// 101 - PD
	// 111 - PID
	//
	std::vector<double> parametryRegulatora = plik->odczytParametrowRegulatora(nazwaRegulatora);

	int typ = 0;

	if (parametryRegulatora[0] != 0)
		typ += 1;

	if (parametryRegulatora[1] != 0)
		typ += 10;

	if (parametryRegulatora[2] != 0)
		typ += 100;


	k = parametryRegulatora[0];
	Ti = parametryRegulatora[1];
	Td = parametryRegulatora[2];

	//impuls
	parametryGeneratora.push_back(0);
	//skok
	parametryGeneratora.push_back(4.0);
	//trojkat
	parametryGeneratora.push_back(0.0);
	parametryGeneratora.push_back(0.0);
	//sinus
	parametryGeneratora.push_back(2.0);
	parametryGeneratora.push_back(1000);
	//szum
	parametryGeneratora.push_back(0.0);
	parametryGeneratora.push_back(0.0);

	//Stworzenie odpowiedniego typu regulatora
	switch (typ)
	{
	case 1:
		regulator = new P(parametryGeneratora, k);
		break;
	case 11:
		regulator = new PI(parametryGeneratora, k, Ti);
		break;
	case 101:
		regulator = new PD(parametryGeneratora, k, Td);
		break;
	case 111:
		regulator = new PID(parametryGeneratora, k, Ti, Td);
		break;

	}

}

Symulacja::Symulacja(std::string nazwaPliku, std::string nazwaARX, std::string nazwaRegulatora)
{
	// domyslna nazwa pliku do odczytu
	
	this->nazwaPliku = nazwaPliku;
	
	// Domyslne nazwy obiektow wczytywanych z pliku
	
	this->nazwaARX = nazwaARX;
	this->nazwaRegulatora = nazwaRegulatora;
	// Wywolanie metody tworzacej obiekty sumulowane
	
	stworzenieObiektow();
}

void Symulacja::petlaSymulacji(int n)
{
	std::vector<double> wektorY, wektorU, wektorSP;
	Regulator* wskREG{static_cast<Regulator*>(regulator)};
	
	double tempU = 0.0, tempY = 0.0;
	std::cout << "Start symulacji: \n";
	// Petla symulujaca dzialanie obiektow
	for (auto i = 0; i < n; i++) {
		tempU = wskREG->symuluj(tempY);
		wektorU.push_back(tempU);

		tempY = arx->symuluj(tempU);
		wektorY.push_back(tempY);
		std::cout << "U = " << tempU << "\tY = " << tempY << std::endl;
	}
	// Wywolanie metody zapisujacej symulacje do pliku
	zapisDoPliku(wektorU, wektorY);

}

Symulacja::~Symulacja()
{
	// Usuniecie stworzonych obiektow symulacji
	if (regulator != nullptr)
		delete regulator;
	if (arx != nullptr)
		delete arx;
	if (plik != nullptr)
		delete plik;
}