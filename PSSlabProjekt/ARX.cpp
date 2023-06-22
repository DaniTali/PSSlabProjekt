#include "ARX.h"

ARX::ARX() :nA(0), nB(0), nk(0) {}

ARX::ARX(int nk, int nA, int nB)
{

    try {
        if (nk < 0 || nA < 0 || nB < 0) {
            throw std::logic_error("Niewlaciwe wartosci parametrow ARX.");
        }
        this->nA = nA;
        this->nB = nB;
        this->nk = nk;

        paramA.reserve(nA + 1);
        paramB.reserve(nB + 1);
        pamiecU.reserve(nB + nk);
        pamiecY.reserve(nA);

        for (auto i = 0; i < nB + nk; i++) {
            pamiecU.push_back(0.0);
        }
        for (auto i = 0; i < nA; i++) {
            pamiecY.push_back(0.0);
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    


}

double ARX::symuluj(double u)
{
    try {
        std::vector<double> wektorY = pamiecY;
        std::transform(wektorY.begin(), wektorY.end(), wektorY.begin(),
            std::bind1st(std::multiplies<double>(), (-1)));

        double y = std::inner_product(pamiecU.begin(), pamiecU.end(), paramB.begin(), 0.0);
        y = y + std::inner_product(wektorY.begin(), wektorY.end(), paramA.begin() + 1, 0.0);

        pamiecY.emplace(pamiecY.begin(), y);
        pamiecY.pop_back();
        //std::cout << "y = " << y << std::endl;
        pamiecU.emplace(pamiecU.begin(), u);
        pamiecU.pop_back();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    
    return *pamiecY.begin();
}

int ARX::ustawStopnie(int nk, int nA, int nB)
{
    if (nk < 0 || nA < 0 || nB < 0) {
        throw std::logic_error("Niewlaciwe wartosci parametrow ARX.");
        return -1;
    }
    this->nA = nA;
    this->nB = nB;
    this->nk = nk;

    return 0;
}

void ARX::wypiszStopnie()
{
    std::cout << "Stopnie wielomianow: nk = " << nk <<
        ", nA = " << nA << ", nB = " << nB << std::endl;

}

void ARX::wpiszParametry()
{
    try {
        if (nA > 0) {
            std::vector<double>& wielomianA = paramA;
            std::cout << "Wpisz parametry wielomianu A" << std::endl;
            wielomianA[0] = 1;
            std::cout << "a(0) = " << wielomianA[0] << std::endl;
            for (auto i = 1; i <= nA; i++) {
                std::cout << "a(" << i << ") = ";
                std::cin >> wielomianA[i];

            }

        }

        if (nB > 0) {
            std::vector<double>& wielomianB = paramB;
            std::cout << "Wpisz parametry wielomianu B" << std::endl;

            for (auto i = 0; i <= nB; i++) {
                std::cout << "b(" << i << ") = ";
                std::cin >> wielomianB[i];

            }

        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    


}

void ARX::wypiszWielomiany()
{
    try {
        if (nA > 0) {
            std::cout << "Wielomian A:\n";
            for (auto i = paramA.begin(); i != paramA.end(); i++) {
                std::cout << "a(" << i - paramA.begin() <<
                    ") = " << *i;
                if (i != paramA.end())
                    std::cout << "; ";
            }
        }

        std::cout << std::endl;
        if (nB > 0) {
            std::cout << "Wielomian B:\n";
            for (auto i = paramB.begin(); i != paramB.end(); i++) {
                std::cout << "b(" << i - paramB.begin() <<
                    ") = " << *i;
                if (i != paramB.end())
                    std::cout << "; ";
            }
        }
        std::cout << std::endl;
    }

    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    

}

ARX::~ARX()
{
   

}

int ARX::wpiszParametry(std::vector<double> wektorA, std::vector<double> wektorB)
{
    try {
        paramA = wektorA;
        nA = paramA.size() - 1;

        paramB = wektorB;
        nB = paramB.size() - 1;
        
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        
    }

    

    return 0;
}

std::vector<std::vector<double>> ARX::wypiszParametry()
{
    std::vector<std::vector<double>> wektorParametrow;
    
    try {
        
        std::vector<double> parametryA(paramA);
        std::vector<double> parametryB(paramB);
        wektorParametrow.push_back(parametryA);
        wektorParametrow.push_back(parametryB);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;

    }
    
    return wektorParametrow;

}

std::vector<int> ARX::zwrocStopnie()
{
    std::vector<int> stopnie;
    

    try {
        stopnie.push_back(nk);
        stopnie.push_back(nA);
        stopnie.push_back(nB);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;

    }

    return stopnie;

}



