#pragma once
#include<string>

using namespace std;

using std::string;

///Klasa Pracownik, podklasa klasy Pociag
class Pracownik
{
public:
	///Konstruktor domy�lny
	Pracownik();
	///Destruktor
	~Pracownik();
	///Funkcja wypisuj�ca dane pracownika
	void wypisDanychPracownika();
	///Procedura dodaj�ca dane pracownika.
	///Jako parametry przyjmuje  imie i nazwisko pracownika, zaw�d i zarobki
	/**
	\param nowy_imie_nazwisko okre�la imi� i nazwisko pracownika
	\param nowy_zawod okre�la zaw�d pracownika
	\param nowy_zarobki okre�la zarobki pracownika
	\return Funkcja nie zwraca �adnej warto�ci
	*/
	void dodajDanePracownika(string nowy_imie_nazwisko, string nowy_zawod, int nowy_zarobki);
	///Funkcja zapisuj�ca dane  pracownik� do pliku 
	///Jako parametr przyjmuje kontener zawieraj�cy pracownik�w  i zapisuje informacje o nich do pliku
	/**
	\param pracownicy okre�la pracownik�w kt�rych zapisujemy
	*/
	void zapisz(Pracownik &pracownicy);
	///Funkcja wczytuj�ce dane z pliku pracownikom  
	///Jako parametr przyjmuje kontener zawieraj�cy pracownik�w i wczytuje im dane z pliku
	/**
	\param pracownicy okre�la pracownik�w kt�rym wczytujemy dane
	*/
	void wczytaj(Pracownik &pracownicy);
	///Operator strumieniowy <<
	friend ostream& operator<< (ostream &s, Pracownik&p);
	///Operator strumieniowy >>
	friend istream& operator>> (istream &s, Pracownik&p);

	
private:

	string imie_nazwisko;///< okre�la i mi� i nazwisko pracownika
	string zawod;///< okre�la zaw�d pracownika
	int zarobki;///< okre�la zarobki pracownika
};
 
