#pragma once
#include "Regulator.h"
class PD :
    private Regulator
{
public:
    /**
     * @brief Kontruktor przyjmujacy parametry dla generatorow
     * @param parametryGeneratora wektor parametrow generatora
    */
    PD(std::vector<double> parametryGeneratora);
    /**
     * @brief Kontruktor przyjmujacy parametry generatora wartoci zadanej oraz wartoc wzmocnienia regulatora
     * @param parametryGeneratora Wektor parametrow dla generatora
     * @param k Wzmocnienie regulatora
    */
    PD(std::vector<double> parametryGeneratora, double k, double Td);
    ~PD();
    /**
     * @brief Metoda symulujaca regulator i zwaracajaca terowanie dla ukladu
     * @param u Wartocsc zmiennej procesowej - wejscie do regulatora
     * @return Sygnal sterujacy -  wyjscie z regulatora
    */
    double symuluj(double u) override;
};

