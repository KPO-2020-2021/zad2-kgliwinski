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

bool LZespolona::operator == (LZespolona  Skl2){
  /*
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;
    */
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  
  if (abs(re - Skl2.re) <= MIN_DIFF && abs(im - Skl2.im) <= MIN_DIFF) //uzyje alternatywnego podejscia aby test2 z dzieleniem przez skalar 2 dzialal
    return true;
  else
    return false;
  
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
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
LZespolona  LZespolona::operator / (double  Skl2){
  LZespolona  Wynik;

  Wynik.re = re / Skl2;
  Wynik.im = im / Skl2;
  return Wynik;
}


/************************************************************/
/* Realizuje sprzezenie jednej liczby zespolonej.           */
/* Argument:                                                */
/*    Skl - liczba zepsolona ktora sprzezamy                */
/* Zwraca:                                                  */
/*    Sprzezona liczbe zepsolona                            */
/************************************************************/
LZespolona LZespolona::Sprzezenie(){
  LZespolona conjugated;
  conjugated.re = re;
  conjugated.im = -im;
  return conjugated;
}

/************************************************************/
/* Pozwala na uzyskanie kwadratu modulu liczby zespolonej   */
/* Argument:                                                */
/*    Skl - liczba zepsolona ktorej modul^2 chcemy uzyskac  */
/* Zwraca:                                                  */
/*    Kwadrat modulu liczby zespolonej (liczbe rzeczywista) */
/************************************************************/
double LZespolona::Modul2(){
  double wynik = re*re+im*im;
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
LZespolona  LZespolona::operator - (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
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
LZespolona LZespolona::operator * ( LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re * Skl2.re - im * Skl2.im;
  Wynik.im = re * Skl2.im + im * Skl2.re;
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
LZespolona LZespolona::operator / (LZespolona  Skl2)
{
  
  double modul2_skl2 = Skl2.Modul2();        //pobranie modulu Skl2

  if (modul2_skl2!=0){                      //Warunek zabezpieczajacy przed dzieleniem przez 0
    LZespolona  Wynik, Sprzez = Skl2.Sprzezenie(), a;
    a.re = re; a.im = im;
    Wynik = a*Sprzez/modul2_skl2;
    return Wynik;
  }
  else{
    std::cerr<<"Dzielenie liczb zespolonych nie powiodlo sie. W mianowniku jest liczba rowna 0: kwadrat modulu z liczby ";
    return Skl2;    //dzielenie przez zero zwroci komunikat bledu oraz mianownik dzielenia 
    
  }
}

/************************************************************/
/* Definiuje w jaki sposob wyswietlac liczby zespolone      */
/* Argumenty:                                               */
/*    stdwyj - operator strumienia wyjsciowego              */
/*    Skl - wyswietlana liczba zespolona                    */
/* Zwraca:                                                  */
/*    wyswietlona odpowiednio liczbe zespolona Skl          */
/************************************************************/
std::ostream & operator << ( std::ostream & stdwyj ,   LZespolona Skl){
  return stdwyj<<Skl.re<< std::showpos <<Skl.im<< std::noshowpos <<'i';
}

/************************************************************/
/* Definiuje w jaki sposob wczytywac liczby zespolone       */
/* Argumenty:                                               */
/*    stdwej - operator strumienia wyjsciowego              */
/*    Skl - wczytywana liczba zespolona                     */
/* Zwraca:                                                  */
/*    wczytana odpowiednio liczbe zespolona Skl             */
/************************************************************/
std::istream & operator >> ( std::istream & stdwej,  LZespolona & Skl){
  char nawias, litera;
  stdwej>>nawias;
  if (stdwej.fail())
    return stdwej;
  if (nawias!='('){
    stdwej.setstate(std::ios::failbit);
    return stdwej;
  }
  stdwej>>Skl.re;
  if (stdwej.fail())
    return stdwej;
  stdwej>>Skl.im;
  if (stdwej.fail())
    return stdwej;
  stdwej>>litera;
  if (stdwej.fail())
    return stdwej;
  if (litera!='i'){
    stdwej.setstate(std::ios::failbit);
    return stdwej;
  }
  stdwej>>nawias;
  if (stdwej.fail())
    return stdwej;
  if(nawias!=')'){
    stdwej.setstate(std::ios::failbit);
    return stdwej;
  }
  return stdwej;


}