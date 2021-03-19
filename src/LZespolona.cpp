#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.00001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  /*
  if abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF
    return true;
  else
    return false;
  */
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}


/************************************************************/
/* Realizuje sprzezenie jednej liczby zespolonej.           */
/* Argument:                                                */
/*    Skl - liczba zepsolona ktora sprzezamy                */
/* Zwraca:                                                  */
/*    Sprzezona liczbe zepsolona                            */
/************************************************************/
LZespolona Sprzezenie(LZespolona Skl){
  LZespolona conjugated;
  conjugated.re = Skl.re;
  conjugated.im = -Skl.im;
  return conjugated;
}

/************************************************************/
/* Pozwala na uzyskanie kwadratu modulu liczby zespolonej   */
/* Argument:                                                */
/*    Skl - liczba zepsolona ktorej modul^2 chcemy uzyskac  */
/* Zwraca:                                                  */
/*    Kwadrat modulu liczby zespolonej (liczbe rzeczywista) */
/************************************************************/
double Modul2(LZespolona Skl){
  double wynik = Skl.re*Skl.re + Skl.im*Skl.im;
  return wynik;
}

/************************************************************/
/* Realizuje odejmowanie dwoch liczb zespolonych.           */
/* Argumenty:                                               */
/*    Skl1 - pierwszy skladnik odejmowania                  */
/*    Skl2 - drugi skladnik odejmowania                     */
/* Zwraca:                                                  */
/*    Roznice dwoch skladnikow przekazanych jako parametry. */
/************************************************************/
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/************************************************************/
/* Realizuje mnozenie dwoch liczb zespolonych.              */
/* Argumenty:                                               */
/*    Skl1 - pierwszy skladnik mnozenia,                    */
/*    Skl2 - drugi skladnik mnozenia.                       */
/* Zwraca:                                                  */
/*    Iloczyn dwoch skladnikow przekazanych jako parametry. */
/************************************************************/
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re  - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

/************************************************************/
/* Realizuje dzielenie dwoch liczb zespolonych.             */
/* Argumenty:                                               */
/*    Skl1 - pierwszy skladnik dzielenia,                   */
/*    Skl2 - drugi skladnik dzielenia,                      */
/* Zwraca:                                                  */
/*    Iloraz dwoch skladnikow przekazanych jako parametry.  */
/************************************************************/
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  
  double modul2_skl2 = Modul2(Skl2);        //pobranie modulu Skl2
  if (modul2_skl2!=0){                      //Warunek zabezpieczajacy przed dzieleniem przez 0
    LZespolona  Wynik;
    Wynik=Skl1*Sprzezenie(Skl2)/modul2_skl2;
    return Wynik;
  }
  else{
    cerr<<"Dzielenie liczb zespolonych nie powiodlo sie. W mianowniku jest liczba rowna 0: ";
    return Skl2;    //dzielenie przez zero zwroci komunikat bledu oraz mianownik dzielenia 
    
  }
}

/************************************************************/
/* Definiuje w jaki sposob wyswietlac liczby zespolone      */
/* Argumenty:                                               */
/*    stdout - operator strumienia wyjsciowego              */
/*    Skl - wyswietlana liczba zespolona                    */
/* Zwraca:                                                  */
/*    brak                                                  */
/************************************************************/
ostream & operator << ( ostream & stdout , LZespolona Skl){
  return stdout << Skl.re << showpos << Skl.im << noshowpos << 'i';
}