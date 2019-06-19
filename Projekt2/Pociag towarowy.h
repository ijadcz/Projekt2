#pragma once
#include "pociag.h"

///Klasa PociagTowarowy, pochodna klasy Pociag
class PociagTowarowy: public Pociag
{
private:
	string rodzaj_towaru;///< okre�la rodzaj przewo�onego towaru
	int waga_towaru_w_tonach;///< okre�la wag� towaru w tonach 
public:
	///Konstruktor domy�lny
	PociagTowarowy();
	///Destruktor
	~PociagTowarowy();

	///Funkcja wirtualna wy�wietlaj�ca dane poci�gu towarowego
	void wyswietlDane();
	///Funckcja wirtualna zmieniaj�ca kolor poci�gu towarowego.
	///Jako parametr podawany jest nowy kolor poci�gu towarowego
	/**
	/param nowy_kolor okre�la kolor poci�gu towarowego
	/return Funkcja nie zwraca �adnej warto�ci
	*/
	void zmienKolor(string nowy_kolor_pociagu_towarowego);
	///Funckcja dodaj�ca towar .
	///Jako parametry podawany jest rodzaj towaru i jego waga
	/**
	\param nowy_rodzaj_towaru okre�la rodzaj towaru
	\param nowa_waga_towaru_w_tonach okre�la wage towaru w tonach
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajTowar(string nowy_rodzaj_towaru, int nowa_waga_towaru_w_tonach);
	///Funkcja zapisuj�ca poci�g towarowy do pliku 
	///Jako parametr przyjmuje obiekt poci�g towarowy i zapisuje informacje o nim do pliku
	/**
	\param pociag okre�la pociag towarowy kt�ry zapisujemy 
	*/
	void zapisz(PociagTowarowy &pociag);
	///Funkcja wczytuj�ca poci�g towarowy z pliku 
	///Jako parametr przyjmuje obiekt poci�g towarowy i wczytuje do niego informacje z pliku 
	/**
	\param pociag okre�la pociag towarowy do kt�rego wczytujemy dane 
	*/
	void odczytaj(PociagTowarowy &pociag);
	///Operator strumieniowy <<
	friend ostream& operator<< (ostream &s, PociagTowarowy&p);
	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, PociagTowarowy&p);



};
