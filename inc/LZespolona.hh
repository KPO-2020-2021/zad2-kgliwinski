#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

LZespolona Sprzezenie();

double Modul2();

LZespolona  operator - ( LZespolona Skl2);

LZespolona  operator * (LZespolona Skl2);

LZespolona  operator / (LZespolona Skl2);

bool  operator == (LZespolona  Skl2);

LZespolona  operator + (LZespolona  Skl2);

LZespolona operator / (double Skl2);

};

std::ostream & operator << ( std::ostream & stdwyj, LZespolona Skl);

std::istream & operator >> ( std::istream & stdwej, LZespolona & Skl);

void blad_wczyt (std::istream & stdwej);
#endif
