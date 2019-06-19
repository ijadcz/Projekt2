#include <iostream>
#include <fstream>
#include <string>
#include "pracownik.h"


using namespace std;

string nazwa_pliku_pra = "pracownicy.txt";

Pracownik::Pracownik()
{
#ifdef _DEBUG
	cout << " Wywolano konstruktor pracownika" << endl;
#endif
}

void Pracownik::wypisDanychPracownika()
{
	cout << "Dane pracownika: " << endl;
	cout << "Imie nazwisko: " << imie_nazwisko << endl;
	cout << "Zawod: " << zawod << endl;
	cout << "Zarobki pracownika: " << zarobki << endl;
}

void Pracownik::dodajDanePracownika(string nowy_imie_nazwisko,string nowy_zawod,int nowy_zarobki)
{
	imie_nazwisko = nowy_imie_nazwisko;
	zawod = nowy_zawod;
	zarobki =nowy_zarobki;
}

void Pracownik::zapisz(Pracownik &pracownicy)
{
#ifdef _DEBUG  
	cout << "Zapisano pracownikow" << endl;
#endif
	ofstream plik(nazwa_pliku_pra);
	plik << pracownicy;
	plik.close();
}

void Pracownik::wczytaj(Pracownik &pracownicy)
{
#ifdef _DEBUG  
	cout << "Wczytano pracownikow" << endl;
#endif
	ifstream plik(nazwa_pliku_pra);
	plik >> pracownicy;
	plik.close();
}

ostream& operator<< (ostream &s, Pracownik &p)
{
	s << "Imie i Nazwisko pracownika: " << " " << p.imie_nazwisko << endl << "zawod: " << " " << p.zawod << endl << "zarobki: " << " " << p.zarobki << endl;
	return s;
}

istream& operator >>(istream &s, Pracownik &p)
{
	s >>  p.imie_nazwisko >> p.zawod >>  p.zarobki;
	return s;
}


Pracownik::~Pracownik()
{
#ifdef _DEBUG
	//cout << "dekonstruktor pracownika" << endl;
#endif
}

