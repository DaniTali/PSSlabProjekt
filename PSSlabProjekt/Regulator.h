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
     * @brief 
     * Konstruktor regulatora 
     * @param typ 
     * Typ generatora wartosci zadanej
     * @param a
     * @param b 
    */
    Regulator(int typ, double a, double b);
    Regulator(std::vector<double> parametry);
    virtual ~Regulator() override;
    virtual double symuluj(double u) override;

    
private:
    void tworzenieGeneratorow();
    double symulujSP();
    std::vector<double> parametryGeneratora;
    //Generator* generator;
    std::vector<Generator*> generatory;

};

