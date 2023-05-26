#include "Plik_JSON.h"

Plik_JSON::Plik_JSON()
{
	nazwaPliku = "data.json";

}

Plik_JSON::Plik_JSON(std::string nazwa)
{
	/**
	 * @brief weryfikacja przyjetego rozszerzenia pliku
	 * @param nazwa 
	*/
	if (nazwa.find(".json") != std::string::npos)
		nazwaPliku = nazwa;
	else
		throw std::logic_error("Nieodpowiednia nazwa pliku o rozszerzeniu .json");

}

int Plik_JSON::odczytParametrow_Plik(ARX obiekt, std::string nazwa)
{
	
	try {
		if (auto plik = std::ifstream(nazwaPliku)) {

			json parametryObiektu, Obiekt, Jplik;

			if (plik >> Jplik) {

				for (const auto& wczytanyObiekt : Jplik.items()) {

					//std::cout << obiekt.key()<< obiekt.value()["nazwa"] << std::endl;

					if (wczytanyObiekt.value()["nazwa"] == nazwa && wczytanyObiekt.value()["typ"] == "ARX") {
						std::vector<double> wektorA, wektorB;
						std::vector<int> stopnie;
						if (wczytanyObiekt.value()["parametry"] != NULL) {
							parametryObiektu = wczytanyObiekt.value()["parametry"];

							stopnie.push_back(parametryObiektu["nk"].get<int>());
							stopnie.push_back(parametryObiektu["nA"].get<int>());
							stopnie.push_back(parametryObiektu["nB"].get<int>());
							for (const auto& parametr : parametryObiektu["a"]) {
								wektorA.push_back(parametr.get<double>());
							}
							for (const auto& parametr : parametryObiektu["b"]) {
								wektorB.push_back(parametr.get<double>());
							}

						}
						obiekt.ustawStopnie(stopnie[0], stopnie[1], stopnie[2]);
						obiekt.wpiszParametry(wektorA, wektorB);
						plik.close();

						return 1;
					}

				}
				throw std::logic_error("Brak wymaganego obiektu w pliku.");
				plik.close();


			}
			else {
				throw std::logic_error("Niepobrano zawartosci z pliku JSON.");
				plik.close();
			}


		}
		else {
			throw std::runtime_error("Blad odczytu z pliku.");
			
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		
	}
	
	return 0;
	

}

int Plik_JSON::zapisParametrow_Plik(ARX obiekt, std::string nazwa)
{
	//TODO jak jest juz w pliku taki obiekt to tylko go musze zmienic 


	try {
		json zawartoscPliku;
		if (auto plik = std::ifstream(nazwaPliku)) {
			
			try {
				plik >> zawartoscPliku;
			}
			catch (std::exception& e) {
				//if(e==)
				std::cout << e.what() << std::endl;
			}

			plik.close();
		}

		if (auto plik = std::ofstream(nazwaPliku)) {

			std::vector<std::vector<double>> parametry = obiekt.wypiszParametry();

			if (parametry.size() < 2) {
				return -1;
			}
			std::vector<double> wektorA = parametry[0];
			std::vector<double> wektorB = parametry[1];


			std::vector<int> stopnie = obiekt.zwrocStopnie();


			json parametryObiektu, Obiekt, Jplik;

			parametryObiektu["nk"] = stopnie[0];
			parametryObiektu["nA"] = stopnie[1];
			parametryObiektu["nB"] = stopnie[2];
			parametryObiektu["a"] = wektorA;
			parametryObiektu["b"] = wektorB;

			Obiekt["nazwa"] = nazwa;
			Obiekt["typ"] = "ARX";
			Obiekt["parametry"] = parametryObiektu;
			

			Jplik = zawartoscPliku;
			Jplik.push_back(Obiekt);


			plik << Jplik.dump(4);
			plik.close();

			return 0;
		}
		else {
			return -1;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;

}

int Plik_JSON::zapisSymulacji(ARX obiekt, std::string nazwa, double u, double y)
{

	json zawartoscPliku, odpowiedz, nowyObiekt;
	if (auto plik = std::ifstream(nazwaPliku)) {

		try {
			plik >> zawartoscPliku;
			plik.close();
		}
		catch (std::exception& e) {
			//if(e==)
			//TODO jak pusty 
			std::cout << e.what() << std::endl;
			
		}

		if (auto plik = std::ofstream(nazwaPliku)) {

			for (const auto& wczytanyObiekt : zawartoscPliku.items()) {

				if (wczytanyObiekt.value()["nazwa"] == nazwa && wczytanyObiekt.value()["typ"] == "Symulacja") {



					zawartoscPliku.emplace(nowyObiekt, wczytanyObiekt.key());

					/*if (wczytanyObiekt.value()["parametry"] != NULL) {
						parametryObiektu = wczytanyObiekt.value()["parametry"];

						stopnie.push_back(parametryObiektu["nk"].get<int>());
						stopnie.push_back(parametryObiektu["nA"].get<int>());
						stopnie.push_back(parametryObiektu["nB"].get<int>());
						for (const auto& parametr : parametryObiektu["a"]) {
							wektorA.push_back(parametr.get<double>());
						}
						for (const auto& parametr : parametryObiektu["b"]) {
							wektorB.push_back(parametr.get<double>());
						}

					}
					obiekt.ustawStopnie(stopnie[0], stopnie[1], stopnie[2]);
					obiekt.wpiszParametry(wektorA, wektorB);*/
					//plik.close();

					return 1;
				}

			}

			nowyObiekt["nazwa"] = nazwa;
			nowyObiekt["typ"] = "Symulacja";
			nowyObiekt["u"] = u;
			nowyObiekt["y"] = y;
			zawartoscPliku.push_back(nowyObiekt);
			plik << zawartoscPliku.dump(4);

			plik.close();
			return 1;
		}
	}
	/*if (auto plik = std::ofstream(nazwaPliku)) {
		double u = 1;
		odpowiedz = obiekt.symuluj(u);
		zawartoscPliku.push_back(odpowiedz);
		plik << zawartoscPliku.dump(4);
		plik.close();
	}*/


}

Plik_JSON::~Plik_JSON()
{
	
}

