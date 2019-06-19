// PROJEKT.cpp : Defines the entry point for the console application.
//
#include <string>
#include <iostream>
#include <fstream>
#include "trasa.h"
#include "wagony.h"
#include "pracownik.h"
#include "pociag.h"
#include "Pojazd.h"
#include "Pociag towarowy.h"
#include "Samochód.h"


using namespace std;
void test1();
string nowy_kolor;
int opcja, obiekt;

int main()
{
	PociagTowarowy towarowy1;
	Samochod samochod1("Audi" , "osobowy", 2010, "czarny");
	Pociag pociag1;

	towarowy1.dodajDanePociagu("Posejdon", 1997, "niebieski",6 ,"Szczecin Glowny", "Gdansk", 240, 354);
	towarowy1.dodajTowar("wegiel", 20);
	towarowy1.dodajPracownika("Krzysztof Kowalski", "maszynista", 2500);

	pociag1.dodajDanePociagu("Moniuszko", 2000, "czerwony" ,9 , "Poznan ", "Warszawa", 200, 310);
	pociag1.dodajPracownika("Joanna Ostrowska", "maszynista", 2500);
	pociag1.dodajPracownika("Tomasz Kono", "konduktor", 2000);
	pociag1.dodajPracownika("Michal Kowalik", "konduktor", 2000);





	cout << "Wybierz obiekt: " << endl;
	cout << "[1 -Samochod   2 - Pociag  3 -Pociag towarowy ]" << endl << endl;
	cin >> obiekt;


	do {
		switch (opcja)
		{
		case 0:
			cout << endl;
			cout << "MENU PROGRAMU" << endl;
			cout << "-------------------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1: Zmien obiekt" << endl;
			cout << "2: Wyswietl dane" << endl;
			cout << "3: Zmien kolor pojazdu" << endl;
			cout << "4: Zapisz informacje o obiekcie do pliku" << endl;
			cout << "5: Wczytaj informacje o obiekcie z pliku" << endl;
			cout << "6: Testowanie pojazdow" << endl;
			cout << "7: Zamknij program" << endl;
			cout << "-------------------------------" << endl;
			cout << "Opcja: "<<endl<<endl;
			cin >> opcja;
			break;
		case 1:
			do {
				cout << "Zmien obiekt: " << endl;
				cout << "[1 -Samochod   2 - Pociag  3 -Pociag towarowy ]" << endl << "Obiekt: ";
				cin >> obiekt;
				cout << endl;
			} while (obiekt != 1 && obiekt != 2 && obiekt != 3);
			opcja = 0;
			break;
		case 2:
			if (obiekt == 1)
				samochod1.wyswietlDane();
			else if (obiekt == 2)
				pociag1.wyswietlDane();
			else if (obiekt == 3)
				towarowy1.wyswietlDane();

			opcja = 0;
			break;
		case 3:
			cout << "Wpisz nowy kolor pojazdu: ";
			cin >> nowy_kolor;
			if (obiekt == 1)
				samochod1.zmienKolor(nowy_kolor);
			else if (obiekt == 2)
				pociag1.zmienKolor(nowy_kolor);
			else if (obiekt == 3)
				towarowy1.zmienKolor(nowy_kolor);

			opcja = 0;
			break;
		case 4:
			if (obiekt == 1)
				samochod1.zapisz(samochod1);
			else if (obiekt == 2)
				pociag1.zapisz(pociag1);
			else if (obiekt == 3)
				towarowy1.zapisz(towarowy1);

			opcja = 0;
			break;
		case 5:
		{
			if (obiekt == 1)
				samochod1.wczytaj(samochod1);
			else if (obiekt == 2)
				pociag1.wczytaj(pociag1);
			else if (obiekt == 3)
				towarowy1.wczytaj(towarowy1);

			opcja = 0;
			break;
		}
		case 6:
		{
			cout << "Polimorfizm z uzyciem tablicy wskaznikow na obiekty klasy podstawowej" << endl;
			Pojazd *pojazdy[3];
			pojazdy[0] = &samochod1;
			pojazdy[1] = &pociag1;
			pojazdy[2] = &towarowy1;

			for (int i = 0; i < 3; i++)
			{
				string kolor = "Fioletowy";
				pojazdy[i]->zmienKolor(kolor);
				pojazdy[i]->wyswietlDane();
			}

			cout << "Testowanie zapisu dla klasy Pociag" << endl;
			pociag1.zapisz(pociag1);
			pociag1.wczytaj(pociag1);
			towarowy1.zapisz(towarowy1);
			towarowy1.wczytaj(towarowy1);
			cout << endl << endl;

			cout << "Metody wirtualne na wektora obiektow (STL)" << endl;
			vector <Pojazd*> pojazdy2;
			pojazdy2.push_back(&samochod1);
			pojazdy2.push_back(&pociag1);
			pojazdy2.push_back(&towarowy1);

			for (int i = 0; i < 3; i++)
			{
				string kolor = "zielony";
				pojazdy[i]->zmienKolor(kolor);
				pojazdy[i]->wyswietlDane();
				
				
			}
			opcja = 0;   
			break;
		}
		default:
			cout << "Wybrano niepoprawna opcje." << endl;
			opcja = 0;
		}

		} while (opcja != 7);

	return 0;
}













