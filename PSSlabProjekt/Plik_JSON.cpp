#include "Plik_JSON.h"

Plik_JSON::Plik_JSON()
{
	//Domyslna nazwa pliku
	nazwaPliku = "data.json";

}

Plik_JSON::Plik_JSON(std::string nazwa)
{
	//Weryfikacja przyjetego rozszerzenia pliku
	if (nazwa.find(".json") != std::string::npos)
		nazwaPliku = nazwa;
	else
		throw std::logic_error("Nieodpowiednia nazwa pliku o rozszerzeniu .json");

}

int Plik_JSON::odczytParametrow_Plik(ARX& obiekt, std::string nazwa)
{
	
	try {
		if (auto plik = std::ifstream(nazwaPliku)) {

			json parametryObiektu, Obiekt, Jplik;

			if (plik >> Jplik) {

				for (const auto& wczytanyObiekt : Jplik.items()) {

					//Wyszukanie odpowiedniego obiektu do odczytu
					if (wczytanyObiekt.value()["nazwa"] == nazwa && wczytanyObiekt.value()["typ"] == "ARX") {
						std::vector<double> wektorA, wektorB;
						std::vector<int> stopnie;
						if (wczytanyObiekt.value()["parametry"] != NULL) {
							parametryObiektu = wczytanyObiekt.value()["parametry"];
							//Przepisanie struktury z pliku do wektorow
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
						//Wpisanie parametrow z wektorow do obiektow
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

std::vector<double> Plik_JSON::odczytParametrowRegulatora(std::string nazwa)
{
	try {
		//Proba otwarcia pliku
		if (auto plik = std::ifstream(nazwaPliku)) {

			json parametryObiektu, Jplik;

			if (plik >> Jplik) {
				//Petla przeszukujaca dane z pliku pod katem wymaganego typu obiektu i nazwy 
				for (const auto& wczytanyObiekt : Jplik.items()) {


					if (wczytanyObiekt.value()["nazwa"] == nazwa && wczytanyObiekt.value()["typ"] == "Regulator") {
						
						std::vector<double> parametry;

						parametry.push_back(wczytanyObiekt.value()["P"].get<double>());
						parametry.push_back(wczytanyObiekt.value()["I"].get<double>());
						parametry.push_back(wczytanyObiekt.value()["D"].get<double>());

						plik.close();

						return parametry;
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

	
	return std::vector<double>();
}

int Plik_JSON::zapisParametrowRegulatora(std::vector<double> parametry, std::string nazwa)
{

	json zawartoscPliku, odpowiedz, nowyObiekt;
	if (auto plik = std::ifstream(nazwaPliku)) {

		try {
			plik >> zawartoscPliku;
			plik.close();
		}
		catch (std::exception& e) {

			std::cout << e.what() << std::endl;

		}

		if (auto plik = std::ofstream(nazwaPliku)) {
			//Stworzenie struktury do zapisu w pliku
			nowyObiekt["nazwa"] = nazwa;
			nowyObiekt["typ"] = "Regulator";
			nowyObiekt["P"] = parametry[0];
			nowyObiekt["I"] = parametry[1];
			nowyObiekt["D"] = parametry[2];

			size_t index = 0;
			//Przeszukanie zawartosci pliku pod kontem obecnosci obiektu o zalozonej nazwie i ewentualne nadpisanie go
			for (const auto& wczytanyObiekt : zawartoscPliku.items()) {

				if (wczytanyObiekt.value()["nazwa"] == nazwa && wczytanyObiekt.value()["typ"] == "Regulator") {
					zawartoscPliku.erase(index);
					break;
				}
				index++;
			}

			//Zapis do pliku
			zawartoscPliku.push_back(nowyObiekt);
			plik << zawartoscPliku.dump(4);

			plik.close();
			return 1;
		}
	}
	return 0;


}

int Plik_JSON::zapisParametrow_Plik(ARX obiekt, std::string nazwa)
{


	try {
		json zawartoscPliku;
		if (auto plik = std::ifstream(nazwaPliku)) {
			
			try {
				plik >> zawartoscPliku;
			}
			catch (std::exception& e) {

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
			//Stworzenie struktury obiektow do zapisu do pliku
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

			//Wpisanie do pliku
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

int Plik_JSON::zapisSymulacji(std::string nazwa, std::vector<double> wektorU, std::vector<double> wektorY)
{

	json zawartoscPliku, odpowiedz, nowyObiekt;
	if (auto plik = std::ifstream(nazwaPliku)) {

		try {
			plik >> zawartoscPliku;
			plik.close();
		}
		catch (std::exception& e) {

			std::cout << e.what() << std::endl;
			
		}
		try {
			if (auto plik = std::ofstream(nazwaPliku)) {
				//Stworzenie obiektow do zapisu
				nowyObiekt["nazwa"] = nazwa;
				nowyObiekt["typ"] = "Symulacja";
				json arrayU = json::array({ wektorU }), arrayY = json::array({ wektorY });
				nowyObiekt["u"] = arrayU;
				nowyObiekt["y"] = arrayY;
				size_t index = 0;
				//Wyszukiwanie juz istniejacego obiektu w pliku o zadanej nazwie i usuniecie go
				for (const auto& wczytanyObiekt : zawartoscPliku.items()) {
					if (wczytanyObiekt.value()["nazwa"] == nazwa && wczytanyObiekt.value()["typ"] == "Symulacja") {
						zawartoscPliku.erase(index);
						break;
					}
					index++;
				}
				//Wpisanie danych do pliku
				zawartoscPliku.push_back(nowyObiekt);
				plik << zawartoscPliku.dump(4);
				plik.close();
				return 1;
			}
		}
		catch (std::exception& e) {

			std::cout << e.what() << std::endl;

		}
		
	}
	return -1;

}

Plik_JSON::~Plik_JSON()
{
	
}

