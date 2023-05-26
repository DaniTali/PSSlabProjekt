#include "ARX.h"
#include "Plik.h"
#include "Plik_JSON.h"
#include "Regulator.h"

int main() {
	ARX x(1, 1, 1);
	x.wypiszStopnie();
	//x.wpiszParametry();
	std::vector<double> wektorA = { 1, 0.8 };
	std::vector<double> wektorB = { 0.5, -0.7 };
	x.wpiszParametry(wektorA, wektorB);

	std::vector<std::vector<double>> parametry;
	parametry = x.wypiszParametry();

	x.wypiszWielomiany();
	std::cout << "Symulacja: \n";
	x.symuluj(1);
	x.symuluj(1);
	x.symuluj(1);
	x.symuluj(1);

	// LAB2
	/*Plik plik("data.txt");
	plik.zapisParametrow_Plik(x);*/

	//json
	Plik_JSON plikjson("data.json");
	//plikjson.zapisParametrow_Plik(x, "arx1");
	//plikjson.odczytParametrow_Plik(x, "arx1");
	//plikjson.zapisSymulacji(x, "arx1", 1, 2);
	//plikjson.zapisSymulacji(x, "arx1", 1, 3);
	
	// LAB 4
	Regulator regulator(5, 2, 0.2);
	double test = regulator.symuluj(1.23456);
	std::cout << "Test regulatora:" << test << std::endl;
	
	// Test klasy generator
	{
		std::cout << "Test generatora sinus:" << std::endl;
		Generator generator(4, 1, 10);
		for (size_t i = 0; i < 20; i++) {
			std::cout << "Probka: " << generator.symuluj() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "Test generatora szum:" << std::endl;
		Generator generator(5, 10, 0.2);
		for (size_t i = 0; i < 20; i++) {
			std::cout << "Probka: " << generator.symuluj() << std::endl;
		}
		std::cout << std::endl;
	}



	return 0;
}


