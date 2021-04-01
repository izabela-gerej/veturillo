#include "v_int.h"
#include "v_ins.h"
#include <iostream>

using namespace std;

int main()
{
    ifstream plik;
    Lista *glowa=NULL;

    wczytanie_z_pliku(plik,glowa);

    int wybor=-1;
    while(true)
    {
        wypisanie_menu();
        cin>>wybor;
        switch(wybor)
        {
        case 1:
        {
            cout<<"\n";
            drukuj_naglowek();
            drukuj_liste(glowa);
            cout<<"\n";
            break;
        }
        case 2:
        {
            string szukana;
            cout<<"Podaj szukana nazwe: ";
            cin>>szukana;
            szukanie_nazwy(glowa, szukana);
            cout<<"\n";
            break;
        }
        case 3:
        {
            cout<<"Wybierz 1 aby szukac po dlugosci \n";
            cout<<"Wybierz 2 aby szukac po dlugosci i szerokosci \n";
            int wyborcase3=0;

            while(wyborcase3!=1 && wyborcase3!=2)
            {
                cin>>wyborcase3;
                switch (wyborcase3)
                {
                case 1:
                {
                    double dlugosc = -1;
                    cout<<"Podaj dlugosc: ";
                    cin>>dlugosc;
                    szukanie_wsp1(glowa, dlugosc);
                    break;
                }
                case 2:
                {
                    double dlugosc=-1;
                    double szerokosc=-1;
                    cout<<"Podaj dlugosc: ";
                    cin>>dlugosc;
                    cout<<"Podaj szerokosc: ";
                    cin>>szerokosc;
                    szukanie_wsp2(glowa, dlugosc, szerokosc);
                    break;
                }
                default:
                {
                    cout<<"Podaj poprawny wybor \n";
                    break;
                }
                }
            }
            break;
        }
        case 4:
        {
            cout<<"Wybierz 1 aby dodac na poczatek \n";
            cout<<"Wybierz 2 aby dodac na koniec \n";
            cout<<"Wybierz 3 aby dodac na miejsce o numerze.. \n";

            int wyborcase4=0;
            while(wyborcase4!=1 && wyborcase4!=2 &&wyborcase4!=3)
            {
                cin>>wyborcase4;
                switch(wyborcase4)
                {
                case 1:
                {
                    dodaj_na_poczatek(glowa); //czy wpisywanie lepiej zeby bylo tu czy w funkcji ok?
                    break;
                }
                case 2:
                {
                    dodaj_na_koniec(glowa);
                    break;
                }
                case 3:
                {
                    dodaj_na_numer(glowa);
                    break;
                }
                default:
                {
                    cout<<"Podaj poprawny wybor \n";
                    break;
                }
                }
            }
            break;
        }

        case 5:
        {
            cout<<"Wybierz 1 aby usunac poczatek \n";
            cout<<"Wybierz 2 aby usunac koniec \n";
            cout<<"Wybierz 3 aby usunac miejsce o numerze.. \n";

            int wyborcase5=0;
            while(wyborcase5!=1 && wyborcase5!=2 &&wyborcase5!=3)
            {
                cin>>wyborcase5;
                switch(wyborcase5)
                {
                case 1:
                {
                    usun_poczatek(glowa);
                    break;
                }
                case 2:
                {
                    usun_koniec(glowa);
                    break;
                }
                case 3:
                {
                    usun_numer(glowa);
                    break;
                }
                default:
                {
                    cout<<"Podaj poprawny wybor \n";
                    break;
                }
                }
            }
            break;

        }

        case 6:
        {

            break;
        }

        case 7:
        {
            cout<<"\nKONIEC"<<endl;
            return 0;
        }

        default:
        {
            cout<<"Podaj poprawny wybor \n";
            break;
        }
        }

        cout<<"\n";
    }


    return 0;
}

