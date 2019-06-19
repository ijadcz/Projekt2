#pragma once
#include <string>

using namespace std;
using std::string;

///Klasa Trasa, podklasa klasy Pociag
class Trasa
{
public:
	///Konstruktor domyœlny
	Trasa();
	///Destruktor
	~Trasa();
	
	///Funkcja wypisuj¹ca informacje o trasie
	void wypisDanychTrasy();
	///Funkcja dodaj¹ca dane o trasie
	///Jako parametry przyjmuje pocz¹tek i koniec trasy, czas przejazdu i d³ugoœæ trasy
	/**
	\param poczatek_t okreœla pocz¹tek trasy poci¹gu
	\param koniec_t okreœla koniec trasy poci¹gu
	\param czas_przejazdu okreœla czas przejazdu poci¹gu
	\param dlugosc_t okreœla d³ugoœæ trasy w kilometrach
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajDaneTrasy(string poczatek_t,string koniec_t,int czas_przejazdu,int dlugosc_t);
	///Funkcja dodaj¹ca opóŸnienie na trasie
	///Jako parametr przyjmuje d³ugoœæ opóŸnienia w minutach
	/**
	\param opoznienie okreœla d³ugoœæ opóŸniena poci¹gu w minutach
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajOpoznienie(int opoznienie);
	///Funkcja zapisuj¹ca trase do pliku
	///Jako parametr przyjmuje obiekt trase i zapisuje informacje o niej do pliku
	/**
	\param trasa okreœla trase, której dane zapisujemy
	*/
	void zapisz(Trasa &trasa);
	///Funkcja wczytuj¹ca obiekt z pliku
	///Jako parametr przyjmuje obiekt trasa  i wczytuje do niego informacje z pliku 
	/**
	\param trasa okreœla pociag do którego wczytujemy dane
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
	string poczatek_trasy;///< okreœla pocz¹tek trasy
	string koniec_trasy;///< okreœla koniec trasy
	int dlugosc_trasy;///<okreœla d³ugoœæ trasy
	int czas_przejazdu_min;///< okreœla czas przejazdu 
	




};