#pragma once
#include "Regulator.h"
class PI :
    private Regulator
{
public:
    /**
     * @brief Kontruktor przyjmujacy parametry dla generatorow
     * @param parametryGeneratora wektor parametrow generatora
    */
    PI(std::vector<double> parametryGeneratora);
    /**
     * @brief Kontruktor przyjmujacy parametry generatora wartoci zadanej oraz wartoc wzmocnienia regulatora
     * @param parametryGeneratora Wektor parametrow dla generatora
     * @param k Wzmocnienie regulatora
     * @param Ti Czas calkowania
    */
    PI(std::vector<double> parametryGeneratora, double k, double Ti);
    ~PI();
    /**
     * @brief Metoda symulujaca regulator i zwaracajaca terowanie dla ukladu
     * @param u Wartocsc zmiennej procesowej - wejscie do regulatora
     * @return Sygnal sterujacy -  wyjscie z regulatora
    */
    double symuluj(double u) override;

};

