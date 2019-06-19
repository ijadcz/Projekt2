#pragma once
#include <string>
#include "pracownik.h"
#include "wagony.h"
#include "trasa.h"
#include "Pojazd.h"
#include "vector"

using namespace std;
using std::string;

///Klasa Poci�g, pochodna klasy Pojazd
class Pociag: public Pojazd
{
public:
	///Konstruktor domy�lny
	Pociag();
	///Konstruktor
	///Jako parametry przyjmuje  now� nazw� poci�gu, nowy rok produkcji poci�gu nowy kolor,now� liczb� wagon�w, nowy pocz�tek trasy poci�gu, nowy koniec trasy poci�gu, nowy czas przejazdu poci�gu, now� d�ugo�� trasy w kilometrach
	/**
	\param nazwa_p okre�la nazw� poci�gu
	\param rok_produkcji okre�la rok produkcji poci�gu
	\param 
	\param liczba_w okre�la liczb� wagon�w
	\param poczatek_t okre�la pocz�tek trasy poci�gu
	\param koniec_t okre�la koniec trasy poci�gu
	\param czas_przejazdu okre�la czas przejazdu poci�gu
	\param dlugosc_t okre�la d�ugo�� trasy w kilometrach
	\return Konstruktor  nie zwraca �adnej warto�ci
	*/
	Pociag(string nazwa_p, int rok_produkcji, string kolor, int liczba_w, string poczatek_t, string koniec_t, int czas_przejazdu, int dlugosc_t);
	///Destruktor
	~Pociag();
	///Konstruktor kopiuj�cy
	Pociag(const Pociag& pociag);
	
	///metoda statyczna zwracaj�ca liczbe poci�g�w
	static int wyswietlLiczbePociagow()
	{
		return ilosc_pociagow;
	};
	///Funkcja wirtualna wy�wietlaj�ca dane poci�gu
	void wyswietlDane();
	///Procedura zmieniaj�ca dane  poci�gu.
	///Jako parametry przyjmuje  now� nazw� poci�gu, nowy rok produkcji poci�gu,nowy kolor poci�gu, now� liczb� wagon�w, nowy pocz�tek trasy poci�gu, nowy koniec trasy poci�gu, nowy czas przejazdu poci�gu, now� d�ugo�� trasy w kilometrach
	/**
	\param nazwa_p okre�la nazw� poci�gu
	\param rok_produkcji okre�la rok produkcji poci�gu 
	\param kolor_p okre�la nowy kolor poci�gu
	\param liczba_w okre�la liczb� wagon�w
	\param poczatek_t okre�la pocz�tek trasy poci�gu
	\param koniec_t okre�la koniec trasy poci�gu 
	\param czas_przejazdu okre�la czas przejazdu poci�gu 
	\param dlugosc_t okre�la d�ugo�� trasy w kilometrach
	\return Funkcja nie zwraca �adnej warto�ci 
	*/
	void dodajDanePociagu(string nazwa_p, int rok_produkcji,string kolor_p, int liczba_w,  string poczatek_t, string koniec_t, int czas_przejazdu, int dlugosc_t);
	///Funkcja zmieniaj�ca nazwe poci�gu.
	///Przyjmuje jako parametr now� nazwe poci�gu
	/**
	\param nowa_nazwa okre�la nazw� poci�gu
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void zmienNazwe(string nowa_nazwa);
	///Funkcja dodaj�ca pracownika.
	///Jako parametry podawane s�: imi� i nazwisko, zaw�d, zarobki
	/**
	\param nowy_imie_nazwisko okre�la imie i nazwisko pracownika 
	\param nowy_zawod okre�la zaw�d pracownika
	\param nowy_zarobki okre�la zarobki pracownika
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajPracownika(string nowy_imie_nazwisko,string nowy_zawod,int nowy_zarobki);
	///Funckcja dodaj�ca wagony do poci�gu.
	///Jako parametr podawana jest liczba wagon�w, kt�re chce sie do��czy� do pojazdu
	/**
	\param ile_wagonow_pociagu okre�la liczbe wagon�w
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajWagonyPociagu(int ile_wagonow_pociagu);
	///Funckcja zmieniaj�ca kolor wagon�w .
	///Jako parametr podawany jest nowy kolor wagon�w
	/**
	\param nowy_kolor_wagonow okre�la kolor wagon�w
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void zmienKolorWagonow(string nowy_kolor_wagonow);
	///Funckcja wirtualna zmieniaj�ca kolor poci�gu .
	///Jako parametr podawany jest nowy kolor poci�gu
	/**
	/param nowy_kolor okre�la kolor poci�gu 
	/return Funkcja nie zwraca �adnej warto�ci
	*/
	void zmienKolor(string nowy_kolor_pocigu);
	///Funkcja zapisuj�ca poci�g do pliku
	///Jako parametr przyjmuje obiekt poci�g i zapisuje informacje o nim do pliku
	/**
	\param pociag okre�la pociag kt�rego dane zapisujemy
	*/
	void zapisz(Pociag &pociag);
	///Funkcja wczytuj�ca obiekt z pliku
	///Jako parametr przyjmuje obiekt poci�g  i wczytuje do niego informacje z pliku 
	/**
	\param pociag okre�la pociag do kt�rego wczytujemy dane
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
	\return Zwraca liczbe pracownik�w poci�gu
	*/
	operator int();
	///operator strumieniowy <<
	friend ostream& operator<< (ostream &s, Pociag&p);
	///operator strumieniowy >>
	friend istream& operator>> (istream &s, Pociag&p);


protected:
	static int ilosc_pociagow;///<zmienna statyczna przechowuj�ca ilo�� poci�g�w
	string nazwa_pociagu;///<okre�la nazwe poci�gu 
	int liczba_pracownikow;///<okre�la liczb� pracownik�w w poci�gu 
	Wagony wagony;///< okre�la wagony poci�gu
	vector <Pracownik> pracownicy;///< okre�la pracownik�w poci�gu 
	Trasa trasa;///<okre�la trase poci�gu 
	
	
	


};





