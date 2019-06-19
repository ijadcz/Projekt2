#include <iostream>
#include <fstream>
#include <string>
#include "wagony.h"


using namespace std;

string nazwa_pliku_w = "wagony.txt";

Wagony::Wagony()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor wagonow" << endl;
#endif
	
}

void Wagony::zapisz(Wagony &wagony)
{
#ifdef _DEBUG  
	cout << "Zapisano obiekt wagony" << endl;
#endif
	ofstream plik(nazwa_pliku_w);
	plik << wagony;
	plik.close();
}

void Wagony::wczytaj(Wagony &wagony)
{
#ifdef _DEBUG  
	cout << "Wczytano obiekt wagony" << endl;
#endif
	ifstream plik(nazwa_pliku_w);
	plik >> wagony;
	plik.close();
}

void Wagony::dodajDaneWagonow( int liczba_w)
{
	
	liczba_wagonow = liczba_w;
}

void Wagony::wypisDanychWagonow()
{
	cout << "Liczba wagonow: " << liczba_wagonow << endl;
	

}



void Wagony :: dodajWagony(int ile_wagonow)
{
	liczba_wagonow +=ile_wagonow;

}

bool Wagony:: operator== (const Wagony &w)
{
	if (liczba_wagonow == w.liczba_wagonow) return true;
	else
		return false;

}

Wagony Wagony :: operator+ ( const Wagony &w)
{
	Wagony suma;
	suma.liczba_wagonow = w.liczba_wagonow + liczba_wagonow;
	
	return suma;

}



bool  Wagony ::operator > (const Wagony &w)
{ 
	if (liczba_wagonow > w.liczba_wagonow)
		return true;
	else
		return false;


}
bool  Wagony ::operator < (const Wagony &w)
{
	if (liczba_wagonow < w.liczba_wagonow)
		return true;
	else
		return false;


}
ostream& operator<< (ostream &s, Wagony&w)
{
	s<< "Liczba wagonow: "<<" " <<w.liczba_wagonow<<endl;
	return s;


}

istream& operator >> (istream &s, Wagony&w)
{
	s>>  w.liczba_wagonow ;
	return s;


}




Wagony::~Wagony()
{
#ifdef _DEBUG
	cout << "Wywolano dekonstruktor wagonow" << endl;
#endif

}