#pragma once
#include "SISO.h"
#include <vector>
#include <iostream>
#include "Generator.h"

/**
 * @brief 
 * Klasa regulatora dziedziczaca po SISO
 * 
 */
class Regulator :
    public SISO
{

public:
    /**
     * @brief Konstruktor regualtora tworzacy tylko jeden generator wartosci zadanej
     * @param typ Typ generatora
     * @param a parametr a generatora
     * @param b parametr b generatora
    */
    Regulator(int typ, double a, double b);
    /**
     * @brief Konstruktor regulatora
     * @param parametry Wektor parametrow generatorow wartosci zadanej 
    */
    Regulator(std::vector<double> parametry);
    /**
     * @brief Destruktor klasy
    */
    virtual ~Regulator() override;
    /**
     * @brief Metoda symulujaca wyjscie z regulatora
     * @param u Wejscie do regulatora
     * @return Wyjscie z regulatora
    */
    virtual double symuluj(double u) override;

    
private:
    /**
     * @brief Metoda tworzaca wektor generatorow, zalezny od przyjetego wektora partametrow generatorow
    */
    void tworzenieGeneratorow();
    /**
     * @brief Wektor parametrow generatorow wartosci zadanej
    */
    std::vector<double> parametryGeneratora;
    /**
     * @brief Wektor wskaznikow na stworzone obiekty generatorow wartosci zadanej
    */
    std::vector<Generator*> generatory;

protected:
    /**
     * @brief metoda symulujaca wartosc zadana z wykorzystaniem stworzonej puli generatorow
     * @return Wartosc zadana
    */
    double symulujSP();
    /**
     * @brief Metoda czlonu P regulatora
     * @param u Wartosc wejsciowa regulatora
     * @return Wyjscie regulatora
    */
    double czlonP(double u);
    /**
     * @brief Metoda czlonu I regulatora
     * @param u Wartosc wejsciowa regulatora
     * @return Wyjscie regulatora
    */
    double czlonI(double u);
    /**
     * @brief Metoda czlonu D regulatora
     * @param u Wartosc wejsciowa regulatora
     * @return Wyjscie regulatora
    */
    double czlonD(double u);
    /**
     * @brief Parametry regulatora.
    */
    double k = 1.0, Ti = 20.0, Td = 0.0, Esuma = 0.0, e = 0.0, eP = 0.0;
    double SP = 0.0;
    /**
     * @brief Czas dyskretyzacji
    */
    const double h = 0.1;

};

