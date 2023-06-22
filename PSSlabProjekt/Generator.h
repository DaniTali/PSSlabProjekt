#pragma once
#include <cmath>
#include <iostream>
#include <random>
//#include <math.h>

/**
 * @brief
 * Klasa generatora 
 * typ: 
	1 - impuls, 
	2 - skok, 
	3 - trojkat, 
	4 - sinus, 
	5 - szum
*/
class Generator
{

public:
	/**
	 * @brief Konstruktor domuslny generatora - typ 1
	*/
	Generator();
	/**
	 * @brief Konstruktor tworzacy generator typu 2
	 * @param typ 
	 * @param a 
	*/
	Generator(int typ, double a);
	/**
	 * @brief Konstruktor tworzacy odpowiedni typ generatora z zalozonymi parametrami
	 * @param typ Zalozony typ generatora
	 * @param a Parametr a zalezny od typu
	 * @param b Parametr b zalezny od typu
	*/
	Generator(int typ, double a, double b);
	~Generator();
	/**
	 * @brief Metoda symulujaca wartosc zadana przez generator
	 * @return Wartosc wygenerowana przez generator
	*/
	double symuluj();
	void zmianaParametrow(double a, double b);

private:
	/**
	 * @brief Metoda symulujaca przebieg sinusoidalny
	 * @return Wyjscie zasymulowane
	*/
	double sinus();
	/**
	 * @brief Metoda symulujaca przebieg trojkatny
	 * @return Wyjscie zasymulowane
	*/
	double trojkat();
	/**
	 * @brief Metoda symulujaca skok
	 * @return Wyjscie zasymulowane
	*/
	double skok();
	/**
	 * @brief Metoda generujaca impuls 
	 * @return Wyjscie zasymulowane
	*/
	double impuls();
	/**
	 * @brief Metoda generujaca szum losowy
	 * @return Wyjscie zasymulowane 
	*/
	double szum();
	/**
	 * @brief Parametry generatora 
	*/
	double A, T, mi, sigma;
	/**
	 * @brief Typ generatora 
	*/
	int typ;
	/**
	 * @brief Wskaznik na zmienna zawierajaca aktualna iteracje generatora 
	*/
	int* iteracja;
	/**
	 * @brief Wskaznik na obiekt generujacy liczby losowe
	*/
	std::default_random_engine* generator;
	/**
	 * @brief Wskaznik na obiekt rozkladu normalnego
	*/
	std::normal_distribution<double>* rozklad;

};

