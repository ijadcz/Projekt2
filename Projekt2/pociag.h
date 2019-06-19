#pragma once
#include <string>
#include "pracownik.h"
#include "wagony.h"
#include "trasa.h"
#include "Pojazd.h"
#include "vector"

using namespace std;
using std::string;

///Klasa Poci¹g, pochodna klasy Pojazd
class Pociag: public Pojazd
{
public:
	///Konstruktor domyœlny
	Pociag();
	///Konstruktor
	///Jako parametry przyjmuje  now¹ nazwê poci¹gu, nowy rok produkcji poci¹gu nowy kolor,now¹ liczbê wagonów, nowy pocz¹tek trasy poci¹gu, nowy koniec trasy poci¹gu, nowy czas przejazdu poci¹gu, now¹ d³ugoœæ trasy w kilometrach
	/**
	\param nazwa_p okreœla nazwê poci¹gu
	\param rok_produkcji okreœla rok produkcji poci¹gu
	\param 
	\param liczba_w okreœla liczbê wagonów
	\param poczatek_t okreœla pocz¹tek trasy poci¹gu
	\param koniec_t okreœla koniec trasy poci¹gu
	\param czas_przejazdu okreœla czas przejazdu poci¹gu
	\param dlugosc_t okreœla d³ugoœæ trasy w kilometrach
	\return Konstruktor  nie zwraca ¿adnej wartoœci
	*/
	Pociag(string nazwa_p, int rok_produkcji, string kolor, int liczba_w, string poczatek_t, string koniec_t, int czas_przejazdu, int dlugosc_t);
	///Destruktor
	~Pociag();
	///Konstruktor kopiuj¹cy
	Pociag(const Pociag& pociag);
	
	///metoda statyczna zwracaj¹ca liczbe poci¹gów
	static int wyswietlLiczbePociagow()
	{
		return ilosc_pociagow;
	};
	///Funkcja wirtualna wyœwietlaj¹ca dane poci¹gu
	void wyswietlDane();
	///Procedura zmieniaj¹ca dane  poci¹gu.
	///Jako parametry przyjmuje  now¹ nazwê poci¹gu, nowy rok produkcji poci¹gu,nowy kolor poci¹gu, now¹ liczbê wagonów, nowy pocz¹tek trasy poci¹gu, nowy koniec trasy poci¹gu, nowy czas przejazdu poci¹gu, now¹ d³ugoœæ trasy w kilometrach
	/**
	\param nazwa_p okreœla nazwê poci¹gu
	\param rok_produkcji okreœla rok produkcji poci¹gu 
	\param kolor_p okreœla nowy kolor poci¹gu
	\param liczba_w okreœla liczbê wagonów
	\param poczatek_t okreœla pocz¹tek trasy poci¹gu
	\param koniec_t okreœla koniec trasy poci¹gu 
	\param czas_przejazdu okreœla czas przejazdu poci¹gu 
	\param dlugosc_t okreœla d³ugoœæ trasy w kilometrach
	\return Funkcja nie zwraca ¿adnej wartoœci 
	*/
	void dodajDanePociagu(string nazwa_p, int rok_produkcji,string kolor_p, int liczba_w,  string poczatek_t, string koniec_t, int czas_przejazdu, int dlugosc_t);
	///Funkcja zmieniaj¹ca nazwe poci¹gu.
	///Przyjmuje jako parametr now¹ nazwe poci¹gu
	/**
	\param nowa_nazwa okreœla nazwê poci¹gu
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void zmienNazwe(string nowa_nazwa);
	///Funkcja dodaj¹ca pracownika.
	///Jako parametry podawane s¹: imiê i nazwisko, zawód, zarobki
	/**
	\param nowy_imie_nazwisko okreœla imie i nazwisko pracownika 
	\param nowy_zawod okreœla zawód pracownika
	\param nowy_zarobki okreœla zarobki pracownika
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajPracownika(string nowy_imie_nazwisko,string nowy_zawod,int nowy_zarobki);
	///Funckcja dodaj¹ca wagony do poci¹gu.
	///Jako parametr podawana jest liczba wagonów, które chce sie do³¹czyæ do pojazdu
	/**
	\param ile_wagonow_pociagu okreœla liczbe wagonów
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajWagonyPociagu(int ile_wagonow_pociagu);
	///Funckcja zmieniaj¹ca kolor wagonów .
	///Jako parametr podawany jest nowy kolor wagonów
	/**
	\param nowy_kolor_wagonow okreœla kolor wagonów
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void zmienKolorWagonow(string nowy_kolor_wagonow);
	///Funckcja wirtualna zmieniaj¹ca kolor poci¹gu .
	///Jako parametr podawany jest nowy kolor poci¹gu
	/**
	/param nowy_kolor okreœla kolor poci¹gu 
	/return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void zmienKolor(string nowy_kolor_pocigu);
	///Funkcja zapisuj¹ca poci¹g do pliku
	///Jako parametr przyjmuje obiekt poci¹g i zapisuje informacje o nim do pliku
	/**
	\param pociag okreœla pociag którego dane zapisujemy
	*/
	void zapisz(Pociag &pociag);
	///Funkcja wczytuj¹ca obiekt z pliku
	///Jako parametr przyjmuje obiekt poci¹g  i wczytuje do niego informacje z pliku 
	/**
	\param pociag okreœla pociag do którego wczytujemy dane
	*/
	void wczytaj(Pociag &pociag);


	///Operator ==
	bool operator== (const Pociag &p);
	///Operator >
	bool operator > (const Pociag &p);
	///Operator <
	bool operator < (const Pociag &p);
	///Operator =
	Pociag& operator=(const Pociag &p);
	///Operator+
	Pociag operator+(const Pociag&p);
	///Operator ++
	Pociag& operator++ (int);
	///Operator --
	Pociag& operator-- (int);
	///Operator indeksowy 
	/**
	\param i oznacza numer pracownika
	\return Zwraca pracownika o danym numerze
	*/
	Pracownik& operator[](int i);
	///Operator rzutowania
	/**
	\return Zwraca liczbe pracowników poci¹gu
	*/
	operator int();
	///operator strumieniowy <<
	friend ostream& operator<< (ostream &s, Pociag&p);
	///operator strumieniowy >>
	friend istream& operator>> (istream &s, Pociag&p);


protected:
	static int ilosc_pociagow;///<zmienna statyczna przechowuj¹ca iloœæ poci¹gów
	string nazwa_pociagu;///<okreœla nazwe poci¹gu 
	int liczba_pracownikow;///<okreœla liczbê pracowników w poci¹gu 
	Wagony wagony;///< okreœla wagony poci¹gu
	vector <Pracownik> pracownicy;///< okreœla pracowników poci¹gu 
	Trasa trasa;///<okreœla trase poci¹gu 
	
	
	


};





