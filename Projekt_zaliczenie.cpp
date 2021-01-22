#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstdio>


using namespace std;

#define MAX 100

string imie;
int tabela_pytan[MAX];
int szanse;
int pytanie = 1;
int ok = 0;
int ilosc_pytan = 24;
int pieniadze = 0;
int i = 0;
int p = 1;
int wartosc = 500;
int j = 0;





void menu(); //+
void poziom_trudnosci(); //+
//void prezentuj_pytanie();
void prezentuj_gre();//+
void losuj_pytanie(int[]);//
int pokaz_pytanie();//+/-
void dodaj_pytanie();//+
void sprawdzenie_wyniku();//+
void rysuj_drabine(int);//+
void wczytaj();//+
void zapisz();//+
void wynik();//+




int main()
{
	srand(time(NULL));
	menu();
	prezentuj_gre();
	pokaz_pytanie();


	return 0;
}


void wynik()
{
	fstream plik3;
	plik3.open("Best.txt", ios::out | ios::app);
	if (plik3.good() == false)
	{
		cout << "Cos poszlo nie tak :(";
	}
	else
	{
		plik3 << imie << endl;
		plik3 << pieniadze << endl;
		plik3.close();

	}
}

void zapisz()
{
	/*FILE* save = fopen("Zapis.txt", "w");
	fprintf(save, "%01d , %01d , %01d , %01d, %01d", i, j, pieniadze, szanse, p);
	fclose(save);*/
	fstream plik2;
	plik2.open("Zapis.txt", ios::out);

	plik2 << imie << endl;
	plik2 << i << endl;
	plik2 << j << endl;
	plik2 << pieniadze << endl;
	plik2 << szanse << endl;
	plik2 << p << endl;
	plik2.close();
	//getchar(); getchar();
	//system("cls");
}

void wczytaj()
{
	{
		/*FILE* save = fopen("Zapis.txt", "r");
		fscanf(save, "%01d , %01d , %01d , %01d, %01d", &i, &j, &pieniadze, &szanse, &p);
		system("pause");

		fclose(save);*/
		int nr_linii = 1;
		string linia2;

		fstream plik2;
		plik2.open("Zapis.txt", ios::in);
		if (plik2.good() == false)
		{
			cout << "Nie udalo sie otworzyc pliku";
			exit(0);
		}
		while (getline(plik2, linia2))
		{
			switch (nr_linii)
			{
			case 1: imie = linia2;							break;
			case 2: i = atoi(linia2.c_str());				break;
			case 3: j = atoi(linia2.c_str()); 				break;
			case 4: pieniadze = atoi(linia2.c_str()); 		break;
			case 5: szanse = atoi(linia2.c_str()); 			break;
			case 6: p = atoi(linia2.c_str()); 				break;
			}
			nr_linii++;
		}

		plik2.close();
	}

}


void rysuj_drabine(int nr_pytania1)
{
	switch (nr_pytania1)
	{
	case 1:
		cout << "############\n###########\n##########\n#########\n########\n#######\n######\n#####\n####\n###\n##\n# +500$";
		break;
	case 2:
		cout << "############\n###########\n##########\n#########\n########\n#######\n######\n#####\n####\n###\n## +1000$\n# +500$";
		break;
	case 3:
		cout << "############\n###########\n##########\n#########\n########\n#######\n######\n#####\n####\n### +2000$\n## +1000$\n# +500$";
		break;
	case 4:
		cout << "############\n###########\n##########\n#########\n########\n#######\n######\n#####\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 5:
		cout << "############\n###########\n##########\n#########\n########\n#######\n######\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 6:
		cout << "############\n###########\n##########\n#########\n########\n#######\n###### +20000$\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 7:
		cout << "############\n###########\n##########\n#########\n########\n####### +40000$\n###### +20000$\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 8:
		cout << "############\n###########\n##########\n#########\n######## +75000$\n####### +40000$\n###### +20000$\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 9:
		cout << "############\n###########\n##########\n######### +125000$\n######## +75000$\n####### +40000$\n###### +20000$\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 10:
		cout << "############\n###########\n########## +250000$\n######### +125000$\n######## +75000$\n####### +40000$\n###### +20000$\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 11:
		cout << "############\n########### +500000$\n########## +250000$\n######### +125000$\n######## +75000$\n####### +40000$\n###### +20000$\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	case 12:
		cout << "############ +1000000$\n########### +500000$\n########## +250000$\n######### +125000$\n######## +75000$\n####### +40000$\n###### +20000$\n##### +10000$\n#### +5000$\n### +2000$\n## +1000$\n# +500$";
		break;
	}
}


