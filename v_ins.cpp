#include "v_ins.h"


void wstaw_na_koniec(string nazwa, int dostepne_rowery, int ilosc_stojakow, int wolne_stojaki, double wspolrz1, double wspolrz2, Lista *&glowa)
{

    Lista *tmp=NULL;
    Lista *ogon=NULL;

    tmp=glowa;

    ogon=new Lista;
    ogon->nast=NULL;

    ogon->nazwa=nazwa;
    ogon->dostepne_rowery=dostepne_rowery;
    ogon->ilosc_stojakow=ilosc_stojakow;
    ogon->wolne_stojaki=wolne_stojaki;
    ogon->wspolrz1=wspolrz1;
    ogon->wspolrz2=wspolrz2;

    if(tmp!=NULL)
    {
        while(tmp->nast)
            tmp=tmp->nast;

        tmp->nast=ogon;
    }
    else
        glowa=ogon;
}


void wczytanie_z_pliku(ifstream &plik, Lista *&glowa)
{
    plik.open("stacje_v.txt");
    string nazwa;
    int dostepne_rowery, ilosc_stojakow, wolne_stojaki;
    double wspolrz1, wspolrz2;

    cout<<"Sprawdzanie pliku...";
    if(plik.good())
    {
        cout<<"OK! \n";
    }
    else
    {
        cout<<"ERROR! \n";
        return;
    }

    while(!plik.eof())
    {
        plik>>nazwa;
        plik>>dostepne_rowery;
        plik>>ilosc_stojakow;
        plik>>wolne_stojaki;
        plik>>wspolrz1;
        plik>>wspolrz2;
        wstaw_na_koniec(nazwa, dostepne_rowery, ilosc_stojakow, wolne_stojaki, wspolrz1, wspolrz2, glowa);
    }
    cout<<"Dane zostaly odczytane \n";
}

void drukuj_naglowek()
{
    //cout<< "lokalizacja" <<'\t'<<'\t'<< "dostepne_rowery" <<'\t'<<'\t'<< "wolne_stojaki" <<'\t'<<'\t'<< "wspolrzedne1" <<'\t'<<'\t'<< "wspolrzedne2" <<endl;

    cout.width(44);
    cout<<left<<"lokalizacja";
    cout.width(20);
    cout<<"dostepne_rowery";
    cout.width(19);
    cout<<"ilosc_stojakow";
    cout.width(17);
    cout<<"wspolrzedne1";
    cout.width(17);
    cout<<"wspolrzedne2"<<"\n";
}

void drukuj_liste(Lista *&glowa)
{
    Lista *tmp=glowa;
    int indeks=1;

    while(tmp!=NULL)
    {
        // cout<<indeks<<".) "<<setw(10)<< tmp->nazwa <<setw(10)<< tmp->dostepne_rowery <<setw(10)<< tmp->wolne_stojaki <<setw(10)<< tmp->wspolrz1 <<setw(10)<< tmp->wspolrz2 <<endl;

        cout.width(3);
        cout<<indeks<<".) ";
        cout.width(45);
        cout<<tmp->nazwa;
        cout.width(19);
        cout<<tmp->dostepne_rowery;
        cout.width(14);
        cout<<tmp->ilosc_stojakow;
        cout.width(17);
        cout<<setprecision(10)<<tmp->wspolrz1;
        cout<<setprecision(10)<<tmp->wspolrz2<<"\n";

        tmp=tmp->nast;
        indeks++;
    }
}

void drukuj_pojedyncza(Lista *&glowa, int numer)
{
    Lista *tmp=glowa;
    int n=1;

    if(tmp==NULL)
        return;

    while(n!=numer)
    {
        tmp=tmp->nast;
        n++;
    }
    cout.width(3);
    cout<<n<<".) ";
    cout.width(43);
    cout<<tmp->nazwa;
    cout.width(19);
    cout<<tmp->dostepne_rowery;
    cout.width(14);
    cout<<tmp->ilosc_stojakow;
    cout.width(17);
    cout<<setprecision(10)<<tmp->wspolrz1;
    cout<<setprecision(10)<<tmp->wspolrz2<<"\n";
}

void szukanie_nazwy(Lista *&glowa, string lokalizacja)
{
    Lista *tmp=glowa;
    int indeks=1;
    bool znaleziona=0;
    while(tmp!=NULL)
    {
      //  if(tmp->nazwa.find(lokalizacja) <= tmp->nazwa.length())

        if(tmp->nazwa.find(lokalizacja) != std::string::npos)
        {
            znaleziona=1;
            drukuj_pojedyncza(glowa, indeks);
        }
        indeks++;
        tmp=tmp->nast;
    }
    if(znaleziona==0)
        cout<<"nie znaleziono lokalizacji \n";
}

void szukanie_wsp1(Lista *&glowa, double wsp1)
{
    Lista *tmp=glowa;
    int indeks=1;
    bool znaleziona=0;
    while(tmp!=NULL)
    {
        if(abs(tmp->wspolrz1 - wsp1) < 0.001)
        {
            znaleziona=1;
            drukuj_pojedyncza(glowa,indeks);
        }

        indeks++;
        tmp=tmp->nast;

    }
    if(znaleziona==0)
        cout<<"nie znaleziono lokalizacji \n"<<endl;
}


