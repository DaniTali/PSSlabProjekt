#pragma once
#include "SISO.h"
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <exception>

class ARX :
    public SISO
{

public:
    /**
     * @brief 
     * Konstruktor klasy ARX
    */
    ARX();
    /**
     * @brief 
     * Konstruktor klasy ARX
     * @param nk 
     * opoznienie
     * @param nA 
     * stopien wielomianu A
     * @param nB 
     * stopien wielomianu B
    */
    ARX(int nk, int nA, int nB);
    /**
     * @brief 
     * Symulacja obiektu
     * @param u 
     * Zadane wymuszenie
     * @return 
     * Odpowiedz ukladu
    */
    double symuluj(double u) override;
    /**
     * @brief 
     * Ustawienie stopni obiektu ARX
     * @param nk 
     * @param nA 
     * @param nB 
     * @return 
    */
    int ustawStopnie(int nk, int nA, int nB);
    void wypiszStopnie();
    void wpiszParametry();
    void wypiszWielomiany();
    ~ARX() override;
    /**
     * @brief 
     * Metoda pozwalajaca na przekazanie wektorow 
     * parametrow do obiektu ARX
     * @param wektorA 
     * Wektor zawierajacy parametry wielomianu A
     * @param wektorB 
     * Wektor zawierajacy parametry wielomianu B
     * @return 
     * 
    */
    int wpiszParametry(std::vector<double> wektorA, std::vector<double> wektorB);
    /**
     * @brief 
     * Metoda zwracajaca wektory parametrow 
     * @return 
     * Zwracany wektor z dwoma wektorami zawierajacymi parametry kolejno 
     * wielomianu A i B
    */
    std::vector<std::vector<double>> wypiszParametry();
    /**
     * @brief 
     * Metoda zwracajaca stopnie wielomianow
     * @return 
     * wektor - opoznienie, stopien wielomianu A, stopien wielomianu B
    */
    std::vector<int> zwrocStopnie();

private:
    int nk, nA, nB;
    std::vector<double> paramA,  paramB;
    std::vector<double> pamiecU,  pamiecY;


};

