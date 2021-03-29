#include <iostream>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{
  LZespolona pyt_test;    /*zmienna do obslugi pytania testowego*/
  statystyki stat;        /*zmienna do zliczania odpowiedzi poprawnych*/
  stat.popr=0; stat.bled=0;

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Wynik;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout<<"Podaj wynik operacji: "<<WyrZ_PytanieTestowe<<" ="<<endl;
    cout<<"Twoja odpowiedz: ";
    cin>>pyt_test;

    Wynik = WyrZ_PytanieTestowe.Oblicz();   /*liczenie postawionego wyrazenia zespolonego*/
    if (pyt_test == Wynik){                 /*gdy uzytkownik poda dobra odpowiedz*/
      cout<<"Odpowiedz poprawna"<<endl;
      stat.popr++;
    }
    else{                                   /*gdy uzytkownik poda bledna odpowiedz*/
      cout<<"Blad. Prawidlowym wynikiem jest: "<<Wynik<<endl;
      stat.bled++;
    }

  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  cout<<stat;       /*wypisanie statystyk (poprzez przeciazony operator dla struktury statystyki)*/



}