void menu() // gra, autorzy
{

	cout << ("\t\t\t\t\t\tPodaj imie gracza\n");
	cin >> (imie);
	int wybor1;
	cout << ("\t\t\t\t\t\tMILIONERZY\n\t\t\t\t\t\t1: Gra\n\t\t\t\t\t\t2: Kontynuuj\n\t\t\t\t\t\t3: Autorzy\n");
	while (ok == 0)
	{
		cin >> (wybor1);
		if (wybor1 == 1)
		{
			poziom_trudnosci();
			ok = 1;
		}
		else
		{
			if (wybor1 == 2)
			{
				wczytaj();
				ok = 2;
			}
			else
			{
				if (wybor1 == 3)
				{
					cout << ("\t\t\t\t\t\tAutorzy: Andrzej Olech, Mateusz Marszalek\n");
					ok = 3;
				}
				else
				{
					cout << ("\t\t\t\t\t\tNiepoprawny znak\n");
				}
			}
		}
	}


}


void poziom_trudnosci() // latwy, trudny, sredni
{
	int wybor2;
	int ok2 = 0;
	cout << ("\t\t\t\t\t\tWybierz poziom trudności\n\t\t\t\t\t\t1: Latwy\n\t\t\t\t\t\t2: Sredni\n\t\t\t\t\t\t3: Trudny\n");
	while (ok2 == 0)
	{
		cin >> (wybor2);
		if (wybor2 == 1)
		{
			cout << ("\t\t\t\t\t\tWybrales poziom Latwy\n");
			szanse = 3;
			ok2 = 1;
		}
		else
		{
			if (wybor2 == 2)
			{
				cout << ("\t\t\t\t\t\tWybrales poziom Sredni\n");
				szanse = 2;
				ok2 = 1;
			}
			else
			{
				if (wybor2 == 3)
				{
					cout << ("\t\t\t\t\t\tWybrales poziom Trudny\n");
					szanse = 1;
					ok2 = 1;
				}
				else
				{
					cout << ("\t\t\t\t\t\tNiepoprawny znak\n");
				}
			}
		}
	}


}


/*void prezentuj_pytanie()
{
	cout << ("\t\t\t\t\t\t Pytanie: ") << (pytanie) << ("\n");

	int dobrze = 1;
	if (dobrze == 1)
	{
		pytanie++;
	}
	else
	{
		szanse = szanse - 1;
		sprawdzenie_wyniku();
	}
}*/


void prezentuj_gre()
{
	if (ok == 1)
	{
		cout << ("\t\t\t\t\tWitamy w milionerach. Posiadasz ") << (szanse) << " sznase.\n\t\t\t\t\tOdpowiadaj uzywajac a,b,c,d. Powodzenia!" << endl;
	}
}


void losuj_pytania(int ile_pytan_w_partii)
{
	ile_pytan_w_partii = 14;
	int ni = 0;
	while (ni < ile_pytan_w_partii)
	{
		int nrp = rand() % ilosc_pytan + 1;
		int pytanie_ok = 1, nj;
		for (nj = 0; nj < ni && pytanie_ok; nj++)
		{
			if (nrp == tabela_pytan[nj])
			{
				pytanie_ok = 0;
			}
		}
		if (pytanie_ok == 1)
		{
			tabela_pytan[ni] = nrp;
		}
	}
}



