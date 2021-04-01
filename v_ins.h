#ifndef V_INS_H
#define V_INS_H


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <time.h>
#include <cmath>

using namespace std;

struct Lista {
    string nazwa;
    int dostepne_rowery;
    int ilosc_stojakow;
    int wolne_stojaki;
    double wspolrz1;
    double wspolrz2;

    Lista *nast;
};

void wstaw_na_koniec(string nazwa, int dostepne_rowery, int ilosc_stojakow, int wolne_stojaki, double wspolrz1, double wspolrz2, Lista *&glowa);

void wczytanie_z_pliku(ifstream &plik, Lista *&glowa);

void drukuj_liste(Lista *&glowa);

void drukuj_naglowek();

void drukuj_pojedyncza(Lista *&glowa, int numer);

void szukanie_nazwy(Lista *&glowa, string lokalizacja);

void szukanie_wsp1(Lista *&glowa, double wsp1);

void szukanie_wsp2(Lista *&glowa, double wsp1, double wsp2);

void wpisz_rzeczy(Lista *&nowy, string &nazwa, int &dostepne_rowery, int &ilosc_stojakow, int &wolne_stojaki, double &wspolrz1, double &wspolrz2);

void dodaj_na_poczatek(Lista *&glowa);

void dodaj_na_koniec(Lista *&glowa);

void dodaj_na_numer(Lista *&glowa);

void usun_poczatek(Lista *&glowa);

void usun_koniec(Lista *&glowa);

void usun_numer(Lista *&glowa);





#endif // V_INS_H
