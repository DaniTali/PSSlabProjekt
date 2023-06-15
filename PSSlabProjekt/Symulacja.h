#pragma once
#include "ARX.h"
#include "Plik_JSON.h"
#include "Regulator.h"
#include <iostream>
#include "P.h"
#include "PI.h"
#include "PD.h"
#include "PID.h"


class Symulacja
{
public:
	/**
	 * @brief Konstruktor klasy symulajcji 
	 * @param regulator obiekt regulatora przekazywany do symulacji
	 * @param arx Obiekt ARX przekazywany do symulacji
	*/
	/*Symulacja(Regulator& regulator, ARX& arx);*/
	Symulacja();
	/**
	 * @brief Metoda odpowiedzialna za symulacjê obiektow
	 * @param n - liczba iteracji
	*/
	void petlaSymulacji(int n);
	~Symulacja();

private:
	
	/**
	 * @brief wskaznik na obiekt regulatora
	*/
	void* regulator;
	/**
	 * @brief Wskaznik na obiekt regulacji
	*/
	ARX* arx;
	/**
	 * @brief wskaznik na obiekt odpowiedzialny za zapis i odczyt z pliku
	*/
	Plik_JSON* plik;
	/**
	 * @brief nazwy obiektow do wczytania z pliku
	*/
	std::string nazwaPliku, nazwaARX, nazwaRegulatora;
	/**
	 * @brief Parametry regulatora w symulacji 
	*/
	double k, Ti, Td;
	/**
	 * @brief Parametry generatora
	*/
	std::vector<double> parametryGeneratora;
};


