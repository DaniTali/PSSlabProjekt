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
    std::vector<double> parametryGeneratora;
    //Generator* generator;
    std::vector<Generator*> generatory;

protected:
    double symulujSP();
    double czlonP(double u);
    double czlonI(double u);
    double czlonD(double u);

    double k = 1.0, Ti = 20.0, Td = 0.0, Esuma = 0.0, e, eP;
    double SP;
    const double h = 0.1;

};

