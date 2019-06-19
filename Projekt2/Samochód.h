#pragma once
#include"Pojazd.h"
#include<iostream>

using namespace std;

///Klasa Samochod, pochodna klasy Pojazd
class Samochod: public Pojazd
{
private:
	string marka;///< okreœla markê samochodu
	string typ_samochodu;///<okreœla typ samochodu 
	
public:
	///Konstruktor domyœlny 
	Samochod();
	///Destruktor
	~Samochod();
	///Konstruktor
	///Przyjmuje jako parametry marke, typ samochodu, rok produkcji i kolor
	/**
	\param n_marka okreœla markê samochodu 
	\param n_typ_samochodu okreœla typ samochodu
	\param n_rok_produkcji okreœla rok produkcji samochodu
	\param n_kolor okreœla kolor samochodu
	\return Konstruktor nie zwraca ¿adnej wartoœci
	*/
	Samochod(string n_marka, string n_typ_samochodu, int n_rok_produkcji, string n_kolor);
	///Funkcja wirtualna wyœwietlaj¹ca dane samochodu
	void wyswietlDane();
	///Funkcja wirtuaolna zmieniaj¹ca kolor samochodu
	void zmienKolor(string nowy_kolor_samochodu);
	///Funkcja zapisuj¹ca samochód do pliku
	///Jako parametr przyjmuje obiekt samochod i zapisuje informacje o nim do pliku
	/**
	\param samochod okreœla pociag którego dane zapisujemy
	*/
	void zapisz(Samochod &samochod);
	///Funkcja wczytuj¹ca obiekt z pliku
	///Jako parametr przyjmuje obiekt samochod  i wczytuje do niego informacje z pliku 
	/**
	\param pociag okreœla samochód do którego wczytujemy dane
	*/
	void wczytaj(Samochod &samochod);
	///Operator strumieniowy <<
	friend ostream& operator<< (ostream &s, Samochod&c);
	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Samochod&c);



};
