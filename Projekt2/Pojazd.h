#pragma once
#include <string>

using namespace std;

/// Klasa abstrakcyjna
class Pojazd
{

protected:
	int rok_produkcji;///<okre�la rok produkcji pojazdu
	string kolor;///<okre�la kolor pojazdu
	
	

public:
	///Konstruktor domy�lny
	Pojazd();
	///Destruktor wirtualny
	virtual ~Pojazd();
	///Procedura wirtualna 
	virtual void wyswietlDane()=0;
	///Procedura wirtualna 
	virtual void zmienKolor(string nowy_kolor)=0;
	///Procedura wirtualna
	virtual void zapisz(Pojazd &pojazd);
	///Procedura wirtualna 
	virtual void odczytaj(Pojazd &pojazd);
	///Operator strumieniowy <<
	friend std::ostream& operator << (std::ostream &s, Pojazd &p);
	///Operator strumieniowy >>
	friend std::istream& operator >> (std::istream &s, Pojazd &p);
	


};
