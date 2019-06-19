#pragma once
#include"Pojazd.h"
#include<iostream>

using namespace std;

///Klasa Samochod, pochodna klasy Pojazd
class Samochod: public Pojazd
{
private:
	string marka;///< okre�la mark� samochodu
	string typ_samochodu;///<okre�la typ samochodu 
	
public:
	///Konstruktor domy�lny 
	Samochod();
	///Destruktor
	~Samochod();
	///Konstruktor
	///Przyjmuje jako parametry marke, typ samochodu, rok produkcji i kolor
	/**
	\param n_marka okre�la mark� samochodu 
	\param n_typ_samochodu okre�la typ samochodu
	\param n_rok_produkcji okre�la rok produkcji samochodu
	\param n_kolor okre�la kolor samochodu
	\return Konstruktor nie zwraca �adnej warto�ci
	*/
	Samochod(string n_marka, string n_typ_samochodu, int n_rok_produkcji, string n_kolor);
	///Funkcja wirtualna wy�wietlaj�ca dane samochodu
	void wyswietlDane();
	///Funkcja wirtuaolna zmieniaj�ca kolor samochodu
	void zmienKolor(string nowy_kolor_samochodu);
	///Funkcja zapisuj�ca samoch�d do pliku
	///Jako parametr przyjmuje obiekt samochod i zapisuje informacje o nim do pliku
	/**
	\param samochod okre�la pociag kt�rego dane zapisujemy
	*/
	void zapisz(Samochod &samochod);
	///Funkcja wczytuj�ca obiekt z pliku
	///Jako parametr przyjmuje obiekt samochod  i wczytuje do niego informacje z pliku 
	/**
	\param pociag okre�la samoch�d do kt�rego wczytujemy dane
	*/
	void wczytaj(Samochod &samochod);
	///Operator strumieniowy <<
	friend ostream& operator<< (ostream &s, Samochod&c);
	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Samochod&c);



};
