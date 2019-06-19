#pragma once
#include <string>

using namespace std;
using std::string;

///Klasa Wagony, podklasa klasy Pociag
class Wagony
{
public:
	///Konstruktor domyœlny
	Wagony();
	///Destruktor
	~Wagony();
	
	///Funkcja wypisuj¹ca dane o wagonach
	void wypisDanychWagonow();
	///Funkcja dodaj¹ca dane o wagonach 
	///Przyjmuje jako parametr liczbê wagonów
	/**
	\param liczba_w okreœla liczbê wagonów
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajDaneWagonow( int liczba_w);

	///Funkcja zmieniaj¹ca liczbe wagonów
	///Jako parametr przyjmuje nowy liczbe wagonów
	/**
	\param ile_wagonow okreœla liczbe wagonów
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajWagony(int ile_wagonow);
	///Funkcja wczytuj¹ca obiekt z pliku
	///Jako parametr przyjmuje obiekt wagony  i wczytuje do niego informacje z pliku 
	/**
	\param wagony okreœla pociag do którego wczytujemy dane
	*/
	void zapisz(Wagony &wagony);
	///Funkcja wczytuj¹ca obiekt z pliku
	///Jako parametr przyjmuje obiekt wagony  i wczytuje do niego informacje z pliku 
	/**
	\param wagony okreœla trase do którego wczytujemy dane
	*/
	void wczytaj(Wagony &wagony);

	///Operator ==
	bool operator== (const Wagony &w);
	///Operator >
	bool  operator > (const Wagony &w);
	///Operator <
	bool  operator < (const Wagony &w);
	///Operator +
	Wagony operator+(const Wagony&w);

	///Operator stumieniowy  <<
	friend ostream& operator<< (ostream &s, Wagony&w);
	///Operator strumieniowy >>
	friend istream& operator >> (istream &s, Wagony&w);
	
	
	



private:
	
	int liczba_wagonow;///< okreœla liczbe wagonów

	


};