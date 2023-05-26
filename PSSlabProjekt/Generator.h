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
	Generator();
	Generator(int typ, double a);
	/**
	 * @brief 
	 * Konstruktor generatora 
	 * @return 
	*/
	Generator(int typ, double a, double b);
	~Generator();
	double symuluj();
	void zmianaParametrow(double a, double b);

private:
	double sinus();
	double trojkat();
	double skok();
	double impuls();
	double szum();
	double A, T, mi, sigma;
	int typ;
	int* iteracja;
	std::default_random_engine* generator;
	std::normal_distribution<double>* rozklad;

};

