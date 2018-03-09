#pragma once //to jest nasz plik maina
#include<vector>
#include<fstream>
#include"dane.h"
#include<iostream>
#include<string>
#include<algorithm>
class Rajd {
private:
	std::vector<Konkurencja> konkurencje;  //wektory zbieraj¹ dane które chcemy im przekazaæ; troche jak dynamiczne tablice
	std::vector<Patrol> patrole;
	void wczytajDane() {


		std::ifstream konkurencjePlik("konkurencje.txt");

		unsigned int podstawa;
		konkurencjePlik >> podstawa;
		Konkurencja::ustawPodstawe(podstawa);

		std::string nazwa; //pobieramy podstawe, konkurencje, mno¿nik 
		unsigned int mnoznik;
		std::map<std::string, unsigned int> punktyWzor;

		while (konkurencjePlik >> nazwa) {
			konkurencjePlik >> mnoznik;
			konkurencje.emplace_back(nazwa, mnoznik);

			punktyWzor.emplace(nazwa, 0);

		}


		std::ifstream patrolePlik("patrole.txt"); //pobieramy nazwy patroli
		while (patrolePlik >> nazwa)
		{
			patrole.emplace_back(nazwa, punktyWzor);
		}

		
	}
void zapiszDoPliku() {
	
}
void sortujPatrole() {
	std::sort(patrole.begin(), patrole.end(), [](Patrol p1, Patrol p2){
		return p1.sumaPunktow() > p2.sumaPonktow(); //trzeba dodaæ metody suma punktów
		});

}

public:
	Rajd() {
		wczytajDane();
	}

};