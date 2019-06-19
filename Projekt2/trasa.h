#pragma once
#include <string>

using namespace std;
using std::string;

///Klasa Trasa, podklasa klasy Pociag
class Trasa
{
public:
	///Konstruktor domy�lny
	Trasa();
	///Destruktor
	~Trasa();
	
	///Funkcja wypisuj�ca informacje o trasie
	void wypisDanychTrasy();
	///Funkcja dodaj�ca dane o trasie
	///Jako parametry przyjmuje pocz�tek i koniec trasy, czas przejazdu i d�ugo�� trasy
	/**
	\param poczatek_t okre�la pocz�tek trasy poci�gu
	\param koniec_t okre�la koniec trasy poci�gu
	\param czas_przejazdu okre�la czas przejazdu poci�gu
	\param dlugosc_t okre�la d�ugo�� trasy w kilometrach
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajDaneTrasy(string poczatek_t,string koniec_t,int czas_przejazdu,int dlugosc_t);
	///Funkcja dodaj�ca op�nienie na trasie
	///Jako parametr przyjmuje d�ugo�� op�nienia w minutach
	/**
	\param opoznienie okre�la d�ugo�� op�niena poci�gu w minutach
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajOpoznienie(int opoznienie);
	///Funkcja zapisuj�ca trase do pliku
	///Jako parametr przyjmuje obiekt trase i zapisuje informacje o niej do pliku
	/**
	\param trasa okre�la trase, kt�rej dane zapisujemy
	*/
	void zapisz(Trasa &trasa);
	///Funkcja wczytuj�ca obiekt z pliku
	///Jako parametr przyjmuje obiekt trasa  i wczytuje do niego informacje z pliku 
	/**
	\param trasa okre�la pociag do kt�rego wczytujemy dane
	*/
	void wczytaj(Trasa &trasa);
	///Operator >
	bool  operator > (const Trasa &t);
	///Operator <
	bool  operator < (const Trasa &t);
	///Operator +
	Trasa operator+(const Trasa&t);
	///Operator strumieniowy <<
	friend ostream& operator<< (ostream &s, Trasa&t);
	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Trasa&t);

private:
	string poczatek_trasy;///< okre�la pocz�tek trasy
	string koniec_trasy;///< okre�la koniec trasy
	int dlugosc_trasy;///<okre�la d�ugo�� trasy
	int czas_przejazdu_min;///< okre�la czas przejazdu 
	




};