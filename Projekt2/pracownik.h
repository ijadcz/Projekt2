#pragma once
#include<string>

using namespace std;

using std::string;

///Klasa Pracownik, podklasa klasy Pociag
class Pracownik
{
public:
	///Konstruktor domyœlny
	Pracownik();
	///Destruktor
	~Pracownik();
	///Funkcja wypisuj¹ca dane pracownika
	void wypisDanychPracownika();
	///Procedura dodaj¹ca dane pracownika.
	///Jako parametry przyjmuje  imie i nazwisko pracownika, zawód i zarobki
	/**
	\param nowy_imie_nazwisko okreœla imiê i nazwisko pracownika
	\param nowy_zawod okreœla zawód pracownika
	\param nowy_zarobki okreœla zarobki pracownika
	\return Funkcja nie zwraca ¿adnej wartoœci
	*/
	void dodajDanePracownika(string nowy_imie_nazwisko, string nowy_zawod, int nowy_zarobki);
	///Funkcja zapisuj¹ca dane  pracownikó do pliku 
	///Jako parametr przyjmuje kontener zawieraj¹cy pracowników  i zapisuje informacje o nich do pliku
	/**
	\param pracownicy okreœla pracowników których zapisujemy
	*/
	void zapisz(Pracownik &pracownicy);
	///Funkcja wczytuj¹ce dane z pliku pracownikom  
	///Jako parametr przyjmuje kontener zawieraj¹cy pracowników i wczytuje im dane z pliku
	/**
	\param pracownicy okreœla pracowników którym wczytujemy dane
	*/
	void wczytaj(Pracownik &pracownicy);
	///Operator strumieniowy <<
	friend ostream& operator<< (ostream &s, Pracownik&p);
	///Operator strumieniowy >>
	friend istream& operator>> (istream &s, Pracownik&p);

	
private:

	string imie_nazwisko;///< okreœla i miê i nazwisko pracownika
	string zawod;///< okreœla zawód pracownika
	int zarobki;///< okreœla zarobki pracownika
};
 
