#pragma once
#include "pociag.h"

///Klasa PociagTowarowy, pochodna klasy Pociag
class PociagTowarowy: public Pociag
{
private:
	string rodzaj_towaru;///< okreœla rodzaj przewo¿onego towaru
	int waga_towaru_w_tonach;///< okreœla wagê towaru w tonach 
public:
	///Konstruktor domyœlny
	PociagTowarowy();
	///Destruktor
	~PociagTowarowy();

	///Funkcja wirtualna wyœwietlaj¹ca dane poci¹gu towarowego
	void wyswietlDane();
	///Funckcja wirtualna zmieniaj¹ca kolor poci¹gu towarowego.
	///Jako parametr podawany jest nowy kolor poci¹gu towarowego
	/**
	/param nowy_kolor okreœla kolor poci¹gu towarowego
	/return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void zmienKolor(string nowy_kolor_pociagu_towarowego);
	///Funckcja dodaj¹ca towar .
	///Jako parametry podawany jest rodzaj towaru i jego waga
	/**
	\param nowy_rodzaj_towaru okreœla rodzaj towaru
	\param nowa_waga_towaru_w_tonach okreœla wage towaru w tonach
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajTowar(string nowy_rodzaj_towaru, int nowa_waga_towaru_w_tonach);
	///Funkcja zapisuj¹ca poci¹g towarowy do pliku 
	///Jako parametr przyjmuje obiekt poci¹g towarowy i zapisuje informacje o nim do pliku
	/**
	\param pociag okreœla pociag towarowy który zapisujemy 
	*/
	void zapisz(PociagTowarowy &pociag);
	///Funkcja wczytuj¹ca poci¹g towarowy z pliku 
	///Jako parametr przyjmuje obiekt poci¹g towarowy i wczytuje do niego informacje z pliku 
	/**
	\param pociag okreœla pociag towarowy do którego wczytujemy dane 
	*/
	void odczytaj(PociagTowarowy &pociag);
	///Operator strumieniowy <<
	friend ostream& operator<< (ostream &s, PociagTowarowy&p);
	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, PociagTowarowy&p);



};
