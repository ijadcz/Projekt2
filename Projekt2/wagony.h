#pragma once
#include <string>

using namespace std;
using std::string;

///Klasa Wagony, podklasa klasy Pociag
class Wagony
{
public:
	///Konstruktor domy�lny
	Wagony();
	///Destruktor
	~Wagony();
	
	///Funkcja wypisuj�ca dane o wagonach
	void wypisDanychWagonow();
	///Funkcja dodaj�ca dane o wagonach 
	///Przyjmuje jako parametr liczb� wagon�w
	/**
	\param liczba_w okre�la liczb� wagon�w
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajDaneWagonow( int liczba_w);

	///Funkcja zmieniaj�ca liczbe wagon�w
	///Jako parametr przyjmuje nowy liczbe wagon�w
	/**
	\param ile_wagonow okre�la liczbe wagon�w
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajWagony(int ile_wagonow);
	///Funkcja wczytuj�ca obiekt z pliku
	///Jako parametr przyjmuje obiekt wagony  i wczytuje do niego informacje z pliku 
	/**
	\param wagony okre�la pociag do kt�rego wczytujemy dane
	*/
	void zapisz(Wagony &wagony);
	///Funkcja wczytuj�ca obiekt z pliku
	///Jako parametr przyjmuje obiekt wagony  i wczytuje do niego informacje z pliku 
	/**
	\param wagony okre�la trase do kt�rego wczytujemy dane
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
	
	int liczba_wagonow;///< okre�la liczbe wagon�w

	


};