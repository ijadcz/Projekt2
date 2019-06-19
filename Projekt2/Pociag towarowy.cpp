#include"Pociag towarowy.h"
#include<iostream>
#include <fstream>

using namespace std;
string nazwa_pliku_po_towa = "pociag towarowy.txt";

PociagTowarowy ::PociagTowarowy ()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor domyslny pociagu towarowego " << endl << endl;
#endif
	rodzaj_towaru = "Brak towaru";
	waga_towaru_w_tonach = 0;

}

void PociagTowarowy::dodajTowar(string nowy_rodzaj_towaru, int nowa_waga_towaru_w_tonach)
{
	rodzaj_towaru = nowy_rodzaj_towaru;
	waga_towaru_w_tonach = nowa_waga_towaru_w_tonach;

}


void PociagTowarowy::wyswietlDane()
{
	cout << "Nazwa pociagu: " << nazwa_pociagu << endl;
	cout << "Rok produkcji: " << rok_produkcji << endl;
	cout << "Kolor pociagu: " << kolor << endl;
	cout << "Rodzaj towaru: " << rodzaj_towaru << endl;
	cout << "Waga towaru w tonach: " <<waga_towaru_w_tonach<<endl; 
	wagony.wypisDanychWagonow();
	trasa.wypisDanychTrasy();
	if (liczba_pracownikow > 0)
		{
			vector<Pracownik>::iterator it;
			for (it = pracownicy.begin(); it != pracownicy.end(); it++)
				it->wypisDanychPracownika();
			cout << endl;
		}
	
	else
		cout << "Brak pracownikow" << endl;
	cout << endl << endl;
}

void PociagTowarowy:: zmienKolor(string nowy_kolor_pociagu_towarowego)
{
	kolor = nowy_kolor_pociagu_towarowego;


}

void PociagTowarowy::zapisz(PociagTowarowy &pociag) {
#ifdef _DEBUG  
	cout << "Zapisano pociag towarowy" << endl;
#endif
	ofstream plik(nazwa_pliku_po_towa);
	plik << pociag;
	plik.close();
}

void PociagTowarowy::odczytaj(PociagTowarowy &pociag) {
#ifdef _DEBUG  
	cout << "Wczytano pociag towarowy" << endl;
#endif
	ifstream plik(nazwa_pliku_po_towa);
	plik >> pociag;
	plik.close();
}

ostream& operator<< (ostream &s, PociagTowarowy &p)//operator strumienowy
{
	s << "Nazwa pociagu: " << " " << p.nazwa_pociagu << endl << "Rok produkcji pociagu: " << " " << p.rok_produkcji << endl << "Liczba pracownikow: " << " " <<p.liczba_pracownikow<< endl << p.wagony << p.trasa<<endl<<"Rodzaj towaru: "<<" "<<p.rodzaj_towaru<<endl<<"Waga towaru w tonach: "<<" "<<p.waga_towaru_w_tonach<<endl;
	for (int i = 0; i < p.pracownicy.size(); i++)
	{
		s << p.pracownicy[i] << endl;

	}
	return s;


}

istream& operator >> (istream &s, PociagTowarowy &p)//operator strumienowy
{
	s >> p.nazwa_pociagu >> p.rok_produkcji >> p.liczba_pracownikow>> p.rodzaj_towaru>>p.waga_towaru_w_tonach;

	return s;


}

PociagTowarowy::~PociagTowarowy()
{

#ifdef _DEBUG
	cout << "Wywolano destruktor pociagu towarowego" << endl;
#endif
	
	ilosc_pociagow--;

}
