#pragma once
class SISO
{
public:
	/**
	 * @brief Metoda symulacji obiektu SISO
	 * @param u Sygnal wejsciowy
	 * @return Sygnal wyjsciowy
	*/
	virtual double symuluj(double u);
	/**
	 * @brief Konstruktor klasy SISO
	*/
	virtual ~SISO();

};