int pokaz_pytanie()
{
	string pytanie[MAX];
	string odpA[MAX], odpB[MAX], odpC[MAX], odpD[MAX];
	string poprawna[MAX];
	string odpowiedz;



	int nr_linii = 1;
	string linia;
	int nr_pytania = 0;
	fstream plik;
	plik.open("pytania.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku";
		exit(0);
	}
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 1: pytanie[nr_pytania] = linia; 	break;
		case 2: odpA[nr_pytania] = linia; 		break;
		case 3: odpB[nr_pytania] = linia; 		break;
		case 4: odpC[nr_pytania] = linia; 		break;
		case 5: odpD[nr_pytania] = linia; 		break;
		case 6: poprawna[nr_pytania] = linia; 	break;
		}
		if (nr_linii == 6)
		{
			nr_linii = 0;
			//losuj_pytania(nr_pytania);
			nr_pytania = rand() % (ilosc_pytan);
			nr_pytania++;
		}
		nr_linii++;
	}

	plik.close();
	for (i = 0; i <= 13; i++)
	{
		rysuj_drabine(p);
		//cout << (nr_pytania);
		cout << endl << pytanie[i] << endl;
		cout << "A. " << odpA[i] << endl;
		cout << "B. " << odpB[i] << endl;
		cout << "C. " << odpC[i] << endl;
		cout << "D. " << odpD[i] << endl;
		cout << "twoja odpowiedz: ";
		cin >> (odpowiedz);


		transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);
		if (odpowiedz == poprawna[i])
		{
			j++;
			p++;
			switch (j)
			{
			case 1: wartosc = 500; break;
			case 2: wartosc = 500; break;
			case 3: wartosc = 1000; break;
			case 4: wartosc = 3000; break;
			case 5: wartosc = 5000; break;
			case 6: wartosc = 10000; break;
			case 7: wartosc = 20000; break;
			case 8: wartosc = 35000; break;
			case 9: wartosc = 50000; break;
			case 10: wartosc = 125000; break;
			case 11: wartosc = 250000; break;
			case 12: wartosc = 500000; break;

			}
			pieniadze = pieniadze + wartosc;
			cout << "Dobrze! Masz teraz " << (pieniadze) << " zlotych" << endl;
			sprawdzenie_wyniku();
			zapisz();
		}
		else
		{
			szanse = szanse - 1;
			cout << "Nie poprawna odpowiedz! Poprawna odpowiedz to " << poprawna[i] << endl;
			sprawdzenie_wyniku();
			zapisz();
		}




	}
	cout << endl << "Koniec gry! Zdobyles " << (pieniadze) << " zlotych\n";
	return 0;
}


void dodaj_pytanie()
{
	string pytanie, poprawna, a, b, c, d;
	/*cout << "Twoje pytanie: " << endl;
	getline(cin, pytanie);
	cout << "1 odpowiedz: " << endl;
	getline(cin, a);
	cout << "2 odpowiedz: " << endl;
	getline(cin, b);
	cout << "3 odpowiedz: " << endl;
	getline(cin, c);
	cout << "4 odpowiedz: " << endl;
	getline(cin, d);
	cout << "poprawna odpowiedz (litera): " << endl;
	getline(cin, poprawna);*/
	cout << "Twoje pytanie: " << endl;
	cin >> pytanie;
	cout << "1 odpowiedz: " << endl;
	cin >> a;
	cout << "2 odpowiedz: " << endl;
	cin >> b;
	cout << "3 odpowiedz: " << endl;
	cin >> c;
	cout << "4 odpowiedz: " << endl;
	cin >> d;
	cout << "poprawna odpowiedz (litera): " << endl;
	cin >> poprawna;

	fstream plik;
	plik.open("pytania.txt", ios::out | ios::app);
	if (plik.good() == false)
	{
		cout << "Cos poszlo nie tak :(";
	}
	else {
		plik << pytanie << endl;
		plik << a << endl;
		plik << b << endl;
		plik << c << endl;
		plik << d << endl;
		plik << poprawna << endl;
		plik.close();
		ilosc_pytan++;
	}
	exit(0);
}


void sprawdzenie_wyniku()
{
	//int decyzja = 1;
	if (szanse == 0)
	{
		cout << "Niestety Przegrales. Sprobuj ponownie " << endl << "Twoj wynik to " << (pieniadze) << " zlotych\n";
		i = -1;
		//decyzja = 0;
		wynik();
		exit(0);
	}
	else
	{
		if (pieniadze == 1000000)
		{
			cout << "Gratulcje, Wygrales 1 MLN zlotych!!! " << endl << "Mozesz teraz dodac swoje pytanie do puli" << endl;
			wynik();
			dodaj_pytanie();
		}
	}

}