#pragma once
#include "Regulator.h"
class PID :
    private Regulator
{
public:
    /**
     * @brief Kontruktor przyjmujacy parametry dla generatorow
     * @param parametryGeneratora wektor parametrow generatora
    */
    PID(std::vector<double> parametryGeneratora);
    /**
     * @brief Kontruktor przyjmujacy parametry generatora wartoci zadanej oraz wartoc wzmocnienia regulatora
     * @param parametryGeneratora Wektor parametrow dla generatora
     * @param k Wzmocnienie regulatora
     * @param Ti Czas calkowania
     * @param Td Czas rozniczkowania
    */
    PID(std::vector<double> parametryGeneratora, double k, double Ti, double Td);
    ~PID();
    /**
     * @brief Metoda symulujaca regulator i zwaracajaca terowanie dla ukladu
     * @param u Wartocsc zmiennej procesowej - wejscie do regulatora
     * @return Sygnal sterujacy -  wyjscie z regulatora
    */
    double symuluj(double u) override;
};