/*void test1()
{
	{
		cout << endl;
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^  TEST  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl << endl;




		cout << "----TEST POCIAGU----" << endl << endl;

		cout << "Liczba pociagow to: " << Pociag::wyswietlLiczbePociagow() << endl << endl << endl;

		Pociag pociag;//konstruktor
		Pociag pociag1("Posejdon", 1997,"niebieski",6, "Szczecin Glowny", "Gdansk", 240, 354), pociag2("Moniuszko", 2000, "czerwony", 9,"Poznan ", "Warszawa", 200, 310), pociag3("Chrobry", 1999,  "szary",8, "Warszawa", "Krakow ", 180, 210);

		pociag1.dodajPracownika("Krzysztof Kowalski", "maszynista", 2500);
		pociag1.dodajPracownika("Adam Zalewski", "konduktor", 2700);
		pociag1.dodajPracownika("Dariusz Drozd", "konduktor", 2700);
		pociag1.dodajPracownika("Anna Nowak", "konduktor", 2700);

		pociag2.dodajPracownika("Joanna Ostrowska", "maszynista", 2500);
		pociag2.dodajPracownika("Tomasz Kono", "konduktor", 2000);
		pociag2.dodajPracownika("Michal Kowalik", "konduktor", 2000);
		pociag2.dodajPracownika("Jan Kuszyna", "konduktor", 2000);
		pociag2.dodajPracownika("Andrzej Wak", "sprzedawca przekasek", 1800);

		pociag1.zapisz(pociag1);

		cout << endl << "Dane pociagu 1: " << endl << endl;
		pociag1.wyswietlDane();
		cout << endl;

		cout << "Dane pociagu 2: " << endl << endl;
		pociag2.wyswietlDane();
		cout << endl;



		cout << "Test konstruktora kopiujacego pociagu" << endl;
		Pociag pociag4(pociag2);
		cout << endl << "Dane pociagu 4 bedacego kopia 2: " << endl;
		pociag4.wyswietlDane();



		cout << endl << "Liczba pociagow to: " << Pociag::wyswietlLiczbePociagow() << endl << endl << endl;



		cout << endl << "Test funkcji dodajacej dane do pociagu i pracownikow" << endl << endl;
		cout << endl << "Pociag przed dodaniem danych" << endl;
		pociag.wyswietlDane();

		cout << endl << "Pociag po dodaniu danych i pracownikow" << endl;

		pociag.dodajDanePociagu("Kopernik", 1990, 8, "zielony", "Wroclaw", "Torun", 280, 390);
		pociag.dodajPracownika("Damian Bodys", "maszynista", 2800);
		pociag.dodajPracownika("Marek Kowal", "konduktor", 2000);

		pociag.wyswietlDane();

		cout << endl << "Zmieniamy nazwe pociagu na Lesnik " << endl << endl;
		pociag.zmienNazwe("Lesnik");
		cout << "Zmieniamy kolor wagonow na zielony" << endl << endl;
		pociag.zmienKolorWagonow("zielony");
		cout << "Zwiekszamy liczbe wagonow o 2" << endl << endl;
		pociag.dodajWagonyPociagu(2);
		cout << "Pociag  po zmianach" << endl;
		pociag.wyswietlDane();


		cout << endl << "Wybierz 2 razy ENTER aby kontynuowac" << endl << endl << endl;
		getchar();
		getchar();




		cout << endl << "Dynamiczne tworzenie pociagu" << endl << endl << endl;
		Pociag *pociag5 = new Pociag;
		cout << endl << "Testowanie funkcji dodajacej dane pociagu" << endl << endl;
		pociag5->dodajDanePociagu("Wodnik", 1993, 5, "Bialy", "Stargard", "Poznan", 120, 200);

		pociag5->wyswietlDane();

		cout << endl << "Liczba pociagow to: " << Pociag::wyswietlLiczbePociagow() << endl << endl << endl;





		cout << endl << "Wywolanie destrukora obiektu pociag5" << endl;
		if (pociag5 != NULL)
		{
			delete pociag5;
			pociag5 = NULL;

		}
		cout << endl << endl;
		cout << "Liczba pociagow to: " << Pociag::wyswietlLiczbePociagow() << endl << endl << endl;


		cout << "Wybierz 2 razy ENTER aby kontynuowac" << endl << endl << endl;
		getchar();
		getchar();




		#ifdef  _DEBUG



		cout << "----TEST OPERATOROW----" << endl << endl;

		cout << " 'TEST OPERATORA  ==' " << endl << endl;
		if (pociag1 == pociag2)
		cout << "Pociagi  Posejdon i Moniuszko maja taka sama liczbe wagonow " << endl << endl << endl;
		else
		cout << "Pociagi Posejdon i Moniuszko nie mja takiej samej liczby wagonow" << endl << endl << endl;



		cout << " 'TEST OPERATORA  >' " << endl << endl;
		if (pociag1 > pociag2)
		cout << "Pociag  'Posejdon' jest wiekszy od pociagu 'Moniuszko'  " << endl << endl << endl;
		else
		cout << "Pociag 'Posejdon' nie jest wiekszy od pociagu 'Moniuszko" << endl << endl << endl;


		cout << " 'TEST OPERATORA  <' " << endl << endl;
		if (pociag3 < pociag2)
			cout << "Pociag 'Chrobry' jest mniejszy od pociagu 'Moniuszko'   " << endl << endl << endl;
		else
		cout << "Pociag 'Chrobry' nie jest mniejszy od pociagu 'Moniuszko' " << endl << endl << endl;


		cout << " 'TEST OPERATORA  ++' " << endl << endl;
		cout << " Pociag 1 przed preinkrementacja " << endl << endl;
		pociag1.wyswietlDane();
		pociag1++;
		cout << " Pociag 1 po preinkrementacja " << endl;
		pociag1.wyswietlDane();

		cout << " 'TEST OPERATORA  --' " << endl << endl;
		cout << " Pociag 1 przed predekrementacja " << endl << endl;
		pociag1.wyswietlDane();
		pociag1--;
		cout << " Pociag 1 po predekrementacja " << endl;
		pociag1.wyswietlDane();


		cout << " 'TEST OPERATORA  INDEKSOWEGO' " << endl << endl;
		cout << " Informacje o 2 pracowniku pociagu 1: " << endl << endl;
		cout << pociag1[1] << endl << endl;

		cout << " 'TEST OPERATORA  STRUMIENIOWEGO' " << endl << endl;
		cout << pociag3 << endl << endl;

		cout << " 'TEST OPERATORA  KONWERSJI' " << endl << endl;
		cout << "Liczba pracownikow 1 pociagu wynosi: " << (int)pociag1 << endl << endl;


		cout << "Wybierz dwukrotnie ENTER aby kontynuowac" << endl << endl;

		getchar();
		getchar();

		cout << " 'TEST OPERATORA  +' " << endl << endl;
		cout << "Dane 2 pociagu " << endl;
		pociag2.wyswietlDane();
		cout << endl << endl;
		cout << "Dane 3 pociagu" << endl;
		pociag3.wyswietlDane();
		cout << endl << endl;
		pociag = pociag1 + pociag3;
		cout << "Dane pociagu bedacego suma tych 2: " << endl << endl << endl;
		pociag.wyswietlDane();
		cout << endl << endl;


		cout << " 'TEST OPERATORA  =' " << endl << endl;
		cout << "Dane pociagu 1 przed przypisaniem" << endl;
		pociag1.wyswietlDane();
		cout << endl << endl << endl;
		cout << "Przypisujemy dane pociagu 2" << endl << endl;
		pociag2.wyswietlDane();
		cout << endl << endl;
		pociag1 = pociag2;
		cout << "Dane pociagu 1 po przypisaniu" << endl;
		pociag1.wyswietlDane();
		cout << endl << endl;


		#endif





		cout << "Liczba pociagow to: " << Pociag::wyswietlLiczbePociagow() << endl << endl << endl;


			}

		cout << endl << "Liczba pociagow to: " << Pociag::wyswietlLiczbePociagow() << endl << endl << endl;


		cout << "Wybierz dwukrotnie ENTER aby zakonczyc" << endl << endl;


		}

}*/