void szukanie_wsp2(Lista *&glowa, double wsp1, double wsp2)
{
    Lista *tmp=glowa;
    int indeks=1;
    bool znaleziona=0;
    while(tmp!=NULL)
    {
        if(abs(tmp->wspolrz1 - wsp1)<0.001 && abs(tmp->wspolrz2 - wsp2)<0.001)
        {
            znaleziona=1;
            drukuj_pojedyncza(glowa,indeks);
        }
        indeks++;
        tmp=tmp->nast;
    }
    if(znaleziona==0)
        cout<<"nie znaleziono lokalizacji \n";
}




void wpisz_rzeczy(Lista *&nowy, string &nazwa, int &dostepne_rowery, int &ilosc_stojakow, int &wolne_stojaki, double &wspolrz1, double &wspolrz2)
{
    dostepne_rowery=0, ilosc_stojakow=0, wolne_stojaki=0;
    wspolrz1=0, wspolrz2=0;

    nowy=new Lista;      //ALE wtedy tu jest robienie nowego miejsca

    cout<<"Podaj nazwe lokalizacji: ";
    cin>>nazwa;
    cout<<"Podaj liczbe dostepnych rowerow: ";
    cin>>dostepne_rowery;
    cout<<"Podaj ilosc stojakow: ";
    cin>>ilosc_stojakow;
    cout<<"Podaj ilosc wolnych stojakow: ";
    cin>>wolne_stojaki;
    cout<<"Podaj dlugosc geograficzna: ";
    cin>>wspolrz1;
    cout<<"Podaj szerokosc geograficzna: ";
    cin>>wspolrz2;
    cout<<"\n";

    nowy->nazwa=nazwa;
    nowy->dostepne_rowery=dostepne_rowery;
    nowy->ilosc_stojakow=ilosc_stojakow;
    nowy->wolne_stojaki=wolne_stojaki;
    nowy->wspolrz1=wspolrz1;
    nowy->wspolrz2=wspolrz2;

}

void dodaj_na_poczatek(Lista *&glowa)
{
    Lista *nowy=new Lista; //ALE wtedy tu tez jest robienie nowego miejsca

    string nazwa;
    int dostepne_rowery=0, ilosc_stojakow=0, wolne_stojaki=0;
    double wspolrz1=0, wspolrz2=0;

    wpisz_rzeczy(nowy, nazwa, dostepne_rowery, ilosc_stojakow, wolne_stojaki, wspolrz1, wspolrz2);

    if(glowa!=NULL)
    {
        nowy->nast=glowa;
        glowa=nowy;
    }
    else
        glowa=nowy;
}


void dodaj_na_koniec(Lista *&glowa)
{
    Lista *nowy=new Lista;
    Lista *tmp=glowa;

    string nazwa;
    int dostepne_rowery=0, ilosc_stojakow=0, wolne_stojaki=0;
    double wspolrz1=0, wspolrz2=0;

    wpisz_rzeczy(nowy, nazwa, dostepne_rowery, ilosc_stojakow, wolne_stojaki, wspolrz1, wspolrz2);

    while(tmp->nast!=NULL)
    {
        tmp=tmp->nast;
    }
    tmp->nast=nowy;
}


void dodaj_na_numer(Lista *&glowa)
{
    Lista *nowy=new Lista;
    Lista *tmp=glowa;

    string nazwa;
    int dostepne_rowery=0, ilosc_stojakow=0, wolne_stojaki=0;
    int nr=0;
    int licz=1;
    double wspolrz1=0, wspolrz2=0;

    wpisz_rzeczy(nowy, nazwa, dostepne_rowery, ilosc_stojakow, wolne_stojaki, wspolrz1, wspolrz2);

    cout<<"Podaj numer na ktory chcesz dodac stacje: ";
    cin>>nr;
    if(nr==1)
    {
        nowy->nast=glowa;
        glowa=nowy;
    }
    else
    {
        while(licz!=(nr-1))
        {
            tmp=tmp->nast;
            licz++;
        }
        nowy->nast=tmp->nast;
        tmp->nast=nowy;
    }
}

void usun_poczatek(Lista *&glowa)
{
    if(glowa!=NULL)
    {
        Lista *tmp=glowa;
        glowa=glowa->nast;
        delete tmp;
    }
    else
        cout<<"Nie mozna usunac, bo nie ma poczatku listy \n";
}

void usun_koniec(Lista *&glowa)
{
    Lista *tmp=glowa;
    if(glowa!=NULL)
    {
        while(tmp->nast->nast!=NULL)
        {
            tmp=tmp->nast;
        }
        delete tmp->nast;
        tmp->nast=NULL;
    }
    else
        cout<<"Nie mozna usunac, nie ma konca listy \n";
}

void usun_numer(Lista *&glowa)
{
    Lista *tmp=glowa;

    int nr=0;
    int licz=1;
    cout<<"Podaj numer stacji ktora chcesz usunac: ";
    cin>>nr;

    while(tmp->nast!=NULL)
    {
        tmp=tmp->nast;
        licz++;
    }
    while(nr==0 || nr>licz)
    {
        cout<<"Podaj poprawny numer: ";
        cin>>nr;
    }

    tmp=glowa;

    if(nr==1)
    {
        usun_poczatek(glowa);
    }
    else
    {
        licz=1;
        while(licz!=(nr-1))
        {
            tmp=tmp->nast;
            licz++;
        }
        Lista *x=tmp->nast;
        tmp->nast=x->nast;
        delete x;
    }
}

