#include "Generator.h"



Generator::Generator(int typ, double a, double b)
{
    this->typ = typ;
    A = 0.0;
    T = 0.0;
    mi = 1.0;
    sigma = 1.0;
    iteracja = new int(0);
    generator = nullptr;
    rozklad = nullptr;

    switch (typ)
    {
    case 2:
        A = a;
        break;
    case 3:
        A = a;
        T = b;
        break;
    case 4:
        A = a;
        T = b;
        break;
    case 5:
        mi = a;
        sigma = b;
        generator = new std::default_random_engine();
        rozklad = new std::normal_distribution<double>(mi, sigma);
        break;
    }
}

Generator::~Generator()
{
    if (iteracja != nullptr){
        delete iteracja;
        iteracja = nullptr;
    }
    if (generator != nullptr) {
        delete generator;
        generator = nullptr;
    }
    if (rozklad != nullptr) {
        delete rozklad;
        rozklad = nullptr;
    }

}

double Generator::symuluj()
{
    switch (typ)
    {
    case 1:
        return impuls();
    case 2:
        return skok();
    case 3:
        return trojkat();
    case 4:
        return sinus();
    case 5:
        return szum();
    }
}

Generator::Generator() : typ(1), A(0), T(0), mi(1.0), sigma(1.0)
{
    iteracja = new int(0);
    generator = new std::default_random_engine();
    rozklad = new std::normal_distribution<double>(mi, sigma);
}

Generator::Generator(int typ, double a) : typ(2), A(a), T(0), mi(1.0), sigma(1.0)
{
    iteracja = new int(0);
    generator = new std::default_random_engine();
    rozklad = new std::normal_distribution<double>(mi, sigma);
}

double Generator::sinus()
{
    int& Iter = *iteracja;
    double wynik = A * sin(*iteracja * (2 * 3.1415 / T));
    Iter++;
    return wynik;
}

double Generator::trojkat()
{
    //TODO
    int& Iter = *iteracja;
    Iter++;
    return 0.0;
}

double Generator::skok()
{
    int& Iter = *iteracja;
    Iter++;
    return A;
}

double Generator::impuls()
{
    int& Iter = *iteracja;
    if (Iter == 0) 
    {
        Iter = 1;
        return 1.0;
    }
    else
        Iter++;
        return 0.0;
}

double Generator::szum()
{
    int& Iter = *iteracja;
    Iter++;
    std::normal_distribution<double>& roz = *rozklad;
    return roz(*generator);
}


void Generator::zmianaParametrow(double a, double b)
{

}
