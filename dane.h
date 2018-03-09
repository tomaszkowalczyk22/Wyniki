#pragma once
#include<fstream>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
class Patrol { //operujemy na danych o patrolach
private:
	std::string nazwa;
	unsigned int sumaPunktow;
	std::map<std::string, unsigned int> punkty;
public:
	Patrol(std::string _nazwa, std::map<std::string,unsigned int> punktyWzor) {
		nazwa = _nazwa;
		sumaPunktow = 0;
		punkty = punktyWzor;
	}

	std::string zwrocNazwe() {
		return nazwa;
	}
	void przyznajPunkty(unsigned int n, std::string nazwaKonkurencji) {
		punkty[nazwaKonkurencji] = n;
		sumaPunktow += n;
	}
};
class Konkurencja { //operujemy na danych o konkurencjach
private:
	std::string nazwa;
	unsigned int mnoznik;

	static unsigned int podstawa;

public:
	Konkurencja(std::string _nazwa, unsigned int _mnoznik) {
		nazwa = _nazwa;
		mnoznik = _mnoznik;

	}
	static void ustawPodstawe(unsigned int _podstawa) { //przypisujemy podstawe do konkurencji
		podstawa = _podstawa;

	}
	std::string zwrocNazwe() {
		return nazwa;
	}
};

unsigned int Konkurencja::podstawa;



