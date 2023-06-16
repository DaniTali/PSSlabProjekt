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
	 * @brief Konstruktor przyjmujacy nazwe pliku i obiektow symulacji do odczytu z pliku 
	 * @param nazwaPliku Nazwa pliku zawieracjacego obiekty sumulacji
	 * @param nazwaARX Nazwa obiektu ARX do odczytu z pliku
	 * @param nazwaRegulatora Nazwa regulatora do odczytu z pliku
	*/
	Symulacja(std::string nazwaPliku, std::string nazwaARX, std::string nazwaRegulatora);
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
	/**
	 * @brief Metoda zapisujaca wynik symulacji do pliku
	 * @param wektorU Wektor zmiennej sterujacej
	 * @param wektorY Wektor zmienne procesowek
	*/
	void zapisDoPliku(std::vector<double>& wektorU, std::vector<double>& wektorY);
	/**
	 * @brief Metoda tworzace obiekty - Inicjalizacja symulacji
	*/
	void stworzenieObiektow();

};


