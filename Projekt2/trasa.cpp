#include <iostream>
#include <fstream>
#include <string>
#include "trasa.h"

using namespace std;

string nazwa_pliku_t = "trasa.txt";

Trasa::Trasa()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor trasy" << endl;
#endif
}

void Trasa::dodajDaneTrasy(string poczatek_t, string koniec_t, int czas_przejazdu, int dlugosc_t)
{
	poczatek_trasy = poczatek_t;
	koniec_trasy = koniec_t;
	czas_przejazdu_min = czas_przejazdu;
	dlugosc_trasy = dlugosc_t;
}

void Trasa::wypisDanychTrasy()
{
	cout << "Poczatek trasy: " << poczatek_trasy << endl;
	cout << "Koniec trasy: " << koniec_trasy << endl;
	cout << "Dlugosc trasy: " << dlugosc_trasy << endl;
	cout << "Czas przejazdy w min: " << czas_przejazdu_min << endl;
}



void Trasa :: dodajOpoznienie(int opoznienie)
{
	czas_przejazdu_min += opoznienie;
}
bool Trasa ::  operator > (const Trasa &t)
{
	if (dlugosc_trasy > t.dlugosc_trasy && czas_przejazdu_min > t.czas_przejazdu_min)
		return true;
	else
		return false;

}

void Trasa::zapisz(Trasa &trasa) 
{
#ifdef _DEBUG  
	cout << "Zapisano obiekt trasa" << endl;
#endif
	ofstream plik(nazwa_pliku_t);
	plik << trasa;
	plik.close();
}

void Trasa::wczytaj(Trasa &trasa)
{
#ifdef _DEBUG  
	cout << "Wczytano obiket trasa" << endl;
#endif
	ifstream plik(nazwa_pliku_t);
	plik >> trasa;
	plik.close();
}
bool Trasa ::  operator < (const Trasa &t)
{
	if (dlugosc_trasy < t.dlugosc_trasy && czas_przejazdu_min < t.czas_przejazdu_min)
		return true;
	else
		return false;

}

Trasa Trasa :: operator+ (const Trasa &t)
{
	Trasa suma;
	if (koniec_trasy == t.poczatek_trasy)
	{
		suma.poczatek_trasy = poczatek_trasy;
		suma.koniec_trasy = t.koniec_trasy;
		suma.dlugosc_trasy = dlugosc_trasy + t.dlugosc_trasy;
		suma.czas_przejazdu_min = czas_przejazdu_min + t.czas_przejazdu_min;
		return suma;
	}
	else
	{
		suma.poczatek_trasy = poczatek_trasy;
		suma.koniec_trasy = koniec_trasy;
		suma.dlugosc_trasy = dlugosc_trasy;
		suma.czas_przejazdu_min = czas_przejazdu_min;
		return suma;
	}
}

ostream& operator<< (ostream &s, Trasa&t)
{

	s<< "Poczatek trasy: "<<" " <<t.poczatek_trasy<<endl<<"Koniec trasy: "<<" "<< t.koniec_trasy<<endl<<"Dlugosc trasy: "<<" "<< t.dlugosc_trasy<<endl<<"Czas przejazdu w minutach: "<<" " <<t.czas_przejazdu_min<<endl;
	return s;

}
istream& operator >> (istream &s, Trasa&t)
{
	s >> t.poczatek_trasy >> t.koniec_trasy >> t.dlugosc_trasy >> t.czas_przejazdu_min ;
	return s;

}


Trasa::~Trasa()
{
#ifdef _DEBUG
	cout << "Wywolano dekonstruktor trasy" << endl;
#endif
}