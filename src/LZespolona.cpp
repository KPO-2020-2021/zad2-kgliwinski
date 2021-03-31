#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.00001
#define READ_ERR -1 /*zmienna do sprawdzania bledu odczytu*/
/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool LZespolona::operator==(LZespolona Skl2) const
{
  /*
  if ((re == Skl2.re) && (im == Skl2.im))
    return true;
  else
    return false;
    */
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika

  if ((abs(re - Skl2.re) <= MIN_DIFF) && (abs(im - Skl2.im) <= MIN_DIFF)) //uzyje alternatywnego podejscia aby test2 z dzieleniem przez skalar 2 dzialal
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
LZespolona LZespolona::operator+(LZespolona Skl2) const
{
  LZespolona Wynik;

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
LZespolona LZespolona::operator/(double Skl2) const
{
  LZespolona Wynik;
  if (Skl2!=0){
  Wynik.re = re / Skl2;
  Wynik.im = im / Skl2;
  return Wynik;
  }
  else{   /*Przy dzieleniu przez 0 funkcja wypisuje blad oraz zwraca liczbe zespolona rowna 0*/
    throw std::runtime_error("Blad: Proba dzielenia przez 0");
  }
}

/************************************************************/
/* Realizuje sprzezenie jednej liczby zespolonej.           */
/* Argument:                                                */
/*    Skl - liczba zepsolona ktora sprzezamy                */
/* Zwraca:                                                  */
/*    Sprzezona liczbe zepsolona                            */
/************************************************************/
LZespolona LZespolona::Sprzezenie() const
{
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
double LZespolona::Modul2() const
{
  double wynik = re * re + im * im;
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
LZespolona LZespolona::operator-(LZespolona Skl2) const
{
  LZespolona Wynik;

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
LZespolona LZespolona::operator*(LZespolona Skl2) const
{
  LZespolona Wynik;

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
LZespolona LZespolona::operator/(LZespolona Skl2) const
{

  double modul2_skl2 = Skl2.Modul2(); //pobranie modulu Skl2

  if (modul2_skl2 != 0)
  { //Warunek zabezpieczajacy przed dzieleniem przez 0
    LZespolona Wynik, Sprzez = Skl2.Sprzezenie(), a;
    a.re = re;
    a.im = im;
    Wynik = a * Sprzez / modul2_skl2;
    return Wynik;
  }
  else
  {
    throw std::runtime_error("Blad: Proba dzielenia przez 0");
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
std::ostream &operator<<(std::ostream &stdwyj, LZespolona Skl)
{
  stdwyj.precision(4); /*wypisanie do 4 miejsc po przecinku*/
  return stdwyj <<'('<< Skl.re << std::showpos << Skl.im << std::noshowpos << 'i' << ')';
}

/************************************************************/
/* Definiuje co program ma zrobic gdy wczytywana jest       */
/* bledna wartosc                                           */
/* Argumenty:                                               */
/*    stdwej - operator strumienia wejsciowego              */
/* Zwraca:                                                  */
/*    komunikat bledu oraz ustawia flage failbit dla stdwej */
/************************************************************/
void blad_wczyt(std::istream &stdwej)
{

  std::cerr << std::endl
            << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << std::endl; /*komunikat o bledzie wczytania*/
  stdwej.setstate(std::ios::failbit);                                              /*ustawienie flagi bledu wczytania*/
}

/************************************************************/
/* Wczytuje znak do strumienia i zwraca wartosc logiczna    */
/* czy zostal wczytany odpowiedni znak                      */
/* Argumenty:                                               */
/*    stdwej - operator strumienia wejsciowego              */
/*    znak - znak ktory chcemy sprawdzic czy jest           */
/*           odpowiednio wczytywany                         */
/* Zwraca:                                                  */
/*    znak w strumieniu wejsciowym oraz 1 lub 0 (w          */
/*    zaleznosci czy znak sie odpowiednio wczytal           */
/************************************************************/
bool czyt_sym(std::istream &stdwej, char znak)
{
  char read_znak = ' ';
  stdwej >> read_znak;
  if (read_znak != znak)
  {
    blad_wczyt(stdwej);
    return 0;
  }
  return 1;
}

/************************************************************/
/* Definiuje w jaki sposob wczytywac liczby zespolone       */
/* Argumenty:                                               */
/*    stdwej - operator strumienia wyjsciowego              */
/*    Skl - wczytywana liczba zespolona                     */
/* Zwraca:                                                  */
/*    wczytana odpowiednio liczbe zespolona Skl             */
/************************************************************/
std::istream &operator>>(std::istream &stdwej, LZespolona &Skl)
{

  if (!czyt_sym(stdwej, '('))
    return stdwej;

  stdwej >> Skl.re;
  if (stdwej.fail())
  {
    blad_wczyt(stdwej);
    return stdwej;
  }
  stdwej >> Skl.im;
  if (stdwej.fail())
  {
    blad_wczyt(stdwej);
    return stdwej;
  }
  if (!czyt_sym(stdwej, 'i'))
    return stdwej;

  if (!czyt_sym(stdwej, ')'))
    return stdwej;

  return stdwej;
}