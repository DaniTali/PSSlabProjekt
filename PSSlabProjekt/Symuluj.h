#pragma once
#include "ARX.h"
#include "Plik_JSON.h"
#include "Regulator.h"
#include <iostream>
#include "P.h"
#include "PI.h"
#include "PD.h"
#include "PID.h"

enum class typRegulatora:char{
	P,PI,PD,PID
};

class Symuluj
{
public:
	Symuluj(typRegulatora typ);
	~Symuluj();

private:

};


