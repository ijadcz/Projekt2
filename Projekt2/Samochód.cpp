#include"Samochód.h"
#include<fstream>

string nazwa_pliku_sa = "samochod.txt"; 

Samochod::Samochod()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor domyslny samochodu" << endl << endl;
#endif


}

Samochod:: Samochod (string n_marka, string n_typ_samochodu, int n_rok_produkcji, string n_kolor)
{
	marka = n_marka;
	typ_samochodu = n_typ_samochodu;
	rok_produkcji = n_rok_produkcji;
	kolor = n_kolor;

}

void Samochod::zapisz(Samochod &samochod) {
#ifdef _DEBUG  
	cout << "Zapisano obiekt klasy Samochod" << endl;
#endif
	ofstream plik(nazwa_pliku_sa);
	plik << samochod;
	plik.close();

}

void Samochod::wczytaj(Samochod &samochod) {
#ifdef _DEBUG  
	cout << "Wczytano obiekt klasy Samochod" << endl;
#endif
	ifstream plik(nazwa_pliku_sa);
	plik >> samochod;
	plik.close();





}

void Samochod::zmienKolor(string nowy_kolor_samochodu)
{
	kolor = nowy_kolor_samochodu;


}

void Samochod::wyswietlDane()
{
	cout << "Marka samochodu : " << marka << endl;
	cout << "Rok produkcji: " << rok_produkcji << endl;
	cout << "Typ samochodu: " << typ_samochodu << endl;
	cout << "Kolor: " << kolor << endl;


}

ostream& operator<< (ostream &s, Samochod &c)//operator strumienowy
{
	s <<"Marka samochodu : "<<" "<< c.marka << endl <<"Typ : "<<" "<< c.typ_samochodu << endl <<"Rok produkcji: "<<" " <<c.rok_produkcji<<endl<<"Kolor: "<<" "<<c.kolor<<endl<<endl;

	return s;


}

istream& operator >> (istream &s, Samochod &c)//operator strumienowy
{
	s >> c.marka >>c.typ_samochodu >>c.rok_produkcji>>c.kolor;

	return s;


}



Samochod::~Samochod()
{

#ifdef _DEBUG
	cout << "Wywolano destruktor samochodu" << endl;
#endif


}