#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "pociag.h"



using namespace std;
int Pociag::ilosc_pociagow = 0;

string nazwa_pliku_po = "pociag.txt";

 
Pociag::Pociag()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor domyslny pociagu" << endl<<endl;
#endif
	liczba_pracownikow = 1;
	ilosc_pociagow++;

}



Pociag::Pociag(const Pociag &p)
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor kopiujacy pociagu" << endl << endl;
#endif
	ilosc_pociagow++;
	nazwa_pociagu = p.nazwa_pociagu;
	wagony = p.wagony;
	trasa = p.trasa;
	rok_produkcji = p.rok_produkcji;

	liczba_pracownikow = p.liczba_pracownikow;
	
}


Pociag::Pociag(string nazwa_p, int rok_produkcji_p, string kolor, int liczba_w, string poczatek_t, string koniec_t, int czas_przejazdu, int dlugosc_t)
{
#ifdef _DEBUG  
	cout << "Wywolano konstruktor Pociagu " << endl<<endl;
#endif

	
	liczba_pracownikow = 0;
	nazwa_pociagu = nazwa_p;
	rok_produkcji = rok_produkcji_p;
	trasa.dodajDaneTrasy(poczatek_t, koniec_t,czas_przejazdu,dlugosc_t);
	wagony.dodajDaneWagonow(liczba_w);
	ilosc_pociagow++;
}

void Pociag::dodajDanePociagu(string nazwa_p, int rok_produkcji_p,string kolor_p, int liczba_w, string poczatek_t, string koniec_t, int czas_przejazdu, int dlugosc_t)
{
	liczba_pracownikow = 0;
	nazwa_pociagu = nazwa_p;
	rok_produkcji = rok_produkcji_p;
	kolor = kolor_p;
	trasa.dodajDaneTrasy(poczatek_t, koniec_t, czas_przejazdu, dlugosc_t);
	wagony.dodajDaneWagonow( liczba_w);
}

void Pociag::dodajPracownika(string nowy_imie_nazwisko, string nowy_zawod, int nowy_zarobki)
{
	pracownicy.push_back(Pracownik());
	pracownicy[pracownicy.size() - 1].dodajDanePracownika( nowy_imie_nazwisko, nowy_zawod,  nowy_zarobki);


	liczba_pracownikow++;
}

void Pociag::wyswietlDane()
{
	cout << "Nazwa pociagu: " << nazwa_pociagu << endl;
	cout << "Rok produkcji: " << rok_produkcji << endl;
	cout << "Kolor: " << kolor << endl;
	wagony.wypisDanychWagonow();
	trasa.wypisDanychTrasy();
	if (liczba_pracownikow > 0)
	{
		vector<Pracownik>::iterator it;
		for (it = pracownicy.begin(); it != pracownicy.end(); it++)
			it->wypisDanychPracownika();
	}
	else
		cout << "Brak pracownikow" << endl;
	cout << endl << endl;
}

void Pociag::zmienNazwe(string nowa_nazwa)
{
	nazwa_pociagu = nowa_nazwa;
}


void Pociag::dodajWagonyPociagu(int ile_wagonow_pociagu)
{
	wagony.dodajWagony(ile_wagonow_pociagu);

}

void Pociag::zmienKolor(string nowy_kolor_pocigu)
{
	kolor = nowy_kolor_pocigu;

}
void Pociag::zapisz(Pociag &pociag) {
#ifdef _DEBUG  
	cout << "Zapisano obiekt klasy Pociag" << endl;
#endif
	ofstream plik(nazwa_pliku_po);
	plik << pociag;
	plik.close();
	
}

void Pociag::wczytaj(Pociag &pociag) {
#ifdef _DEBUG  
	cout << "Wczytano obiekt klasy Pociag" << endl;
#endif
	ifstream plik(nazwa_pliku_po);
	plik >> pociag;
	plik.close();
	




}

bool Pociag:: operator== (const Pociag &p)
{
	if (wagony == p.wagony) return true;

	else
		return false;

}
bool Pociag::  operator> (const Pociag &p)
{
	if (rok_produkcji > p.rok_produkcji && wagony > p.wagony && trasa > p.trasa)
		return true;
	else
		return false;

}
bool Pociag::  operator < (const Pociag &p)
{
	if (rok_produkcji < p.rok_produkcji && wagony < p.wagony && trasa < p.trasa)
		return true;
	else
		return false;

}

Pociag& Pociag::  operator=(const Pociag &p)
{
	nazwa_pociagu = p.nazwa_pociagu;
	wagony = p.wagony;
	trasa = p.trasa;
	rok_produkcji = p.rok_produkcji;

	liczba_pracownikow = p.liczba_pracownikow;
	pracownicy = p.pracownicy;



	return *this;

 }

Pociag Pociag:: operator+(const Pociag &p)
{
	Pociag suma;
	suma.nazwa_pociagu = nazwa_pociagu+ "_" +p.nazwa_pociagu;
	suma.rok_produkcji = int ((rok_produkcji+p.rok_produkcji)/2);
	suma.wagony = wagony + p.wagony;
	suma.trasa = trasa + p.trasa;
	

	return suma;

}



ostream& operator<< (ostream &s, Pociag &p)//operator strumienowy
{
	s <<"Nazwa pociagu: "<<" "<< p.nazwa_pociagu <<endl<<"Rok produkcji pociagu: "<<" " << p.rok_produkcji<<endl<<"Liczba pracownikow: "<<" "<<p.liczba_pracownikow<<endl<<p.wagony<<p.trasa;
	for (int i = 0; i < p.pracownicy.size(); i++)
	{
		s << p.pracownicy[i] << endl;

	}
	return s;


}

istream& operator>> (istream &s, Pociag &p)//operator strumienowy
{
	s >> p.nazwa_pociagu >> p.rok_produkcji >> p.liczba_pracownikow>>p.wagony>>p.trasa;
	for (int i = 0; i < p.pracownicy.size(); i++)
	{
		s >> p.pracownicy[i];

	}
	return s;


}

Pociag& Pociag ::operator++ (int)
{
	rok_produkcji++;
	return *this;

}
Pociag& Pociag ::operator-- (int)
{
	rok_produkcji--;
	return *this;

}

Pociag ::operator int()//pociag rzutowany  na inta(operator rzutowania)
{
	return liczba_pracownikow;

}

Pracownik& Pociag:: operator[](int i)//operator indeksowy
{
	if (i < liczba_pracownikow )
	{
		return pracownicy[i];
	}
}

Pociag::~Pociag()
{
	
#ifdef _DEBUG
	cout << "Wywolano destruktor pociagu" << endl;
#endif
	
	ilosc_pociagow--;

}