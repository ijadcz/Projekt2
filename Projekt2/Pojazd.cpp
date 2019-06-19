#include"Pojazd.h"
#include<iostream>
#include<fstream>

using namespace std;
string nazwa_pliku_poj = "pojazd.txt";

Pojazd::Pojazd() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor pojazdu " << endl;
#endif

}

void Pojazd::zapisz(Pojazd &pojazd) {
#ifdef _DEBUG  
	cout << "Zapisano pojazd" << endl;
#endif
	ofstream plik(nazwa_pliku_poj);
	plik << pojazd;
	plik.close();
	
}

void Pojazd::odczytaj(Pojazd &pojazd) {
#ifdef _DEBUG  
	cout << "Wczytano pojazd" << endl;
#endif
	ifstream plik(nazwa_pliku_poj);
	plik >> pojazd;
	plik.close();
	
}

std::ostream& operator << (std::ostream &s, Pojazd &p) {
	s <<p.rok_produkcji<<endl<<p.kolor<<endl;
	return s;
}


 std::istream& operator >> (std::istream &s, Pojazd &p)
 {
	 s >> p.rok_produkcji >> p.kolor;
	 return s;
}



Pojazd::~Pojazd() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny destruktor pojazdu " << endl;
#endif

}
